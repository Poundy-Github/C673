"""
monitor_ipc.py
--------------

Class which provides a Server client Socket Communication for HPC
AppWatcher and AppMonitor Communication.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:09CET $
"""
# Import Python Modules -------------------------------------------------------
import win32pipe
import win32file
import pickle

# Defines ---------------------------------------------------------------------
MONITOR_PORT = 8089
MONITOR_PC = 'localhost'
MONITOR_TIMEOUT = 60.0


class MonitorServer(object):
    """
    Part of Communication System MonitorServer - MonitorClient.
    Can be used to create and communicate over an identic Communication Channel.
    The Monitor Server itselfs create the Communication and receives Data
    from the Monitor Client.

    :author:        Robert Hecker
    :date:          22.01.2013
    """

    def __init__(self, name):
        """
        Creates a Named Pipe for the Server - Client Communciation.

        :param name:  Name, which identify a unique communication channel
        :type  name:  string
        :return:      -
        """
        name = '\\\\.\\pipe\\' + name
        self.__hPipe = win32pipe.CreateNamedPipe(name,
                                                 win32pipe.PIPE_ACCESS_DUPLEX,
                                                 win32pipe.PIPE_TYPE_MESSAGE |
                                                 win32pipe.PIPE_READMODE_MESSAGE |
                                                 win32pipe.PIPE_WAIT,
                                                 win32pipe.PIPE_UNLIMITED_INSTANCES,
                                                 4048,
                                                 4048,
                                                 0,
                                                 None)

    def WaitForConnection(self):
        """
        Wait till a Client connects to the Named pipe, to be able afterwards to
        receive data.
        """
        win32pipe.ConnectNamedPipe(self.__hPipe, None)

    def Receive(self, timeout=MONITOR_TIMEOUT):
        """
        Method for receiving the data as an dictionary of monitored values
        from the Monitor Client.
        :param Timeout: sec. to wait, till timeout happens.
        :type  Timeout: int
        :return:        dict of monitored values if everything is ok
                        None, when connection was closed
                        "" (empty string) on timeout.
        :todo:          Decide, either to kick out timeout,
                        or to get it working
        """

        data = ""
        try:
            _hr, buf = win32file.ReadFile(self.__hPipe, 4048)
            data = pickle.loads(buf)
        except win32file.error:
            data = None

        return data


class MonitorClient(object):
    """
    Part of Communication System MonitorServer - MonitorClient.
    Can be used to connect to a Communication channel (Named Pipe)
    The Monitor Client itselfs connects to an existing pipe and send
    the Data towards the server.

    :author:        Robert Hecker
    :date:          22.01.2013
    """
    def __init__(self, name):
        name = '\\\\.\\pipe\\' + name
        self.__hPipe = win32file.CreateFile(name,  # pipe name
                                            win32file.GENERIC_READ |  # read and write access
                                            win32file.GENERIC_WRITE,
                                            0,
                                            None,
                                            win32file.OPEN_EXISTING,
                                            0,
                                            None)

    def Send(self, data):
        """
        Convert data from type dict to an string, and send the data towards
        the Server.

        :param data: data values to be send to the server.
        :type  data: dictionary
        :return:     -
        """
        buf = pickle.dumps(data)
        win32file.WriteFile(self.__hPipe, buf)

    def Close(self):
        """
        Close the Communication Pipe on Client side.
        :return:     -
        """
        if(self.__hPipe is not None):
            win32file.CloseHandle(self.__hPipe)
            self.__hPipe = None

"""
CHANGE LOG:
-----------
$Log: monitor_ipc.py  $
Revision 1.1 2021/12/13 17:57:09CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/app/project.pj
Revision 1.6 2013/09/11 15:10:56CEST Hecker, Robert (heckerr) 
removed pylint issues.
- Added comments -  heckerr [Sep 11, 2013 3:10:57 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.5 2013/03/01 09:07:38CET Hecker, Robert (heckerr) 
Updates regarding Pep8 Styleguide.
--- Added comments ---  heckerr [Mar 1, 2013 9:07:39 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/07 17:18:10CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:18:10 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/01/22 17:46:31CET Hecker, Robert (heckerr)
Modified IPC Communication from socket to pipe.
--- Added comments ---  heckerr [Jan 22, 2013 5:46:31 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/12 10:37:23CET Hecker, Robert (heckerr)
Updated Code regarding pep8.
--- Added comments ---  heckerr [Dec 12, 2012 10:37:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/10 16:37:58CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
