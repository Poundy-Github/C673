"""
Filename                  :  scons_adas_extensions\eclipse_cdt_ccs5.py
Description               :  Script used to generate Eclipse projects for ECU-Lib builds and SIM-HiL builds.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: eclipse_cdt_ccs5.py
#
# DESCRIPTION: Script used to generate Eclipse projects for ECU-Lib builds and SIM-HiL builds.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/03/27
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:52CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: eclipse_cdt_ccs5.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:52CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.19 2017/05/30 10:48:17CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.18 2017/04/27 16:02:11CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.17 2016/05/27 11:43:54CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.16 2015/06/29 13:35:41CEST Stark-EXT, Roland (uidw1169) 
# CHANGES:                   Added support for CortexM3 and M4
# CHANGES:                   - Added comments -  uidw1169 [Jun 29, 2015 1:35:42 PM CEST]
# CHANGES:                   Change Package : 351977:1 http://mks-psad:7002/im/viewissue?selection=351977
# CHANGES:                   Revision 1.15 2015/06/26 05:17:24CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:24 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#########
# IMPORTS
#########
import sys, os, re
import SCons
from xml.dom.minidom import Document
from SCons.Script import *

execfile(File("#../GSCons_project_config.scfg").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)
#########
# GLOBALS
#########
oe_cdt = 'org.eclipse.cdt'
cdt_mk = oe_cdt + '.make.core'
cdt_core = oe_cdt + '.core'
cdt_bld = oe_cdt + '.build.core'
oe_rtsc = 'org.eclipse.rtsc'
cti_ccs = 'com.ti.ccstudio'
cti_ccs_build = cti_ccs + '.buildDefinitions'

def _WritePreferenceXmlAntBuilderFile(filename, preferencesFile):
    """
    Function                     :  _WritePreferenceXmlAntBuilderFile
    Description                  :  Writes an Ant builder file which contains a reference to the preferences file to be imported.
    filename                     :  
    preferencesFile              :  
    Returns                      :  
    """
    fileHeader = \
        '<?xml version="1.0" encoding="UTF-8" ?>\n' \
        '<project default="importpreferences">\n' \
        '<target name="importpreferences" description="import preferences from file">\n'
    fileFooter = ' </target>\n</project>' 
    xmlFile = open(filename, 'w')
    xmlFile.write(fileHeader)
    xmlFile.write('<ImportPreferences preferencesFile="' +
                  preferencesFile + '"/>')
    xmlFile.write(fileFooter)
    xmlFile.close()

def _WriteXmlToProjectFile(xmlDoc, fileName):
    """
    Function              :  _WriteXmlToProjectFile
    Description           :  Writes the given XML document to the given file.
    xmlDoc                :  XML file to be read from.
    fileName              :  Project file to write.
    Returns               :  
    """
    projectFile = open(fileName, 'w')

    # The standard prettyprintting provided by xmlDoc.toprettyxml(), eg:
    #
    #     <dictionary>
    #         <key>
    #             org.eclipse.cdt.make.core.enableFullBuild
    #         </key>
    #         <value>
    #             true
    #         </value>
    #     </dictionary>
    #
    # does not appear to get on with Eclipse very well - strange things
    # happen like not being able to clean the current project by right
    # clicking on the project in the browser and selecting clean.
    #
    # However, the following style appears to work better:
    # 
    #     <dictionary>
    #         <key>org.eclipse.cdt.make.core.enableFullBuild</key>
    #         <value>true</value>
    #     </dictionary>
    #
    # Unforunately the regex below doesn't maintain indentation - TBD!

    # projectFile.write(xmlDoc.toprettyxml())
    out = xmlDoc.toxml()
    niceOut = re.sub(r'><', r'>\n<', re.sub(r'(<\/.*?>)', r'\1\n', out))
    projectFile.write(niceOut)
    projectFile.close()
    return 0

def _CreateImportFile(fileName):
    """
    Function             :  _CreateImportFile
    Description          :  Creates a .import file that signifies a particular Eclipse project has been imported into a workspace.
    fileName             :  
    Returns              :  
    """
    open(fileName, 'w').write("DO NOT DELETE MANUALLY - use scons.bat -c\n")
    return 0

def _WriteProjectFile(target_name, linked_resources, use_rtsc, additional_natures, filename):
    """
    Function                        :  _WriteProjectFile
    Description                     :  Writes project data to XML document, writes this XML document to project file.
    target_name                     :  
    linked_resources                :  
    use_rtsc                        :  
    additional_natures              :  
    filename                        :  
    Returns                         :  
    """
    # create xml-content for project file
    xmlDoc = impl_create_project(sys.executable,
                                 target_name,
                                 linked_resources,
                                 use_rtsc,
                                 additional_natures)
    # write xml-content to project file
    _WriteXmlToProjectFile(xmlDoc, filename)
    return 0
 
def _WriteCProjectFile(scons,
                       scons_target,
                       scons_argument,
                       env_tools,
                       target_name,
                       variants,
                       defines,
                       target_type,
                       core,
                       code_gen_dir,
                       workspace_includes,
                       cpppath,
                       use_rtsc,
                       source_dirs,
                       xdc_platform,
                       xdc_target,
                       xdc_package_path,
                       dsp_xdctools_path, filename):
    """
    Function                       :  _WriteCProjectFile
    Description                    :  Writes project data to XML document, writes this XML document to project file.
    scons                          :  
    scons_target                   :  
    scons_argument                 :  
    env_tools                      :  
    target_name                    :  
    variants                       :  
    defines                        :  
    target_type                    :  
    core                           :  
    code_gen_dir                   :  
    workspace_includes             :  
    cpppath                        :  
    use_rtsc                       :  
    source_dirs                    :  
    xdc_platform                   :  
    xdc_target                     :  
    xdc_package_path               :  
    dsp_xdctools_path              :  
    filename                       :  
    Returns                        :  
    """
    # create xml-content for project file                       
    xmlDoc = impl_create_cproject(sys.executable,
                                  scons,
                                  scons_target,
                                  scons_argument,
                                  env_tools,								  
                                  target_name,
                                  variants,
                                  defines,
                                   target_type,
                                   core,
                                   code_gen_dir,
                                   workspace_includes,
                                   cpppath,
                                   use_rtsc,
                                   source_dirs,
                                   xdc_platform,
                                   xdc_target,
                                   xdc_package_path,
                                   dsp_xdctools_path
                                   )
    # write xml-content to project file
    _WriteXmlToProjectFile(xmlDoc, filename)
    return 0

def _WriteCCSProjectFile(core, filename):
    """
    Function              :  _WriteCCSProjectFile
    Description           :  Writes project data to XML document, writes this XML document to project file.
    core                  :  
    filename              :  
    Returns               :  
    """
    # create xml-content for project file    
    xmlDoc = impl_create_ccsproject(core)
    # write xml-content to project file
    _WriteXmlToProjectFile(xmlDoc, filename)
    return 0   

    
########################################################
# Actions
# SCons actions created for the _WriteXmlToProjectFile
# and _CreateImportFile functions.
########################################################
WritePreferenceXmlAntBuilderFile = \
    SCons.Action.ActionFactory(_WritePreferenceXmlAntBuilderFile,
                               lambda filename, preferences:
                               'Writing Ant build file to %s' % filename)

WriteXmlToProjectFile = \
    SCons.Action.ActionFactory(_WriteXmlToProjectFile,
                               lambda xmlDoc, fileName:
                               'Writing XML to %s' % fileName)

CreateImportFile = \
    SCons.Action.ActionFactory(_CreateImportFile, 
                               lambda fileName:
                               'Writing project export file %s' % fileName)
                               
WriteProjectFile = \
    SCons.Action.ActionFactory(_WriteProjectFile, 
                               lambda target_name, linked_resources, use_rtsc, additional_natures, fileName:
                               'Writing XML to %s' % fileName)
                               
WriteCProjectFile = \
    SCons.Action.ActionFactory(_WriteCProjectFile, 
	                           lambda scons,scons_target,scons_argument,env_tools,target_name,variants,defines,
                               target_type,core,code_gen_dir,workspace_includes,cpppath,use_rtsc,source_dirs,
                               xdc_platform,xdc_target,xdc_package_path,dsp_xdctools_path, fileName:
                               'Writing XML to %s' % fileName)

WriteCCSProjectFile =   \
    SCons.Action.ActionFactory(_WriteCCSProjectFile,
                               lambda core, fileName:
                               'Writing XML to %s' % fileName)    
       
########################################################
# Example: to build a unit test project for the Cantata
#          unit test tool:
# env.EclipseProject(target_name = "unit_under_test", 
#                    target_dir = Dir('#').abspath+'/unittests/',
#                    variants = ["debug", "release"], 
#                    defines = [define["debug"], define["release"]], 
#                    target_type = "out", 
#                    core = "TMS470",
#                    code_gen_version = get_arm_codegen_version(
#                                            Dir(tms470_code_gen_tool_dir).abspath), 
#                    scons_target = "unit_under_test" 
#                    scons_argument = "", 
#                    linked_resources= Dir('#').abspath+'/extra/other_file.cpp",
#                    use_rtsc = True,
#                    additional_natures='com.ipl.products.eclipse.cantpp.cdt.CantataCDTNature')
########################################################
def EclipseProject(env,
                   target_name,
                   target_dir,
                   variants,
                   defines,
                   target_type,
                   core,
                   code_gen_dir,
                   scons_target,
                   scons_argument,
                   Build_target,
                   linked_resources=None,
                   use_rtsc=False,
                   additional_natures=""):
				   
				   
				   
    """
    Function                       :  EclipseProject
    Description                    :  Pseudo-Builder for eclipse projects. Don't use an actual builder as the targets are always the same and 
	                                  we don't want to be forced to specify the targets on each call.
    env                            :  Environment variable.
    target_name                    :  Name of the application to be built.
    target_dir                     :  The directory where the Eclipse project will be stored.
    variants                       :  list of build variant, for example "debug", "release".
    defines                        :  list of defines for each variant.
    target_type                    :  The directory where the Eclipse project will be stored.
    core                           :  processor core, for example "C6000", "TMS470".
    code_gen_dir                   :  Version of the compiler.
    scons_target                   :  The SCons target used to build the application.
    scons_argument                 :  Additional parameter for SCons command.
    Build_target                   :  
    linked_resources               :  A list of external files and/or directories to be linked into the Eclipse project.
    use_rtsc                       :  Specify if rtsc is used in the project or not.
    additional_natures             :  Non-default natures to be added to the list of natures in the .project file.
	                                  Here you can specify natures for particular tools built on top of Eclipse.
    Returns                        :  
    """
################################################################
# For CCS .project file Singh-EXT Vishal uidj9083	
	
################################################################


    required_dir = []
    required_dirF = []
    required_file = []
    All_required = []


    header_files = env.FindAllIncludes(Build_target)	
    header_files = [header for header in header_files if not (header.startswith('C:\\LegacyApp') or '02_Development_Tools' in header or '04_Build' in header)]
    for D1 in header_files:
        Dir_path = os.path.dirname(D1)
        if '01_Source_Code' in Dir_path :
            head, sep, tail = Dir_path.partition('01_Source_Code')
        elif '03_Workspace' in Dir_path:
            head, sep, tail = Dir_path.partition('03_Workspace')		
        dir_req = sep + tail
        dir_req1 = dir_req
        while '\\' in dir_req1 :		
            New_Dir_path = dir_req1.split('\\', 1)
            head, sep, tail = dir_req.partition(New_Dir_path[0])
            directory = head + sep			
            if 	directory in required_dir:
			    pass
            else:
                required_dir.append(directory)				
            dir_req1 = New_Dir_path[1]
        head, sep, tail = dir_req.partition(dir_req1)
        directory = head + sep			
        if 	directory in required_dir:
		    pass
        else:
            required_dir.append(directory)
    for File1 in linked_resources:	
        Dir_path = os.path.dirname(File1)
        if '01_Source_Code' in Dir_path :
            head, sep, tail = Dir_path.partition('01_Source_Code')
        elif '03_Workspace' in Dir_path:
            head, sep, tail = Dir_path.partition('03_Workspace')
        elif '02_Development_Tools' in Dir_path:
            head, sep, tail = Dir_path.partition('02_Development_Tools')
        else:
            continue		
        dir_req = sep + tail
        dir_req2 = dir_req
        while '\\' in dir_req2 :		
            New_Dir_path = dir_req2.split('\\', 1)
            head, sep, tail = dir_req.partition(New_Dir_path[0])
            directory = head + sep			
            if 	directory in required_dir:
			    pass
            else:
                required_dir.append(directory)				
            dir_req2 = New_Dir_path[1]
        head, sep, tail = dir_req.partition(dir_req2)
        directory = head + sep			
        if 	directory in required_dir:
		    pass
        else:
            required_dir.append(directory)
			

    for l1 in required_dir:
        required_dirF.append(l1.replace("\\", "/"))

    for l2 in linked_resources:
        required_file.append(l2.replace("\\", "/"))

    for l3 in header_files:
        required_file.append(l3.replace("\\", "/"))
    All_required = 	required_dirF + required_file
	
    linked_resources = None
    linked_resources = All_required
################################################################
# For CCS .project file Singh-EXT Vishal uidj9083	END
	
################################################################

    projectTarget = Command(target_dir + '.project',
                            [],
                            WriteProjectFile(target_name, linked_resources, use_rtsc, additional_natures, "$TARGET"))

    cpppath = list()
    for path in env['CPPPATH']:
        if path == '${TARGET.dir}':
            # Remove an unneccessary $-tag in include paths
            cpppath.append(str(Dir(path).abspath).split('$')[0])
        else:
            # Ensure any SCons characters (#, .) are expanded
            cpppath.append(str(Dir(path).abspath))

    # Currently unused parameters - consider removal or proper inclusion in
    # interface.
    workspace_includes = []
    source_dirs = []

    scons = os.path.abspath(sys.argv[0])
    
    # gather optional information from construction environment
    # Since construction environemt seems to not be available 
    # within the specific builder here, we have to do it in advance.
    try: 
        xdc_platform = env['XDC_PLATFORM']
    except KeyError:
        xdc_platform = ''
        
    try:
        xdc_target = env['XDC_TARGET']
    except KeyError:
        xdc_target = ''
        
    try:
        xdc_package_path = env['XDC_PACKAGE_PATH']
    except KeyError:
        xdc_package_path = ''
        
    try:
        dsp_xdctools_path = env['_DSP_XDCTOOLS_PATH']
    except KeyError:
        dsp_xdctools_path = ''

    cprojectTarget = Command(target_dir + '.cproject',
                             [],
                             WriteCProjectFile(scons,
                                               scons_target,
                                               scons_argument,
                                               env['TOOLS'],											   
                                               target_name,
                                               variants,
                                               defines,
                                               target_type,
                                               core,
                                               code_gen_dir,
                                               workspace_includes,
                                               cpppath,
                                               use_rtsc,
                                               source_dirs,
                                               xdc_platform,
                                               xdc_target,
                                               xdc_package_path,
                                               dsp_xdctools_path, 
                                               "$TARGET"
                                               ))

    ccsprojectTarget = Command(target_dir + '.ccsproject',
                             [],
                             WriteCCSProjectFile(core, "$TARGET"))
                             
    return [projectTarget, cprojectTarget, ccsprojectTarget]


def EclipseWorkspace(env, target_dir, projects = None, preferences = None):

    """
    Function                  :  EclipseWorkspace
    Description               :  Pseudo-Builder for eclipse workspaces.
    env                       :  Environment variable.
    target_dir                :  Directory to place the workspace.
    projects                  :  list of projects to import into the projects.
    preferences               :  preference file (.epf) for import into the generated workspace.
    Returns                   :  
    """
    baseWorkspaceString = \
        env['ECLIPSE_EXE'] + \
        " -nosplash" + \
        " -data " + \
        str(Dir(target_dir))

    baseWorkspaceCreationString = \
        baseWorkspaceString + \
        " -application org.eclipse.cdt.managedbuilder.core.headlessbuild"

    if preferences:

        preferencesString = \
            baseWorkspaceString + \
            " -application org.eclipse.ant.core.antRunner -buildfile " + \
            Dir(".").abspath + \
            "\\PreferenceImporter.xml"

        workspaceActions = \
            list([preferencesString, 
                  Delete(Dir(".").abspath+"\\PreferenceImporter.xml")])

        # Create Ant build file to import preferences required for the workspace
        preferencesImportFile = \
            Command("PreferenceImporter.xml",
                    preferences,
                    WritePreferenceXmlAntBuilderFile("$TARGET",
                                                     File(preferences).abspath))

        targetSources = list(preferencesImportFile)

    else:
        workspaceActions = list()
        targetSources = list()

    if projects:

        # Trying to import the same project into a workspace twice results in
        # an Eclipse error. There is no easy way to check if a project has
        # already been imported into an eclipse workspace already, so we use
        # a ".imported" file in the project directory to indicate that the
        # project has already been imported.

        projectPaths = ''
        importFiles = []
        projectsToImport = []

        for project in projects:
            projectPath = os.path.dirname(str(env.GetBuildPath(project[0])[0]))
            imported = projectPath + "\\.imported"
            importFile = env.Command(imported, '', CreateImportFile("$TARGET"))
            Depends("#/ide", importFile)
            importFiles.append(importFile)
            if not (os.path.exists(imported) and
                    os.path.isfile(imported) and
                    os.access(imported, os.R_OK)):
                projectPaths = projectPaths + " -import " + projectPath
                projectsToImport.append(project)

        if projectsToImport:

            workspaceCreationString = baseWorkspaceCreationString + projectPaths
            workspaceActions.insert(0, workspaceCreationString)
            targetSources.append(projectsToImport)

            workspace= env.Command(target_dir, targetSources, workspaceActions)

            for importFile in importFiles:
                Depends(importFile, workspace)

        # else: if there are projects that have already been imported then
        #       presumably the workspace already exists - do nothing.

    else:
        # Dummy headless build command to force creation of workspace
        # without projects.
        workspaceCreationString = \
            baseWorkspaceCreationString + " -cleanBuild all"

        workspaceActions.insert(0, workspaceCreationString)

        env.Command(target_dir,
                    targetSources,
                    workspaceCreationString)


def generate(env):
    """
    Function        :  generate
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    try:
        env.AddMethod(EclipseProject, "EclipseProject")
        env.AddMethod(EclipseWorkspace, "EclipseWorkspace")
    except AttributeError:
        # Looks like we use a pre-0.98 version of SCons...
        from SCons.Script.SConscript import SConsEnvironment
        SConsEnvironment.EclipseProject = EclipseProject
        SConsEnvironment.EclipseWorkspace = EclipseWorkspace

def exists(env):
    """
    Function        :  exists
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    return 1

def impl_create_project(executable,
                        appname,
                        linked_resources,
                        use_rtsc,
                        additional_natures=""):
    """
    Function                       :  impl_create_project
    Description                    :  Creates the .project XML file.
    executable                     :  Path to python executable.
    appname                        :  Name of the executable to be built.
    linked_resources               :  A list of external files and/or directories to be linked into the Eclipse project.
    use_rtsc                       :  Specify if rtsc is used in the project or not.
    additional_natures             :  Non-default natures to be added to the list of natures in the .project file.
	                                  Here you can specify natures for particular tools built on top of Eclipse.
    Returns                        :  
    """
    doc = Document()
    projectDescription = doc.createElement('projectDescription')
    add(doc, projectDescription, 'name', appname)
    add(doc, projectDescription, 'comment')
    add(doc, projectDescription, 'projects')
    buildSpec = add(doc, projectDescription, 'buildSpec')
    buildCommand = add(doc, buildSpec, 'buildCommand')
    add(doc,
        buildCommand,
        'name',
        oe_cdt + '.managedbuilder.core.genmakebuilder')
    add(doc, buildCommand, 'triggers', 'clean,full,incremental,')
    arguments = add(doc, buildCommand, 'arguments')
    # the default make-style targets are overwritten by the .cproject values
    dictionaries = {
                    cdt_mk + '.contents': cdt_mk + '.activeConfigSettings',
                    cdt_mk + '.enableAutoBuild': 'false',
                    cdt_mk + '.enableCleanBuild': 'true',
                    cdt_mk + '.enableFullBuild': 'true',
                   }
    for k, v in dictionaries.items():
        addDictionary(doc, arguments, k, v)
        
    natures = add(doc, projectDescription, 'natures')
    nature_list = """
                  core.cnature
                  managedbuilder.core.managedBuildNature
                  core.ccnature
                  managedbuilder.core.ScannerConfigNature
                  """.split()
    for n in nature_list:
        add(doc, natures, 'nature', oe_cdt + '.' + n)
        
    add(doc, natures, 'nature', 'com.ti.ccstudio.core.ccsNature')
    if use_rtsc == True:
        add(doc, natures, 'nature', oe_rtsc + '.xdctools.buildDefinitions.XDC.xdcNature')

    additional_nature_list = additional_natures.split()
    for n in additional_nature_list:
        add(doc, natures, 'nature', n)

    # add(doc, natures, 'nature', 'org.python.pydev.pythonNature')

    if linked_resources:
        resources = add(doc, projectDescription, 'linkedResources')
        for l in linked_resources: 
            link = add(doc, resources, 'link')
            if os.path.isfile(l): 
                if '01_Source_Code' in l :
                    head, sep, tail = l.partition('01_Source_Code')
                elif '03_Workspace' in l:
                    head, sep, tail = l.partition('03_Workspace')
                elif '02_Development_Tools' in l:
                    head, sep, tail = l.partition('02_Development_Tools')
                else:
                    continue				
                name_req = 	sep + tail
                add(doc, link, 'name', name_req)				
                add(doc, link, 'type', '1')
                add(doc, link, 'location', l)				
            else:
                add(doc, link, 'name', l)			
                add(doc, link, 'type', '2')
                add(doc, link, 'locationURI', 'virtual:/virtual')				

    doc.appendChild(projectDescription)
    return doc

def impl_create_cproject(executable,
                         scons,
                         scons_target,
                         scons_argument,
                         env_tools,
                         appname,
                         variants,
                         defines,
                         target_type,
                         core,
                         code_gen_dir,
                         workspace_includes,
                         cpppath,
                         use_rtsc=False,
                         source_dirs=[],
                         xdc_platform='',
                         xdc_target='',
                         xdc_package_path='',
                         dsp_xdctools_path=''
                         ):
    """
    Function                       :  impl_create_cproject
    Description                    :  Creates the .cproject XML file.
    executable                     :  Path to python executable.
    scons                          :  Path to the installed SCons python script.
    scons_target                   :  The SCons target used to build the application.
    scons_argument                 :  Additional argument for SCons command.
    env_tools                      :  
    appname                        :  Name of the executable to be built.
    variants                       :  list of build variant.
    defines                        :  list of defines for each variant.
    target_type                    :  library ("lib") or executable ("out").
    core                           :  Processor core ("C6000" or "TMS470" or "TMS470_GNU").
    code_gen_dir                   :  Directory of compiler.
    workspace_includes             :  Unused
    cpppath                        :  Include paths
    use_rtsc                       :  Specify if rtsc is used in the project or not.
    source_dirs                    :  Unused
    xdc_platform                   :  xdc-platform
    xdc_target                     :  xdc-target
    xdc_package_path               :  xdc package path.
    dsp_xdctools_path              :  xdc-tools directory.
    Returns                        :  
    """
    # get tool version
    if core == "C6000":
        code_gen_version = get_c6000_codegen_version(Dir(code_gen_dir).abspath)
    elif core == "TMS470":
        code_gen_version = get_arm_codegen_version(Dir(code_gen_dir).abspath)
    elif core == "TMS470_GNU":
        code_gen_version = get_arm_gcc_codegen_version(Dir(code_gen_dir).abspath)

    code_gen_version = code_gen_version.split('v', 1)
    compiler_complete_version = code_gen_version[1]

    if core == "TMS470_GNU":
        # fake the compiler version for GCC projects
        comp_ver = '4.0'
    else:
        comp_ver = compiler_complete_version[:3].replace('_', '.')
      
    if target_type == 'lib':
        build_type = 'library'
    else:
        build_type = 'exe'
    
    doc = Document()
    doc.appendChild(doc.createProcessingInstruction('fileVersion', '4.0.0'))
    cproject = doc.createElement('cproject')
    storageModuleConf = add(doc, cproject, 'storageModule',
                        {'configRelations': '2',
                         'moduleId': cdt_core + '.settings'})
    
    # create cconfiguration
    iteration = 0
    for variant, define in zip(variants, defines):
        
        # extract "release", "debug" from variant
        if "release" in variant:
            build_variant = "release"
        elif "debug" in variant:
            build_variant = "debug"
        else:
            # not valid, default to "release"
            build_variant = "release"
            
        cconf_id_parent = cti_ccs_build + '.' + core.split("_")[0] + '.' + build_variant.capitalize()
        cconf_id = cti_ccs_build + '.' + core.split("_")[0] + '.' + build_variant.capitalize() + '.' + str(iteration + 1)
        cconf_comp = cti_ccs_build + '.' + core
        cconf = add(doc, storageModuleConf, 'cconfiguration', {'id':cconf_id})

        storageModule = add(doc, cconf, 'storageModule',
                            {'buildSystemId': oe_cdt + '.managedbuilder.core.configurationDataProvider',
                             'id': cconf_id,
                             'moduleId': cdt_core + '.settings',
                             'name': variant.capitalize()})

        add(doc, storageModule, 'externalSettings')

        extensions = add(doc, storageModule, 'extensions')
        extension_list = """
                         errorparser.CoffErrorParser
                         errorparser.LinkErrorParser
                         errorparser.AsmErrorParser
                         """.split()
        ext = add(doc, extensions, 'extension',
                  {'id': cti_ccs + '.binaryparser.CoffParser', 'point': cdt_core + '.BinaryParser'})
        if use_rtsc == True:
            ext = add(doc, extensions, 'extension',
                  {'id': oe_rtsc + '.xdctools.parsers.ErrorParser', 'point': cdt_core + '.ErrorParser'})
        for e in extension_list:
            ext = add(doc, extensions, 'extension',
                      {'id': cti_ccs + '.' + e, 'point': cdt_core + '.ErrorParser'})

        storageModule = add(doc, cconf, 'storageModule',
                            {'moduleId': 'cdtBuildSystem', 'version': '4.0.0'})
        error_parser_string = cti_ccs + '.errorparser.CoffErrorParser;' + cti_ccs + '.errorparser.LinkErrorParser;' + cti_ccs + '.errorparser.AsmErrorParser'
        if use_rtsc == True:
            error_parser_string = oe_rtsc + '.xdctools.parsers.ErrorParser;' + error_parser_string
        config = add(doc, storageModule, 'configuration',
                     {'artifactName': appname,
                      'artifactExtension': target_type,
                      'id': cconf_id,
                      'name': variant.capitalize(),
                      'parent': cconf_id_parent,
                      'errorParsers': error_parser_string})
        folderInfo = add(doc, config, 'folderInfo',
                         {'id': cconf_id + '.', 'name': '/', 'resourcePath': ''})
        
        # there is inconsistency here (additional .) in the id and superClass of toolChain
        if build_variant == 'release':
            separator = '.'
        else:
            separator = ''
        if target_type == 'lib':
            toolChain = add(doc, folderInfo, 'toolChain',
                        {'id': cconf_comp + '_' + comp_ver + '.' + 'library' + separator + build_variant.capitalize() + 'Toolchain.' + str(iteration + 1),
                         'name': 'TI Build Tools',
                         'superClass': cconf_comp + '_' + comp_ver + '.' + 'library' + separator + build_variant.capitalize() + 'Toolchain',
                         'targetTool': cconf_comp + '_' + comp_ver + '.' + 'library' + '.librarian' + build_variant.capitalize() + '.' + str(iteration + 1)})
        else:
            toolChain = add(doc, folderInfo, 'toolChain',
                        {'id': cconf_comp + '_' + comp_ver + '.' + 'exe' + '.' + build_variant.capitalize() + 'Toolchain.' + str(iteration + 1),
                         'name': 'TI Build Tools',
                         'superClass': cconf_comp + '_' + comp_ver + '.' + 'exe' + '.' + build_variant.capitalize() + 'Toolchain',
                         'targetTool': cconf_comp + '_' + comp_ver + '.' + 'exe.' + 'linker' + build_variant.capitalize() + '.' + str(iteration + 1)})
        
        if core == "TMS470_GNU":
          option = add(doc, toolChain, 'option',
                           {'id': cti_ccs_build + '.core.OPT_CODEGEN_VERSION.' + str(iteration + 1),
                            'name': 'Compiler version',
                            'superClass': cti_ccs_build + '.core.OPT_CODEGEN_VERSION',
                            'value': "GNU_" + compiler_complete_version.replace('_', '.'),
                            'valueType': "string"})
        else:
          option = add(doc, toolChain, 'option',
                           {'id': cti_ccs_build + '.core.OPT_CODEGEN_VERSION.' + str(iteration + 1),
                            'name': 'Compiler version',
                            'superClass': cti_ccs_build + '.core.OPT_CODEGEN_VERSION',
                            'value': compiler_complete_version.replace('_', '.'),
                            'valueType': "string"})
        
        option = add(doc, toolChain, 'option',
                         {'id': cti_ccs_build + '.core.OPT_TAGS.' + str(iteration + 1),
                          'superClass': cti_ccs_build + '.core.OPT_TAGS',
                          'valueType': "stringList"})
        add(doc, option, 'listOptionValue',
                         {'builtIn': 'false',
                          'value': 'CCS_MBS_VERSION=5.1.0.01'})
        if use_rtsc == True:
            add(doc, option, 'listOptionValue',
                             {'builtIn': 'false',
                              'value': 'RTSC_MBS_VERSION=2.2.0'})
            add(doc, option, 'listOptionValue',
                             {'builtIn': 'false',
                              #'value': 'XDC_VERSION=3.24.5.48'})
                              'value': 'XDC_VERSION=3.23.4.60'})
            add(doc, option, 'listOptionValue',
                             {'builtIn': 'false',
                              #'value': 'RTSC_PRODUCTS=com.ti.rtsc.SYSBIOS:6.34.2.18;'})
                              'value': 'RTSC_PRODUCTS=com.ti.rtsc.SYSBIOS:6.33.6.50;'})

        targetPlatform = add(doc, toolChain, 'targetPlatform',
                         { 'superClass': cconf_comp + '_' + comp_ver + '.' + build_type + '.targetPlatform' + build_variant.capitalize(),
                           'id': cconf_comp + '_' + comp_ver + '.' + build_type + '.targetPlatform' + build_variant.capitalize() + '.' + str(iteration + 1), 
                           'name': 'Platform'})

        scons_build = ' %s %s' % (scons_target[iteration], scons_argument)
        scons_clean = ' -c %s %s' % (scons_target[iteration], scons_argument)
        builder = add(doc, toolChain, 'builder',
                      {'autoBuildTarget': scons_build,
                       'buildPath': str(Dir('#').abspath),
                       'command': str(Dir('#').abspath) + '\\scons.bat',
                       'enableAutoBuild': 'false',
                       'cleanBuildTarget': scons_clean,
                       'enableIncrementalBuild': 'true',
                       'id': cconf_comp + '_' + comp_ver + '.' + build_type + '.builder' + build_variant.capitalize() + '.' + str(iteration + 1),
                       'incrementalBuildTarget': scons_build,
                       'managedBuildOn': 'false',
                       'name': 'Gnu Make Builder',
                       'superClass': cconf_comp + '_' + comp_ver + '.' + build_type + '.builder' + build_variant.capitalize()})

        compiler = add(doc, toolChain, 'tool',
                         { 'superClass': cconf_comp + '_' + comp_ver + '.' + build_type + '.compiler' + build_variant.capitalize(),
                           'id': cconf_comp + '_' + comp_ver + '.' + build_type + '.compiler' + build_variant.capitalize() + '.' + str(iteration + 1), 
                           'name': core + ' Compiler'})
        # add include paths
        include_paths = add(doc, compiler, 'option',
                         { 'superClass': cconf_comp + '_' + comp_ver + '.' + build_type + '.compilerID.INCLUDE_PATH',
                           'id': cconf_comp + '_' + comp_ver + '.' + build_type + '.compilerID.INCLUDE_PATH' + '.' + str(iteration + 1), 
                           'name': 'Add dir to #include search path (--include_path, -I)',
                           'valueType': 'includePath'})
        if cpppath:
            for path in cpppath:
                add(doc, include_paths, 'listOptionValue', {'builtIn': 'false', 'value': path})
                
        # add defines
        c_defines = add(doc, compiler, 'option',
                     { 'superClass': cconf_comp + '_' + comp_ver + '.' + build_type + '.compilerID.DEFINE',
                       'id': cconf_comp + '_' + comp_ver + '.' + build_type + '.compilerID.DEFINE' + '.' + str(iteration + 1), 
                       'name': 'Pre-define NAME (--define, -D)',
                       'valueType': 'definedSymbols'})
        for entry in define:
            add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': entry})
		
		# MACRO defined for ti_arp32, ti_c66xx, ti_c674x, ti_cortex_a8, ti_cortex_a15, ti_cortex_m4		
		
        if "ti_arp32" in scons_target[iteration]:
            for macro in arp32_built_in_defines_list:
                add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})
            if "--abi=eabi" in 	arp32_common_ccflags:
                for macro_flag in arp32_built_in_eabi_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro_flag})
	
        if "ti_c674x" in scons_target[iteration]:
            for macro in c674x_built_in_defines_list: 
                add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})
            if "--abi=eabi" in 	c674x_common_ccflags:			
                for macro_flag in c674x_built_in_eabi_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro_flag})
			
        if "ti_c66xx" in scons_target[iteration]:
            for macro in c66xx_built_in_defines_list:
                add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})
            if "--abi=eabi" in 	c66xx_common_ccflags:
                for macro_flag in c66xx_built_in_eabi_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro_flag})
			
        if "ti_cortex_a8" in scons_target[iteration]:	
            if "arm_gcc" != env_tools[0]:
                for macro in cortex_a8_built_in_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})				
                if "--abi=eabi" in 	cortex_a8_gcc_common_ccflags:
                    for macro_flag in cortex_a8_built_in_eabi_defines_list:
                        add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro_flag})
					
        if "ti_cortex_a15" in scons_target[iteration]:	
            if "arm_gcc" != env_tools[0]:
                for macro in cortex_a15_built_in_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})				
                if "--abi=eabi" in 	cortex_a15_gcc_common_ccflags:
                    for macro_flag in cortex_a15_built_in_eabi_defines_list:
                        add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro_flag})

        if "ti_cortex_m3" in scons_target[iteration]:	
            if "arm_gcc" != env_tools[0]:
                for macro in cortex_m3_built_in_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})				
			
        if "ti_cortex_m4" in scons_target[iteration]:	
            if "arm_gcc" != env_tools[0]:
                for macro in cortex_m4_built_in_defines_list:
                    add(doc, c_defines, 'listOptionValue', {'builtIn': 'false', 'value': macro})				
			
        if use_rtsc == True:
            rtsc = add(doc, toolChain, 'tool',
                             { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool",
                               'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool." + str(iteration + 1), 
                               'name': 'XDCtools'})
            if core == "C6000":
                add(doc, rtsc, 'option',
                                 { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.CODEGEN_TOOL_DIR",
                                   'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.CODEGEN_TOOL_DIR." + str(iteration + 1), 
                                   'value': Dir(code_gen_dir).abspath,
                                   'valueType': 'string'})
            elif core == "TMS470":
                add(doc, rtsc, 'option',
                                 { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.CODEGEN_TOOL_DIR",
                                   'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.CODEGEN_TOOL_DIR." + str(iteration + 1), 
                                   'value': Dir(code_gen_dir).abspath,
                                   'valueType': 'string'})
            elif core == "TMS470_GNU":
                add(doc, rtsc, 'option',
                                 { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.CODEGEN_TOOL_DIR",
                                   'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.CODEGEN_TOOL_DIR." + str(iteration + 1), 
                                   'value': Dir(code_gen_dir).abspath,
                                   'valueType': 'string'})
            add(doc, rtsc, 'option',
                             { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.TARGET",
                               'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.TARGET." + str(iteration + 1), 
                               'value': xdc_target,
                               'valueType': 'string'})
            add(doc, rtsc, 'option',
                             { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.PLATFORM",
                               'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.PLATFORM." + str(iteration + 1), 
                               'value': xdc_platform,
                               'valueType': 'string'})
            add(doc, rtsc, 'option',
                             { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.PLATFORM_RAW",
                               'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.PLATFORM_RAW." + str(iteration + 1), 
                               'value': xdc_platform,
                               'valueType': 'string'})
            add(doc, rtsc, 'option',
                             { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.BUILD_PROFILE",
                               'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.BUILD_PROFILE." + str(iteration + 1), 
                               'value': build_variant,
                               'valueType': 'string'})
            xdcpath = add(doc, rtsc, 'option',
                             { 'superClass': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.XDC_PATH",
                               'id': "com.ti.rtsc.buildDefinitions.XDC_3.16.tool.XDC_PATH." + str(iteration + 1), 
                               'valueType': 'stringList'})
            package_paths = xdc_package_path.split(';')
            for path in package_paths:
                if len(path):
                    add(doc, xdcpath, 'listOptionValue', {'builtIn': 'false', 'value': path})
            add(doc, xdcpath, 'listOptionValue', {'builtIn': 'false', 'value': dsp_xdctools_path})
                           
        if source_dirs:
            sourceEntries = add(doc, config, 'sourceEntries')
            for i in source_dirs:
                add(doc, sourceEntries, 'entry',
                    {'excluding': i,
                     'flags': 'VALUE_WORKSPACE_PATH|RESOLVED',
                     'kind': 'sourcePath',
                     'name': ''})
                add(doc, sourceEntries, 'entry',
                    {'flags': 'VALUE_WORKSPACE_PATH|RESOLVED',
                     'kind': 'sourcePath',
                     'name': i})
        
        storageModule = add(doc, cconf, 'storageModule',
                            {'moduleId': 'org.eclipse.cdt.core.externalSettings'})
        iteration = iteration + 1
    # end cconfiguration
    
    storageModule = add(doc, cproject, 'storageModule',
                        {'moduleId': 'org.eclipse.cdt.core.LanguageSettingsProviders'})               
    storageModule = add(doc, cproject, 'storageModule',
                        {'moduleId': 'cdtBuildSystem',
                         'version': '4.0.0'})
    project = add(doc, storageModule, 'project',
                  {'id': '%s.' % appname + cconf_comp.split("_")[0] + ".ProjectType.1", 'name': core, 'projectType': cconf_comp.split("_")[0] + ".ProjectType"})
    storageModule = add(doc, cproject, 'storageModule',
                        {'moduleId': 'scannerConfiguration'})
    storageModule = add(doc, cproject, 'storageModule',
                        {'moduleId': 'org.eclipse.cdt.core.language.mapping'})
    projectMapping = add(doc, storageModule, 'project-mappings',{})
    add(doc, projectMapping, 'content-type-mapping',
                        {'configuration': '',
                         'content-type': 'org.eclipse.cdt.core.asmSource',
                         'language': 'com.ti.ccstudio.core.TIASMLanguage'})
    add(doc, projectMapping, 'content-type-mapping',
                        {'configuration': '',
                         'content-type': 'org.eclipse.cdt.core.cHeader',
                         'language': 'com.ti.ccstudio.core.TIGCCLanguage'})
    add(doc, projectMapping, 'content-type-mapping',
                        {'configuration': '',
                         'content-type': 'org.eclipse.cdt.core.cSource',
                         'language': 'com.ti.ccstudio.core.TIGCCLanguage'})
    add(doc, projectMapping, 'content-type-mapping',
                        {'configuration': '',
                         'content-type': 'org.eclipse.cdt.core.cxxHeader',
                         'language': 'com.ti.ccstudio.core.TIGPPLanguage'})
    add(doc, projectMapping, 'content-type-mapping',
                        {'configuration': '',
                         'content-type': 'org.eclipse.cdt.core.cxxSource',
                         'language': 'com.ti.ccstudio.core.TIGPPLanguage'})

    doc.appendChild(cproject)
    return doc

def impl_create_ccsproject(core):
    
    """
    Function         :  impl_create_ccsproject
    Description      :  Creates the .ccsproject XML file.
    core             :  Processor core.
    Returns          :  
    """
    doc = Document()
    doc.appendChild(doc.createProcessingInstruction('ccsproject', 'version="1.0"'))

    projectOptions = doc.createElement('projectOptions')
    add(doc, projectOptions, 'deviceFamily', {'value': core})
    doc.appendChild(projectOptions)
    return doc
    
def addDictionary(doc, parent, k, v):
    """
    Function            :  addDictionary
    Description         :  Eclipse project dictionary.
    doc                 :  
    parent              :  
    k                   :  
    v                   :  
    Returns             :  
    """
    dictionary = add(doc, parent, 'dictionary')
    add(doc, dictionary, 'key', k)
    add(doc, dictionary, 'value', v)
    return dictionary

def addTarget(doc,
              buildTargets,
              executable,
              name,
              buildTarget,
              runAllBuilders = True):
    """
    Function                    :  addTarget
    Description                 :  Adds a build target to the project.
    doc                         :  
    buildTargets                :  
    executable                  :  
    name                        :  
    buildTarget                 :  
    runAllBuilders              :  
    Returns                     :  
    """
    target = add(doc, buildTargets, 'target',
                 {'name': name,
                  'path': '',
                  'targetID': oe_cdt + '.build.MakeTargetBuilder'})
    add(doc, target, 'buildCommand', executable)
    add(doc, target, 'buildArguments', None)
    add(doc, target, 'buildTarget', buildTarget)
    add(doc, target, 'stopOnError', 'true')
    add(doc, target, 'useDefaultCommand', 'false')
    add(doc, target, 'runAllBuilders', str(runAllBuilders).lower())

def add(doc, parent, tag, value = None):
    """
    Function            :  add
    Description         :  Adds the given XML tag, value pair to the project file, under the given parent.
    doc                 :  
    parent              :  
    tag                 :  
    value               :  
    Returns             :  
    """
    el = doc.createElement(tag)
    if (value):
        if type(value) == type(str()):
            el.appendChild(doc.createTextNode(value))
        elif type(value) == type(dict()):
            setAttributes(el, value)
    parent.appendChild(el)
    return el

def setAttributes(node, attrs):
    """
    Function           :  setAttributes
    Description        :  Sets attributes for the given XML node.
    node               :  
    attrs              :  
    Returns            :  
    """
    for k, v in attrs.items():
        node.setAttribute(k, v) 
