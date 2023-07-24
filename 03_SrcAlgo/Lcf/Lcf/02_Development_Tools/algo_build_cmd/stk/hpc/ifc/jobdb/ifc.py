"""
stk.hpc.util.db.ifc
-------------------

Interface file for database support for hpc job creation.

Note: for this package, SQLAlchemy 0.8.1 or higher is needed.

:org:           Continental AG
:author:        Robert Hecker

:creation date: 07.05.2013

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:25CET $
"""
# Import Python Modules -------------------------------------------------------
from . tabels import Base
from . import tabels as tabel
from sqlalchemy import create_engine
from sqlalchemy import func
from sqlalchemy.interfaces import PoolListener

import os
import sys
import pickle
from sqlalchemy.orm import sessionmaker
import threading
from os.path import basename


# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------

class SubTask(object):
    """
    Subtask class which contain all attributes which are valid in the SubTask.
    """
    name = ""
    cmdline = ""
    curworkdir = ""
    envars = []
    nodefolders = []
    appwatcher = True
    useglobaldata = False


# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------

class JournalModeListener(PoolListener):
    """
    Class which is needed to Turn Off the jounal mode on SQLite DB.
    This results in a faster commit of the DB, because the
    Backup files are not longer created.

    :author:        Robert Hecker
    :date:          04.09.2013
    """
    def connect(self, dbapi_con, con_record):
        """
        On connect event, a special dbapi command will be executed.

        :author:        Robert Hecker
        :date:          04.09.2013
        """
        dbapi_con.execute('pragma journal_mode=OFF')


class HpcDbError(BaseException):
    """
    Exception Class for all HPC Exceptions.

    :author:        Robert Hecker
    :date:          04.09.2013
    """
    def __init__(self , msg, errno= -1):
        """
        Init Method of Exception class

        :param msg:   Error Message string, which explains the user was went wrong.
        :type msg:    string
        :param errno: unique number which represents a Error Code inside the Package.
        :type errno:  integer

        :author:      Robert Hecker
        :date:        04.09.2013
        """
        BaseException.__init__(self)

        self.msg = msg
        self.errno = errno
        self.frame = sys._getframe(1)

    def __str__(self):
        return "'%s': %s (line %d) attr: %s" % (self.msg, basename(self.frame.f_code.co_filename),
                                                self.frame.f_lineno, self.frame.f_code.co_name)


class HpcDbSession(object):
    """
    **Interface for accessing the Hpc-DB Information**

    This Interface is build on SQLAlchemie, and act as an wrapper, to access the
    Information from the DB in a easy way.

    :author:        Robert Hecker
    :date:          15.05.2013
    """
    def __init__(self, engine):
        self.__session = sessionmaker(bind=engine)
        self._session = self.__session()
        self._order = 1
        self._taskname = ""

    def add(self, args):
        """
        Adds new table entries into the DB.

        :author:        Robert Hecker
        :date:          11.09.2013
        """
        self._session.add(args)

    def add_all(self, args):
        """
        Adds multiple table entries into the DB.

        :author:        Robert Hecker
        :date:          11.09.2013
        """
        self._session.add_all(args)

    def commit(self):
        """
        Commit the actual changes into the DB File.
        """
        self._session.commit()

    @property
    def job_name(self):
        """
        Read only attribute to get the JobName of the Job.

        :type: string
        """
        res = self._session.query(tabel.Job).first()
        return res.name

    @property
    def ora_usage(self):
        """
        Property to get if the Information if the Master Oracle DB
        is used or not for this Job.

        :type: boolean
        """
        res = self._session.query(tabel.Job).first()
        return res.master_ora_db

    @property
    def base_folder(self):
        """
        Base Folder of the FileServer, where the Job is stored.

        :type: string
        """
        res = self._session.query(tabel.Job).first()
        return res.hpcbasefolder

    @property
    def project_name(self):
        """
        Name of the Project (e.g. MFC310, ....)

        :type: string
        """
        res = self._session.query(tabel.Job).first()
        return res.project

    @property
    def headnode_name(self):
        """
        Server name of the used Head Node for the Cluster.

        :type: string
        """
        res = self._session.query(tabel.Job).first()
        return res.headnode

    def __get_subtask(self, taskname, sequence):
        """
        This method is returns based on a taskname and the sequence the correct
        subtask.

        This method is only for internal usage, and not part of the USER-API.

        :param taskname:   The name of the task
        :type taskname:    string
        :return:           SubTask object with all the attributes
        :rtype:            object of type SubTask

        :author:           Robert Hecker
        :date:             11.09.2013
        """
        # Get the correct Task id from the current Task
        res = self._session.query(tabel.Task).filter(tabel.Task.name == taskname).first()
        task_id = res.id

        # Select the First assigned SubTaskId from the DB
        res = self._session.query(tabel.SubTaskMapping).filter(tabel.SubTaskMapping.task_id ==
                                                               task_id, tabel.SubTaskMapping.order == sequence).first()
        subtask_id = res.subtask_id

        # Select the Correct SubTask
        subtask = self._session.query(tabel.SubTask).filter(tabel.SubTask.id == subtask_id).first()

        # Select the Settings from the SubTask
        settings = self._session.query(tabel.SubTaskSettings).filter(tabel.SubTaskSettings.id ==
                                                                     subtask.settings).first()

        result = SubTask()
        result.name = subtask.name
        result.cmdline = pickle.loads(str(subtask.cmdline))
        result.curworkdir = settings.curworkdir
        result.envars = pickle.loads(str(settings.environmentvars))
        result.nodefolders = pickle.loads(str(settings.nodefolders))
        result.appwatcher = settings.appwatcher
        result.useglobaldata = settings.globaldatafolder

        # Get all CMDVars
        cmdvars = self._get_all_cmdvars(subtask.cmdlinemapping)

        cmdline2 = []
        # Go through all CMDVars and Replace them
        for item in result.cmdline:
            if(len(cmdvars) > 0):
                for var in cmdvars:
                    item = item.replace(var, cmdvars[var])
                cmdline2.append(item)
            else:
                cmdline2.append(item)

        result.cmdline = cmdline2

        return result

    def get_first_subtask(self, taskname):
        """
        This method is returns the first subtask connected to the taskname.

        :param taskname:   The name of the task
        :type taskname:    string
        :return:           SubTask object with all the attributes
        :rtype:            object of type SubTask2

        :author:           Robert Hecker
        :date:             11.09.2013
        """
        self._order = 1
        self._taskname = taskname
        result = None

        try:
            result = self.__get_subtask(self._taskname, self._order)
            self._order += 1
        except:
            pass

        return result

    def get_next_subtask(self):
        """
        This method is returns the next subtask connected to the taskname.
        Sequential call after "get_first_subtask" or "get_next_subtask".

        :return:           SubTask object with all the attributes
        :rtype:            object of type SubTask2

        :author:           Robert Hecker
        :date:             11.09.2013
        """
        result = None

        try:
            result = self.__get_subtask(self._taskname, self._order)
            self._order += 1
        except:
            pass

        return result

    def _get_all_cmdvars(self, mapping_id):
        """
        This method returns a dictionary of all CommandlineVariables which are
        used (identified) by the mapping id.

        :param mapping_id: Number which maps a cmdvar to a subtask.
        :type mapping_id:  integer
        :return:           Dictionary filled with variables and values.
        :rtype:            dictionary

        :author:           Robert Hecker
        :date:             11.09.2013
        """
        cmdvars = {}

        res = self._session.query(tabel.CMDLineMapping).filter(tabel.CMDLineMapping.mapping_id == mapping_id).all()
        for mapping in res:
            res2 = self._session.query(tabel.CMDLineVars).filter(tabel.CMDLineVars.id == mapping.cmdvar_id).first()
            cmdvars[res2.key] = res2.value

        return cmdvars


class HpcDb(object):
    """
    Class for creating a local database file ("hpc.db") which includes all needed information about the job,
    his HPC Tasks and the SubTasks.

    With this class you can save all needed informations into a Database, so later, the HPC can get the
    whole commandline and other settings out of this Database to run the HPC Job.

    Improvements are the possibility to allow SubTasks, and to handle Commandlines which have more than
    420 characters, which was the limitation of hpc with the old interface.

    :note:          Class is not Thread Save !
                    Use this class only in a single threaded Environment!

    :author:        Robert Hecker
    :date:          15.05.2013
    """
    lock = threading.Lock()

    def __init__(self):
        self._filename = ""
        self._engine = None
        self.session = None

    @ property
    def filename(self):
        """
        Property to get the currently used Filename, which is used
        as Database SQLite file.

        :type:    string

        :author:          Robert Hecker
        :date:            15.05.2013
        """
        return self._filename

    def create(self, filename):
        """
        create a new empty database file.

        :param filename:  Name of db File to create
        :type filename:   string

        :return:          -

        :author:          Robert Hecker
        :date:            15.05.2013
        """
        if(os.path.exists(filename)):
            os.remove(filename)

        self._filename = filename

        self._engine = create_engine('sqlite:///' + filename, listeners=[JournalModeListener()])
        # self._engine = create_engine('sqlite:///hpc.db', echo=True)
        self.session = HpcDbSession(self._engine)
        # create tables
        Base.metadata.create_all(self._engine)

    def open(self, filename):
        """
        Opens a existing database file.

        :return:         -

        :author:        Robert Hecker
        :date:          15.05.2013
        """
        self._filename = filename

        self._engine = create_engine('sqlite:///' + self._filename)
        # self._engine = create_engine('sqlite:///' + self._filename, echo=True)
        self.session = HpcDbSession(self._engine)

    def add_subtask_settings(self, cwd, envars, nodefolders, appwatch, useglobaldatafolder):
        """
        Adds a new SubTaskEntry into the DB.

        :param cwd:                 CurentWorkingDirectory
        :type cwd:                  string
        :param envars:              Environment Variables
        :type envars:               list of strings
        :param nodefolders:         Node Folders
        :type nodefolders:          list of strings
        :param appwatch:            Enable ApplicationWatcher
        :type appwatch:             boolean
        :param useglobaldatafolder: Enable Usage of the "2_Output/data Folder
        :type useglobaldatafolder:  boolean
        :return:                    unique id of the created entry

        :note:                      When useGlobalDataFolder is "True", the job can only be configured with
                                    JobUnitType=Node ! Should not be used!
                                    The appwatch should be all the time "True"

        :author:                    Robert Hecker
        :date:                      15.05.2013
        """
        subtasksettings = tabel.SubTaskSettings(cwd, envars, nodefolders, appwatch, useglobaldatafolder)
        self.session.add(subtasksettings)
        self.session.commit()

        sub_id = subtasksettings.id

        if(sub_id is None):
            raise HpcDbError("subtask ID is set to None")

        return sub_id

    def add_cmdvar(self, key, value):
        """
        Adds a new CmdVariable into the DB.

        :param key:     key which is used for replacement in cmdline string.
        :type key:      string
        :param value:   value
        :type value:    the value for replacement.
        :return:        unique id of the created entry

        :author:        Robert Hecker
        :date:          15.05.2013
        """
        cmdvar = tabel.CMDLineVars(key, value)
        self.session.add(cmdvar)
        self.session.commit()

        cmdvar_id = cmdvar.id

        if(cmdvar_id is None):
            raise HpcDbError("cmdvar ID is set to None")

        return cmdvar_id

    def add_mapping(self, cmdvarmapping):
        """
        Adds a new Mapping Entry between SubTask Table and CMDVar Table.
        With This Mapping Entry, the correct relationship for replacing the
        CMDVar Entries with the correct Values can be made.

        :param cmdvarmapping:   actual set, for the cmdvars and their ids.
        :type cmdvarmapping:    dict
        :return:                unique id of the created entry

        :author:                Robert Hecker
        :date:                  15.05.2013
        """
        self.lock.acquire()

        mapping_id = 0

        if(len(cmdvarmapping) > 0):
            # Get last used mapping id
            qry = self.session._session.query(func.max(tabel.CMDLineMapping.mapping_id))
            for res in qry.all():
                if(res[0] is not None):
                    mapping_id = res[0] + 1

        self.lock.release()

        for item in cmdvarmapping:
            mapping = tabel.CMDLineMapping(mapping_id, cmdvarmapping[item])
            self.session.add(mapping)
            self.session.commit()

        if(mapping_id is None):
            raise HpcDbError("Mapping ID is set to None")

        return mapping_id

    def add_subtask(self, name, cmdline, settings, cmdlinemapping):
        """
        Adds a new SubTask into the db.
        With This Mapping Entry, the correct relationship for replacing the
        CMDVar Entries with the correct Values can be made.

        :param name:            name of SubTask
        :type name:             string
        :param cmdline:         cmdline for subtask to execute.
        :type cmdline:          list of strings
        :param settings:        settings
        :type settings:         integer
        :param cmdlinemapping:  cmdvar Mapping set to be used.
        :type cmdlinemapping:   integer
        :return:                unique id of the created entry

        :author:                Robert Hecker
        :date:                  15.05.2013
        """

        subtask = tabel.SubTask(name, cmdline, settings, cmdlinemapping)
        self.session.add(subtask)
        self.session.commit()

        return subtask.id

"""
CHANGE LOG:
-----------
$Log: ifc.py  $
Revision 1.1 2021/12/13 17:57:25CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/jobdb/project.pj
Revision 1.11 2013/09/11 17:57:42CEST Hecker, Robert (heckerr) 
Some adaptions regarding pylint.
- Added comments -  heckerr [Sep 11, 2013 5:57:42 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.10 2013/09/11 13:59:25CEST Hecker, Robert (heckerr)
- Added Docu.
- Removed some pylint Issues.
--- Added comments ---  heckerr [Sep 11, 2013 1:59:25 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.9 2013/09/06 15:01:18CEST Hecker, Robert (heckerr)
Added modifications for parallel submit possibility.
sqlite DB Filename is now the JobName.
--- Added comments ---  heckerr [Sep 6, 2013 3:01:18 PM CEST]
Change Package : 193310:1 http://mks-psad:7002/im/viewissue?selection=193310
Revision 1.8 2013/09/05 11:46:56CEST Hecker, Robert (heckerr)
derived HpcDbError class from the HpcError Exception class.
--- Added comments ---  heckerr [Sep 5, 2013 11:46:56 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.7 2013/08/09 10:29:53CEST Hecker, Robert (heckerr)
BugFix: Changed Variable Name to prevent crash.
--- Added comments ---  heckerr [Aug 9, 2013 10:29:53 AM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.6 2013/08/08 09:03:45CEST Hecker, Robert (heckerr)
Bugfix in import and variable name.
--- Added comments ---  heckerr [Aug 8, 2013 9:03:45 AM CEST]
Change Package : 192878:1 http://mks-psad:7002/im/viewissue?selection=192878
Revision 1.5 2013/07/15 16:39:49CEST Hecker, Robert (heckerr)
Removed Journal Feature in sqlite, to improve performance.
--- Added comments ---  heckerr [Jul 15, 2013 4:39:49 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.4 2013/07/09 08:30:52CEST Hecker, Robert (heckerr)
Get xml Interface working again.
--- Added comments ---  heckerr [Jul 9, 2013 8:30:52 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.3 2013/07/04 17:37:43CEST Hecker, Robert (heckerr)
Removed some pep8 violations.
Revision 1.2 2013/07/01 08:24:58CEST Hecker, Robert (heckerr)
Added HeadNodeName into DB;
Removed single commits to improve performance.
--- Added comments ---  heckerr [Jul 1, 2013 8:24:58 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/05/16 08:04:07CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/hpc/util/db/project.pj
"""
