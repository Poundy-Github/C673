"""
filter.py
-------------------

Definition of an acc events.
:org:           Continental AG
:author:        Zaheer Ahmed

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:45CET $

"""
import uuid
from xml.dom.minidom import parse, Document
from stk.db.val.val import COL_NAME_EVENTS_VIEW_BEGINABSTS, COL_NAME_EVENTS_VIEW_ENDABSTS, \
    COL_NAME_EVENTS_VIEW_TRID, TABLE_NAME_EVENTS_ATTRIBUTES_VIEW, COL_NAME_EVENTS_VIEW_EVENTTYPE, \
    COL_NAME_EVENTS_VIEW_NAME, COL_NAME_EVENTS_VIEW_VALUE, COL_NAME_EVENT_ATTR_TYPES_NAME
from  stk.db.db_sql import SQLBinaryExpr, OP_EQ, SQLLiteral, OP_AND, OP_OR, \
    SQLTableExpr, SQLColumnExpr, OP_SUB

NAME = "name"
ROOT_EVENT_FILTERING = "eventfiltering"
FILTERDATA = "filterdata"
FILTERDATA_FILTER = "filter"
FILTERDATA_FIELD = "field"
FILTERDATA_COMPARITOR = "comparitor"
FILTERDATA_VALUE = "value"
FILTERDATA_VTYPE = "vtype"
FILTERDATA_ATTRIB_DURATION = "Duration"

FILTERMAPDATA = "filtermapdata"
FILTERMAPDATA_FILTERMAP = "filtermap"
FILTERMAPDATA_DESCRIPTION = "description"
FILTERMAPDATA_STATEMENT = "statement"
FILTERMAPDATA_FILTER_JOINS = [OP_AND, OP_OR]


class ValBaseFilter(object):
    """Base class for filter"""
    def __init__(self, filetpath, trid=None):
        """
        Constructor for Base Filter Class
        :param trid: Test Run ID
        """
        self._trid = trid
        self._dom_file_path = filetpath
        self._dom = None
        self.__filtermapdoms = None
        self.__filtermaps = {}
        self.__filterdoms = None
        self.__filters = {}
        self._cond = {}

    def _ReadXMLConfig(self):
        """
        Parse the XML filter setting file and Prepare list of Filtermaps Tags and Filters Tag
        :param filter_file_path: path to filter setting file
        """
        try:
            self._dom = parse(self._dom_file_path)
        except Exception:
            raise StandardError("Failed to read the xml config or the files doesnt exist")

        self.__filtermapdoms = self._dom.getElementsByTagName(FILTERMAPDATA_FILTERMAP)
        self.__filterdoms = self._dom.getElementsByTagName(FILTERDATA_FILTER)
        self.__filtermaps = {}
        self.__filters = {}
        self._cond = {}
        for filterdom in self.__filterdoms:
            dom_dict = self.GetAttributeDict(filterdom)
            self.__filters[dom_dict[NAME]] = dom_dict

        for filtermapdom in self.__filtermapdoms:
            dom_dict = self.GetAttributeDict(filtermapdom)
            self.__filtermaps[dom_dict[NAME]] = dom_dict

    def GetFilterMaps(self):
        """
        Return list of Filtermap data as dict
        """
        return self.__filtermaps

    def GetFilterMapNames(self):
        """
        Return list of Filtermap names as list
        """
        return self.__filtermaps.keys()

    def GetFilters(self):
        """
        Return list of Filter data  as dict
        """
        return self.__filters

    def GetFilterNames(self):
        """
        Return list of Filtermap names as list
        """
        return self.__filters.keys()

    def GetFilterMap(self, name):
        """
        Get the Filter Tag for the given name
        :param name: Name of the Filtermap
        :return filter_map: Dictionary format filter map
        """
        if name in self.__filtermaps:
            return self.__filtermaps[name]
        else:
            return None

    def GetFilter(self, name):
        """
        Get the Filter Tag for the given name
        :param name: Name of the Filter
        :return filter: Dictionary format filter entry
        """
        if name in self.__filters:
            return self.__filters[name]
        else:
            return None

    def GetAttributeDict(self, minidom_attribute):  # pylint: disable=R0201
        """
        Genertic function to convert minidom into Dictionary
        :param minidom_attribute: Minidom reference for filter or filtermap
        :return minidom_attri_dict: return minidom data into dictionary format
        """
        minidom_attri_dict = {}
        keys = minidom_attribute.attributes.keys()
        for key in keys:
            minidom_attri_dict[key] = minidom_attribute.getAttribute(key).strip()

        return minidom_attri_dict

    def GetValue(self, value, vtype):  # pylint: disable=R0201
        """
        Genertic function to type cast the data to be use in building SQLBinaryExpression
        :param value: value in String format
        :param  vtype: Value type
        :return Typcasted value according to vtype
        """
        if vtype == "float":
            return float(value)
        elif vtype == "int":
            return int(value)
        elif vtype == "str":
            return str(SQLLiteral(value))

    def GetFilterMapDoms(self, name=None):
        """
        Get the list of all doms under <filtermapdata> tag
        param name: attribute value for NAME in the dom
        :return if the name is passed then only desired dom is return else whole list of dom
        """
        if name is None:
            return self.__filtermapdoms
        else:
            for dom in self.__filtermapdoms:
                if dom.getAttribute(NAME) == name:
                    return dom
        return None

    def GetFilterDoms(self, name=None):
        """
        Get the list of all doms under <filterdata> tag
        param name: attribute value for NAME in the dom
        :return if the name is passed then only desired dom is return else whole list of dom
        """
        if name is None:
            return self.__filterdoms
        else:
            for dom in self.__filterdoms:
                if dom.getAttribute(NAME) == name:
                    return dom
        return None

    def GetFilterMapSqlExpression(self, filtermap_name):
        """
        Return SQLBinaryExpression for the given filtermap name
        :param filtermap_name: Filter MAP name
        :return: SQLBinaryExpression corresponding to filtermap name
        """
        if filtermap_name in self._cond:
            return self._cond[filtermap_name]
        else:
            return None


class ValEventFilter(ValBaseFilter):
    """Child to implement filter Class specific to events"""

    def __init__(self, file_path, trid=None):
        """
        Constructor for the inhertited class specific to Events
        :param trid: Test Run ID
        :param  file_path: Path XML filter setting file
        """
        ValBaseFilter.__init__(self, file_path, trid)
        self.__attribute_name_list = None

    def __GetAttributeValue(self, key, attribute_dict):  # pylint: disable=R0201
        """
        Genertic function to return value for the given key of dictionary
        :param key: Key of the dictionary
        :param  attribute_dict: Dictionary
        :return attribute_dict[key]: The correspoinding value for the key in the dictionary
        """
        if key in attribute_dict:
            return attribute_dict[key]
        else:
            return None

    def __GetEventFilterSqlExpression(self, ev_filter):
        """
        Genertic Function to build SQLBinaryExpression for the given Filter
        :param ev_filter: Minidom XML filter entry
        :return SQLBinaryExpression representing filter for Database
        """
        field_name = self.__GetAttributeValue(FILTERDATA_FIELD, ev_filter)
        comp = self.__GetAttributeValue(FILTERDATA_COMPARITOR, ev_filter)
        value = self.GetValue(self.__GetAttributeValue(FILTERDATA_VALUE, ev_filter),
                              self.__GetAttributeValue(FILTERDATA_VTYPE, ev_filter))

        if field_name in self.__attribute_name_list:
#                if the field is Attribute
            name_cond = SQLBinaryExpr(COL_NAME_EVENTS_VIEW_NAME, OP_EQ, SQLLiteral(field_name))
            val_cond = SQLBinaryExpr(COL_NAME_EVENTS_VIEW_VALUE, comp, value)
            return SQLBinaryExpr(name_cond, OP_AND, val_cond)

        elif field_name == FILTERDATA_ATTRIB_DURATION:
#                special case for event duration if it is not an attribute
            field_name = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(TABLE_NAME_EVENTS_ATTRIBUTES_VIEW),
                                                     COL_NAME_EVENTS_VIEW_ENDABSTS), OP_SUB,
                                       SQLColumnExpr(SQLTableExpr(TABLE_NAME_EVENTS_ATTRIBUTES_VIEW),
                                                     COL_NAME_EVENTS_VIEW_BEGINABSTS))

        return SQLBinaryExpr(field_name, comp, value)

    def __SetAtttribute_list(self, dbi_val):
        """
        Supporting function to initialize the list of attribute list registered in database
        @param dbi_val: Val Database interface object
        """

        if dbi_val is not None:
            self.__attribute_name_list = []
            attribute_type_records = dbi_val.GetEventAttributeType()
            for attrib_rec in attribute_type_records:
                self.__attribute_name_list.append(attrib_rec[COL_NAME_EVENT_ATTR_TYPES_NAME])

    def Load(self, dbi_val, filtermap_name=None):
        """
        Load filter data from Xml file
        :param dbi_val: Val Database interface reference
        :param filtermap_name: name of the filter map
        :return if the no filtermap_name passed then only boolean status for decoding is return
                if the filtermap_name is passed then statement is return
                if the filtermap_name doesnt exist in config then NoneType is return
        """

        self.__SetAtttribute_list(dbi_val)
        load_status = self.__DecodeEventFilters()
        if filtermap_name is None:
            return load_status
        else:
            statement = []
            filter_mapdict = self.GetFilterMap(filtermap_name)
            if filter_mapdict is not None:
                for entry in filter_mapdict[FILTERMAPDATA_STATEMENT].split(" "):
                    if entry not in FILTERMAPDATA_FILTER_JOINS:
                        filter_dict = dict(self.GetFilter(entry))
                        filter_dict.pop(NAME)
                        statement.append(filter_dict)
                    else:
                        statement.append(entry)

                return statement
            else:
                return None

    def Save(self, filtermap_name, statement, desc=" ", overwrite=False):
        """
        Add/Update filter Entry
            if the filter is already is existing then orverwrite it

        :param filtermap_name: name of the filter map
        :type filtermap_name: string
        :param statement: filter data entries please refer to example at the end of dco String
        :type statement: list
        :param desc: description of filter
        :type desc: string
        :param overwrite: flag to overwrite the existing file
        :type overwrite: boolean
        :return: returns boolean True if the Save is successful

        example of statement passed from Assessment tool for saving
        statement = [{"field": "vehspeed", "comparitor": ">", "value": "22.22", "vtype": "float"}, "and",
                    {"field": "assessment", "comparitor":"=", "value": "Invalid", "vtype": "str"}]
        """

        filtermap_statement = ""
        if overwrite:
            self._dom = Document()
            event_filter = self._dom.createElement(ROOT_EVENT_FILTERING)
            event_filter.appendChild(self._dom.createElement(FILTERDATA))
            event_filter.appendChild(self._dom.createElement(FILTERMAPDATA))
            self._dom.appendChild(event_filter)
            self._dom.writexml(open(self._dom_file_path, 'wb'), "    ", "    ", "\n")
            self._dom.unlink()

        self._ReadXMLConfig()
#        Check if the filters already exist and delete it
        if self.GetFilterMap(filtermap_name) is not None:
            self.Delete(filtermap_name)

        for stat in statement:

            if type(stat) is dict:
                filter_dom = self._dom.createElement(FILTERDATA_FILTER)
                for key, value in stat.items():
                    filter_dom.setAttribute(key, value)
                filter_name = str(uuid.uuid4())
                filter_dom.setAttribute(NAME, filter_name)
                self._dom.getElementsByTagName(FILTERDATA)[0].appendChild(filter_dom)
                filtermap_statement += filter_name
            elif stat.upper() in FILTERMAPDATA_FILTER_JOINS:
                filtermap_statement += " %s " % stat.upper()

        filtermap_dom = self._dom.createElement(FILTERMAPDATA_FILTERMAP)
        filtermap_dom.setAttribute(NAME, filtermap_name)
        filtermap_dom.setAttribute(FILTERMAPDATA_DESCRIPTION, desc)
        filtermap_dom.setAttribute(FILTERMAPDATA_STATEMENT, filtermap_statement)
        self._dom.getElementsByTagName(FILTERMAPDATA)[0].appendChild(filtermap_dom)
        self._dom.writexml(open(self._dom_file_path, 'wb'), "    ", "    ", "\n")
        return True

    def Delete(self, filtermap_name, save=False):
        """
        Delete the filter of the specified name

        :param filtermap_name: Name of the Filter map
        :type filtermap_name: String
        :param save: flag to write changes into filter config XML file
        :type save:  boolean
        :return: returns boolean True if the delete is successful
        """

        if self.GetFilterMapDoms() is None:
            self._ReadXMLConfig()

        statement = self.GetFilterMap(filtermap_name)[FILTERMAPDATA_STATEMENT]

        for stat in statement.split(" "):

            if stat not in FILTERMAPDATA_FILTER_JOINS:
                filter_dom = self.GetFilterDoms(stat)
                self._dom.getElementsByTagName(FILTERDATA)[0].removeChild(filter_dom)

        filtermap_dom = self.GetFilterMapDoms(filtermap_name)
        self._dom.getElementsByTagName(FILTERMAPDATA)[0].removeChild(filtermap_dom)
        if save:
            self._dom.writexml(open(self._dom_file_path, 'wb'), "    ", "    ", "\n")
            self._ReadXMLConfig()
        return True

    def __DecodeEventFilters(self):
        """
        Decode Filter XML filter setting file for EVENT and Prepare all the statements for Filtermaps
        :param file_path: Path to filter setting XML file
        """
        self._ReadXMLConfig()
        filtermaps = self.GetFilterMaps()
        filters = self.GetFilters()

        for filtermap_key, filtermap_domdict in filtermaps.items():

#            filtermap_dict = self.__GetAttributeValue(filtermap)
            if FILTERMAPDATA_STATEMENT in filtermap_domdict:
                cond = None
                statement = filtermap_domdict[FILTERMAPDATA_STATEMENT].strip()
                relation = None
                for entry in statement.split(" "):

                    if entry.upper() in FILTERMAPDATA_FILTER_JOINS:
                        if cond is None:
                            raise StandardError("The filter configuration are invalid")
                        else:
                            relation = entry
                    else:
                        if cond is None:
                            cond = self.__GetEventFilterSqlExpression(filters[entry])
                        else:
                            if relation is None:
                                raise StandardError("The filter configuration are invalid")
                            else:
                                cond = SQLBinaryExpr(cond, relation.upper(),
                                                     self.__GetEventFilterSqlExpression(filters[entry]))
                                relation = None

                if self._trid is not None:
                    if cond is not None:
                        cond = SQLBinaryExpr(cond, OP_AND, SQLBinaryExpr(COL_NAME_EVENTS_VIEW_TRID, OP_EQ, self._trid))
                    else:
                        cond = SQLBinaryExpr(COL_NAME_EVENTS_VIEW_TRID, OP_EQ, self._trid)

                self._cond[filtermap_key] = cond

        return True
