Option Explicit
REM We use "Option Explicit" to help us check for coding mistakes

REM the Excel Application
Dim objExcel
REM the text file Application
Dim objFSO
Dim objOutFile
REM the path to the excel file
Dim excelPath
REM the path to the text output file
Dim txtOut
REM the current path where I am
Dim myCurrentPath
REM how many worksheets are in the current excel file
Dim worksheetCount
Dim counter
REM the worksheet we are currently getting data from
Dim currentWorkSheet
REM the number of columns in the current worksheet that have data in them
Dim usedColumnsCount
REM the number of rows in the current worksheet that have data in them
Dim usedRowsCount
Dim row
Dim column
REM the topmost row in the current worksheet that has data in it
Dim top
REM the leftmost row in the current worksheet that has data in it
Dim left
Dim Cells
REM the current row and column of the current worksheet we are reading
Dim curCol
Dim curRow
REM the value of the current row and column of the current worksheet we are reading
Dim word

WScript.Echo "Running generate_SourceListName.vbs"

REM find out where I am
myCurrentPath = CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.ScriptFullName)

REM quit script if parameter is wrong
If WScript.Arguments.Count = 0 then
    WScript.Echo "Missing parameter!"
	Wscript.Quit

REM where is the Excel file located?
ElseIf WScript.Arguments(0) = "MFC4T0" Then
	WScript.Echo "Generating with Option: MFC4T0" & vbCrLf
	excelPath = myCurrentPath & "\..\..\..\..\..\01_Supporting_Processes\01_Project_Management\02_Planning\QualityStatusFiles\SW_SMFC4T0_SoC_FileStatusOverview_560A.xlsm"
ElseIf WScript.Arguments(0) = "mfc431" Then
	WScript.Echo "Generating with Option: mfc431" & vbCrLf
	excelPath = myCurrentPath & "\..\..\..\..\..\01_Supporting_Processes\01_Project_Management\02_Planning\QualityStatusFiles\SW_MFC400_SoC_FileStatusOverview_trunk.xlsm"
ElseIf WScript.Arguments(0) = "mfl420ta46" Then
	WScript.Echo "Generating with Option: mfl420ta46" & vbCrLf
	excelPath = myCurrentPath & "\..\..\..\..\..\01_Supporting_Processes\01_Project_Management\02_Planning\QualityStatusFiles\SW_MFL420_SoC_FileStatusOverview_R3.0.xlsm"
Else
	WScript.Echo "Wrong parameter!"
	Wscript.Quit
End If

REM where text file is located
txtOut = myCurrentPath & "\source_list_" & WScript.Arguments(0) & "\fromXLS_SourceListNames.txt"

REM WScript.Echo "Reading Data from: " & excelPath
REM WScript.Echo "Writing Data to:   " & txtOut

REM Create an invisible version of Excel
Set objExcel = CreateObject("Excel.Application")
REM Create an invisible version of the output file
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objOutFile = objFSO.CreateTextFile(txtOut,True)    

REM don't display any messages about documents needing to be converted
REM from  old Excel file formats
objExcel.DisplayAlerts = 0

REM open the excel document as read-only
REM open (path, confirmconversions, readonly)
objExcel.Workbooks.open excelPath, false, true

REM How many worksheets are in this Excel documents
workSheetCount = objExcel.Worksheets.Count
REM WScript.Echo vbCRLF & "We have " & workSheetCount & " worksheets"
REM Set the worksheet number to be read
counter = 2
REM WScript.Echo "Reading data from worksheet " & counter & vbCRLF

Set currentWorkSheet = objExcel.ActiveWorkbook.Worksheets(counter)
REM how many columns are used in the current worksheet
usedColumnsCount = currentWorkSheet.UsedRange.Columns.Count
REM how many rows are used in the current worksheet
usedRowsCount = currentWorkSheet.UsedRange.Rows.Count
REM What is the topmost row in the spreadsheet that has data in it
top = currentWorksheet.UsedRange.Row
REM What is the leftmost column in the spreadsheet that has data in it
left = currentWorksheet.UsedRange.Column

Set Cells = currentWorksheet.Cells
REM Loop through each row in the worksheet 
For row = 22 to (usedRowsCount-1)
	REM only look at rows that are in the "used" range
	curRow = row+top
	REM only look at columns that are in the "used" range
	curCol = column+left
	REM get the value/word that is in the cell 
	word = Cells(curRow,curCol+4).Value & ";"&Cells(curRow,curCol).Value & Cells(curRow,curCol+1).Value
	REM display the column on the screen and write to file if column 1 is not empty
	If Cells(curRow,curCol+1).Value <> "" Then
		REM WScript.Echo (word)
		objOutFile.Write (word & vbCrLf)
	End If
Next

REM We are done with the current worksheet, release the memory
Set currentWorkSheet = Nothing

objExcel.Workbooks(1).Close
objExcel.Quit
objOutFile.Close

Set currentWorkSheet = Nothing
REM We are done with the Excel object, release it from memory
Set objExcel = Nothing