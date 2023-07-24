#!/usr/bin/python
# -*- coding: utf-8 -*-

#***************************************************************************************************
import sys
import re
import glob
import os
import datetime
import optparse
import win32api
from   win32com.client import gencache, constants


#***************************************************************************************************
# CONSTANTS -> CONFIGURATION
#***************************************************************************************************

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# "S00_ALL/04_Engineering/04_Build/out/" relative to the location of this file
#
# Please use POSIX directory separator (/)
#
BASE_PATH = os.path.abspath( os.path.join( __file__, u'../../../../04_Build/out' ) )

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Template path to the config files, with placeholder for project and core
#
# Please use POSIX directory separator (/)
#
CONFIG_PATH = u'{PROJECT}/{CORE}/configPkg/package/cfg'


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Name of the generated header file without extention
#
# The generated files are located at BASE_PATH/PROJECT/xxx_FILE_NAME
#
FILE_NAME   = u'xdc_module_and_error_ids'


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Name of the generated header file
#
# The generated file is located at BASE_PATH/PROJECT/HEADER_FILE_NAME
#
HEADER_FILE_NAME = FILE_NAME + u'.h'


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Name of the generated excel file
#
# The generated file is located at BASE_PATH/PROJECT/EXCEL_FILE_NAME
#
EXCEL_FILE_NAME = FILE_NAME + u'.xlsx'


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Template for the header file.
#
# It contains all necessary informations or placeholder for the information
#
# HEADER_UPPERCASE  => header file name in upper case. Dot . is replaced with the underscore _
# HEADER            => header file name as given in HEADER_FILE_NAME
# DATE_TIME         => Date and time at generation of this file
# USER              => Logged in user name (uid...)
# STRUCTS           => All generated module and error id structs
# MAIN_STRUCT       => Struct which contains all generated structs. This is done for better readability in MTS software
#
TEMPLATE_FILE = u'''#ifndef {HEADER_UPPERCASE}
#define {HEADER_UPPERCASE}
/*
 * {HEADER}
 *
 * This file is automatically generated
 *
 *  Created on: 08.04.2015
 *      Author: uidg9452
 *
 * Generated on: {DATE_TIME}
 *       Author: {USER}
 */


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "glob_type.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
{STRUCTS}
{MAIN_STRUCT}


#define SW_MEAS_VADDR_XDC_IDS    0x82150B00U
#define SW_MEAS_CYCID_XDC_IDS    TASK_ID_S12

typedef {MAIN_STRUCT_NAME} {MAIN_STRUCT_NAME}_Xdc_Ids; /* @vaddr:SW_MEAS_VADDR_XDC_IDS @cycleid:SW_M3_0_ENV @vname:Xdc_Ids */

#endif
'''


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Template for struct geneation
#
# VALUE => Generated content of the struct
# NAME  => Name of the struct
#
TEMPLATE_STRUCT = u'''
typedef struct
{
{VALUE}
} {NAME};'''


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Template for for error id struct name
#
# CORENAME  => name of the core
#
TEMPLATE_ERROR_ID_STRUCT = u'IS_t_XdcErrorIds__{CORENAME}'


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Template for formoduleerror id struct name
#
# CORENAME  => name of the core
#
TEMPLATE_MODULE_ID_STRUCT = u'IS_t_XdcModuleIds__{CORENAME}'


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Name of the main struct, which combines all generated module and error id structs into one big
# struct.
#
# This is done to keep the ids together and to achieve a better readability in the MTS software.
#
MAIN_STRUCT_NAME = u'IS_t_XdcModuleAndErrorIds'



#***************************************************************************************************
# REGULAR EXPRESSIONS
#***************************************************************************************************

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression for testing directory to be a project directory
#
REGEX_PROJECT       = re.compile( r's?mf[c|f|l|s]|(ars)|(hlf)?[a-z0-9]+', re.IGNORECASE )


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression to find all debug out directories in a project path
#
REGEX_DEBUG_CORE    = re.compile( r'debug_[a-z0-9\-_]+',    re.IGNORECASE )


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression to find all release out directories in a project path
#
REGEX_RELEASE_CORE  = re.compile( r'release_[a-z0-9\-_]+',  re.IGNORECASE )


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression to get the core name from path
#
REGEX_CORE_NAME     = re.compile( r'[release|debug]_([a-z0-9\-_]+)',  re.IGNORECASE )


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression to get the error name and the error id from the C file
#
REGEX_ERROR_ID      = re.compile( r'/\* (E_.*)__C \*/\s+__FAR__ const CT_.*\(xdc_runtime_Error_Id\)([0-9]+)\) << ([0-9]+) \| ([0-9]+)\);' )


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression to get the module name and module content from the XML file
#
REGEX_MODULE        = re.compile( r'<module (?:name|id)=(?:"|\')(.*?)(?:"|\')((?:(?!</?module)[\s\S])*)' )


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Regular expression to get the module id from the module content
#
REGEX_MODULE_ID     = re.compile( r'name=(?:"|\')Module__id(?:"|\')(?:>(.*?)<| type="number" value="(.*?)"/>)' )



#***************************************************************************************************
# CLASSES
#***************************************************************************************************

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Wrapper for write data into a excel document.
#
# This class uses the win32 COM interface to instrument a installed excel. The class wrappes the
# most used functions.
#
class Excel( object ):

  #-------------------------------------------------------------------------------------------------
  # CONTRUCTOR
  #-------------------------------------------------------------------------------------------------
  def __init__( self ):

    object.__init__( self )

    try:
      self.xlApp = gencache.EnsureDispatch('Excel.Application')
    except IOError:
      self.xlApp = gencache.EnsureDispatch('Excel.Application')

    self.xlApp.Visible = 0

    self.xlApp.Workbooks.Add()

    self.xlApp.ActiveWorkbook.Worksheets(3).Delete()
    self.xlApp.ActiveWorkbook.Worksheets(2).Delete()

    self.xlApp.ActiveWorkbook.Worksheets(1).Activate()
    self.activeSheet = self.xlApp.ActiveSheet


  #-------------------------------------------------------------------------------------------------
  # PUBLIC
  #-------------------------------------------------------------------------------------------------

  #-------------------------------------------------------------------------------------------------
  def writeRow( self, row, array ):

    for col, entry in enumerate( array ):

      self.activeSheet.Cells(row + 1, col + 1).Value = unicode( entry )


  #-------------------------------------------------------------------------------------------------
  def getColumnName( self, number ):

    A     = ord( 'A' )
    Z     = ord( 'Z' ) - A + 1
    char  = ''

    while True:
      number, mod = divmod( number, Z )
      char        = chr( mod + A ) + char
      number     -= 1

      if number < 0:
        break

    return char


  #-------------------------------------------------------------------------------------------------
  def getRange( self, rowStart, colStart, rowEnd, colEnd ):

    charStart = self.getColumnName( colStart )
    charEnd   = self.getColumnName( colEnd )

    return u'%s%d:%s%d' % ( charStart, rowStart + 1, charEnd, rowEnd + 1 )


  #-------------------------------------------------------------------------------------------------
  def formatRange( self, rowStart, colStart, rowEnd, colEnd, format ):

    """ Example:
        format = { 'Font.Bold'            : True,
                   'HorizontalAlignment'  : 'constants.xlCenter',
                   'Borders(4).LineStyle' : 1,
                   'Borders(4).Weight'    : 3,
                   'NumberFormat'         : '#.##0,00_ ;-#.##0,00',
                  }
    """

    range = self.getRange( rowStart, colStart, rowEnd, colEnd )

    for key, value in format.iteritems():
      object  = self.activeSheet.Range( range )
      element = key.split('.')

      for key in element[0:-1]:
        if key.find( '(' ) >= 0:
          method, index = key.split( '(' )
          index         = index[0:-1]
          object        = getattr( object, method )
          object        = object( index )
        else:
          object = getattr( object, key )

      setattr( object, element[-1], value )


  #-------------------------------------------------------------------------------------------------
  def autoFitColumn( self ):
    self.activeSheet.Columns.AutoFit()


  #-------------------------------------------------------------------------------------------------
  def addSheet( self, title = None ):
    self.xlApp.ActiveWorkbook.Worksheets.Add( None, self.xlApp.ActiveSheet )
    self.xlApp.ActiveWorkbook.Worksheets( self.xlApp.ActiveWorkbook.Worksheets.Count ).Activate()
    self.activeSheet = self.xlApp.ActiveSheet

    if title != None:
      self.activeSheet.Name = unicode( title )


  #-------------------------------------------------------------------------------------------------
  def activateSheet( self, index ):
    self.xlApp.ActiveWorkbook.Worksheets( index + 1 ).Activate()
    self.activeSheet = self.xlApp.ActiveSheet


  #-------------------------------------------------------------------------------------------------
  def delSheet( self, index ):

    self.xlApp.ActiveWorkbook.Worksheets( index + 1 ).Delete()


  #-------------------------------------------------------------------------------------------------
  def setSheetTitle( self, index, title ):
    self.xlApp.ActiveWorkbook.Worksheets( index + 1 ).Name = unicode( title )


  #-------------------------------------------------------------------------------------------------
  def getColor( self, red, green, blue ):
    return win32api.RGB( red, green, blue )


  #-------------------------------------------------------------------------------------------------
  def setFormatConditionFormula( self, range, formula, fontColor, backColor ):
    condFormat = self.activeSheet.Range( range ).FormatConditions.Add( constants.xlExpression, None, formula )
    condFormat.Font.Color     = fontColor
    condFormat.Interior.Color = backColor


  #-------------------------------------------------------------------------------------------------
  def close( self, path ):
    # Prevent overwrite warning
    self.xlApp.DisplayAlerts = False
    self.xlApp.ActiveWorkbook.SaveAs( path )
    self.xlApp.DisplayAlerts = True

    self.xlApp.Quit()



#***************************************************************************************************
# This class extraxts SysBios Module- and Error-IDs from a given base path
#
class GetIds( object ):

  #-------------------------------------------------------------------------------------------------
  # CONTRUCTOR
  #-------------------------------------------------------------------------------------------------
  def __init__( self, basePath ):

    object.__init__( self )
    self.__basePath = basePath


  #-------------------------------------------------------------------------------------------------
  # PRIVATE
  #-------------------------------------------------------------------------------------------------

  #-------------------------------------------------------------------------------------------------
  # Extracts all project directories from given base path; name convetion defined by REGEX_PROJECT
  # is taken into account
  #
  def __getProjects( self, basePath, filterProject = None ):

    if filterProject:
      if REGEX_PROJECT.match( filterProject ):
        path = os.path.abspath( os.path.join( basePath, filterProject ) )
        if os.path.isdir( path ):
          return [ filterProject ]

      raise IOError( 'Project "%s" is unkown or not build' % filterProject )

    return [ dir for dir in os.listdir( basePath ) if REGEX_PROJECT.match( dir ) ]


  #-------------------------------------------------------------------------------------------------
  # Extracts all core directories from given project path; name convetion defined by
  # REGEX_DEBUG_CORE and REGEX_RELEASE_CORE are taken into account
  #
  def __getCores( self, projectPath, filterConfig = None ):

    cores = {}
    dirs  = os.listdir( projectPath )

    if not filterConfig or filterConfig == u'debug':
      cores[u'debug'] = [ dir for dir in dirs if REGEX_DEBUG_CORE.match( dir ) ]

    if not filterConfig or filterConfig == u'release':
      cores[u'release'] = [ dir for dir in dirs if REGEX_RELEASE_CORE.match( dir ) ]

    return cores


  #-------------------------------------------------------------------------------------------------
  # Converts a string to a integer
  # First try to convert to int with base 10, then try to convert to int with base 16.
  # If this also fails return -1 (error code, -1 is never used as id)
  #
  def __str2Int( self, id ):

    # Try to convert to base 10 integer
    try:
      return int( id )
    except:
      pass

    # Try to convert to base 16 integer
    try:
      return int( id, 16 )
    except:
      pass

    # Convertion was not possible
    return -1


  #-------------------------------------------------------------------------------------------------
  def __format( self, string, **kwargs ):

    for key, value in kwargs.iteritems():

      string = string.replace( '{'+key+'}', value )

    return string


  #-------------------------------------------------------------------------------------------------
  # Get the list of all file pathes for the given project, core and file extention
  #
  def __getFilePathes( self, basePath, project, core, fileExt ):

    # Build wildcard filename with given file extention
    filePattern = "*.%s" % fileExt

    # Set the platform and build configin the path
    configPath  = self.__format( CONFIG_PATH, PROJECT = project, CORE = core )

    # Add wildcard filename to the debug path
    path  = os.path.abspath( os.path.join( basePath, configPath, filePattern ) )

    # Search and return all found files which match the wildcard filename and path
    return glob.glob( path )


  #-------------------------------------------------------------------------------------------------
  # Returns the content of the file with the given path
  #
  def __getFileContent( self, filePath ):

    try:
      # Open the file
      readFile = open( filePath, 'r' )

      # read all lines and join them together
      content = ''.join( readFile.readlines() )

      # Close file
      readFile.close()

      # return the file content
      return content

    # File is not openable, return empty string
    except:
      return ""


  #-------------------------------------------------------------------------------------------------
  # Converts the in the given list contained numbers to an error id and returns error name
  # and error id
  #
  def __convertErrorId( self, errorId ):

    # Unzip list entries
    name, baseVal, shiftVal, orVal = errorId

    # Convert base value to integer
    baseVal   = self.__str2Int( baseVal )

    # Convert shift value to integer
    shiftVal  = self.__str2Int( shiftVal )

    # Convert or value to integer
    orVal     = self.__str2Int( orVal )

    # Caluculate error id
    id = ( baseVal << shiftVal ) | orVal;

    # return error id and name
    return ( id, name )


  #-------------------------------------------------------------------------------------------------
  # Converts the in the given content contained module id (string) to in integer. If no module id
  # is found an exception is raised (index out of range)
  #
  def __convertModuleId( self, content ):

    # Extraxt the module id from the given string, concates both module id strings (one is empty)
    # and then convert this one to an integer.
    # If no module id is found, an 'index out of range' exception is raised.
    return [ self.__str2Int( entry[0] + entry[1] ) for entry in REGEX_MODULE_ID.findall( content ) ][0]



  #-------------------------------------------------------------------------------------------------
  # PUBLIC
  #-------------------------------------------------------------------------------------------------

  #-------------------------------------------------------------------------------------------------
  # Extracts projects and core paths from in init set base path
  #
  def getProjectsAndCores( self, filterProject = None, filterConfig = None ):

    projects = {}

    for projectPath in self.__getProjects( self.__basePath, filterProject ):

      projects[projectPath] = self.__getCores( os.path.join( self.__basePath, projectPath ), filterConfig )

    return projects


  #-------------------------------------------------------------------------------------------------
  # Extractes the controller name from the given path
  #
  def getCoreName( self, corePath ):

    try:
      return REGEX_CORE_NAME.findall( corePath )[0]

    # No core name found, path didn't match core name pattern
    except IndexError:
      return u''


  #-------------------------------------------------------------------------------------------------
  # Extracts all error ids for all controllers from the config C file and writes them to a
  # output file
  #
  def getErrorIds( self, project, core ):

    list = []

    # Run through all found config C files
    for fileName in self.__getFilePathes( self.__basePath, project, core, "c" ):

      # Get the file content
      content   = self.__getFileContent( fileName )

      # Extract error name, and the error values from the content
      errorIds  = REGEX_ERROR_ID.findall( content )

      # Convert the list to error name and error id
      list.extend( [ self.__convertErrorId( errorId ) for errorId in errorIds ] )

    # Sort the list by error id
    sortedList  = sorted( list, key=lambda entry: entry[0] )

    return sortedList


  #-------------------------------------------------------------------------------------------------
  # Extracts all module ids for all controllers from the config XML file and writes them to a
  # output file
  #
  def getModuleIds( self, project, core ):

    list    = []

    # Run through all found config XML files
    for fileName in self.__getFilePathes( self.__basePath, project, core, "cfg.xml" ):

      # Get the file content
      content = self.__getFileContent( fileName )

      # Get module name and module content (string which contains the module id)
      modules = REGEX_MODULE.findall( content )

      # Go trough all modules found
      for name, content in map( lambda entry: entry[0], zip( modules ) ):

        # Try to get the module id from the module content and then add the id and the name to the list
        try:
          list.append( ( self.__convertModuleId( content ), name ) )

        # No module id found, don't add the module to the list
        except:
          pass

    # Sort the list by module id
    sortedList = sorted( list, key=lambda entry: entry[0] )

    return sortedList


  #-------------------------------------------------------------------------------------------------
  #
  #
  def getErrorAndModuleIds( self, list ):

    errorAndModulIds  = {}

    for project, configs in list.iteritems():
      errorAndModulIds[project]  = {}

      for config, cores in configs.iteritems():
        errorAndModulIds[project][config] = {}

        for core in cores:
          errorAndModulIds[project][config][core] = { u'errorIds':  self.getErrorIds( project, core ),
                                                      u'moduleIds': self.getModuleIds( project, core ) }

    return errorAndModulIds


#***************************************************************************************************
class ExcelWriter( object ):

  #-------------------------------------------------------------------------------------------------
  # CONTRUCTOR
  #-------------------------------------------------------------------------------------------------
  def __init__( self, verbose ):

    object.__init__( self )
    self.verbose = verbose


  #-------------------------------------------------------------------------------------------------
  def __print( self, message ):

    if self.verbose:
      print message


  #-------------------------------------------------------------------------------------------------
  def __convertData( self, moduleIds, errorIds ):

    rows        = []
    maxRowCount = max( len( errorIds ), len( moduleIds ) )

    for i in xrange( maxRowCount ):
      row = ['']

      try:
        row.extend( moduleIds[i] )
      except:
        row.extend( ['', ''] )

      try:
        row.extend( [ errorIds[i][0], u'0x%08X' % errorIds[i][0], errorIds[i][1] ] )
      except:
        row.extend( ['', '', ''] )

      rows.append( row )

    return rows


  #-------------------------------------------------------------------------------------------------
  def write( self, basePath, outFileName, errorAndModuleIds ):

    for project, configs in errorAndModuleIds.iteritems():
      self.__print( 'Generate EXCEL SHEET for "%s"' % project )

      doc       = Excel()
      docPath   = os.path.abspath( os.path.join( basePath, project, outFileName ) )

      for config, cores in configs.iteritems():
        self.__print( '  %s' % config )
        doc.addSheet( config )
        rowIndex  = 0
        coreKeys  = sorted( cores.keys() )

        for core in coreKeys:
          self.__print( '    %s' % core )

          # Get entries for this core
          entries = cores[core]

          # Transfer module and error ids into row arrangement
          rows    = self.__convertData( entries[u'moduleIds'], entries[u'errorIds'] )

          # Write header for this core
          doc.writeRow( rowIndex, [ getIds.getCoreName( core ),
                                    "Module ID's", "",
                                    u"Error ID's", "", "" ] )
          doc.formatRange( rowIndex, 0, rowIndex, 5, { 'Font.Bold': True,
                                                       'Borders(4).LineStyle' : 1,
                                                       'Borders(4).Weight'    : 3, } )
          rowIndex += 1

          # Write rows
          for row in rows:
            doc.writeRow( rowIndex, row )
            rowIndex += 1

          # Add additional empty row
          rowIndex += 1

        # Auto fit column width
        doc.autoFitColumn()

      # Remove first empty sheet
      doc.delSheet(0)

      # Save document and close excel
      doc.close( docPath )
      self.__print( docPath )
      self.__print( 'Done\n' )




#***************************************************************************************************
class HeaderWriter( object ):

  #-------------------------------------------------------------------------------------------------
  # CONTRUCTOR
  #-------------------------------------------------------------------------------------------------
  def __init__( self, verbose ):

    object.__init__( self )
    self.verbose = verbose


  #-------------------------------------------------------------------------------------------------
  def __print( self, message ):

    if self.verbose:
      print message


  #-------------------------------------------------------------------------------------------------
  def __format( self, string, **kwargs ):

    for key, value in kwargs.iteritems():

      string = string.replace( '{'+key+'}', value )

    return string


  #-------------------------------------------------------------------------------------------------
  def write( self, basePath, outFileName, errorAndModuleIds ):

    for project, configs in errorAndModuleIds.iteritems():
      self.__print( 'Generate HEADER for "%s"' % project )

      for config, cores in configs.iteritems():
        self.__print( '  %s' % config )

        docPath   = os.path.abspath( os.path.join( basePath, project, outFileName ) )
        coreKeys  = sorted( cores.keys() )
        structs   = {}

        for core in coreKeys:
          self.__print( '    %s' % core )

          coreName  = REGEX_CORE_NAME.findall( core )[0].replace('-', '_');
          entries   = cores[core]
          errorIds  = entries[u'errorIds']
          moduleIds = entries[u'moduleIds']
          header    = outFileName.replace('.', '_').upper()

          if len( errorIds ) > 0:
            entries = [ '  uint32  %s__0x%08X;' % ( entry[1].replace('.', '_'), entry[0] ) for entry in errorIds ]
            name    = self.__format( TEMPLATE_ERROR_ID_STRUCT, CORENAME = coreName )
            value   = '\n'.join( entries )
            structs[name] = self.__format( TEMPLATE_STRUCT, VALUE = value, NAME = name )


          if len( moduleIds ) > 0:
            entries = [ '  uint32  %s__%d;' % ( entry[1].replace('.', '_'), entry[0] ) for entry in moduleIds ]
            name    = self.__format( TEMPLATE_MODULE_ID_STRUCT, CORENAME = coreName )
            value   = '\n'.join( entries )
            structs[name] = self.__format( TEMPLATE_STRUCT, VALUE = value, NAME = name )

        handle  = open( docPath, 'w' )
        entries = [ '  %-25s %s;' % ( name, name.replace( 'IS_t_', '' ) ) for name in structs.keys() ]
        globalStruct  = self.__format( TEMPLATE_STRUCT, VALUE = '\n'.join( entries ), NAME = MAIN_STRUCT_NAME )

        fileContent = self.__format( TEMPLATE_FILE, HEADER_UPPERCASE  = outFileName.replace('.', '_').upper(),
                                                    HEADER            = outFileName,
                                                    DATE_TIME         = datetime.datetime.now().strftime( '%d.%m.%Y %H:%M:%S' ),
                                                    USER              = os.environ['USERNAME'],
                                                    STRUCTS           = '\n'.join( structs.values() ),
                                                    MAIN_STRUCT       = globalStruct,
                                                    MAIN_STRUCT_NAME  = MAIN_STRUCT_NAME )
        handle.write( fileContent )
        handle.close()

        self.__print( '%s' % docPath )
        self.__print( 'Done\n' )
      self.__print( '\n' )



#***************************************************************************************************
# MAIN
#***************************************************************************************************
if __name__  == '__main__':

  description = """Collect all XDC module and error id's and write them into a header file.
                                                                                            .
The collected data will be written into a header file which then can be used for generate SDL files.
                                                                                            .
Additionally a excel sheet with the same information can be generated."""

  parser = optparse.OptionParser( description = description )
  parser.add_option( '--project', '-p',
                       default = None,
                       help = 'Only this project is considered. By default all found projects are considered'
                      )

  parser.add_option( '--config', '-c',
                       default = None,
                       choices = ('release', 'debug'),
                       help = 'Only this configuration is considered. By default both, release and debug, are considered' )

  parser.add_option( '--verbose', '-v',
                       action = 'store_true',
                       help = 'Print debug messages' )

  parser.add_option( '--excel', '-e',
                       action = 'store_true',
                       help = 'Generate excel sheet additionally' )

  args = parser.parse_args()[0]

  if args.verbose:
    print "Collect data"

  try:
    getIds            = GetIds( BASE_PATH )
    projectsAndCores  = getIds.getProjectsAndCores( args.project, args.config )
    errorAndModuleIds = getIds.getErrorAndModuleIds( projectsAndCores )
  except IOError, error:
    print error
    exit(-1)

  if args.verbose:
    print "Done\n"

  if args.excel:
    writer  = ExcelWriter( args.verbose )
    writer.write( BASE_PATH, EXCEL_FILE_NAME, errorAndModuleIds )

  writer  = HeaderWriter( args.verbose )
  writer.write( BASE_PATH, HEADER_FILE_NAME, errorAndModuleIds )
