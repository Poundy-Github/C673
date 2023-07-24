XML-Template for XML-Configuration-File
=======================================

XML-Template
------------
Following code block shows an example XML-Configuration-File with its different tags.


.. code-block:: xml
	:linenos:

	<?xml version="1.0" ?>
	<!-- <excel_file> is the root tag. -->
	<excel_file file_path="<relative_path_to_excel_file>">
		<!-- <excel_config> is a tag for configuration details 
		on the level of the whole document. -->
		<excel_config dump_path=""/>
		<!-- <excel_sheet> is a tag representing one sheet of 
		an Excel workbook. You may add more as required. -->
		<excel_sheet sheet_name="<excel_sheet_name>">
			<!-- <table> is a tag used for defining the range of a table. 
			You may add more as required. -->
			<table header_rows="2" table_end="A1" table_start="E20"/>
			<table header_rows="1" table_end="A22" table_start="E42"/>
		</excel_sheet>
	</excel_file>
	
	
XML-Tags
--------

Short description for all XML-tags and their usage goes here.


**<excel_file>**
	Has a non-optional attribute *file_path* which takes a relative path to the Excel file to be used.
	It is the root tag.

**<excel_config>**
	Can hold multiple (optional) attributes and is a child tag of <excel_file> with 0 to 1 occurrences. Is used to define configuration details for this Excel file.
	E.g. defining defaults for processing, like table formats.
	
	*	*dump_path* takes a path for an dump file if one should be created
	
**<excel_sheet>**
	Has a non-optional attribute *sheet_name* which takes the name of the sheet in Excel file. 
	I.d. the name of the tab in Excel. It is a child tag of <excel_file> with 0 to n occurrences.
	
**<table>**
	Has non-optional attributes *header_rows*, *table_start* and *table_end* and is a child tag of <excel_sheet>
	with 1 to n occurrences.
	
	*	*header_rows* takes the count of lines of a table header as an integer value.
	
	*	*table_start* takes the xy-value of the cell marking the start of a table in Excel notation. 
		(E.g. 'A1')
	
	*	*table_end* takes the xy-value of the cell marking the end of a table in Excel notation.
		(E.g. 'E20')



Future Work
-----------

* Infos im XML ablegen, Configs, …
	- Header adden? (also erzeugte in xml ablegen)
	- Xml definition erzeugen?
* Cell-Groups lesen oder nur Teile von Tabellen (in xml z.B. festlegen)
	- Sachen in Groups zerlegen?
* Was in das config Tag rein?
* Wie Zeug handlen, das keine (üblichen) Tabellen sind? Spezielle Zeilen, freier Text…, dafür extra Tags anlegen und iwie indizierte Speichermöglichkeit (Dictionary) in der Datenstruktur anlegen?
* Xml:
	- Kann ich lesen/schreiben/bearbeiten mehr/besser trennen?
* Xml-creation und dump creation irgendwie separat machen?
	- Bessere Trennung der Komponenten erzielen
* In xml Pfade bestimmter Dateien speichern? (Z.B. auch welches Excel genau verwendet wird!)
* DTD/Schema anlegen und validator dazu heranziehen
* Infos im XML ablegen, Configs, …
