"""
cxoracle_ifc
-------------

Connect to Oracle Database with Python cx_Oracle package

:org:           science-computing ag
:author:        Jimmy Selatsa

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:35CET $
"""
# Import Python Modules -------------------------------------------------------
import cx_Oracle as ora

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# Defines ---------------------------------------------------------------------
CONNECTIONSTRING = 'hpc_user/Baba1234@racadmpe'


class ICXOracle(object):
    """
    Class which works as Interface between hpc (python)
    and the HPC Oracle sheme on the oracle database.

    :author:        Robert Hecker
    :date:          12.09.2013
    """
    def __init__(self, connection_string=CONNECTIONSTRING):

        self._connection_string = connection_string
        self._con = self.connect(self._connection_string)

    def connect(self, connection_string=CONNECTIONSTRING):
        """
        Connect to the given Oracle DB over cxOracle with the
        given connectionstring.

        :param connection_string:   Oracle DB connectionstring.
        :type  connection_string:   string
        :return:                    connect object
        :rtype:                     object of type (connection)
        """
        self._con = ora.Connection(connection_string)
        self._cur = self._con.cursor()
        return self._con

    def disconnect(self):
        """
        Disconnect the current connection to the oracle db.

        :return:        -
        """
        if self._cur is not None:
            self._cur.close()
            self._cur = None

        if self._con is not None:
            self._con.close()
            self._con = None

    def submitJob(self, xmljobstatus):
        """
        Insert a whole XMLJobStatus file into the oracle db.

        :param xmljobstatus:   xmlstring with complete jobdescription
        :type xmljobstatus:    string

        :return:        result of the called db procedure
        :rtype:         ???

        :todo:          update docu.
        """
        param = self._cur.var(ora.CLOB, 32000)
        param.setvalue(0, xmljobstatus)

        # Submit new Job into Oracle DB
        result = self._cur.callfunc('hpc_admin.jobcontrol.insertJob',
                                    ora.NUMBER,
                                    (param,))

        # Commit changes
        self._con.commit()

        return result

    def setTaskState(self, jobname, taskname, taskstatus):
        """
        Set the current State of the current task inside the
        hpc db new.

        :param jobname:    Name of the job.
        :type jobname:     string
        :param taskname:   Name of the task.
        :type taskname:    string
        :param taskstatus: Status of the Task. See also `TaskState`
        :type taskstatus:  integer

        :return:        result of the called db procedure
        :rtype:         ???

        :todo:          update docu.
        """
        result = int(self._cur.callfunc('hpc_admin.jobcontrol.setTaskState',
                                        ora.NUMBER,
                                        (taskname, jobname, taskstatus)))

        self._con.commit()

        return result

    def updateTask(self, xmltaskreport):
        """
        Send a new taskreport towards the hpc oracle db.

        :param xmltaskreport:    xml string with a whole taskreport inside.
        :type xmltaskreport:     string

        :return:        result of the called db procedure
        :rtype:         ???

        :todo:          update docu.
        """
        # DBMS_LOB.CREATETEMPORARY( dest_clob, true );
        param = self._cur.var(ora.CLOB)
        param.setvalue(0, xmltaskreport)

        # Send XML Report to Oracle DB
        result = int(self._cur.callfunc('hpc_admin.jobcontrol.updateTask',
                                        ora.NUMBER,
                                        (param,)))

        # Commit Changes
        self._con.commit()

        return result

"""
CHANGE LOG:
-----------
$Log: cxoracle_ifc.py  $
Revision 1.1 2021/12/13 17:57:35CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/masterdb/project.pj
Revision 1.12 2013/09/12 17:49:04CEST Hecker, Robert (heckerr) 
Updated docu.
- Added comments -  heckerr [Sep 12, 2013 5:49:04 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.11 2013/04/29 17:00:06CEST Hecker, Robert (heckerr)
Some needed changes in the interface.
--- Added comments ---  heckerr [Apr 29, 2013 5:00:07 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.10 2013/04/26 15:27:26CEST Hecker, Robert (heckerr)
BugFix in Parameter usage for callfunc.
--- Added comments ---  heckerr [Apr 26, 2013 3:27:27 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/04/19 11:57:58CEST Hecker, Robert (heckerr)
Added comments to interface file.
--- Added comments ---  heckerr [Apr 19, 2013 11:57:58 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/03/01 09:06:04CET Hecker, Robert (heckerr)
Some Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 9:06:04 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/07 17:17:16CET Hecker, Robert (heckerr)
Removed unecessary code.
--- Added comments ---  heckerr [Feb 7, 2013 5:17:16 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/01/16 13:28:19CET Hecker, Robert (heckerr)
Removed unused Code.
--- Added comments ---  heckerr [Jan 16, 2013 1:28:19 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/12 10:37:24CET Hecker, Robert (heckerr)
Updated Code regarding pep8.
--- Added comments ---  heckerr [Dec 12, 2012 10:37:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/10 16:41:52CET Hecker, Robert (heckerr)
Added some Methods.
--- Added comments ---  heckerr [Dec 10, 2012 4:41:55 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/10 09:06:58CET Hecker, Robert (heckerr)
Added correct ConnectionString to use.
--- Added comments ---  heckerr [Dec 10, 2012 9:06:59 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:52CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:52 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:49:36CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
