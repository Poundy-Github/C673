"""
logger
------

Logger class for logging messages to the console and/or file

**User-API Interfaces**

    - `utils` (complete package)
    - `Logger` (this module)

Other defined classes for internal usage, interface changes are possible without warning.

:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:39CET $
"""
#======================================================================================================================
# Imports
#======================================================================================================================
from sys import stdout, stderr, _getframe
import logging

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

#======================================================================================================================
# Global Definitions
#======================================================================================================================
DEBUG = logging.DEBUG
INFO = logging.INFO
WARNING = logging.WARNING
ERROR = logging.ERROR
CRITICAL = logging.CRITICAL
EXCEPTION = CRITICAL + 10

LEVEL_INFO_MAP = {DEBUG: "DEBUG", INFO: "INFO", WARNING: "WARNING",
                  ERROR: "ERROR", CRITICAL: "CRITICAL", EXCEPTION: "EXCEPTION"}
#======================================================================================================================
# Classes
#======================================================================================================================


class LoggerException(StandardError):
    """
    Database errors
    """
    def __init__(self, description):
        self.__description = str(description)

    def __str__(self):
        return str(self.__description)


class Singleton(object):
    """
    Singleton interface,
    ensuring that only one instance of the logger is instantiated.
    """
    def __new__(cls, *args, **kwargs):
        it = cls.__dict__.get("__it__")
        if it is not None:
            return it
        cls.__it__ = it = object.__new__(cls)
        it.initialize(*args, **kwargs)

        return it

    def initialize(self, *args, **kwargs):
        pass


class LoggerManager(Singleton):
    """
    Logger Manager class implementation
    """
    def initialize(self, level=DEBUG, filename=None, strm=None):
        self.__logger = logging.getLogger()
        self.__statistics = {}
        self._lastmsg = None

        if strm not in [None, stdout, stderr]:
            strm = None

        console_handler = logging.StreamHandler(strm)
        self.__logger.setLevel(level)

        if filename is not None:
            file_handler = None
            try:
                file_handler = logging.FileHandler(filename, "w")
            except:
                tmp = "Couldn't create/open file "
                tmp += "'%s'. Please check permisions." % (filename)
                raise LoggerException(tmp)

            tmp1 = "%(asctime)s %(name)-15s - %(levelname)s %(message)s"
            tmp2 = "%d.%m.%Y %H:%M:%S"
            formatter = logging.Formatter(tmp1, tmp2)
            file_handler.setFormatter(formatter)
            file_handler.setLevel(DEBUG)
            self.__logger.addHandler(file_handler)

        console_handler.setLevel(level)
        tmp1 = "%(asctime)s %(name)s - %(levelname)s %(message)s"
        tmp2 = "%d.%m.%Y %H:%M:%S"
        formatter = logging.Formatter(tmp1, tmp2)
        console_handler.setFormatter(formatter)
        self.__logger.addHandler(console_handler)

    def __update_statistics(self, logging_level):
        """Update logging statisics"""
        try:
            self.__statistics[logging_level] += 1
        except:
            self.__statistics[logging_level] = 1

    def get_statistics(self):
        """Gets number of each type of logging message"""
        return self.__statistics

    def get_lastmsg(self):
        """return the last message posted"""
        return self._lastmsg

    def debug(self, logger_name, msg):
        """Displays debug messages"""
        self._lastmsg = msg
        self.__logger = logging.getLogger(logger_name)
        self.__logger.debug(msg)

        self.__update_statistics(LEVEL_INFO_MAP[DEBUG])

    def error(self, logger_name, msg):
        """Displays error messages"""
        self._lastmsg = msg
        self.__logger = logging.getLogger(logger_name)
        self.__logger.error(msg)

        self.__update_statistics(LEVEL_INFO_MAP[ERROR])

    def info(self, logger_name, msg):
        """Displays info messages"""
        self._lastmsg = msg
        self.__logger = logging.getLogger(logger_name)
        self.__logger.info(msg)

        self.__update_statistics(LEVEL_INFO_MAP[INFO])

    def warning(self, logger_name, msg):
        """Displays warning messages"""
        self._lastmsg = msg
        self.__logger = logging.getLogger(logger_name)
        self.__logger.warning(msg)

        self.__update_statistics(LEVEL_INFO_MAP[WARNING])

    def exception(self, logger_name, msg):
        """Displays exception messages"""
        self._lastmsg = msg
        self.__logger = logging.getLogger(logger_name)
        self.__logger.exception(msg)

        self.__update_statistics(LEVEL_INFO_MAP[EXCEPTION])

    def critical(self, logger_name, msg):
        """Displays critical messages"""
        self._lastmsg = msg
        self.__logger = logging.getLogger(logger_name)
        self.__logger.critical(msg)

        self.__update_statistics(LEVEL_INFO_MAP[CRITICAL])


class Logger():
    """
    A logging mechanism for handling runtime information of different modules

    usage
    -----
    .. python::

        # logging to file + console
        main_logger = logger.Logger("my_main_logger",
                                    level=logger.DEBUG,
                                    filename="my_logging_file.log")

        # logging to console
        main_logger = logger.Logger("my_main_logger",
                                    level=logger.DEBUG)

        #where:
        #  logger_name: is the name of the logger
        #  level:       is the logging level [10=DEBUG, 20=INFO,
        #                                     30=WARNING, 40=ERROR,
        #                                     50=CRITICAL]
        #  filename:    None : only console,  FilePath: Log file

        # displays message as debug
        main_logger.debug(" This is a debug message")
        # displays message as info
        main_logger.info(" This is an info message")
        # displays message as warning
        main_logger.warning(" This is a warning")
        # displays message as error
        main_logger.error(" This is an error message")
        # displays message as critical
        main_logger.critical(" This is a critical message")
        # displays message as exception
        # -> to be called from an exception handler
        main_logger.exception(" This is an exception message")


        # created from another script
        logger2 = logger.Logger("my_logger2")
        # displays message as info
        logger2.info(" This is an info message")
        #...

    :author:  Sorin Mogos
    """
    def __init__(self, logger_name, level=DEBUG, filename=None, strm=None):
        """Constructor"""
        self.__logging_level = level
        self.__logger_manager = LoggerManager(self.__logging_level, filename, strm)
        self.__loggername = logger_name

    def get_logging_level(self):
        """Gets the logging level"""
        return self.__logging_level

    def get_statistics(self):
        """Gets number of each type of logging message"""
        return self.__logger_manager.get_statistics()

    @property
    def lastmsg(self):
        """returns the last logging message text"""
        return self.__logger_manager.get_lastmsg()

    def debug(self, msg=None):
        """Displays debug messages"""
        self.__logger_manager.debug(self.__loggername,
                                    (_getframe(1).f_code.co_name + "() called.") if msg is None else msg)

    def error(self, msg):
        """Displays error messages"""
        self.__logger_manager.error(self.__loggername, msg)

    def info(self, msg):
        """Displays info messages"""
        self.__logger_manager.info(self.__loggername, msg)

    def warning(self, msg):
        """Displays warning messages"""
        self.__logger_manager.warning(self.__loggername, msg)

    def exception(self, msg):
        """Displays exception messages"""
        self.__logger_manager.exception(self.__loggername, msg)

    def critical(self, msg):
        """Displays critical messages"""
        self.__logger_manager.critical(self.__loggername, msg)

"""
CHANGE LOG:
-----------
$Log: logger.py  $
Revision 1.1 2021/12/13 17:59:39CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.11 2013/09/10 16:10:02CEST Hospes, Gerd-Joachim (uidv8815) 
add lastmsg method, fix pep8/pylint errors, update docu
- Added comments -  uidv8815 [Sep 10, 2013 4:10:03 PM CEST]
Change Package : 190320:1 http://mks-psad:7002/im/viewissue?selection=190320
Revision 1.10 2013/05/23 06:33:19CEST Mertens, Sven (uidv7805)
to ease function call debug output, empty msg can be used
--- Added comments ---  uidv7805 [May 23, 2013 6:33:20 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.9 2013/04/19 12:51:07CEST Hecker, Robert (heckerr)
Functionality revert to version 1.7.
--- Added comments ---  heckerr [Apr 19, 2013 12:51:07 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/04/12 14:38:29CEST Mertens, Sven (uidv7805)
empty debug message is replace by function call () output
--- Added comments ---  uidv7805 [Apr 12, 2013 2:38:30 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.7 2013/03/28 15:25:16CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:17 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/28 14:20:07CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
Revision 1.5 2013/02/27 17:55:08CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:09 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/14 16:22:46CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:46 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/05 13:49:47CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 11:56:24CET Hecker, Robert (heckerr)
Update regarding pep8.
--- Added comments ---  heckerr [Dec 5, 2012 11:56:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 18:01:46CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/util/project.pj
"""
