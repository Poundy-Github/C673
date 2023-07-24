"""
stk/hpc/ifc/masterdb/error_db
-----------------------------


Interface into the Error Database of HPC.

:org:           Continental AG
:author:        Robert Hecker

:creation date: 10.12.2013

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:36CET $
"""
# Import Python Modules -------------------------------------------------------
from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String
from sqlalchemy import Sequence
from sqlalchemy.orm import sessionmaker
from sqlalchemy import ForeignKey
from sqlalchemy.orm import relationship, backref

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------
Base = declarative_base()

# Classes ---------------------------------------------------------------------

class ErrorType(Base):
    """
    Class Model of the SQL-Table "APP_ERRORTYPES".

    :author:        Robert Hecker
    :date:          11.12.2013
    """
    __tablename__ = 'APP_ERRORTYPES'
    __table_args__ = {'schema' : 'HPC_ADMIN'}
    id = Column('ID', Integer, Sequence('SEQ_APP_ERRORTYPES_ID', schema='HPC_ADMIN'), nullable=False, primary_key=True)
    desc = Column('DESC', String(128))

    def __init__(self, desc):

        self.desc = desc


class Error(Base):
    """
    Class Model of the SQL-Table "APP_ERRORS".

    :author:        Robert Hecker
    :date:          11.12.2013
    """
    __tablename__ = 'APP_ERRORS'
    __table_args__ = {'schema' : 'HPC_ADMIN'}
    id = Column('ID', Integer, Sequence('SEQ_APP_ERRORS_ID', schema='HPC_ADMIN'), nullable=False, primary_key=True)
    #id = Column('ID', Integer, Sequence('id_seq'), primary_key=True)
    jobId = Column('JOBID', Integer, nullable=False)
    taskId = Column('TASKID', Integer, nullable=False)
    type_id = Column('TYPE_ID', Integer, ForeignKey('HPC_ADMIN.APP_ERRORTYPES.ID', schema='HPC_ADMIN'), nullable=False)
    code = Column('CODE', Integer)
    desc = Column('DESC', String(512))
    src = Column('SRC', String(512))

    type = relationship("ErrorType", backref=backref('HPC_ADMIN.APP_ERRORS', order_by=id))

    def __init__(self):
        pass


class HpcErrorDB(object):
    """
    Hpc Error DB Interface

    This Class provides a interface towards the Error-DB from HPC.
    All Errors which are found in the Subtask xxx_check will be stored here.

    :author:        Robert Hecker
    :date:          11.12.2013
    """
    ERR_TYPES = ['Crash', 'Exception', 'Error']

    def __init__(self):

        self.__engine = None
        self.__metadata = None
        self.__session = None

    def Open(self, url="sqlite://", echo=False):
        """
        This Method connects to a Database with the given url.
        The url contains typically the Connection String to the
        Database.

        The string form of the URL is
        ``dialect+driver://user:password@host/dbname[?key=value..]``, where
        ``dialect`` is a database name such as ``mysql``, ``oracle``,
        ``postgresql``, etc., and ``driver`` the name of a DBAPI, such as
        ``psycopg2``, ``pyodbc``, ``cx_oracle``, etc.  Alternatively,

        Typical url's which can be used:
        ``sqlite:///error.db`` - sqlite-db in current working dir.
        ``sqlite:///c:/error.db`` - sqlite-db with absolute path.
        ``sqlite://`` - sqlite db in memory
        ``oracle://hpc_user:Baba1234@racadmpe`` - oracle connection

        :param url:     connection string url for the db.
        :type url:      string
        :param echo:    Enable/Disable Debug Echo output on stdout.
        :type echo:     boolean
        :return:        -
        """
        self.__engine = create_engine(url, echo=echo, case_sensitive=False)

        self.__metadata = Base.metadata

        session = sessionmaker(bind=self.__engine)

        self.__session = session()

    def Close(self):
        """
        Disconnect from the Database.

        :return:        -
        """
        pass

    def CreateTables(self):
        """
        This Method Create the Tables, if wanted on a new Database,
        And initialise a Table with the necessary Data.
        To grant the user 'hpc_user' the necessary rights to use the ErrorDB
        do following step manually:
            - grant select on hpc_admin.seq_app_errors_id to hpc_user;
            - grant select on hpc_admin.seq_app_errortypes_id to hpc_user;
            - grant select rights on table
            - grant insert rights on table.

        :return:        -
        """
        # Create the Tables
        self.__metadata.create_all(self.__engine)

        self.__session.commit()

        # Initialise the Table with Default values
        self.__InitErrorTypes()

    def DeleteTables(self):
        """
        This Method delete all tables inside the Database.

        :return:        -
        """
        self.__session.commit()
        self.__metadata.drop_all(self.__engine)

    def __InitErrorTypes(self):
        """
        Initialise the ErrorType Table with the needed default data.
        """
       # Create possible Error Entries
        for i in self.ERR_TYPES:
            res = self.__session.query(ErrorType).filter(ErrorType.desc == i).first()
            if(res == None):
                err = ErrorType(i)
                self.__session.add(err)
                self.__session.commit()

    def AddCrash(self, jobId, taskId, errCode, errDesc, errSrc):
        """
        Add a new Chrash entry into the Database.

        :param jobId:     HPC Job ID (unique)
        :type jobId:      integer
        :param taskId:    Hpc Task ID
        :type taskId:     integer
        :param errCode:   Error Code of the Error
        :type errCode:    integer
        :param errDesc:   Error Description of the Error
        :type errDesc:    string
        :param errSrc:    Additional Error Source Inforamtion
        :type errSrc:     string
        :return:          -
        """
        err = Error()
        err.jobId = jobId
        err.type_id = self.__session.query(ErrorType.id).filter(ErrorType.desc == "Crash").first()[0]
        err.taskId = taskId
        err.code = errCode
        err.desc = errDesc
        err.src = errSrc

        self.__session.add(err)
        self.__session.commit()

    def AddError(self, jobId, taskId, errCode, errDesc, errSrc):
        """
        Add a new Error entry into the Database.

        :param jobId:     HPC Job ID (unique)
        :type jobId:      integer
        :param taskId:    Hpc Task ID
        :type taskId:     integer
        :param errCode:   Error Code of the Error
        :type errCode:    integer
        :param errDesc:   Error Description of the Error
        :type errDesc:    string
        :param errSrc:    Additional Error Source Inforamtion
        :type errSrc:     string
        :return:          -
        """
        err = Error()
        err.jobId = jobId
        err.type_id = self.__session.query(ErrorType.id).filter(ErrorType.desc == "Error").first()[0]
        err.taskId = taskId
        err.code = errCode
        err.desc = errDesc
        err.src = errSrc

        self.__session.add(err)
        self.__session.commit()

    def AddException(self, jobId, taskId, errCode, errDesc, errSrc):
        """
        Add a new Exception entry into the Database.

        :param jobId:     HPC Job ID (unique)
        :type jobId:      integer
        :param taskId:    Hpc Task ID
        :type taskId:     integer
        :param errCode:   Error Code of the Error
        :type errCode:    integer
        :param errDesc:   Error Description of the Error
        :type errDesc:    string
        :param errSrc:    Additional Error Source Inforamtion
        :type errSrc:     string
        :return:          -
        """
        err = Error()
        err.jobId = jobId
        err.type_id = self.__session.query(ErrorType.id).filter(ErrorType.desc == "Exception").first()[0]
        err.taskId = taskId
        err.code = errCode
        err.desc = errDesc
        err.src = errSrc

        self.__session.add(err)
        self.__session.commit()

    def GetNumCrashs(self, jobId):
        """
        Get Number of Crashes, filtered by JobId.

        :param jobId:     HPC Job ID (unique)
        :type jobId:      integer
        :return:          Number of crashes
        :rtype:           integer
        """
        res = self.__session.query(Error).first()

        print res.type_id
        print res.type.desc

        res = self.__session.query(Error).filter(Error.jobId == jobId).\
                             join(ErrorType).filter(ErrorType.desc == 'Crash').\
                             all()

        return len(res)

    def GetNumErrors(self, jobId):
        """
        Get Number of Errors, filtered by JobId.

        :param jobId:     HPC Job ID (unique)
        :type jobId:      integer
        :return:          Number of crashes
        :rtype:           integer
        """
        res = self.__session.query(Error).filter(Error.jobId == jobId).\
                             join(ErrorType).filter(ErrorType.desc == 'Error').\
                             all()

        return len(res)

    def GetNumExceptions(self, jobId):
        """
        Get Number of Exceptions, filtered by JobId.

        :param jobId:     HPC Job ID (unique)
        :type jobId:      integer
        :return:          Number of crashes
        :rtype:           integer
        """
        res = self.__session.query(Error).filter(Error.jobId == jobId).\
                             join(ErrorType).filter(ErrorType.desc == 'Exception').\
                             all()

        return len(res)

"""
CHANGE LOG:
-----------
$Log: error_db.py  $
Revision 1.1 2021/12/13 17:57:36CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/masterdb/project.pj
Revision 1.2 2013/12/15 14:38:25CET Hecker, Robert (heckerr) 
Added Oracle schema information.
- Added comments -  heckerr [Dec 15, 2013 2:38:25 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.1 2013/12/12 09:32:24CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/ifc/masterdb/project.pj
"""
