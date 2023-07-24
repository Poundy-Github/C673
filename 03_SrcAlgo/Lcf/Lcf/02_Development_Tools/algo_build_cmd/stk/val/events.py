"""
stk/val/events.py
-------------------

 Subpackage for Handling Events Class and States

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:44CET $
"""
import os
import logging
import stk.db.gbl.gbl as db_gbl
import stk.db.val.val as db_val
import stk.db.cat.cat as db_cat

from stk.db.db_common import SQLite3BaseDB
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
    COL_NAME_EVENTS_RDID, COL_NAME_EVENTS_VIEW_NAME, COL_NAME_EVENTS_VIEW_VALUE

from stk.db.gbl.gbl import COL_NAME_UNIT_ID, COL_NAME_UNIT_NAME, COL_NAME_UNIT_TYPE, COL_NAME_UNIT_LABEL
from asmt import ValAssessment
from stk.db.gbl import GblUnits
from result_types import BaseUnit, BaseValue, ValueVector, Signal, Histogram, ValSaveLoadLevel
from stk.valf import PluginManager
from base_events import ValBaseEvent, ValEventError
from stk.util.helper import ListFolders

HEAD_DIR = os.path.abspath(os.path.join(os.path.dirname(os.path.split(__file__)[0]), ".."))
EVENT_PLUGIN_FOLDER_LIST = []
for folder_path in ListFolders(HEAD_DIR):
    EVENT_PLUGIN_FOLDER_LIST.append(folder_path)


class ValEventList():
    """ ValEventLoader Class - loads Event details from Database """
    def __init__(self, plugin_folder_list=EVENT_PLUGIN_FOLDER_LIST, ev_filter=None):
        '''
        Constructor taking database connection
        @param db: Database Connection Dict
        '''
        self.__plugin_folders = plugin_folder_list
        self.__plugin_manager = None
        self.__event_types_list = None
        self.__event_list = []
        self.__event_inst_created = []
        self.__filter = ev_filter

    def __del__(self):
        """
        Destructor
        """
        self.__event_list = []

    def __InitEventTypes(self, plugin_folders=None):
        """ Init the Plugin """
        new_plugin = False

        if plugin_folders is not None:
            new_plugin = True
            self.__plugin_folders = plugin_folders
        if self.__plugin_manager is None or new_plugin:
            self.__plugin_manager = PluginManager(self.__plugin_folders, ValBaseEvent)

        if self.__event_types_list is None:
            self.__event_types_list = self.__plugin_manager.get_plugin_class_list(remove_duplicates=True)

    def __CreateEvent(self, dbi_val, dbi_gbl, event_record, obs_name=None, level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC):
        """ Creates an instance of the corresponding event class
        @param event_record: Loaded event data from DB
        @return: Event object
        """
        event = None
        if event_record[COL_NAME_EVENTS_SEID] not in self.__event_inst_created:
            classname = event_record[COL_NAME_EVENTS_VIEW_CLASSNAME]

            for eType in self.__event_types_list:
                if eType['name'] == classname:
                    cls = eType['type']

            # create new object and call the constructor
            event = object.__new__(cls)
            if COL_NAME_EVENTS_RESASSID in event_record:
                asmt_id = event_record[COL_NAME_EVENTS_RESASSID]

            event.__init__(start_time=event_record[COL_NAME_EVENTS_VIEW_BEGINABSTS],
                           start_index=event_record[COL_NAME_EVENTS_VIEW_START_IDX],
                           stop_time=event_record[COL_NAME_EVENTS_VIEW_ENDABSTS],
                           stop_index=event_record[COL_NAME_EVENTS_VIEW_STOP_IDX],
                           seid=event_record[COL_NAME_EVENTS_VIEW_SEID],
                           assessment_id=asmt_id)
            event.SetEventSeid(event_record[COL_NAME_EVENTS_SEID])
            event.SetMeasId(event_record[COL_NAME_EVENTS_MEASID])
            if level & ValSaveLoadLevel.VAL_DB_LEVEL_2:
                asmt = ValAssessment()
                asmt.Load(asmt_id, dbi_val, dbi_gbl, obs_name)
                event.AddAssessment(asmt)

            if level & ValSaveLoadLevel.VAL_DB_LEVEL_3:
#                event_details = dbi_val.GetEventDetails(seid=event_record[COL_NAME_EVENTS_VIEW_SEID])
                event_attribs = dbi_val.GetEventsAttributesView(seid=event_record[COL_NAME_EVENTS_VIEW_SEID])
                for event_attrib in event_attribs:
                    attrib_type = dbi_val.GetEventAttributeType(name=event_attrib[COL_NAME_EVENTS_VIEW_NAME])
                    if attrib_type[0][COL_NAME_EVENT_ATTR_TYPES_UNITID] is not None:
                        unit = dbi_gbl.GetUnit(uid=attrib_type[0][COL_NAME_EVENT_ATTR_TYPES_UNITID])
                        unit = unit[COL_NAME_UNIT_NAME]
                    else:
                        unit = None
                    image = dbi_val.GetEventImage(event_attrib[COL_NAME_EVENT_IMG_ATTRID])
                    if len(image):
                        image = image[COL_NAME_EVENT_IMG_IMAGE]
                    else:
                        image = None
                    event.AddAttribute(event_attrib[COL_NAME_EVENTS_VIEW_NAME],
                                       value=event_attrib[COL_NAME_EVENTS_VIEW_VALUE],
                                       unit=unit, image=image)

        return event

    def Load(self, dbi_val, dbi_gbl, testrun_id, coll_id=None, meas_id=None,
             rd_id=None, obs_name=None, level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             beginabsts=None, endabsts=None, asmt_state=None, filter_cond=None, plugin_folders=None, cons_key=None):
        """ Load the result
        :param dbi_val: Validation Database interface
        :param dbi_gbl: Global Database interface
        :param testrun_id: Testrun Identifier
        :param coll_id: collection Identifier
        :param meas_id: Measurement Identifier
        :param rd_id: Result Descriptor Identifier
        :param obs_name: Observer Name
        :param level: Database load/store level
        :param beginabsts: Start of the events
        :param endabsts: End of the events
        :param asmt_state: Assessment State
        :param filter_cont: Name of the selected filter condition
        :param cons_key: contraint key
        """
        ret = False
        cond = None
        self.__event_list = []

        if filter_cond is not None:
            if self.__filter is not None:
                if self.__filter.Load(dbi_val):
                    cond = self.__filter.GetFilterMapSqlExpression(filter_cond)
                    if cond is None:
                        logging.error("The map filter was invalid. Events will be loaded without filter")
                else:
                    logging.error("Couldn't load events without filter configuration")
                    return ret
            else:
                logging.error("Couldn't load events without filter configuration")
                return ret

        rd_list = []
        if rd_id is not None:
            rd_list = dbi_val.GetResulsDescriptorChildList(rd_id)
            if len(rd_list) == 0:
                rd_list = [rd_id]

        for rdid in rd_list:
            # add filter loading
            if level > ValSaveLoadLevel.VAL_DB_LEVEL_2:
                events_record = dbi_val.GetEventsAttributesView(measid=meas_id, trid=testrun_id,
                                                                beginabsts=beginabsts,
                                                                endabsts=endabsts, assessment=asmt_state,
                                                                rdid=rdid, cond=cond)
            else:
                events_record = dbi_val.GetEventsView(measid=meas_id, trid=testrun_id,
                                                      beginabsts=beginabsts, endabsts=endabsts,
                                                      assessment=asmt_state, rdid=rdid, cond=cond)

            if len(events_record) > 0:
                self.__InitEventTypes()

            for record in events_record:
                event = self.__CreateEvent(dbi_val, dbi_gbl, record, obs_name, level)
                if event is not None:
                    # ass_id = event.GetAssessment().GetId()
                    self.__event_inst_created.append(event.GetEventSeid())
                    self.__event_list.append(event)
                    ret = True

        return ret

    def Save(self, dbi_val, dbi_gbl, testrun_id,
             coll_id,
             obs_name=None,
             parent_id=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None):
        """ Save the result
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

        for evt in self.__event_list:
            try:
                res = evt.Save(dbi_val, dbi_gbl, testrun_id, coll_id, evt.GetMeasId(),
                               obs_name, parent_id, level, cons_key)
            except ValEventError, ex:
                logging.warning("Events %s could not be stored. See details: %s " % (str(evt), ex))
                res = False

            if res is False:
                break

        if res is True:
            dbi_val.Commit()
            dbi_gbl.Commit()

        return res

    def AddEvent(self, event):
        """ Add a new event to the events list """
        if issubclass(event.__class__, ValBaseEvent):
            self.__event_list.append(event)

    def GetEvents(self):
        """ Get the loaded events """
        return self.__event_list
