'**********************************************************************
'
'  COMPANY:          Continental Temic, BC DAS, A.D.C. GmbH
'
'  MODULNAME:        mk_pdo_sdl.vbs
'
'  DESCRIPTION:      Generating cdl mts measurement file at simulation environment
'
' USE:               Call VBS script with following arguments (in order, if argument
'                              in given position omitted, default assumed):
'                              configuration name eg: Debug|Win32
'                              platform name eg: Win32
'                              vcproj file name, eg: sim_swc_fct.vcproj
'                              options to pass to SDL generation step, eg: --cycleinfo default ARSMainCycle 60
'                              path to pdo_scan.exe and pdo_tool.exe
'                              path to SDLcompiler.exe
'                              output directory (currently unused)
'
'  VERSION:          $Revision: 1.1 $
'
'**********************************************************************

Set objArgs = WScript.Arguments
Set xmlDoc=CreateObject("Microsoft.XMLDOM")
Set fso = CreateObject("Scripting.FileSystemObject")
Set stdout = fso.GetStandardStream (1)
Set regEx = New RegExp 
Set WshShell = CreateObject("WScript.Shell")

If (objArgs.Count > 0) Then
    prj_file   = objArgs(0)
Else
    prj_file   = "vdy_simV3.vcxproj"
End If 
'If (objArgs.Count > 2) Then
'    CfgName    = objArgs(1) + "|" + objArgs(2)
If (objArgs.Count > 1) Then
    CfgName    = objArgs(1)
Else
    CfgName    = "Debug|Win32"
End If
If (objArgs.Count > 2) Then
    CdlName = objArgs(2)
Else
    CdlName = "sim.cdl"
End If
If (objArgs.Count > 3) Then
    sdl_gen_opts = objArgs(3)
Else
    sdl_gen_opts = "--config tool_cfg_sdl.cfg"
End If
If (objArgs.Count > 4) Then
    pdo_dir    = objArgs(4)
Else
    pdo_dir    = "..\..\..\02_Development_Tools\pdo_tool"
End If
If (objArgs.Count > 5) Then
    sdl_dir    = objArgs(5)
Else
    sdl_dir    = "..\..\..\02_Development_Tools\sdlcompiler"
End If
If (objArgs.Count > 6) Then
    file_regex_pattern = objArgs(6)
Else
    file_regex_pattern = "(\w+)\.(c)"
End If
If (objArgs.Count > 7) Then
    makeFileNameSuffix = objArgs(7)
Else
    makeFileNameSuffix = ""
End If
If (objArgs.Count > 8) Then
    UserRootDir = objArgs(8)
Else
    UserRootDir = "c:\Documents and Settings\berndtt1\Local Settings\Application Data\Microsoft\MSBuild\v4.0"
End If
If (objArgs.Count > 9) Then
    VCTargetsPath = objArgs(9)
Else
    VCTargetsPath = "c:\program files\MSBuild\Microsoft.cpp\v4.0\"
End If

xmlDoc.async = "false"
xmlDoc.load(prj_file)

' get Position of extension
prext = InStrRev(prj_file, ".")

' filename length
prlen = len(prj_file)

' get extension, shall be either vcxproj(2010) of vcproj (VS2005)
Prtype = Right(prj_file, prlen-prext)

' distinguish between VS2005 and VS2010
If (Prtype = "vcxproj") Then
stdout.WriteLine "VS2010 project"



' Extract project name
Set projectNameNodes = xmlDoc.getElementsByTagName("ProjectName")
Cntr = 0
For Each projectNameNode in projectNameNodes
    If Cntr = 0 Then
        ProjName = projectNameNode.text
        Cntr = 1
    Else
        ProjName = ProjName + "---" + projectNameNode.text 
    End If
Next
' If project name not set above, then set as default to vcxproj name
if IsEmpty(ProjName) Then
    ProjName = Left(prj_file, InStrRev(prj_file, ".")-1)
End If

' Extract Platform
Platform = "Win32"
Set ProjectConfigurationNodes = xmlDoc.getElementsByTagName("ProjectConfiguration")
For Each ProjectConfigurationNode in ProjectConfigurationNodes
    If ProjectConfigurationNode.getAttribute("Include") = CfgName Then
        Set PropertyGroupChilds = ProjectConfigurationNode.childNodes
        For Each PropertyGroupChild in PropertyGroupChilds
            If PropertyGroupChild.nodeName = "Platform" Then
                Platform = PropertyGroupChild.text
            End If
        Next
    End If
Next

' Extract intermediate output directory (release, debug, ...)
Set PropertyGroupNodes = xmlDoc.getElementsByTagName("PropertyGroup")
For Each PropertyGroupNode in PropertyGroupNodes
    If PropertyGroupNode.hasChildNodes() = True Then
        Set PropertyGroupChilds = PropertyGroupNode.childNodes
        For Each PropertyGroupChild in PropertyGroupChilds
            If PropertyGroupChild.nodeName = "IntDir" Then
                ConditionStr = PropertyGroupChild.getAttribute("Condition")
                ConditionStr = Replace(ConditionStr, "'$(Configuration)|$(Platform)'=='", "")
                ConditionStr = Replace(ConditionStr, "'", "")
                If ConditionStr = CfgName Then
                    IntOutDir = StrReverse(Replace(StrReverse(PropertyGroupChild.text), "\", "", 1, 1))
                End If
            End If
        Next
    End If
Next

' Extract Project Files (*.props)
Set cfgs = xmlDoc.getElementsByTagName("ImportGroup")
found = 0
For each cfg in cfgs 
    If cfg.getAttribute("Label") = "PropertySheets" Then
        ConditionStr = cfg.getAttribute("Condition")
        ConditionStr = Replace(ConditionStr, "'$(Configuration)|$(Platform)'=='", "")
        ConditionStr = Replace(ConditionStr, "'", "")
        If ConditionStr = CfgName Then
            found = 1
            ' Check if any inherited property sheets
            ' Extracting information from *.props files
            If cfg.hasChildNodes() = True Then
                Set ImportNodes = cfg.childNodes
                For Each ImportNode In ImportNodes
                    propsFile = ImportNode.getAttribute("Project")
                    propsFile = Replace(propsFile, "$(Platform)", Platform)
                    propsFile = Replace(propsFile, "$(UserRootDir)", UserRootDir)
                    propsFile = Replace(propsFile, "$(VCTargetsPath)", VCTargetsPath)
                    
                    ' Load inherited property sheet, and extract include paths and pre-processor definitions from it
                    Set xmlInheritedDoc=CreateObject("Microsoft.XMLDOM")
                    xmlInheritedDoc.async = "false"
                    xmlInheritedDoc.load(propsFile)
                    
                    ' Get intermediate file output directory
                    Set IntDirNodes = xmlInheritedDoc.getElementsByTagName("IntDir")
                    For Each IntDirNode In IntDirNodes
                        If IsEmpty(IntOutDir) Then
                            IntOutDir = IntDirNode.text
                        End If
                    Next
                    
                    ' Get project name
                    Set PropertySheetDisplayNameNodes = xmlInheritedDoc.getElementsByTagName("_PropertySheetDisplayName")
                    For Each PropertySheetDisplayNameNode In PropertySheetDisplayNameNodes
                        If IsEmpty(ProjName) Then
                            ProjName = PropertySheetDisplayNameNode.text
                        End If
                    Next
                   
                    ' Get build output directory
                    Set OutDirNodes = xmlInheritedDoc.getElementsByTagName("OutDir")
                    For Each OutDirNode In OutDirNodes
                        outDirBuild = OutDirNode.text
                    Next
                    
                    Set ClCompileNodes =  xmlInheritedDoc.getElementsByTagName("ClCompile")
                    For Each ClCompileNode in ClCompileNodes
                        If ClCompileNode.hasChildNodes() = True Then
                            ' Get include directories
                            Set AdditionalIncludeDirectoriesNodes = ClCompileNode.childNodes
                            For Each AdditionalIncludeDirectoriesNode In AdditionalIncludeDirectoriesNodes
                                If AdditionalIncludeDirectoriesNode.nodeName = "AdditionalIncludeDirectories" Then
                                    'If InStr(AdditionalIncludeDirectoriesNode.text, "%(AdditionalIncludeDirectories)") <> 0 Then 'Not IsEmpty(IncDirs) Then
                                        IncDirs = Replace(AdditionalIncludeDirectoriesNode.text,"%(AdditionalIncludeDirectories)", IncDirs)
                                    'Else
                                    '    IncDirs = IncDirs & AdditionalIncludeDirectoriesNode.text
                                    'End If
                                End If
                            Next
                            ' Get preprocessor definitions
                            Set PreprocessorDefinitionsNodes = ClCompileNode.childNodes
                            For Each PreprocessorDefinitionsNode In PreprocessorDefinitionsNodes
                                If PreprocessorDefinitionsNode.nodeName = "PreprocessorDefinitions" Then
                                    'If Not IsEmpty(PreDefs) Then
                                        PreDefs = Replace(PreprocessorDefinitionsNode.text,"%(PreprocessorDefinitions)", PreDefs)
                                    'Else
                                    '    PreDefs = PreprocessorDefinitionsNode.text
                                    'End If
                                End If
                            Next
                        End If
                    Next
                Next
            End If
            ' End Extracting information from *.props files
        End If
    End If
Next
' Next load tools from vcproj
Set ItemDefinitionGroupNodes = xmlDoc.getElementsByTagName("ItemDefinitionGroup")
For Each ItemDefinitionGroupNode in ItemDefinitionGroupNodes
    ConditionStr = ItemDefinitionGroupNode.getAttribute("Condition")
    ConditionStr = Replace(ConditionStr, "'$(Configuration)|$(Platform)'=='", "")
    ConditionStr = Replace(ConditionStr, "'", "")
    If ConditionStr = CfgName Then
        If ItemDefinitionGroupNode.hasChildNodes() = True Then
            ' Get include directories
            Set ClCompileNodes = ItemDefinitionGroupNode.childNodes
            For Each ClCompileNode In ClCompileNodes
                If ClCompileNode.nodeName = "ClCompile" Then
                    If ClCompileNode.hasChildNodes() = True Then
                        Set ClCompileSubNodes = ClCompileNode.childNodes
                        For Each ClCompileSubNode In ClCompileSubNodes
                            ' Get include directories
                            If ClCompileSubNode.nodeName = "AdditionalIncludeDirectories" Then
                                'If InStr(ClCompileSubNode.text, "%(AdditionalIncludeDirectories)") <> 0 Then 'Not IsEmpty(IncDirs) Then
                                    IncDirs = Replace(ClCompileSubNode.text,"%(AdditionalIncludeDirectories)", IncDirs)
                                'Else
                                '    IncDirs = IncDirs & ClCompileSubNode.text
                                'End If
                            End If
                            ' Get preprocessor definitions
                            If ClCompileSubNode.nodeName = "PreprocessorDefinitions" Then
                                'If Not IsEmpty(PreDefs) Then
                                    PreDefs = Replace(ClCompileSubNode.text,"%(PreprocessorDefinitions)", PreDefs)
                                'Else
                                '    PreDefs = ClCompileSubNode.text
                                'End If
                            End If
                        Next
                    End If
                End If
            Next
        End If
    End If
Next

If found = 0 Then
    Wscript.echo "Configuration " + CfgName + " was not found in " + prj_file + " aborting"
    Wscript.quit(1)
End If

' Determine short config name (without platform spec)
regEx.Pattern = "([^\|]+)\|([^\|]+)$"
CfgNameShort = regEx.Replace(CfgName, "$1")
' Determine project directory
ProjDir = "." + fso.GetParentFolderName(prj_file)

If Not IsNull(PreDefs) Then
    PreDefs = Replace(PreDefs,",",";",1, -1, 1)
    PreDefs = Replace(PreDefs,"$(ConfigurationName)",CfgNameShort,1, -1, 1)
    PreDefs = Replace(PreDefs,"$(Configuration)",CfgNameShort,1, -1, 1)
    IntOutDir = Replace(IntOutDir, "$(ProjectDir)", ProjDir)
    Do While Right(PreDefs,1) = ";"
        PreDefs = Left(PreDefs,Len(PreDefs)-1)
    Loop
    Do While Left(PreDefs,1) = ";"
        PreDefs = Right(PreDefs,Len(PreDefs)-1)
    Loop
End If

If Not IsNull(IncDirs) Then
    IncDirs = Replace(IncDirs,",",";",1, -1, 1)
    IncDirs = Replace(IncDirs,"""","",1, -1, 1)
    Do While Right(IncDirs,1) = ";"
        IncDirs = Left(IncDirs,Len(IncDirs)-1)
    Loop
    Do While Left(IncDirs,1) = ";"
        IncDirs = Right(IncDirs,Len(IncDirs)-1)
    Loop
End if

If Not IsEmpty(IntOutDir) Then
    IntOutDir = Replace(IntOutDir, "$(ConfigurationName)", CfgNameShort)
    IntOutDir = Replace(IntOutDir, "$(Configuration)\", CfgNameShort)
    IntOutDir = Replace(IntOutDir, "$(Configuration)", CfgNameShort)
    IntOutDir = Replace(IntOutDir, "$(ProjectDir)", ProjDir)
    If Not IsEmpty(ProjName) Then
        IntOutDir = Replace(IntOutDir, "$(ProjectName)", ProjName)
    End If
End If

EnvIncludes = WshShell.ExpandEnvironmentStrings("%INCLUDE%")
if Trim(EnvIncludes) = "%INCLUDE%" Then
    EnvIncludes = ""
End If
Do While Right(EnvIncludes,1) = ";"
    EnvIncludes = Left(EnvIncludes,Len(EnvIncludes)-1)
Loop

Do While Left(EnvIncludes,1) = ";"
    EnvIncludes = Right(EnvIncludes,Len(EnvIncludes)-1)
Loop

IncDirsArray = Split(IncDirs + ";" + EnvIncludes, ";")
for each CurIncDir in IncDirsArray
    ' Remove any unnecessary white-spaces or backslashes from the end of the path
    Do While Right(CurIncDir,1) = " " or Right(CurIncDir,1) = "\"
        CurIncDir = Left(CurIncDir, Len(CurIncDir)-1)
    Loop
    ' Remove any spurious white-spaces from the beginning of the path
    Do While Left(CurIncDir,1) = " "
        CurIncDir = Right(CurIncDir, Len(CurIncDir)-1)
    Loop
    ' If after the above removals we still have a valid path, then create a PDO string for it
    if Not IsNull(CurIncDir) and Len(CurIncDir) >= 1 Then
        If Not IsNull(IncDirsPdo) Then
            IncDirsPdo = IncDirsPdo + " ""-I" + CurIncDir + """"
        Else
            IncDirsPdo = """-I" + CurIncDir + """"
        End If
    End If
Next

IncDirs = IncDirs + ";" + EnvIncludes

If Not IsNull(PreDefs) Then
    PreDefs = "-D" + Replace(PreDefs, ";", " -D",1, -1, 1) 
Else
    PreDefs = ""
End If

Set makeFile = fso.CreateTextFile("makesdl"+makeFileNameSuffix, True)

makeFile.WriteLine(".SUFFIXES : .c .dat .sdl")
makeFile.WriteLine("PDO_SCAN = "+pdo_dir+"\pdo_scan.exe")
makeFile.WriteLine("PDO_TOOL = "+pdo_dir+"\pdo_tool.exe")
makeFile.WriteLine("CDL_TOOL = "+sdl_dir+"\SDLCompiler.exe")

makeFile.WriteLine("PDO_SCAN_OPT = --enable-vsmsg -c "+pdo_dir+"\msvc_x86_pdo_cmt.cfg -d0")
makeFile.WriteLine("PDO_TOOL_OPT = -f sdl2.0 --disable normalobj --enable virtualobj " + sdl_gen_opts +" ")

makeFile.WriteLine("INC_OPTS = " + IncDirsPdo)
makeFile.WriteLine("DEF_OPTS = " + PreDefs)

If IsNull(IntOutDir) Or IntOutDir = "$(ConfigurationName)" Then
    IntOutDir = objArgs(0)
End If

makeFile.WriteLine("OUT_DIR ="+IntOutDir)

Target = CdlName
regEx.pattern = "(\S+\\)*(\w\\)*(\w+)\.cdl$"
Target_2 = regEx.replace(CdlName, "$1$2$3_be.cdl")
LogFile1 = regEx.Replace(CdlName, "$1$2$3.log")
LogFile2 = regEx.Replace(Cdlname, "$1$2$3_be.log")

makeFile.WriteLine("all : " & Target & " " & Target_2)

makeFile.WriteLine(Target +" : ")
makeFile.WriteLine(vbTab & "@echo Generating CDL File $@")
makeFile.WriteLine(vbTab & "-@if not exist " & IntOutDir & " mkdir " & IntOutDir)
makeFile.WriteLine(vbTab & "@$(CDL_TOOL) compile -if$(OUT_DIR)\pdo_sim_plg.sdl -of$@ -df$(OUT_DIR)\$(@B).sd_ -lf$(OUT_DIR)\$(@B).log -le -us > " + LogFile1)


makeFile.WriteLine(Target_2 +" : " & Target)
makeFile.WriteLine(vbTab & "@echo Generating CDL File $@")
makeFile.WriteLine(vbTab & "-@if not exist " & IntOutDir & " mkdir " & IntOutDir)
makeFile.WriteLine(vbTab & "@$(CDL_TOOL) compile -if$(OUT_DIR)\pdo_sim_plg.sdl -of$@ -df$(OUT_DIR)\$(@B).sd_ -lf$(OUT_DIR)\$(@B).log -be -us > " + LogFile2)
makeFile.WriteLine(Target & " : " & IntOutDir & "\pdo_sim_plg.sdl")

regEx.Pattern = "(\S+\\)*(\w+\\)*" & file_regex_pattern & "$"

DatFiles = ""

Set ItemGroupNodes = xmlDoc.getElementsByTagName("ItemGroup")
For Each ItemGroupNode in ItemGroupNodes
    If ItemGroupNode.HasChildNodes() = True Then
        Set ItemGroupSubNodes = ItemGroupNode.childNodes
        For Each ItemGroupSubNode In ItemGroupSubNodes
            If ItemGroupSubNode.nodeName = "ClCompile" Then
                ExcludedFromBuild = False
                If ItemGroupSubNode.HasChildNodes() = True Then
                    Set ExcludedFromBuildNodes = ItemGroupSubNode.getElementsByTagName("ExcludedFromBuild")
                    For Each ExcludedFromBuildNode In ExcludedFromBuildNodes
                        ConditionStr = ExcludedFromBuildNode.GetAttribute("Condition")
                        ConditionStr = Replace(ConditionStr, "'$(Configuration)|$(Platform)'=='", "")
                        ConditionStr = Replace(ConditionStr, "'", "")
                        If ConditionStr = CfgName Then
                            If ExcludedFromBuildNode.text = "true" Then
                                ExcludedFromBuild = True
                            End If
                        End If
                    Next
                End If
                If ExcludedFromBuild = False Then
                    path = ItemGroupSubNode.getAttribute("Include")
                    If regEx.Test(path) Then
                        no_ext = regEx.Replace(path, "$3")
                        ext    = regEx.Replace(path, "$4")
                        'DatFiles = DatFiles & outDir & "\" & no_ext & ".dat "
                        DatFiles = DatFiles & IntOutDir & "\" & no_ext & ".dat "
                        'makeFile.WriteLine(outDir & "\" & no_ext & ".dat : " & path & " " & outDir & "\" & no_ext & ".obj")
                        makeFile.WriteLine(IntOutDir & "\" & no_ext & ".dat : " & path & " " & IntOutDir & "\" & no_ext & ".obj")
                        makeFile.WriteLine(vbTab & "-@echo Parsing Source File " & path & "...")
                        makeFile.WriteLine(vbTab & "-@$(PDO_SCAN) $(PDO_SCAN_OPT) $(INC_OPTS) $(DEF_OPTS) -o$@ " & path)
                    End if
                End If
            End If
        Next
    End If
Next

makeFile.WriteLine(IntOutDir & "\pdo_sim_plg.sdl : " & DatFiles)
makeFile.WriteLine(vbTab & "-@echo Generating SDL File $@ ...")
makeFile.WriteLine(vbTab & "-@$(PDO_TOOL) $(PDO_TOOL_OPT) -o$@ " & DatFiles)


makeFile.Close
elseif (Prtype = "vcproj") Then
stdout.WriteLine "VS2005 project"
Set rootNode = xmlDoc.documentElement
' Extract project name
ProjName = rootNode.GetAttribute("Name")
Set cfgs = xmlDoc.getElementsByTagName("Configuration")
found = 0
For each cfg in cfgs 
    If cfg.getAttribute("Name") = CfgName Then
        found = 1
        outDir = cfg.getAttribute("IntermediateDirectory")
        ' Check if any inherited property sheets
        inherited_prop_name = cfg.getAttribute("InheritedPropertySheets")
        If not IsNull(inherited_prop_name) Then
            ' Split up inherited prop name into multiple vsprops files (they are seperated by ';')
            vsprops_files = Split(inherited_prop_name, ";")
            For each vsprops_file in vsprops_files
                ' Load inherited property sheet, and extract include paths and pre-processor definitions from it
                Set xmlInheritedDoc=CreateObject("Microsoft.XMLDOM")
                xmlInheritedDoc.async = "false"
                xmlInheritedDoc.load(vsprops_file)
                Set inheritedRoot = xmlInheritedDoc.documentElement
                ' If intermediate directory not set yet, see if inherited from this property sheet
                If IsNull(outDir) Then
                    outDir = inheritedRoot.getAttribute("IntermediateDirectory")
                End If
                ' If project name not set yet, see if inherited from this property sheet
                If IsNull(ProjName) Then
                    ProjName = inheritedRoot.getAttribute("Name")
                End If
                ' Loop over tools settings in inherited property sheet
                Set inheritedTools = xmlInheritedDoc.getElementsByTagName("Tool")
                For each tool in inheritedTools
                    If tool.getAttribute("Name") = "VCCLCompilerTool" Then
                        If Not IsNull(IncDirs) Then
                            IncDirs = IncDirs + ";" + tool.getAttribute("AdditionalIncludeDirectories")
                        Else
                            IncDirs = tool.getAttribute("AdditionalIncludeDirectories")
                        End If
                        If Not IsNull(PreDefs) Then
                            PreDefs = PreDefs + ";" + tool.getAttribute("PreprocessorDefinitions")
                        Else
                            PreDefs = tool.getAttribute("PreprocessorDefinitions")
                        End If
                    End If
                Next
                If Not IsNull(PreDefs) Then
                    Do While Right(PreDefs,1) = ";"
                        PreDefs = Left(PreDefs,Len(PreDefs)-1)
                    Loop
                End If
            Next

            If Not IsNull(IncDirs) Then
                Do While Right(IncDirs,1) = ";"
                    IncDirs = Left(IncDirs,Len(IncDirs)-1)
                Loop
            End if  
        End If
        ' Next load tools from vcproj
        Set tools = cfg.getElementsByTagName("Tool")
        For each tool in tools
            If tool.getAttribute("Name") = "VCCLCompilerTool" Then
                Temp = tool.getAttribute("AdditionalIncludeDirectories")
                If Not IsNull(Temp) Then
                    IncDirs = IncDirs + ";" + Temp
                End If
                Temp = tool.getAttribute("PreprocessorDefinitions")
                If Not IsNull(Temp) Then
                    If Not IsNull (PreDefs) Then
                        PreDefs = PreDefs + ";" + Temp
                    Else
                        PreDefs = Temp
                    End If
                End If
            End If
        Next
    End If
Next
If found = 0 Then
    Wscript.echo "Configuration " + CfgName + " was not found in " + prj_file + " aborting"
    Wscript.quit(1)
End If
' Determine short config name (without platform spec)
regEx.Pattern = "([^\|]+)\|([^\|]+)$"
CfgNameShort = regEx.Replace(CfgName, "$1")
' Determine project directory
ProjDir = "." + fso.GetParentFolderName(prj_file)

If Not IsNull(PreDefs) Then
    PreDefs = Replace(PreDefs,",",";",1, -1, 1)
    PreDefs = Replace(PreDefs,"$(ConfigurationName)",CfgNameShort,1, -1, 1)
    outDir = Replace(outDir, "$(ProjectDir)", ProjDir)
    Do While Right(PreDefs,1) = ";"
        PreDefs = Left(PreDefs,Len(PreDefs)-1)
    Loop
    Do While Left(PreDefs,1) = ";"
        PreDefs = Right(PreDefs,Len(PreDefs)-1)
    Loop
End If

If Not IsNull(IncDirs) Then
    IncDirs = Replace(IncDirs,",",";",1, -1, 1)
    IncDirs = Replace(IncDirs,"""","",1, -1, 1)
    Do While Right(IncDirs,1) = ";"
        IncDirs = Left(IncDirs,Len(IncDirs)-1)
    Loop
    Do While Left(IncDirs,1) = ";"
        IncDirs = Right(IncDirs,Len(IncDirs)-1)
    Loop
End if

If Not IsNull(outDir) Then
    outDir = Replace(outDir, "$(ConfigurationName)", CfgNameShort)
    outDir = Replace(outDir, "$(ProjectDir)", ProjDir)
    If Not IsNull(ProjName) Then
        outDir = Replace(outDir, "$(ProjectName)", ProjName)
    End If
End If

EnvIncludes = WshShell.ExpandEnvironmentStrings("%INCLUDE%")
Do While Right(EnvIncludes,1) = ";"
    EnvIncludes = Left(EnvIncludes,Len(EnvIncludes)-1)
Loop

Do While Left(EnvIncludes,1) = ";"
    EnvIncludes = Right(EnvIncludes,Len(EnvIncludes)-1)
Loop

IncDirsArray = Split(IncDirs + ";" + EnvIncludes, ";")
for each CurIncDir in IncDirsArray
    ' Remove any unnecessary white-spaces or backslashes from the end of the path
    Do While Right(CurIncDir,1) = " " or Right(CurIncDir,1) = "\"
        CurIncDir = Left(CurIncDir, Len(CurIncDir)-1)
    Loop
    ' Remove any spurious white-spaces from the beginning of the path
    Do While Left(CurIncDir,1) = " "
        CurIncDir = Right(CurIncDir, Len(CurIncDir)-1)
    Loop
    ' If after the above removals we still have a valid path, then create a PDO string for it
    if Not IsNull(CurIncDir) and Len(CurIncDir) >= 1 Then
        If Not IsNull(IncDirsPdo) Then
            IncDirsPdo = IncDirsPdo + " ""-I" + CurIncDir + """"
        Else
            IncDirsPdo = """-I" + CurIncDir + """"
        End If
    End If
Next

IncDirs = IncDirs + ";" + EnvIncludes

If Not IsNull(PreDefs) Then
    PreDefs = "-D" + Replace(PreDefs, ";", " -D",1, -1, 1) 
Else
    PreDefs = ""
End If

Set makeFile = fso.CreateTextFile("makesdl"+makeFileNameSuffix, True)

makeFile.WriteLine(".SUFFIXES : .c .dat .sdl")
makeFile.WriteLine("PDO_SCAN = "+pdo_dir+"\pdo_scan.exe")
makeFile.WriteLine("PDO_TOOL = "+pdo_dir+"\pdo_tool.exe")
makeFile.WriteLine("CDL_TOOL = "+sdl_dir+"\SDLCompiler.exe")

makeFile.WriteLine("PDO_SCAN_OPT = --enable-vsmsg -c "+pdo_dir+"\msvc_x86_pdo_cmt.cfg -d0")
makeFile.WriteLine("PDO_TOOL_OPT = -f sdl2.0 --disable normalobj --enable virtualobj " + sdl_gen_opts +" ")

makeFile.WriteLine("INC_OPTS = " + IncDirsPdo)
makeFile.WriteLine("DEF_OPTS = " + PreDefs)

If IsNull(outDir) Or outDir = "$(ConfigurationName)" Then
    outDir = objArgs(0)
End If

makeFile.WriteLine("OUT_DIR ="+outDir)

Target = CdlName
regEx.pattern = "(\S+\\)*(\w\\)*(\w+)\.cdl$"
Target_2 = regEx.replace(CdlName, "$1$2$3_be.cdl")
LogFile1 = regEx.Replace(CdlName, "$1$2$3.log")
LogFile2 = regEx.Replace(Cdlname, "$1$2$3_be.log")

makeFile.WriteLine("all : " & Target & " " & Target_2)

makeFile.WriteLine(Target +" : ")
makeFile.WriteLine(vbTab & "@echo Generating CDL File $@")
makeFile.WriteLine(vbTab & "-@if not exist " & OutDir & " mkdir " & OutDir)
makeFile.WriteLine(vbTab & "@$(CDL_TOOL) compile -if$(OUT_DIR)\pdo_sim_plg.sdl -of$@ -df$(OUT_DIR)\$(@B).sd_ -lf$(OUT_DIR)\$(@B).log -le -us > " + LogFile1)


makeFile.WriteLine(Target_2 +" : " & Target)
makeFile.WriteLine(vbTab & "@echo Generating CDL File $@")
makeFile.WriteLine(vbTab & "-@if not exist " & OutDir & " mkdir " & OutDir)
makeFile.WriteLine(vbTab & "@$(CDL_TOOL) compile -if$(OUT_DIR)\pdo_sim_plg.sdl -of$@ -df$(OUT_DIR)\$(@B).sd_ -lf$(OUT_DIR)\$(@B).log -be -us > " + LogFile2)
makeFile.WriteLine(Target & " : " & outDir & "\pdo_sim_plg.sdl")

regEx.Pattern = "(\S+\\)*(\w+\\)*" & file_regex_pattern & "$"

DatFiles = ""

Set Files = xmlDoc.getElementsByTagName("File")
For each file in Files
  Set fcfgs = file.getElementsByTagName("FileConfiguration")
  If fcfgs.length <> 0 Then
    For each fcfg in fcfgs 
      If fcfg.getAttribute("Name") = CfgName And (IsNull(fcfg.getAttribute("ExcludedFromBuild")) or fcfg.getAttribute("ExcludedFromBuild")<>"true")  Then
        Set e_fcfgs =  fcfg.childNodes
        For each e_fcfg in e_fcfgs
          If e_fcfg.nodename = "Tool" and e_fcfg.getAttribute("Name") = "VCCLCompilerTool" Then
            path = file.getAttribute("RelativePath")
            If regEx.Test(path) Then
              no_ext = regEx.Replace(path, "$3")
              ext    = regEx.Replace(path, "$4")
              DatFiles = DatFiles & outDir & "\" & no_ext & ".dat "
              makeFile.WriteLine(outDir & "\" & no_ext & ".dat : " & path & " " & outDir & "\" & no_ext & ".obj")
              makeFile.WriteLine(vbTab & "-@echo Parsing Source File " & path & "...")
              makeFile.WriteLine(vbTab & "-@$(PDO_SCAN) $(PDO_SCAN_OPT) $(INC_OPTS) $(DEF_OPTS) -o$@ " & path)
            End if
         End If
        Next
      End If
    Next
  Else
    path = file.getAttribute("RelativePath")
    If regEx.Test(path) Then
      no_ext = regEx.Replace(path, "$3")
      ext    = regEx.Replace(path, "$4")
      DatFiles = DatFiles & outDir & "\" & no_ext & ".dat "
      makeFile.WriteLine(outDir & "\" & no_ext & ".dat : " & path & " " & outDir & "\" & no_ext & ".obj")
      makeFile.WriteLine(vbTab & "-@echo Parsing Source File " & path & "...")
      makeFile.WriteLine(vbTab & "-@$(PDO_SCAN) $(PDO_SCAN_OPT) $(INC_OPTS) $(DEF_OPTS) -o$@ " & path)
    End if
  End If
Next

makeFile.WriteLine(outDir & "\pdo_sim_plg.sdl : " & DatFiles)
makeFile.WriteLine(vbTab & "-@echo Generating SDL File $@ ...")
makeFile.WriteLine(vbTab & "-@$(PDO_TOOL) $(PDO_TOOL_OPT) -o$@ " & DatFiles)


makeFile.Close

else
stdout.WriteLine "unknown project type"
stdout.WriteLine prtype

end if