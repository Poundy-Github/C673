'**********************************************************************
'
'  COMPANY:          Continental Temic, BC DAS, A.D.C. GmbH
'
'  MODULNAME:        res_patch.vbs
'
'  DESCRIPTION:      Automatically insert version, build number and
'                    and build date to resource information
'
'  VERSION:          $Revision: 1.1 $
'
'  DATE:             $Date: 2021/12/13 19:26:14CET $
'
'**********************************************************************

Option Explicit  'require all variables to be declared

Dim colNamedArguments   
Dim fso                ' File system object to get file access 
Dim SrcFile            ' C Source file to read current version
Dim RcFile             ' Windows resource file to patch 
Dim file               ' File handle

Dim strResFileName
Dim strSourceFileName
Dim strPrjName

Dim SrcLines

Dim strVerMain
Dim strVerSub
Dim strVerFix
Dim strBuild
Dim BuildNo
Dim WshShell

Dim regEx ' Regular expression object for file extension filter
Dim Matches

Set colNamedArguments = WScript.Arguments.Named
Set WshShell = WScript.CreateObject("WScript.Shell")
Set fso = CreateObject("Scripting.FileSystemObject")
Set regEx = New RegExp 

If colNamedArguments.Exists("V") Then
	strSourceFileName = colNamedArguments.Item("V")
Else
	strSourceFileName = "..\..\..\..\01_Source_Code\algo\em\frame\em_ext.h"
End If

If colNamedArguments.Exists("R") Then
	strResFileName = colNamedArguments.Item("R")
Else
	strResFileName = "sim_swc_em.rc" 
End If


If colNamedArguments.Exists("D") Then
	strPrjName = colNamedArguments.Item("D")
	strPrjName = Replace(CStr(strPrjName), "CFG_", "", 1, -1, 1)
Else
	WScript.Quit(1)
	WScript.Echo "Error"
End If

' Scan C header file to get version number
Set SrcFile = fso.OpenTextFile(strSourceFileName)
SrcLines = SrcFile.ReadAll()

regEx.Pattern = "#define\W+\w+ALL_SW_MAIN_VER_NO\W+(0x)?([0-9a-fA-F]+)U?.*"
Set Matches = regEx.Execute(SrcLines)
strVerMain = Matches(0).SubMatches(1)

regEx.Pattern = "#define\W+\w+ALL_SW_SUB_VER_NO\W+(0x)?([0-9a-fA-F]+)U?.*"
Set Matches = regEx.Execute(SrcLines)
strVerSub = Matches(0).SubMatches(1)

regEx.Pattern = "#define\W+\w+ALL_SW_BUG_FIX_LEV\W+(0x)?([0-9a-fA-F]+)U?.*"
Set Matches = regEx.Execute(SrcLines)
strVerFix = Matches(0).SubMatches(1)

SrcFile.Close

' Replace entries in resource file
Set RcFile = fso.OpenTextFile(strResFileName)
SrcLines = RcFile.ReadAll()
RcFile.Close

regEx.Pattern = "VALUE\W+""FileVersion"",\W*""\W*[0-9]+,\W+[0-9]+,\W+[0-9]+,\W+([0-9]+)\W*"
Set Matches = regEx.Execute(SrcLines)

strBuild = Matches(0).SubMatches(0)
BuildNo = CInt(strBuild)
BuildNo = BuildNo + 1

regEx.Pattern = "(FILEVERSION\W+).*"
SrcLines = regEx.Replace(SrcLines,"$1" + strVerMain + ", " + strVerSub + ", " + strVerFix + ", " + CStr(BuildNo) + vbCR) 

regEx.Pattern = "(PRODUCTVERSION\W+).*"
SrcLines = regEx.Replace(SrcLines,"$1" + strVerMain + ", " + strVerSub + ", " + strVerFix + ", " + CStr(BuildNo) + vbCR) 

regEx.Pattern = "(VALUE\W+""Comments"",).*"
SrcLines = regEx.Replace(SrcLines,"$1 """ + WshShell.ExpandEnvironmentStrings("%USERNAME%") + " "+ CStr(Now) + """" + vbCR) 

regEx.Pattern = "(VALUE\W+""FileVersion"",).*"
SrcLines = regEx.Replace(SrcLines,"$1 """ + strVerMain + ", " + strVerSub + ", " + strVerFix + ", " + CStr(BuildNo) + """" + vbCR) 

regEx.Pattern = "(VALUE\W+""ProductVersion"",).*"
SrcLines = regEx.Replace(SrcLines,"$1 """ + strVerMain + ", " + strVerSub + ", " + strVerFix + ", " + CStr(BuildNo) + """"+ vbCR) 

regEx.Pattern = "(VALUE\W+""InternalName"",).*"
SrcLines = regEx.Replace(SrcLines,"$1 """ + strPrjName + """" + vbCR) 

regEx.Pattern = "(VALUE\W+""ProductName"",).*"
SrcLines = regEx.Replace(SrcLines,"$1 """ + strPrjName + """" + vbCR) 

' Remove Read-Only attributes
If fso.FileExists(strResFileName) Then
	Set file = fso.GetFile(strResFileName)
	if file.attributes and 1 then
		file.attributes = file.attributes - 1
	End If
End If

' Write modification to file
Set RcFile = fso.OpenTextFile(strResFileName, 2, True, 0)
RcFile.Write(SrcLines)
RcFile.Close

