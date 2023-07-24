TODOs and other stuff
=====================
dumping
-------

* if read workbook and afterwards using the saved dump: use directly the dump_dict instead of reading from file?
* add more information! e.g. like in ResSheet: references for easy access
* multiple dumps, z.B. fuer crossreferencing dann oder so? bzw. wenn man mehrere Excelfiles zusammen verwenden will?
  - irgendwie in eine einzelne Klasse rein statt wie jetzt einen Reader fuer jedes


dataobjects
-----------
ExcelTableObject:

* add offset of column and row for search? (so one just has to type in from excel)
    - add Header-Classes? (with lists (or ordered dicts?), ranges and other useful information? add also to xml(-creator))
    - other dataobjects structures? e.g. with respect to dataobjects elements later to be stored with the header information 
    - add readable print/debug of header 
    - add docstrings
    
* refactor (together with library wrappers; move functionalities here or make it more clearly in other ways what is expected as params for below methods)
* Classes for header and dataobjects segment?
* remove some parameters?
* stuff for those classes?
    

libwrappers
-----------
Contains wrapper for excel libraries, their main wrapper which serves as kind of connector/interface, and the wrapper base class.

* has to initialize and maybe instantly read a excel object; (opt: multiple Exel objects, even for cross referencing between different excel files? e.g. via global dictionary for search queries)
* optional file for options, like a list of sheets to use instead of loading all sheets?
* add default reading behaviour for tables in xml
    - also add different defaults or kind of schemes
    
TODOs:

* use "specials"/parameter of the libraries in their functions
* catch exceptions and improve error handling/printing
* kwargs, using dicts as vars (?) because of variable amount of headers, captions etc.
   
save_methods for xml: 

* use xpath?
* create kind of generalized "save element" method
* save list of something else additionally to the dict?
* or save as dump?
    
	
close/save/write:

* option discard/save changes 
* path, saveAs, name 

* maybe create multiple versions of get/search sheet, via index, name, regex 


get_sheets:

* get all sheets from the workbook; best would be to create kind of interface in order to provide the same access possibilities (e.g. dataobjects types) for all libraries
* mabye extra version to get just some sheets meeting conditions (via regex e.g.)
* has to work in such a way that the outputs of all libraries are the same. I.d., every library returns e.g. the sheets as his sheet objects. Because those sheets have different parameters, methods etc., we have to wrap them and turn them into internal methods not to be used directly!
  
  
wrapper_main:

* fill in or move this to another module/class
* improve exception handling  
    
	
xlrd_wrapper:

* ToDos still in file
    
	
utils
-----
TODOs/Ideas:

* add general parsing functions, e.g. for ints, floats, percentage values, texts, ... , constants
* return corrected index, if order is wrong

* maybe add kind of match group generation with dicts and string formatting? maybe combine with search tool 


xmldescriptor
-------------
Excel_config: 

* think about possible defaults and helpful configs, e.g. dumps, crossreferencing, ... or better as attrs for root tag???


get_xml_attrs:

* maybe adapt default value
* maybe use zip and dict constructor?


unordered_tree
--------------

* might profit from a extra and mor general base class
