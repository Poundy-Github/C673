"""
@author: uidq3472
"""

# general imports
import xml.etree.ElementTree as et
from xml.dom import minidom
import logging
from xml_defs import *


class XMLParser:
    """Reads/Writes XML files in Context of Excel file tasks.
    
    :param str configuration_xml_path: a (relative) path to a XML configuration file
    """

    def __init__(self, configuration_xml_path):
        """Initializes the XMLParser and gets/handles user input."""

        # set up logging
        self.logger = logging.getLogger(__name__)
        self.logger.setLevel(logging.DEBUG)
        # avoid multiple handlers respectively logs
        if not len(self.logger.handlers):
            stream_handler = logging.StreamHandler()
            stream_handler.setLevel(logging.DEBUG)
            formatter = logging.Formatter("(l.%(lineno)d) - %(asctime)s - %(name)s - %(levelname)s - %(message)s")
            stream_handler.setFormatter(formatter)
            self.logger.addHandler(stream_handler)
            self.logger.info("Logger initialized.")
        else:
            self.logger.info("Logger reused.")

        # init some vars for this class
        self.configuration_xml = configuration_xml_path
        self.xml_root = None
        self.tree = None

        self.init_from_file()

    def init_from_file(self):
        """Initiliazes the xml tree from file."""
        self.read_xml(self.configuration_xml)
        # log some intermediate results
        self.logger.debug(
            "Initializing from file.\nXML: Sheet-Elements: {sheet_elems}".format(sheet_elems=self.get_sheet_names()))

    def init_new(self):
        """Creates new xml tree."""
        # TODO: find correct parameter for below line with warning
        self.logger.debug("Creating new XML file.")
        # TODO: fix below problem
        self.xml_root = et.Element(xml_root_tag, self._get_xml_attributes(xml_root_attributes, [self.excel_file_path]))
        # TODO: change line above this like all other
        self.tree = et.ElementTree(self.xml_root)

    def write_xml(self, out_path):
        """Writes xml tree to .xml-file
        
        :param str out_path: path (including filename) where output should be saved
        """
        try:
            with open(out_path, "w") as xmlfile:
                xmlfile.write(self.__str__())
        except IOError:
            self.logger.exception("Could not write XML file.")
        else:
            self.logger.info("Wrote XML to file: {0}".format(out_path))

    def read_xml(self, file_path):
        """Reads xml tree from existing source file.
        
        :param str file_path: a (relative) path to a XML configuration file
        """
        self.logger.info("Reading XML from file: {0}".format(file_path))
        try:
            # read existing xml file
            with open(file_path, "r") as xmlfile:
                self.tree = et.parse(xmlfile)
            # get xml root element of read xml tree
            self.xml_root = self.tree.getroot()
        except IOError:
            self.logger.exception("Could not read XML from file {0}".format(file_path))
        else:
            self.logger.info("Successfully read XML from file {0}".format(file_path))

    def __str__(self):
        """Returns String represenation of the xml tree."""
        # walk elements and strip blank spaces from them - kind of bugfix for 'toprettyxml()'
        self.strip(self.tree.getroot())
        # get string representation of xml tree and reparse for human readable output
        rough_string = et.tostring(self.tree.getroot(), encoding='utf8', method='xml')
        parsed_string = minidom.parseString(rough_string)
        return parsed_string.toprettyxml()

    def strip(self, element):
        """Removes leading and trailing spaces from elements and their texts.
        
        :param Element element: XML element which text is to be stripped
        """
        for element in element.iter():
            if element.text:
                element.text = element.text.strip()
            if element.tail:
                element.tail = element.tail.strip()

    def remove(self, element_tag, element_parent, element_attributes=None, element_values=None):
        """Looks for an element by its values and removes it from its parent. Returns True if element was found and removed and False if element could not be found.
        
        :param str element_tag: tag to be searched
        :param Element element_parent: parent element from which to start to search
        :param element_attributes: xml attribute keys
        :type element_attributes: list(str) or None
        :param element_values: values for each attr key
        :type element_values: list or None
        """
        element_to_remove = self._get_element(element_tag, element_parent, element_attributes, element_values)
        if element_to_remove is None:
            return False
        else:
            element_parent.remove(element_to_remove)
            return True

    def get_excel_path(self):
        """Returns the path to Excel file from XML configuration.
        
        :return: excel file path
        :rtype: str
        """
        return self.xml_root.attrib[excel_path_attr]

    def add_excel_configuration(self):
        """Adds a configuration element to the Excel file tag. Returns a Excel config element in each and every case.
        
        :return: Excel config element
        :rtype: xml.etree.ElementTree.SubElement
        """
        return self._add_element(root_configuration_tag, self.xml_root, root_config_attributes)

    def get_excel_configuration(self):
        """Returns Excel file tag`s configuration element.
        
        :return: Excel configuration element
        :rtype: xml.etree.ElementTree.SubElement or None
        """
        return self._get_element(root_configuration_tag, self.xml_root)  # , root_config_attrs)

    def add_sheet(self, sheet_name):
        """Adds a sheet element if not existing.  Returns a sheet element in each and every case.
        
        :return: sheet element
        :rtype: xml.etree.ElementTree.SubElement
        """
        return self._add_element(sheet_tag, self.xml_root, sheet_attributes, [sheet_name])

    def get_xml_sheet(self, sheet_name):
        """Returns a sheet element by its name.
        
        :param str sheet_name: name of an Excel sheet
        :return: sheet element
        :rtype: xml.etree.ElementTree.SubElement or None
        """
        return self._get_element(sheet_tag, self.xml_root, sheet_attributes, [sheet_name])

    def get_xml_sheets(self):
        """Returns all sheet elements.
        
        :return: list of sheet elements
        :rtype: list(xml.etree.ElementTree.SubElement)
        """
        return self._get_all(sheet_tag, self.xml_root)

    def get_sheet_configuration(self, sheet_element):
        """Returns the config of a given sheet.
        
        :param xml.etree.ElementTree.SubElement sheet_element:  sheet element where to look for config element
        :return sheet config element
        :rtype: xml.etree.ElementTree.SubElement
        """
        return self._get_element(sheet_configuration_tag, sheet_element, sheet_configuration_attributes)

    def get_sheet_names(self):
        """Returns names of all sheet elements.
        
        :return: sheet element names
        :rtype: list(str)
        """
        return [sheet.attrib[sheet_name_attr] for sheet in self.get_xml_sheets()]

    def add_table(self, sheet_element, table_id, table_start="", table_end="", header_rows=""):
        """Adds a table element if not existing. Returns a table element in each and every case.
        
        :param xml.etree.ElementTree.SubElement sheet_element:  sheet element where to add table element
        :param int table_id: id of the table
        :param str table_start: start cell of table in Excel notation
        :param str table_end: end cell of table in Excel notation
        :param int header_rows: row count of table header
        :return: table element
        :rtype: xml.etree.ElementTree.SubElement
        """
        return self._add_element(table_tag, sheet_element, table_attributes,
                                 [table_id, table_start, table_end, header_rows])

    def get_table(self, sheet_element, table_id):
        """Retuns a table element below a sheet element by its table id.
        
        :param xml.etree.ElementTree.SubElement sheet_element:  sheet element where to look for table element
        :param int table_id: id of the table
        :return: table element
        :rtype: xml.etree.ElementTree.SubElement or None
        """
        return self._get_element(table_tag, sheet_element, table_attributes, [table_id])

    def get_tables(self, sheet_element):
        """Returns all table elements below a sheet_element.
        
        :param xml.etree.ElementTree.SubElement sheet_element:  sheet element where to look for table element
        :return: list of table elements
        :rtype: list(xml.etree.ElementTree.SubElement)
        """
        return self._get_all(table_tag, sheet_element)

    def add_header(self, table_element):
        """Adds header element if not existing. Returns a header element in each and every case.
        
        :param xml.etree.ElementTree.SubElement table_element:  table element where to add header element
        :return: header element
        :rtype: xml.etree.ElementTree.SubElement
        """
        return self._add_element(header_tag, table_element)

    def get_header(self, table_element):
        """Returns a header element below a table element.
        
        :param xml.etree.ElementTree.SubElement table_element:  table element where to look for header element
        :return: header element
        :rtype: xml.etree.ElementTree.SubElement or None
        """
        return self._get_element(header_tag, table_element)

    def add_header_field(self, parent_element, title):
        """Adds a header field element to its parent. Which is either a header element or an other header field element.
        Returns a header field element in each and every case.
        
        :param xml.etree.ElementTree.SubElement parent_element: parent element where to add header field element
        :param str title: the title of the header field
        :return: header element
        :rtype: xml.etree.ElementTree.SubElement
        """
        return self._add_element(header_field_tag, parent_element, header_field_attributes, [title])

    def get_header_field(self, parent_element, title):
        """Returns a header field element below its parent element by its title.
        
        :param xml.etree.ElementTree.SubElement parent_element: parent element where to look for header field element
        :param str title: the title of the header field
        :return: header element
        :rtype: xml.etree.ElementTree.SubElement or None
        """
        return self._get_element(header_field_tag, parent_element, header_field_attributes, [title])

    def get_header_fields(self, parent_element):
        """Returns all header field elements below a parent element.
        
        :param xml.etree.ElementTree.SubElement parent_element: parent element where to look for header field elements
        :return: list fo header elements        
        :rtype: list(xml.etree.ElementTree.SubElement)
        """
        return self._get_all(header_field_tag, parent_element)

    def _get_all(self, _element_tag, _element_parent):
        """Returns all elements bewlo a parent element.
        
        :param str _element_tag: xml tag of an element
        :param xml.etree.ElementTree.SubElement _element_parent: parent element where to look for the xml tag
        :return: list of elements of specified tag
        :rtype: list(xml.etree.ElementTree.SubElement)
        """
        return _element_parent.findall(_element_tag)

    def _get_element(self, _element_tag, _element_parent, _element_attributes=None, _element_values=None):
        """Returns an element below a parent element by its attributes and values if provided. Returns an element in each and every case.
        
        :param str _element_tag: xml tag of an element
        :param xml.etree.ElementTree.SubElement _element_parent: parent element where to look for the xml tag
        :param list _element_attributes: list of attributes for specified tag
        :type _element_attributes: list or None
        :param list _element_values: list of values for attributes
        :type _element_values: list or None
        :return: element of specified tag
        :rtype: xml.etree.ElementTree.SubElement or None
        """
        if _element_attributes and _element_values:
            if not hasattr(_element_attributes, "__iter__"):
                _element_attributes = [_element_attributes]
            if not hasattr(_element_values, "__iter__"):
                _element_values = [_element_values]
            self.logger.debug("attrs: {0}; values: {1}".format(_element_attributes, _element_values))
            _xpath_str = ".//{tag}{attrs}".format(tag=_element_tag, attrs="".join(
                ["[@{0}=\"{1}\"]".format(attr, value) for attr, value in zip(_element_attributes, _element_values)]))
            value = _element_parent.find(_xpath_str)
            self.logger.debug("XPATH: {0}; Elements: {1}".format(_xpath_str,
                                                                 value))
            # TODO: make this pretty? mabye utility function for logging return values with *args?
            return value
        else:
            return _element_parent.find(_element_tag)

    def _add_element(self, _element_tag, _element_parent, _element_attributes=None, _element_values=None):
        """Adds an element to a given parent element with provided attributes and values.
        
        :param str _element_tag: xml tag of an element
        :param xml.etree.ElementTree.SubElement _element_parent: parent element where to look for the xml tag
        :param list _element_attributes: list of attributes for specified tag
        :type _element_attributes: list or None
        :param list _element_values: list of values for attributes
        :type _element_values: list or None
        :return: element of specified tag
        :rtype: xml.etree.ElementTree.SubElement
        """
        _element = self._get_element(_element_tag, _element_parent, _element_attributes, _element_values)
        if _element is None:
            _element = et.SubElement(_element_parent, _element_tag,
                                     self._get_xml_attributes(_element_attributes, _element_values))
        return _element

    def _get_xml_attributes(self, _element_attributes, _element_values=None, _default=None):
        """Returns attributes as a dictionary, populated with provided values or a default value.
        
        :param list _element_attributes: list of attributes
        :type _element_attributes: list
        :param list _element_values: list of values for attributes
        :type _element_values: list or None
        :param _default: default value if value list is shorter than attribute list
        :type _default: whichever value one uses
        :return: dictionary of combined attributes and values
        :rtype: dict(str, str)
        """
        if _default is None:
            _default = ""
        if _element_values is None:
            _element_values = []
        elif not hasattr(_element_values, "__iter__"):
            _element_values = [_element_values]
        attributes_dict = {}
        if _element_attributes:
            for idx, attr in enumerate(_element_attributes):
                attributes_dict[attr] = _element_values[idx] if (idx < len(_element_values)) else _default
        return attributes_dict
