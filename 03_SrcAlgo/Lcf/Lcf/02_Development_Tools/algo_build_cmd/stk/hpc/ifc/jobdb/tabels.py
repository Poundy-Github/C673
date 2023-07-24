"""
stk.hpc.util.db.tabels
----------------------

Tabel definitions for hpc job creation abd storage in db file.

:org:           Continental AG
:author:        Robert Hecker

:creation date: 07.05.2013

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:25CET $
"""
# Import Python Modules -------------------------------------------------------
# table_def.py
from sqlalchemy import ForeignKey
from sqlalchemy import Column, Integer, String, Boolean
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship, backref

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------
Base = declarative_base()

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class Job(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as job table interface between Python and
    SQL for the HPC-Schema.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "job"

    id = Column(Integer, primary_key=True)
    name = Column(String)
    hpcbasefolder = Column(String)
    project = Column(String)
    headnode = Column(String)
    master_ora_db = Column(Boolean)

    def __init__(self, name, hpcbasefolder, project, headnode, master_ora_db):
        """
        Set the needed Values at initializatioon time

        :param name: JobName
        :type name:  string
        :param hpcbasefolder: root folder on \\LIFS010 for the Job
        :type hpcbasefolder:  string
        :param project: ProjectName (e.g SMFC4B0)
        :type project:  string
        :param headnode: Name of the HPC Head Node (full qualified)
        :type headnode:  string
        :param master_ora_db: Usage of Master Oracle DB (HPC-DB from S&C)
        :type master_ora_db:  boolean
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """

        self.name = name
        self.hpcbasefolder = hpcbasefolder
        self.master_ora_db = master_ora_db
        self.project = project
        self.headnode = headnode


class Task(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as task table interface between Python and
    SQL for the HPC-Schema.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "task"

    id = Column(Integer, primary_key=True)
    name = Column(String)

    def __init__(self, name):
        """
        Set the needed Values at initializatioon time

        :param name: TaskName
        :type name:  string
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """
        self.name = name


class SubTask(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as subtask table interface between Python and
    SQL for the HPC-Schema.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "subtask"

    id = Column(Integer, primary_key=True)
    name = Column(String)
    cmdline = Column(String)
    settings = Column(String)
    cmdlinemapping = Column(Integer)

    task_id = Column(Integer, ForeignKey("task.id"))
    task = relationship("Task", backref=backref("subtask", order_by=id))

    def __init__(self, name, cmdline, settings, cmdlinemapping):
        """
        Set the needed Values at initializatioon time

        :param name: SubTaskName
        :type name:  string
        :param cmdline: Commandlinestring
        :type cmdline:  string
        :param settings: settings
        :type settings:  string
        :param cmdlinemapping: Mapping between Task and SubTask
        :type cmdlinemapping:  Integer
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """
        self.name = name
        self.cmdline = cmdline
        self.settings = settings
        self.cmdlinemapping = cmdlinemapping


class SubTaskSettings(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as subtasksettings table interface between Python and
    SQL.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "subtasksettings"

    id = Column(Integer, primary_key=True)
    curworkdir = Column(String)
    environmentvars = Column(String)
    nodefolders = Column(String)
    appwatcher = Column(Boolean)
    globaldatafolder = Column(Boolean)

    def __init__(self, curworkdir, environmentvars, nodefolders, appwatcher, globaldatafolder):
        """
        Set the needed Values at initializatioon time

        :param curworkdir: Current Working Directory for the SubTask
        :type curworkdir:  string
        :param environmentvars: Needed Environment Varaibles for the SubTask.
        :type environmentvars:  string
        :param nodefolders: Additional Folders for the Subtask 
        :type nodefolders:  string
        :param appwatcher: Appwatcher usage for SubTask
        :type appwatcher:  boolean
        :param globaldatafolder: Usage of teh Global Data Folder
        :type globaldatafolder:  boolean
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """
        self.curworkdir = curworkdir
        self.environmentvars = environmentvars
        self.nodefolders = nodefolders
        self.appwatcher = appwatcher
        self.globaldatafolder = globaldatafolder


class SubTaskMapping(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as subtaskmapping table interface between Python and
    SQL.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "subtaskmapping"

    id = Column(Integer, primary_key=True)
    task_id = Column(Integer)
    subtask_id = Column(Integer)
    order = Column(Integer)

    def __init__(self, task_id, subtask_id, order):
        """
        Set the needed Values at initializatioon time

        :param task_id: Identifier for the Task
        :type task_id:  Integer
        :param subtask_id: Idetifier for the SubTask
        :type subtask_id:  Integer
        :param order: Counter, in which order the Subtask must be executet. 
        :type order:  Integer
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """
        self.task_id = task_id
        self.subtask_id = subtask_id
        self.order = order


class CMDLineVars(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as cmdlinevars table interface between Python and
    SQL. Here all commandline-variables are stored.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "cmdlinevars"

    id = Column(Integer, primary_key=True)
    key = Column(String)
    value = Column(String)

    def __init__(self, key, value):
        """
        Set the needed Values at initializatioon time

        :param key: Key for the Variable
        :type key:  string
        :param value: Value of the key
        :type value:  string
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """
        self.key = key
        self.value = value


class CMDLineMapping(Base):  # (Table Class for SQLAlchmy) pylint: disable=R0903
    """
    This class interacts as cmdlinemapping table interface between Python and
    SQL. Mapping between CommandLine Variable and SubTask.

    :author:        Robert Hecker
    :date:          09.08.2013
    """
    __tablename__ = "cmdlinemapping"

    id = Column(Integer, primary_key=True)
    mapping_id = Column(Integer)
    cmdvar_id = Column(Integer)

    def __init__(self, mapping_id, cmdvar_id):
        """
        Set the needed Values at initializatioon time

        :param mapping_id: Identifier for the Mapping
        :type mapping_id:  integer
        :param cmdvar_id: Indentifier for the CMDLine Variable
        :type cmdvar_id:  integer
        :return:        -
        
        :author:        Robert Hecker
        :date:          09.08.2013
        """
        self.mapping_id = mapping_id
        self.cmdvar_id = cmdvar_id

"""
CHANGE LOG:
-----------
$Log: tabels.py  $
Revision 1.1 2021/12/13 17:57:25CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/jobdb/project.pj
Revision 1.7 2013/09/18 11:21:59CEST Hecker, Robert (heckerr) 
Removed pylint messages.
- Added comments -  heckerr [Sep 18, 2013 11:21:59 AM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.6 2013/09/11 13:59:24CEST Hecker, Robert (heckerr) 
- Added Docu.
- Removed some pylint Issues.
--- Added comments ---  heckerr [Sep 11, 2013 1:59:24 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.5 2013/08/09 10:13:46CEST Hecker, Robert (heckerr) 
Added author information.
--- Added comments ---  heckerr [Aug 9, 2013 10:13:47 AM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.4 2013/08/09 09:49:52CEST Hecker, Robert (heckerr) 
Updated Dokumentation of the HPC Table interface.
--- Added comments ---  heckerr [Aug 9, 2013 9:49:52 AM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.3 2013/07/04 17:34:53CEST Hecker, Robert (heckerr) 
Removed some pep8 violations.
--- Added comments ---  heckerr [Jul 4, 2013 5:34:53 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.2 2013/07/01 08:24:06CEST Hecker, Robert (heckerr)
Added HeadNode Name into DB.
--- Added comments ---  heckerr [Jul 1, 2013 8:24:06 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/05/16 08:04:08CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit
/04_Engineering/stk/hpc/util/db/project.pj
"""
