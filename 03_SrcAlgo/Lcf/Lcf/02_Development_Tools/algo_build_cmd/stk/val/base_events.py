"""
Observer Template
---------------------

Add Description here

:org:           Continental AG
:author:        Guenther Raedler
@author:         uidt9430

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:44CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from UserList import UserList
from copy import copy
from datetime import datetime
from inspect import currentframe
from os import path, environ
import warnings


# Import STK Modules --------------------------------------------------------------------------------------------------
from stk.db.db_common import AdasDBError, SQLite3BaseDB
from stk.db.gbl.gbl import BaseGblDB, COL_NAME_USER_ID, COL_NAME_WORKFLOW_WFID, COL_NAME_ASSESSMENT_STATE_NAME
from stk.db.val.val import BaseValResDB, COL_NAME_ASS_USER_ID, COL_NAME_ASS_WFID, COL_NAME_ASS_ASSSTID, \
    COL_NAME_ASS_COMMENT, COL_NAME_ASS_DATE, COL_NAME_TR_TYPE_ID, COL_NAME_EVENTTYPE_NAME, COL_NAME_EVENTS_TRID, \
    COL_NAME_EVENTTYPE_CLASSNAME, COL_NAME_EVENTTYPE_DESC, COL_NAME_EVENTS_VIEW_ASSESSMENT, COL_NAME_EVENTS_MEASID, \
    COL_NAME_EVENTS_BEGINABSTS, COL_NAME_EVENTS_ENDABSTS, COL_NAME_EVENTS_START_IDX, COL_NAME_EVENTS_STOP_IDX, \
    COL_NAME_EVENTS_EVENTTYPEID, COL_NAME_EVENTS_RESASSID, COL_NAME_EVENT_ATTR_EDID, COL_NAME_EVENT_ATTR_VALUE, \
    COL_NAME_EVENT_ATTR_ATTRTYPEID, COL_NAME_EVENT_IMG_ATTRID, COL_NAME_EVENT_IMG_FORMAT, COL_NAME_EVENT_IMG_TITLE, \
    COL_NAME_EVENT_IMG_IMAGE, COL_NAME_EVENT_ATTR_TYPES_NAME, COL_NAME_EVENT_ATTR_TYPES_UNITID, \
    COL_NAME_EVENT_ATTR_TYPES_DESC, COL_NAME_EVENTS_SEID, COL_NAME_EVENTS_VIEW_CLASSNAME, COL_NAME_ASS_ID, \
    COL_NAME_EVENTS_VIEW_BEGINABSTS, COL_NAME_EVENTS_VIEW_START_IDX, COL_NAME_EVENTS_VIEW_ENDABSTS, \
    COL_NAME_EVENTS_VIEW_STOP_IDX, COL_NAME_EVENTS_VIEW_SEID, COL_NAME_EVENTS_VIEW_COMMENT, COL_NAME_EVENT_DET_ABSTS, \
    COL_NAME_RESDESC_NAME, COL_NAME_RESDESC_COLLID, COL_NAME_RESDESC_RESTYPE_ID, \
    COL_NAME_RESDESC_UNIT_ID, COL_NAME_RESDESC_PARENT, COL_NAME_RESDESC_REFTAG, \
    COL_NAME_RESULTTYPE_NAME, COL_NAME_RESULTTYPE_DESC, COL_NAME_RESULTTYPE_CLASS, \
    COL_NAME_EVENTS_RDID

from stk.db.cat.cat import BaseRecCatalogDB
from stk.db.obj.objdata import BaseObjDataDB
from stk.db.lbl.genlabel import BaseGenLabelDB
from stk.util.helper import ListFolders
from stk.util.logger import Logger
from stk.valf import PluginManager
import stk.db.gbl.gbl as db_gbl
import stk.db.val.val as db_val
from result_types import ValSaveLoadLevel, BaseUnit
from asmt import ValAssessment, ValAssessmentWorkFlows, ValAssessmentStates

# Defines -------------------------------------------------------------------------------------------------------------
HEAD_DIR = path.abspath(path.join(path.dirname(currentframe().f_code.co_filename), ".."))

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------

PLUGIN_FOLDER_LIST = []
for folder_path in ListFolders(HEAD_DIR):
    PLUGIN_FOLDER_LIST.append(folder_path)


#======================================================================================================================
# Exceptions
#======================================================================================================================
class ValEventError(StandardError):
    """Base of all Event errors"""
    pass


class ValEventNotImplemented(ValEventError):
    """Feature is not implemented"""
    def __init__(self):
        warnings.warn('Class ValEventNotImplemented is deprecated', stacklevel=2)


class ValBaseEventAttributes(object):
    '''
    Base Class for the validation attributes
    '''
    def __init__(self, value=0, unit='', valueType='float', image=None):
        '''
        Constructor
        '''
        self.__value = value
        self.__unit = unit
        self.__valueType = valueType
        self.__image = image

    def __del__(self):
        '''
        Destructor
        '''
        # print 'Event destroyed'
        self.__value = 0
        self.__unit = ''
        self.__valueType = ''

    def __copy__(self):
        cp = ValBaseEventAttributes(self.GetValue(), self.GetUnit(), self.GetType(), self.GetImage())

        return cp

    def SetValue(self, value, valueType=None):
        """ Set the value and value type
        """
        if valueType is not None:
            self.__valueType = valueType
        self.__value = value

    def SetImage(self, image):
        """ Set  the image
        """
        self.__image = image

    def GetValue(self):
        """ Returns the value
        """
        return self.__value

    def GetUnit(self):
        """ Returns the unit
        """
        return self.__unit

    def GetType(self):
        """ Returns the value type
        """
        return self.__valueType

    def GetImage(self):
        """ Returns the image
        """
        return self.__image

    def __str__(self):
        me = "value : %f, Unit %s, ValueType %s" % (self.__value, self.__unit, self.__valueType)
        return me


class ValBaseEventDetails(object):
    '''
    Base Class for the validation event details
    '''
    def __init__(self, rel_timestamp= -1):
        '''
        Constructor taking the rel_timestamp
        @param rel_timestamp: relative timestamp
        '''
        self.__timestamp = rel_timestamp
        self.__attributes = {}

    def __del__(self):
        '''
        Destructor
        '''
        # print 'Event destroyed'
        self.__timestamp = 0
        del self.__attributes

    def __copy__(self):
        cp = ValBaseEventDetails(self.GetTimestamp())

        cp.__attributes = copy(self.__attributes)

        return cp

    def GetTimestamp(self):
        """ Return relative timestamp """
        return self.__timestamp

    def AddAttribute(self, attribute_name, value=0, unit='', valueType='float', image=None):
        """ Add a Attribute to the event detail """
        if image is not None:
            if not isinstance(image, buffer):
                raise Exception("Image for Attribute %s at timestamp %s is not a buffer." %
                                (attribute_name, str(self.__timestamp)))

        if self.__timestamp == -1:
            self.__AddAttribute(attribute_name, value, unit, valueType, image)
        else:
            if attribute_name not in self.__attributes:
                self.__AddAttribute(attribute_name, value, unit, valueType, image)
            else:
                raise Exception("Attribute %s for timestamp %s already exist." %
                                (attribute_name, str(self.__timestamp)))

    def __AddAttribute(self, attribute_name, value, unit, valueType, image):
        """ Add a Attribute to the event detail """
        attribute = ValBaseEventAttributes(value=value, unit=unit, valueType=valueType, image=image)
        self.__attributes.setdefault(attribute_name.lower(), []).append(attribute)

    def UpdateAttribute(self, attribute_name, value):
        """ Update the Attribute of the event detail """
        name = attribute_name.lower()
        if attribute_name in self.__attributes:
            self.__attributes[name][0].SetValue(value)
        else:
            raise Exception("Attribute " + attribute_name + " does not exist")

    def GetAttributeNames(self):
        """ Return names of all the attributes """
        return self.__attributes.keys()

    def GetAttribute(self, name):
        """ Return attribute objekt """
        name = name.lower()
        if name in self.__attributes:
            return self.__attributes[name]
        else:
            raise Exception("Attribute " + name + " does not exist")

    def GetAttributeValue(self, name):
        """ Return attribute value """
        name = name.lower()
        if name in self.__attributes:
            return self.__attributes[name][0].GetValue()
        else:
            raise Exception("Attribute " + name + " does not exist")

    def GetAttributeValues(self, name):
        """ Return attribute values """
        name = name.lower()
        if name in self.__attributes:
            values = []
            for attribute in self.__attributes[name]:
                values.append(attribute.GetValue())
            return values
        else:
            raise Exception("Attribute does not exist")

    def GetAttributeImage(self, name):
        name = name.lower()
        if name in self.__attributes:
            return self.__attributes[name][0].GetImage()
        else:
            return None

    def GetAttributeType(self, name):
        """ Return attribute type """
        name = name.lower()
        if name in self.__attributes:
            return self.__attributes[name][0].GetType()
        else:
            raise Exception("Attribute " + name + " does not exist")

    def GetAttributeUnit(self, name):
        """ Return attribute unit """
        name = name.lower()
        if name in self.__attributes:
            return self.__attributes[name][0].GetUnit()
        else:
            raise Exception("Attribute " + name + " does not exist")

    def DeleteAttribute(self, name):
        """ Delete  attribute values """
        name = name.lower()
        if name in self.__attributes:
            self.__attributes.pop(name)
        else:
            raise Exception("Attribute " + name + " does not exist")

    def __str__(self):
        me = ("Timestamp : %d\n" % self.__timestamp)
        for items in self.__attributes:
            for idx in xrange(len(self.__attributes[items])):
                me += ("%s : %s\n" % (items, self.__attributes[items][idx].GetValue()))
        return me


class ValBaseEventDetailsContainer(UserList):
    '''
    Base Class of the validation event details container
    '''
    def __init__(self, timestamps=None):
        '''
        Constructor taking the timestamps
        @param timestamps: absolute timestamps
        '''
        UserList.__init__(self)
        self.__logger = Logger(self.__class__.__name__)

        self.__event_details_map = {}

        self.SetTimestamps(timestamps)

    def __del__(self):
        '''
        Destructor
        '''
        del self.__event_details_map

    def __copy__(self):
        cp = ValBaseEventDetailsContainer(self.GetTimeStamps())

        cp.__event_details_map = copy(self.__event_details_map)
        cp.data = copy(self.data)

        return cp

    def GetTimeStamps(self):
        """ Returns the array of timestamps of the Event
        """
        if len(self.data) > 0:
            return sorted(self.__event_details_map.keys())

    def SetTimestamps(self, timestamps):
        # if the timestamps are valid create event details for all the timestamps
        if timestamps is not None:
            for timestamp in timestamps:
                if timestamp not in self.__event_details_map:
                    event_details = ValBaseEventDetails(timestamp)
                    self.data.append(event_details)
                    self.__event_details_map[timestamp] = self.data.index(event_details)

    def AddTimingAttribute(self, attribute_name, value=[], unit='', valueType='float', image=None):
        """ Add a Attribute to all event details """
        length = len(value)
        for item in self.data:
            if length > 0:
                try:
                    index = self.data.index(item)
                    item.AddAttribute(attribute_name, value=value[index], unit=unit, valueType=valueType, image=image)
                except Exception, ex:
                    self.__logger.error(str(ex))
            else:
                # add default attribute
                item.AddAttribute(attribute_name)

    def UpdateTimingAttribute(self, attribute_name, value):
        """ Update all Attribute of the event details """
        if len(value) == len(self.data):
            try:
                for item in self.data:
                    index = self.data.index(item)
                    item.UpdateAttribute(attribute_name, value=value[index])
            except Exception, ex:
                self.__logger.error(str(ex))
        else:
            self.__logger.error("Input vector has different size, input: %d != int %d" % (len(self.data, len(value))))

    def GetTimingAttributeNames(self):
        """ Return names of all the attributes """
        if len(self.data) > 0:
            return self.data[0].GetAttributeNames()
        else:
            return {}

    def GetTimingAttribute(self, name):
        """ Return all attribute objekts with name """
        attributes = []
        for item in self.data:
            attributes.append(item.GetAttribute(name))
        return attributes

    def GetTimingAttributeValues(self, name):
        """ Return attribute values """
        values = []
        try:
            for item in self.data:
                values.append(item.GetAttributeValue(name))
        except Exception, ex:
            self.__logger.info(ex)

        return values

    def GetTimingAttributeUnits(self, name):
        """ Return attribute units """
        units = []
        for item in self.data:
            units.append(item.GetAttributeUnit(name))
        return units

    def GetTimingAttributeTypes(self, name):
        """ Return attribute values """
        types = []
        for item in self.data:
            types.append(item.GetAttributeType(name))
        return types

    def GetTimingAttributeImages(self, name):
        """ Return attribute images """
        images = []
        for item in self.data:
            images.append(item.GetAttributeImage(name))
        return images

    def DeleteTimingAttribute(self, name):
        """ Delete all attribute objects with name """
        for item in self.data:
            try:
                item.DeleteAttribute(name)
            except StandardError, ex:
                self.__logger.info(str(ex))

    def __str__(self):
        lines = []
        lines.append("Timestamps  : ")
        if self.GetTimeStamps() is not None:
            lines[0] = lines[0] + ','.join(map(str, self.GetTimeStamps()))
            attr_names = self.GetTimingAttributeNames()
            for name in attr_names:
                lines.append("%s : " % name)

            for name in attr_names:
                attr_index = attr_names.index(name) + 1  # pylint: disable=E1103
                values = self.GetTimingAttributeValues(name)
                lines[attr_index] = lines[attr_index] + str(values).strip('[]')

            string = ""
            for line in lines:
                string = string + "%s\n" % line
        else:
            string = "no timing attributes"
        return string


class ValBaseSingleton(object):
    """ Singleton Class for storing instance which should be only once created """
    __instances = []

    @staticmethod
    def __del__():
        """ Destructor """
        for instance in ValBaseSingleton.__instances:
            instance.__del__()

    @staticmethod
    def GetInstanceOf(cls, *args):
        """ Returns an instance of the given Class
        @param cls: Class
        @return: Instance of cls
        """
        instance = None

        for instance in ValBaseSingleton.__instances:
            if isinstance(instance, cls):
                return instance

        instance = object.__new__(cls)
        instance.__init__(*args)
        ValBaseSingleton.__instances.append(instance)

        return instance


class ValEventDatabaseInterface(object):
    """ Event Database Interface class """
    def __init__(self, db_connection):
        self.__db_connections = db_connection
        self._ValResDB = None
        self._GblDB = None
#
        self.__InitializeDBConnection(self.__db_connections)

        self.__userid = None
        self.__wfid = None
        self.__assessment = {}
        self.__observer_types = {}
        self.__event_types_ids = {}

    def __del__(self):
        self.__db_connections = None
        self._ValResDB = None
        self._GblDB = None
        self._GenLblDB = None
        self._RecCatDB = None
        self._ObjDataDB = None

        self.__event_types_ids = {}

    def __InitializeDBConnection(self, db_connections):
        if not db_connections:
            raise ValEventError("DatabaseConnections not setted.")
        else:
            for ConnectionObject in db_connections:
                if isinstance(ConnectionObject, BaseRecCatalogDB):
                    self._RecCatDB = ConnectionObject
                    continue
                if isinstance(ConnectionObject, BaseObjDataDB):
                    self._ObjDataDB = ConnectionObject
                    continue
                if isinstance(ConnectionObject, BaseGenLabelDB):
                    self._GenLblDB = ConnectionObject
                    continue
                if isinstance(ConnectionObject, BaseGblDB):
                    self._GblDB = ConnectionObject
                    continue
                if isinstance(ConnectionObject, BaseValResDB):
                    self._ValResDB = ConnectionObject
                    continue

        if self._ValResDB is None:
            raise ValEventError("Database connection to validation results could not be established")
        if self._GblDB is None:
            raise ValEventError("Database connection to global could not be established")

    def _GetUserID(self):
        """ Get UserID from DB, if username not in db it raises an error.

            User can be added by the Project ATM.
        """
        if self.__userid is None:
            try:
                user_id = self._GblDB.GetUser(login=environ["USERNAME"])[COL_NAME_USER_ID]
            except Exception:
                raise ValEventError("User is not defined in the database. Please contact the project ATM.")
#                user = {}
#                user[COL_NAME_USER_LOGIN]   = environ["USERNAME"]
#                user[COL_NAME_USER_NAME]    = environ["USERNAME"]
#                user_id = self._GblDB.AddUser(user)
#                self._GblDB.Commit()

            self.__userid = user_id

        return self.__userid

    def _GetWorkflowID(self):
        if self.__wfid is None:
            self.__wfid = self._GblDB.GetWorkflow('automatic')[COL_NAME_WORKFLOW_WFID]

        return self.__wfid

    def _GetAssessmentDefinitionId(self, assessment, observer_type_id):

        if observer_type_id in self.__assessment:
            if assessment not in self.__assessment[observer_type_id]:
                sId = self._GblDB.GetAssessmentStateId(name=assessment, observer_type_id=observer_type_id)
                if sId is None:
                    raise AdasDBError("Assessment State not defined in the DB")

                self.__assessment[observer_type_id][assessment] = sId
            return self.__assessment[observer_type_id][assessment]
        else:
            return None

    def _GetAssessmentDict(self, assessment, comment, observer_type):
        """ Creates an assessment dict
        @param assessment: Event assessment
        @param comment: Assessment comment
        """
        asse = {}
        asse[COL_NAME_ASS_USER_ID] = self._GetUserID()
        asse[COL_NAME_ASS_WFID] = self._GetWorkflowID()
        asse[COL_NAME_ASS_ASSSTID] = self._GetAssessmentDefinitionId(assessment, observer_type)
        asse[COL_NAME_ASS_COMMENT] = comment
        if issubclass(self._GblDB.__class__, SQLite3BaseDB):
            asse[COL_NAME_ASS_DATE] = self._GblDB.GetCurrDateTime()
        return asse

    def _AddAssessment(self, assessment, comment, observer_type):
        assess = self._GetAssessmentDict(assessment, comment, observer_type)
        return  self._ValResDB.AddAssessment(assess)

    def _GetObserverTypeId(self, trid):
        if trid not in self.__observer_types:
            entries = self._ValResDB.GetTestRun(tr_id=trid)
            observer_type = entries[COL_NAME_TR_TYPE_ID]
            self.__observer_types[trid] = observer_type
            self.__assessment[observer_type] = {}

        return self.__observer_types[trid]

    def _GetEventTypeId(self, classname, eType=None):
        # Get event type ID of the event, if event type not found in Database,
        # add new one
        if classname not in self.__event_types_ids:
            event_type_id = self._ValResDB.GetEventTypeId(class_name=classname)
            if event_type_id is None:
                event_type_id = self._AddEventType(classname, eType)
                self._ValResDB.Commit()

            self.__event_types_ids[classname] = event_type_id
        else:
            event_type_id = self.__event_types_ids[classname]

        return event_type_id

    def _AddEventType(self, classname, eType):
        """ Add new event type to the Database, it's called after event type not found in DB
        @return: Returns event type ID
        """
        event_type = {}
        event_type[COL_NAME_EVENTTYPE_NAME] = eType
        event_type[COL_NAME_EVENTTYPE_CLASSNAME] = classname
        event_type[COL_NAME_EVENTTYPE_DESC] = ("automatic generated event type of %s. Time:%s" %
                                               (event_type[COL_NAME_EVENTTYPE_CLASSNAME], datetime.now()))

        return self._ValResDB.AddEventType(event_type)

    def LoadRoadType(self, measid):
        roadtypes = self._GenLblDB.GetGenericLabelsStateValues(measid, 'roadtype')
        return roadtypes

    def LoadObjectKinematics(self, measid, starttime):
        object_kinematics = self._ObjDataDB.GetLabeledObjectKinematics(measid, starttime)
        return object_kinematics

    def LoadLaneAssociation(self, rectobj_id, starttime, stoptime, labelstate):
        lane_association = self._ObjDataDB.GetLabeledLaneAssociation(rectobj_id, starttime,
                                                                     stoptime, lblstate=labelstate)
        return lane_association

    def LoadMeasID(self, filename):
        measid = self._RecCatDB.GetMeasurementID(filename)
        return measid

    def LoadEventAssessment(self, startTime, startIndex, stopTime, stopIndex, eventClassname, measid, trid, eType):
        entries = self._ValResDB.GetEventsView(trid=trid, measid=measid, beginabsts=startTime, endabsts=stopTime,
                                               start_idx=startIndex, stop_idx=stopIndex, eventtype=eType)
        if len(entries) > 0:
            return entries[0][COL_NAME_EVENTS_VIEW_ASSESSMENT]
        else:
            return None


class ValEventSaver(ValEventDatabaseInterface):
    """ ValEventSaver Save event in the database """
    def __init__(self, db):
        '''
        Constructor taking database connection
        @param db: Database Connection Dict
        '''
        ValEventDatabaseInterface.__init__(self, db)
        self.__unit_ids = {}
        self.__attribute_types_ids = {}

    def __del__(self):
        """ Destructor """

        self.__unit_ids = {}
        self.__attribute_types_ids = {}

    def SaveEvent(self, event, trid, measid,
                  level=ValSaveLoadLevel.VAL_DB_LEVEL_ALL, rdid=None):  # pylint: disable=R0913
        """ Add event into Database Val_Events Table and returns seid of the Event
        :param event: Event Iinstance
        :param trid: TestRunID
        :param measid: Measuremnet FileID
        :param level: Save Load Level
        :param rdid: Result Descriptor
        :return: Seid of the event
        """
        seid = None
        try:
            event_dict = self.__GetEventDictionary(event, trid, measid)
            seid = self._ValResDB.AddEvent(event_dict)

            if level & ValSaveLoadLevel.VAL_DB_LEVEL_4:
                # adding timing attributes into DB
                ts_edid = self.__AddEventDetailsToDB(event, seid)
                self.__AddEventTimingAttributes(event, ts_edid)

                # adding global attributes into DB
                edid = self._ValResDB.AddEventDetails(seid, event.GetTimestamp())
                self.__AddEventGlobalAttributes(event, edid)

            self._ValResDB.Commit()
        except Exception, ex:
            if seid is not None:
                self._ValResDB.DeleteEvent(seid=seid)

            raise ValEventError(str(ex))

        return seid

    def __GetEventDictionary(self, event, trid, measid):
        """ Create the event dictionary to be stored into the DB
        :param event: event class derived from ValBaseEvent
        :param trid: testrun identifier
        :param measid: measurement identifier
        """
        rec = {}
        rec[COL_NAME_EVENTS_TRID] = trid
        rec[COL_NAME_EVENTS_BEGINABSTS] = event.GetStartTime()
        rec[COL_NAME_EVENTS_ENDABSTS] = event.GetStopTime()
        rec[COL_NAME_EVENTS_START_IDX] = event.GetStartIndex()
        rec[COL_NAME_EVENTS_STOP_IDX] = event.GetStopIndex()
        rec[COL_NAME_EVENTS_EVENTTYPEID] = self._GetEventTypeId(event.__class__.__name__, event.GetType())

        asmt = event.GetAssessment()
        if asmt is not None:
            asmt_id = event.GetAssessment().GetId()
            if asmt_id is not None:
                rec[COL_NAME_EVENTS_RESASSID] = asmt_id

        if event.GetMeasId() is None:
            rec[COL_NAME_EVENTS_MEASID] = measid
        else:
            rec[COL_NAME_EVENTS_MEASID] = event.GetMeasId()

        rdid = event.GetRdId()
        if rdid is not None:
            rec[COL_NAME_EVENTS_RDID] = rdid

        return rec

    def __AddEventDetailsToDB(self, event, seid):
        """ Add event details into Val_EventDetails Table
        :param seid: Seid in the Val_Events Table of added Event
        :param event: event class derived from ValBaseEvent
        :return: timestamp and edid pairs
        """
        edid_list = []
        timestamps = event.GetTimeStamps()
        if timestamps is not None:
            for timestamp in timestamps:
                edid = self._ValResDB.AddEventDetails(seid, timestamp)
                edid_list.append(edid)
        else:
            timestamps = []

        return zip(timestamps, edid_list)

    def __AddEventTimingAttributes(self, event, ts_edid):
        """ Add event details into Val_EventDetails Table
        :param seid: Seid in the Val_Events Table of added Event
        :param event: event class derived from ValBaseEvent
        :return: Edid list
        """
        if len(ts_edid) > 0:
            attribute_names = event.GetTimingAttributeNames()
            for name in attribute_names:
                values = event.GetTimingAttributeValues(name)
                units = event.GetTimingAttributeUnits(name)
                image = event.GetTimingAttributeImages(name)

                idx = 0
                for _, edid in ts_edid:
                    self.__AddEventAttribute(edid, name, values[idx], units[idx], image[idx])
                    idx += 1

    def __AddEventGlobalAttributes(self, event, edid):
        """ Store the global Attributes of an event
        :param event: event class derived from ValBaseEvent
        :param edid: event details identifier
        """
        attribute_names = event.GetAttributeNames()
        for name in attribute_names:
            values = event.GetAttributeValues(name)
            unit = event.GetAttributeUnit(name)
            image = event.GetAttributeImage(name)

            for value in values:
                self.__AddEventAttribute(edid, name, value, unit, image)

    def __AddEventAttribute(self, edid, name, value, unit, image):
        """ Add event attribute into Val_EventAttr Table
        :param edid: event details identifier
        :param name: name of the attribute
        :param value: value of the attribute
        :param unit: unit identifier of the attribute
        :param image: image of the attribute
        :return attribute identifier
        """
        attribute_id = None
        getattrid = False

        if image is not None:
            getattrid = True

        if value is not None:
            attribute = {}
            attribute[COL_NAME_EVENT_ATTR_EDID] = edid
            attribute[COL_NAME_EVENT_ATTR_VALUE] = value
            attribute[COL_NAME_EVENT_ATTR_ATTRTYPEID] = self.__GetAttributeTypeId(name, unit)

            attribute_id = self._ValResDB.AddEventAttribute(attribute, getattrid=getattrid)

        if image is not None:
            self.__AddEventImage(attribute_id=attribute_id, image=image)

        return attribute_id

    def __AddEventImage(self, attribute_id, image, file_ext='png', title=None):
        """ Add an image as attribute to the event
        :param attribute_id: Attribute Identifier
        :param image: Image Buffer (blub) or filepath to be added to the database
        :param format: format of the image
        :param title: title of the image
        """
        if image is not None:
            event_image = {}
            event_image[COL_NAME_EVENT_IMG_ATTRID] = attribute_id
            event_image[COL_NAME_EVENT_IMG_FORMAT] = file_ext
            if title is None:
                title = str('Event image for Attribute ID %s' % attribute_id)
            event_image[COL_NAME_EVENT_IMG_TITLE] = title
            event_image[COL_NAME_EVENT_IMG_IMAGE] = image

            self._ValResDB.AddEventImage(event_image)

    def __GetAttributeTypeId(self, name, unit):
        """ Get the attribute type id
        :param name: name of the attribute
        :param unit: unit of the attribute
        :return: Attribute Type Identifier
        """
        if name not in self.__attribute_types_ids:
            attribute_type_id = self._ValResDB.GetEventAttributeTypeId(name)
            self.__attribute_types_ids[name] = attribute_type_id
        else:
            attribute_type_id = self.__attribute_types_ids[name]

        if not isinstance(attribute_type_id, (int, float, long)):
            attribute_type_id = self.__AddEventAttributeType(name, unit)

        return attribute_type_id

    def __AddEventAttributeType(self, name, unit, desc='auto generated attribute type'):
        """ Add a new event attribute type
        :param name: name of the attribute
        :param unit: unit of the attribute
        :param desc: description of the attribute
        :return: Attribute Type Identifier
        """
        attribute_type = {}
        attribute_type[COL_NAME_EVENT_ATTR_TYPES_NAME] = name
        attribute_type[COL_NAME_EVENT_ATTR_TYPES_UNITID] = BaseUnit(unit, dbi_gbl=self._GblDB).GetId()
        attribute_type[COL_NAME_EVENT_ATTR_TYPES_DESC] = desc

        return self._ValResDB.AddEventAttributeType(attribute_type)


class ValEventLoader(ValEventDatabaseInterface):
    """ ValEventLoader Class - loads Event details from Database """
    def __init__(self, db, plugin_folder_list=PLUGIN_FOLDER_LIST):
        '''
        Constructor taking database connection
        @param db: Database Connection Dict
        '''
        ValEventDatabaseInterface.__init__(self, db)
        warnings.warn('Class ValEventLoader is deprecated', stacklevel=2)

        self.__plugin_manager = PluginManager(plugin_folder_list, ValBaseEvent)
        self.__event_types_list = self.__plugin_manager.get_plugin_class_list(remove_duplicates=True)
        self.__event = None
        self.__event_list = []
        self.__event_inst_created = {}

        self.__assessment_id = {}

    def __del__(self):
        """
        Destructor
        """
        # ValEventDatabaseInterface.__del__(self)
        self.__event = None

        del self.__event_list

    def LoadEvent(self):
        """ LoadEvent """
        raise NotImplementedError

    def LoadEvents(self, measid=None, trid=None, beginabsts=None, endabsts=None,
                   assessment=None, load_attributes=False):
        """ Load events from Database and creates an Event object of corresponding event class
        @param measid: Measurement File Id
        @param trid: Testrun ID
        @param beginabsts: Start timestamp of an event
        @param endabsts: Stop timestamp of an event
        @return: Returns EventList
        """
        self.__event_list = []

        if load_attributes:
            event_record = self._ValResDB.GetEventsAttributesView(measid=measid, trid=trid, beginabsts=beginabsts,
                                                                  endabsts=endabsts, assessment=assessment)
        else:
            event_record = self._ValResDB.GetEventsView(measid=measid, trid=trid, beginabsts=beginabsts,
                                                        endabsts=endabsts, assessment=assessment)

        self.__CreateEventList(event_record, load_attributes)
        return self.__event_list

    def LoadAssessment(self, ident):
        """ Load assessment from database
        @param aId: Assessment id which is in the database
        @return: Returns the assessment workflow id (WFID)
        """
        ident = self._ValResDB.GetAssessment(ident=ident)[0][COL_NAME_ASS_ASSSTID]

        if ident not in self.__assessment_id:
            assessment = self._GblDB.GetAssessmentState(ident=ident)[0][COL_NAME_ASSESSMENT_STATE_NAME]
            self.__assessment_id[ident] = assessment
        else:
            assessment = self.__assessment_id[ident]

        return  assessment

    def LoadAssesmentComment(self, ident):
        """ Load assessment comment from database
        @param ident: Assessment id which is in the database
        @return: Returns the assessment comment
        """
        return  self._ValResDB.GetAssessment(ident)[0][COL_NAME_ASS_COMMENT]

    def LoadAttributes(self, event, timestamp=None, attribute_name=None):
        """ Load attributes from DB into event
        @param event: Event where DB data should be stored
        @param timestamps: timestamps = None: -> Load all Attributes
                           timestamps = -1 -> Load only global attributes
        """
        self.__event = event

        if timestamp != -1:
            self.__LoadTimingAttributes(event=event, seid=self.__event.GetEventSeid(), attribute_name=attribute_name)
            self.__LoadGlobalAttributes(event=event, seid=self.__event.GetEventSeid(), attribute_name=attribute_name)
        else:
            self.__LoadGlobalAttributes(event=event, seid=self.__event.GetEventSeid(), attribute_name=attribute_name)

    def __CreateEventList(self, events_record, load_attributes):
        """ Loop through event db data and creates of each entrie an event class instance
        @param events: Loaded event data from DB
        """
        self.__event_list = []
        self.__event_inst_created = {}

        for record in events_record:
            event = self.__CreateEventInstance(record)

            if load_attributes:
                self.__event_inst_created.setdefault(record[COL_NAME_EVENTS_SEID], []).append(record)

            if event is not None:
                self.__event_list.append(event)

        if load_attributes:
            for event in self.__event_list:
                self.__SetEventAttributes(event=event, record=self.__event_inst_created[event.GetEventSeid()])

    def __CreateEventInstance(self, record):
        """ Creates an instance of the corresponding event class
        @param event_record: Loaded event data from DB
        @return: Event object
        """
        event = None
        if record[COL_NAME_EVENTS_SEID] not in self.__event_inst_created:
            classname = record[COL_NAME_EVENTS_VIEW_CLASSNAME]
            for eType in self.__event_types_list:
                if eType['name'] == classname:
                    cls = eType['type']

            # create new object and call the constructor
            event = object.__new__(cls)
            event.__init__(start_time=record[COL_NAME_EVENTS_VIEW_BEGINABSTS],
                           start_index=record[COL_NAME_EVENTS_VIEW_START_IDX],
                           stop_time=record[COL_NAME_EVENTS_VIEW_ENDABSTS],
                           stop_index=record[COL_NAME_EVENTS_VIEW_STOP_IDX],
                           seid=record[COL_NAME_EVENTS_VIEW_SEID],
                           assessment_id=record[COL_NAME_EVENTS_RESASSID])

            event.SetAssessment(assessment=record[COL_NAME_EVENTS_VIEW_ASSESSMENT],
                                comment=record[COL_NAME_EVENTS_VIEW_COMMENT])

        return event

    def __SetEventAttributes(self, event, record):
        self.__SetGlobalAttributes(event=event, record=record)
        self.__SetTimingAttributes(event=event, record=record)

    def __LoadGlobalAttributes(self, event, seid, attribute_name):
        record = self._ValResDB.GetEventDetailsAttributes(seid, timestamps= -1, attribute_name=attribute_name)
        self.__SetGlobalAttributes(event=event, record=record)

    def __LoadTimingAttributes(self, event, seid, attribute_name):
        record = self._ValResDB.GetEventDetailsAttributes(seid, attribute_name=attribute_name)
        self.__SetTimingAttributes(event=event, record=record)

    def __GetEventClassName(self, event_type_id):
        """ Load Classname of an event type
        @param event_type_id: Eventtype ID
        @return: Classname as String
        """
        record = self._ValResDB.GetEventType(event_type_id)
        return record[COL_NAME_EVENTTYPE_CLASSNAME]

    def __SetGlobalAttributes(self, event, record):
        """ Load global attributes from DB and set this in the event
        @param seid: Seid of the Event
        """
        # check if the global event attributes are already loaded
        if event.GetLoadLevel1():
            return

        for item in record:
            if item[COL_NAME_EVENT_DET_ABSTS] == -1:
                try:
                    event.AddAttribute(item[COL_NAME_EVENT_ATTR_TYPES_NAME], item[COL_NAME_EVENT_ATTR_VALUE])
                except:
                    raise ValEventError

        # set load level 1 -> global attributes loaded
        event.SetLoadLevel1(True)

    def __SetTimingAttributes(self, event, record):
        if event.GetLoadLevel2():
            return

        attributes = {}
        self.__SetTimestampsInEvent(event=event, record=record)

        for item in record:
            if item[COL_NAME_EVENT_DET_ABSTS] != -1:
                try:
                    attributes.setdefault(item[COL_NAME_EVENT_ATTR_TYPES_NAME],
                                          []).append(item[COL_NAME_EVENT_ATTR_VALUE])
                except:
                    raise ValEventError

        for key, value in attributes.items():
            event.AddTimingAttribute(attribute_name=key, value=value)

        event.SetLoadLevel2(True)

    def __SetTimestampsInEvent(self, event, record):
        """ Set timestamps in event details container
        @param timestamps: Timestamps
        """
        if event.GetTimeStamps() is None:
            timestamps = []
            for item in record:
                if item[COL_NAME_EVENT_DET_ABSTS] != -1:
                    timestamps.append(item[COL_NAME_EVENT_DET_ABSTS])
            # remove duplicates
            timestamps = list(set(timestamps))
            timestamps.sort()

            event.SetTimestamps(timestamps)


class ValEventUpdater(ValEventDatabaseInterface):
    """ ValEventUpdater update the event in the database """
    def __init__(self, db):
        '''
        Constructor taking database connection
        @param db: Database Connection Dict
        '''
        ValEventDatabaseInterface.__init__(self, db)
        warnings.warn('Class ValEventUpdater is deprecated', stacklevel=2)

        self.__event = None
        self.__db = None

    def __del__(self):
        """ Destructor """
        self.__db = None
        self.__event = None

    def UpdateEvent(self, event):
        """ Update the event values + attributes in the database
        @param event: Event from which db data will be updated
        """
        self.__event = event
        # Update the asessment
        assessment = self.__event.GetAssessment()
        comment = self.__event.GetAssessmentComment()
        self.UpdateAssessment(self.__event, assessment, comment)
        # TODO: Update Attributes

    def UpdateAssessment(self, event, assessment, comment=""):
        """ Update the assessment of an event
        @param event: Event
        @param assessment: Assessment according to ASSESSMENT
        @param comment: Assessment comment
        """
        self.__event = event

        assid = self._ValResDB.GetEvents(self.__event.GetEventSeid())[0][COL_NAME_ASS_ID]
        # check if reasaasid is set in the event
        if not isinstance(assid, int):
            # add new assessment into Val_Assessment
            assess = self._GetAssessmentDict(assessment, comment, None)
            assess[COL_NAME_ASS_ID] = assid
            assid = self._ValResDB.AddAssessment(assess)

            # update the resaasid in the event
            event_dict = {}
            event_dict[COL_NAME_ASS_ID] = assid
            event_dict[COL_NAME_EVENTS_SEID] = self.__event.GetEventSeid()
            self._ValResDB.UpdateEvent(event_dict)
            self.__event.SetAssessmentID(assid)
        else:
            # update the assessment
            assess = self._GetAssessmentDict(assessment, comment, None)
            assess[COL_NAME_ASS_ID] = assid
            self._ValResDB.UpdateAssessment(assess)

        self._ValResDB.Commit()
        return assid

    def UpdateEventAttributes(self):
        raise NotImplementedError


class ValEventDeleter(ValEventDatabaseInterface):
    def __init__(self):
        pass

    def DeleteEvent(self):
        raise NotImplementedError

    def DeleteEventAttribute(self):
        raise NotImplementedError

    def DeleteEventAttributes(self):
        raise NotImplementedError

    def DeleteEventAssessement(self):
        raise NotImplementedError


class ValBaseEvent(ValBaseEventDetailsContainer, ValBaseEventDetails):
    """
    Base Class for the validation event
    """
    def __init__(self, start_time=0, start_index= -1, stop_time=0, stop_index= -1,
                 timestamps=None, seid=None, assessment_id=None, measid=None):
        """
        Constructor taking the starttime, startindex and the eventtype as argument
        :param start_time: Absolute Time Start
        :param start_index: Start index
        :param stop_time: Stop time of the event
        :param stop_index: Stop index of the event
        :param timestamps: Timestamps vector (optional)
        :param seid: DB unique identifier (when loading)
        :param assessment_id: Assessment identifier of the event (downward compatibility)
        :param measid: measid of the event (measurement)
        """
        self.__logger = Logger(self.__class__.__name__)

        self.__assid = assessment_id
        self.__seid = seid
        self.__measid = measid
        self.__rdid = None
        self.__parent = None
        self.__assessment = None

        ValBaseEventDetailsContainer.__init__(self, timestamps)
        # create the global event attributes object, for attibutes with not time informations
        ValBaseEventDetails.__init__(self)

        self.__type = self.__class__.__name__
        self.__ref_tag = None
        self.__start_time = start_time
        self.__start_index = start_index
        self.__stop_time = stop_time  # Event Stop Time
        self.__stop_index = stop_index  # Event Stop Index

    def __del__(self):
        '''
        Destructor
        '''
        self.__assid = None
        self.__seid = None
        self.__type = None

    def __copy__(self):
        cp = ValBaseEvent()
        cp.__dict__ = copy(self.__dict__)

        return cp

    def Save(self, dbi_val, dbi_gbl, testrun_id, coll_id, meas_id=None,
             obs_name=None, parent_id=None, level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None):  # pylint: disable=R0912, R0913, R0914, W0613
        """ Save the event
        :param dbi_val: VAL DB interface
        :param dbi_gbl: GBL DB interface
        :param testrun_id: Testrun identifier
        :param coll_id: CAT Collection ID
        :param meas_id: Measurement Identifier
        :param obs_name: Observer Name (registered in GBL)
        :param level: Save level,
                - VAL_DB_LEVEL_STRUCT: Result Descriptor only,
                - VAL_DB_LEVEL_BASIC: Result Descriptor and result,
                - VAL_DB_LEVEL_INFO: Result Descriptor, Result and Assessment
                - VAL_DB_LEVEL_ALL: Result with images and all messages
        :param cons_key: contraint key -- for future use
        """
        res = False
        msg = None
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            self.__logger.error("VAL Database interface undefined")
            return res

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            self.__logger.error("GBL Database interface undefined")
            return res

        unit_id = dbi_gbl.GetUnitIdByName("none")
        if unit_id is None:
            self.__logger.error("Unit is not defined in the GBL Database")
            return res

        if self.__measid is not None:
            meas_id = self.__measid

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_1:
            if dbi_val.GetResultTypeId(self.__type) is None:
                res_type = {COL_NAME_RESULTTYPE_NAME: self.__type, COL_NAME_RESULTTYPE_DESC: "",
                            COL_NAME_RESULTTYPE_CLASS: "None"}
                dbi_val.AddResultType(res_type)

            # use eventtype as name. simple workaround (GR 27.06.2013)
            self.__rdid = dbi_val.GetResultDescriptorId(coll_id, self.__type, ev_type_name=self.__type)

            if self.__rdid is None:
                # use the parent id of the testcase
                if self.__parent is None:
                    self.__parent = parent_id
                # generate a new descriptor
                self.__rdid = dbi_val.AddResultDescriptor(self.__type, self.__type, coll_id, unit_id,
                                                          self.__ref_tag, self.__parent)

                if level < ValSaveLoadLevel.VAL_DB_LEVEL_2:
                    res = True

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_2:

            # if no Assessment Assigned add the default assessment
            if level & ValSaveLoadLevel.VAL_DB_LEVEL_3:
                if self.__assessment is None:
                    user = dbi_gbl.GetUser(login=environ["USERNAME"])
                    user_id = user[COL_NAME_USER_ID]
                    comment = "default automatically assigned - Not assessed."
                    self.__assessment = ValAssessment(user_id=user_id,
                                                   wf_state=ValAssessmentWorkFlows.ASS_WF_AUTO,
                                                   ass_state=ValAssessmentStates.NOT_ASSESSED,
                                                   ass_comment=comment)
                    self.__logger.warning("Event as no Assessment" +
                                          " %s will be saved" % comment)

                self.__assessment.Save(dbi_val, dbi_gbl, obs_name)
                self.__assid = self.__assessment.GetId()

            evt_saver = ValEventSaver([dbi_val, dbi_gbl])
            seid = evt_saver.SaveEvent(self, testrun_id, meas_id)
            if seid is not None:
                res = True

        if res is True:
            dbi_val.Commit()
        else:
            if msg is None:
                self.__logger.error("Event %s could not be stored" % str(self))
            else:
                self.__logger.error(msg)

        return res

    def SaveEventDB(self, db, trid, measid):
        """ Save Event and all Event attributes in Database
        :param db: DatabaseConnection (Getting DBConnection from 'DataBaseObjectsConnections' port),
                   connection to dbval and dbgbl must be avaible
        :param trid: Testrun ID
        :param measid: Measurement ID
        """
        warnings.warn('SaveEventDB of event is deprecated. Use Save() instead', stacklevel=2)
        instance = ValBaseSingleton.GetInstanceOf(ValEventSaver, db)
        self.__seid = instance.SaveEvent(self, trid, measid)

    def LoadEventAttributesDB(self, db, plugin_folder_list, timestamps=None):
        """ Load all Event attributes from Database
        :param db: DatabaseConnection (Getting DBConnection from 'DataBaseObjectsConnections' port),
                   connection to dbval and dbgbl must be avaible
        """
        warnings.warn('LoadEventAttributesDB of event is deprecated. Use class ValEventList() instead', stacklevel=2)
        instance = ValBaseSingleton.GetInstanceOf(ValEventLoader, db, plugin_folder_list)
        if self.__seid is not None:
            instance.LoadAttributes(self, timestamps)

    def UpdateEventDB(self, db):
        """ Update Event values in the Database """
        warnings.warn('LoadEventAttributesDB of event is deprecated. Use class ValEventList() instead', stacklevel=2)
        instance = ValBaseSingleton.GetInstanceOf(ValEventUpdater, db)
        if self.__seid is not None:
            instance.UpdateEvent(self)

    def GetDurationMicroSeconds(self):
        """ Return the timespan of the event
        :return Duration in micro seconds
        """
        if self.__start_time <= self.__stop_time:
            return self.__stop_time - self.__start_time
        raise ValEventError("Event not finished")

    def GetEventCycles(self):
        """ Return the timespan of the event
        :return Duration in cycles
        """

        if self.__start_index + 1 <= self.__stop_index + 1:
            return self.__stop_index - self.__start_index + 1
        raise ValEventError("Event not finished")

    def SetStopTimeAndIndex(self, stop_time, stop_index):
        """ Set the stop time and index of the event
        :param stop_time: The Stop time of the event
        :param stop_index: The Stop index of the event
        """
        self.__stop_time = stop_time
        self.__stop_index = stop_index

    def SetStartTimeAndIndex(self, start_time, start_index):
        """ Set Start Time and Index
        """
        self.__start_time = start_time
        self.__start_index = start_index

    def _SetStartTime(self, start_time):
        """ Set the starting time of
        """
        self.__start_time = start_time

    def _SetStopTime(self, stop_time):
        """ Set the starting time of
        """

        self.__stop_time = stop_time

    def _SetStartIndex(self, start_index):
        """ Set the starting index of
        """
        self.__start_index = start_index

    def _SetStopIndex(self, stop_index):
        """ Set the stop index of
        """
        self.__stop_index = stop_index

    def SetType(self, value):
        """ Set the Type of the Object
        """
        self.__type = value

    def SetEventSeid(self, seid):
        """ Set event seid """
        self.__seid = seid

    def SetAssessmentID(self, ident):
        """ Set event assessment id """
        warnings.warn('SetAssessmentID() of event is deprecated. Use ValAssessment Class instead', stacklevel=2)
        self.__assid = ident

    def SetMeasId(self, measid):
        """ Set the measurement identifier of the event """
        self.__measid = measid

    def SetRdId(self, rdid):
        """ Set the resultdescriptor id """
        self.__rdid = rdid

    def AddAssessment(self, assessment):
        """ Add Assessment Instance to the result
        :param assessment: Assessment instance
        :return: True if passed, False on Error
        """
        if not issubclass(assessment.__class__, ValAssessment):
            self.__logger.error("Not an Assessment Class Instance")
            return False

        self.__assessment = assessment
        return True

    def SetAssessment(self, assessment, comment='', wfid=None):
        """ Set the event assessment according @ASSESSMENT """
        warnings.warn('SetAssessment() of event is deprecated', stacklevel=2)
        self.__assessment = ValAssessment(user_id=None, wf_state=wfid, ass_state=assessment, ass_comment=comment)

    def GetAssessment(self):
        """ Returns event assessment """
        return self.__assessment

    def GetAssessmentComment(self):
        """ Returns event assessment comment"""
        warnings.warn('GetAssessmentComment() of event is deprecated', stacklevel=2)
        return self.__assessment.GetComment()

    def GetAssessmentID(self):
        """ Returns the assessment id of the Event
        """
        warnings.warn('GetAssessmentComment() of event is deprecated', stacklevel=2)
        if issubclass(self.__assessment.__class__, ValAssessment):
            return self.__assessment.GetId()
        else:
            return self.__assid

    def GetEventSeid(self):
        """ Returns event seid """
        return self.__seid

    def GetType(self):
        """ Returns the Type of the Object
        """
        return self.__type

    def GetStartTime(self):
        """ Returns the Start-time of the Event
        """
        return self.__start_time

    def GetStopTime(self):
        """ Returns the Stop-time of the Event
        """
        return self.__stop_time

    def GetStartIndex(self):
        """ Returns the StopIndex of the Event
        """
        return self.__start_index

    def GetStopIndex(self):
        """ Returns the StopIndex of the Event
        """
        return self.__stop_index

    def GetMeasId(self):
        """ Get the measurement identifier of the event """
        return self.__measid

    def GetRdId(self):
        """ Get the result descriptor Identifier of the event """
        return self.__rdid

    def __str__(self):
        me = ""
        if self.__type is not None:
            me += ("Event Type  : %s\n" % self.__type)
        if self.__start_index is not None:
            me += ("Start index : %d\n" % self.__start_index)
        if self.__stop_index is not None:
            me += ("Stop index  : %d\n" % self.__stop_index)
        if self.__start_time is not None:
            me += ("Start time  : %d\n" % self.__start_time)
        if self.__stop_time is not None:
            me += ("Stop time   : %d\n" % self.__stop_time)
        if self.__seid is not None:
            me += ("Seid ID   : %d\n" % self.__seid)
        if self.__assessment is not None:
            me += ("Assessment : %s\n" % str(self.__assessment))
        me += "-- Global event attributes ---\n"
        me += ValBaseEventDetails.__str__(self)
        me += "-- Timing event attributes ---\n"
        me += ValBaseEventDetailsContainer.__str__(self)

        return me


class ValStatObstEvent(ValBaseEvent):
    '''
    Class holding plot signals and data to be consumed by the validation plot
    '''
    def __init__(self, start_index, stop_index, radar_object):
        '''
        Constructor taking the starttime, startindex and the eventtype as argument
        '''
        warnings.warn('Class ValStatObstEvent is deprecated', stacklevel=2)
        start_time = radar_object.GetStartTime()
        stop_time = radar_object.GetStopTime()
        ValBaseEvent.__init__(self, start_time=start_time, start_index=start_index)

        self.__radar_object = radar_object
        self.SetStopTimeAndIndex(stop_time, stop_index)

        self.__so_start = start_index - radar_object.GetStartIndex()
        self.__so_stop = stop_index - radar_object.GetStartIndex()
        self.__has_been_seen_moving = False

    def __del__(self):
        '''
        Destructor of the plot class
        '''
        self.__radar_object = None
        ValBaseEvent.__del__(self)

    def SetStopIndexOfRelevance(self, idx):
        """ Set the stop index of relevance
        """
        self.__so_stop = idx - self.__radar_object.GetStartIndex() - 1

    def GetAbsRelevanceStopIndex(self):
        """ Set the stop index of relevance
        """
        return self.__radar_object.GetStartIndex() + self.__so_stop

    def SetSeenMoving(self, seen_moving):
        """ Set if the Object has been seen moving """
        self.__has_been_seen_moving = seen_moving

    def HasBeenSeenMoving(self):
        """ return True if the Object has been seen moving """
        return self.__has_been_seen_moving

    def GetObjectSignalValues(self, signal):
        """ Return the Signal values for the relevant time range """
        return self.__radar_object.GetSignal(signal, start_idx=self.__so_start, end_idx=self.__so_stop)

    def GetRadarObject(self):
        """returns the radar object"""
        return self.__radar_object


class ValAlnStateEvent(ValBaseEvent):
    '''
    Class holding ALN State events
    '''
    def __init__(self, start_time, start_index, aln_state, stop_time=0, stop_index= -1):
        '''
        Constructor taking the starttime, startindex and the eventtype as argument
        '''
        ValBaseEvent.__init__(self, start_time=start_time, start_index=start_index,
                              stop_time=stop_time, stop_index=stop_index)
        self.__aln_state = aln_state

    def GetState(self):
        """ return the ALN State """
        return self.__aln_state


class ValGenericStateEvent(ValBaseEvent):
    '''
    Class holding Signal Name State events
    '''
    def __init__(self, start_time, start_index, state, stop_time=0, stop_index= -1, sig_name=None):
        '''
        Constructor taking the starttime, startindex and the eventtype as argument
        '''
        warnings.warn('Class ValGenericStateEvent is deprecated', stacklevel=2)

        ValBaseEvent.__init__(self, start_time=start_time, start_index=start_index,
                              stop_time=stop_time, stop_index=stop_index)
        self.__state = state
        self.__sig_name = sig_name

    def GetState(self):
        """ return the State """
        return self.__state

    def GetSignalName(self):
        """ return the Signal Name """
        return self.__sig_name

"""
    CHANGE LOG:
-----------
$Log: base_events.py  $
Revision 1.1 2021/12/13 17:59:44CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/val/project.pj
Revision 1.24 2013/11/05 15:10:30CET Ahmed, Zaheer (uidu7634) 
Added Support for Default Assessment for Events if No assessment given at the time Saving Event
- Added comments -  uidu7634 [Nov 5, 2013 3:10:31 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.23 2013/10/01 10:32:47CEST Raedler, Guenther (uidt9430)
- moved deprecated into constructor
--- Added comments ---  uidt9430 [Oct 1, 2013 10:32:48 AM CEST]
Change Package : 197855:1 http://mks-psad:7002/im/viewissue?selection=197855
Revision 1.22 2013/08/26 15:26:55CEST Ahmed-EXT, Zaheer (uidu7634)
Fixed ViewEvent column in LoadEvents Method
--- Added comments ---  uidu7634 [Aug 26, 2013 3:26:55 PM CEST]
Change Package : 192688:1 http://mks-psad:7002/im/viewissue?selection=192688
Revision 1.21 2013/08/23 13:34:05CEST Ahmed-EXT, Zaheer (uidu7634)
Pep8, pylint fix
Removed deprecrated SetAssessmentID() usage in Save method for base event class
--- Added comments ---  uidu7634 [Aug 23, 2013 1:34:05 PM CEST]
Change Package : 190321:1 http://mks-psad:7002/im/viewissue?selection=190321
Revision 1.20 2013/08/07 13:44:36CEST Raedler, Guenther (uidt9430)
- use __str__ when printing event info (event takes no name)
- fixed error when printing events
--- Added comments ---  uidt9430 [Aug 7, 2013 1:44:36 PM CEST]
Change Package : 192840:1 http://mks-psad:7002/im/viewissue?selection=192840
Revision 1.19 2013/07/18 10:14:48CEST Hecker, Robert (heckerr)
CheckIn of needed changes of Zaheer, to get his code working.
--- Added comments ---  heckerr [Jul 18, 2013 10:14:48 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.18 2013/07/15 13:43:48CEST Raedler, Guenther (uidt9430)
- maked classed as deprecated ValEventNotImplemented, ValEventLoader, ValStatObstEvent, ValAlnStateEvent(), ValGenericStateEvent()
- removed some classes ValBaseEventLoadLevel,ValEventSaverError,ValEventLoaderError, ValEventUpdaterError,ValEventDeleterError
- removed unused db interfaces in ValEventDatabaseInterface
- restructured ValEventSaver(), removed unused internals
- added new methods Save(),SetMeasId(),SetRdId(), AddAssessment(),GetRdId()   to ValBaseEvent and used ValAssessment class
--- Added comments ---  uidt9430 [Jul 15, 2013 1:43:48 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.17 2013/04/22 13:10:33CEST Hecker, Robert (heckerr)
Revert to Version 1.14.1.1. LAst working Version from AL_STK_V02.00.03.
--- Added comments ---  heckerr [Apr 22, 2013 1:10:34 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.16 2013/04/12 14:53:14CEST Mertens, Sven (uidv7805)
adaptation for epydoc and changed PluginManager
--- Added comments ---  uidv7805 [Apr 12, 2013 2:53:14 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.15 2013/04/05 14:40:44CEST Ahmed-EXT, Zaheer (uidu7634)
Changes according to support ACC performance Event
--- Added comments ---  uidu7634 [Apr 5, 2013 2:40:45 PM CEST]
Change Package : 178419:2 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.14 2013/04/04 10:56:46CEST Raedler, Guenther (uidt9430)
- fixed datetime naming conflict on oracle (oracle uses triggers)
--- Added comments ---  uidt9430 [Apr 4, 2013 10:56:46 AM CEST]
Change Package : 175136:1 http://mks-psad:7002/im/viewissue?selection=175136
Revision 1.13 2013/03/28 15:25:20CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:21 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.12 2013/03/28 14:43:09CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:09 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.11 2013/03/28 14:20:09CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
--- Added comments ---  uidv7805 [Mar 28, 2013 2:20:09 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/28 13:31:28CET Mertens, Sven (uidv7805)
minor pep8
Revision 1.9 2013/03/28 09:33:20CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:20 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/27 09:04:31CET Mertens, Sven (uidv7805)
pylint: reorg of imports, rename of some variables
Revision 1.7 2013/03/22 08:24:24CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.6 2013/03/08 08:40:19CET Raedler, Guenther (uidt9430)
- fixed module test errors
--- Added comments ---  uidt9430 [Mar 8, 2013 8:40:20 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.5 2013/03/01 15:25:36CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 3:25:36 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/28 08:12:10CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:11 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 17:55:08CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:08 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/27 16:19:52CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:52 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/26 16:35:26CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/val/project.pj
Revision 1.19 2012/11/21 14:53:00CET Hammernik-EXT, Dmitri (uidu5219)
- added additional argument to LoadEventAssessment function
--- Added comments ---  uidu5219 [Nov 21, 2012 2:53:03 PM CET]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.18 2012/11/05 13:56:30CET Hammernik-EXT, Dmitri (uidu5219)
- moved same functions from EventSaver to EvenetDatabaseInterface
- improved EventSaver, added observer type to assessment
--- Added comments ---  uidu5219 [Nov 5, 2012 1:56:31 PM CET]
Change Package : 163588:1 http://mks-psad:7002/im/viewissue?selection=163588
Revision 1.16 2012/10/18 16:37:21CEST Hammernik-EXT, Dmitri (uidu5219)
- adapted functions to the changes in the database interface
--- Added comments ---  uidu5219 [Oct 18, 2012 4:37:23 PM CEST]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.14 2012/10/10 19:25:35CEST Hammernik-EXT, Dmitri (uidu5219)
- modified ValEventLoader for faster reading all event attributes
--- Added comments ---  uidu5219 [Oct 10, 2012 7:25:35 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.13 2012/10/10 10:24:52CEST Hammernik-EXT, Dmitri (uidu5219)
- added functionality to readin EventImage
- adapt assessment functions to db interface
- changed some functions to reduce database traffic
- code clean
--- Added comments ---  uidu5219 [Oct 10, 2012 10:24:54 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.12 2012/09/13 12:11:36CEST Hammernik-EXT, Dmitri (uidu5219)
- added new database connections to the ValEventDatabaseInterface
- added Exception handling in ValBaseEventDetails methods and save attribute name in lowercase
- added functionality in ValEventLoader to get attribute with speciefied name
- changed the COL_NAME_EVENT_DET_RELTS in COL_NAME_EVENT_DET_ABSTS
--- Added comments ---  uidu5219 [Sep 13, 2012 12:11:38 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.11 2012/08/28 11:54:35CEST Hammernik-EXT, Dmitri (uidu5219)
- improved validation events base class
--- Added comments ---  uidu5219 [Aug 28, 2012 11:54:36 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.11 2012/08/24 11:17:50CEST Hammernik-EXT, Dmitri (uidu5219)
- in ValBaseEvent class: changed access to methods SetStartIndex and SetStopIndex from public to protected
- bugfixes
--- Added comments ---  uidu5219 [Aug 24, 2012 11:17:52 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.10 2012/07/18 08:57:41CEST Hammernik-EXT, Dmitri (uidu5219)
- Added new class ValEventDatabaseInterface for all classes in validation_events
which needs a connection to the Database.
--- Added comments ---  uidu5219 [Jul 18, 2012 8:57:41 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.9 2012/07/02 14:07:23CEST Hammernik-EXT, Dmitri (uidu5219)
- bugfixes
- removed type from BaseEvent
- changed assessment get/ set methods
--- Added comments ---  uidu5219 [Jul 2, 2012 2:07:23 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.7 2012/06/05 14:00:45CEST Hammernik-EXT, Dmitri (uidu5219)
- added EventLoader which return an eventlist of instances of corresponding class
- added comments
--- Added comments ---  uidu5219 [Jun 5, 2012 2:00:52 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.6 2012/05/30 08:47:01CEST Hammernik-EXT, Dmitri (uidu5219)
- Created an Singelton class for stroring instances
- added functionality to update the assessment
--- Added comments ---  uidu5219 [May 30, 2012 8:47:04 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.5 2012/05/24 11:47:28CEST Hammernik-EXT, Dmitri (uidu5219)
- added functionality to read event from Database into ValBaseEvent class
--- Added comments ---  uidu5219 [May 24, 2012 11:47:29 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.3 2012/05/21 16:06:52CEST Hammernik-EXT, Dmitri (uidu5219)
- added ValBaseEventDetailsContainer, ValBaseEventStorage ..... classes
--- Added comments ---  uidu5219 [May 21, 2012 4:06:53 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.2 2012/05/15 10:39:16CEST Hammernik-EXT, Dmitri (uidu5219)
- added some new functions, for saving event in DB
--- Added comments ---  uidu5219 [May 15, 2012 10:39:16 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10.1.1 2012/05/14 14:49:20CEST Hammernik-EXT, Dmitri (uidu5219)
- Update BaseEvent Class: improved SaveToDB method to store events in database
--- Added comments ---  uidu5219 [May 14, 2012 2:49:22 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10 2012/03/28 13:43:43CEST Sampat-EXT, Janani Vasumathy (uidu5218)
- switched to objects handling through validation_radar_objects (encapsulation)
--- Added comments ---  uidu5218 [Mar 28, 2012 1:43:43 PM CEST]
Change Package : 97504:2 http://mks-psad:7002/im/viewissue?selection=97504
Revision 1.9 2012/03/27 16:28:27CEST Raedler-EXT, Guenther (uidt9430)
- use OBJ_START_INDEX instead of OBJ_OBJECT_INDEX which will be deleted
--- Added comments ---  uidt9430 [Mar 27, 2012 4:28:28 PM CEST]
Change Package : 88554:1 http://mks-psad:7002/im/viewissue?selection=88554
Revision 1.8 2011/12/15 14:22:51CET Raedler-EXT, Guenther (uidt9430)
- added signal name to ValGenericStateEvent
--- Added comments ---  uidt9430 [Dec 15, 2011 2:22:52 PM CET]
Change Package : 88150:1 http://mks-psad:7002/im/viewissue?selection=88150
Revision 1.7 2011/12/07 11:03:54CET Sampat-EXT, Janani Vasumathy (uidu5218)
-  added a method to return the radar object
--- Added comments ---  uidu5218 [Dec 7, 2011 11:03:55 AM CET]
Change Package : 88149:1 http://mks-psad:7002/im/viewissue?selection=88149
Revision 1.6 2011/11/29 13:03:18CET Sampat-EXT, Janani Vasumathy (uidu5218)
- stop_index calculation improved
--- Added comments ---  uidu5218 [Nov 29, 2011 1:03:18 PM CET]
Change Package : 88149:1 http://mks-psad:7002/im/viewissue?selection=88149
Revision 1.5 2011/11/04 14:07:42CET Raedler Guenther (uidt9430) (uidt9430)
- added new generic event for actice state changes
- extended base event
--- Added comments ---  uidt9430 [Nov 4, 2011 2:07:42 PM CET]
Change Package : 86868:1 http://mks-psad:7002/im/viewissue?selection=86868
Revision 1.4 2011/10/25 07:52:48CEST Raedler Guenther (uidt9430) (uidt9430)
- fixed error in duration calculation
--- Added comments ---  uidt9430 [Oct 25, 2011 7:52:48 AM CEST]
Change Package : 85000:1 http://mks-psad:7002/im/viewissue?selection=85000
Revision 1.3 2011/10/07 07:45:11CEST Raedler Guenther (uidt9430) (uidt9430)
- extened validation event class
- added new class for stationary obstacles
- added global defines
--- Added comments ---  uidt9430 [Oct 7, 2011 7:45:11 AM CEST]
Change Package : 76661:3 http://mks-psad:7002/im/viewissue?selection=76661
Revision 1.2 2011/09/20 11:30:37CEST Raedler Guenther (uidt9430) (uidt9430)
- added event class code into drop in and drop out observers
- moved port names from acc_global_defs into validation global defs
--- Added comments ---  uidt9430 [Sep 20, 2011 11:30:37 AM CEST]
Change Package : 76661:2 http://mks-psad:7002/im/viewissue?selection=76661
Revision 1.1 2011/08/25 13:51:02CEST Raedler Guenther (uidt9430) (uidt9430)
Initial revision
Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/05_Testing/05_Test_Environment/algo/
    ars301_req_test/valf_tests/vpc/project.pj
"""
