import sys
import os
import string
import argparse
import re

FilterLst={
		 'c_source_files':          ['Not Found',       r'c_source_files {((\s+\S+\n)*)}'],
		 'include_directories':     ['Not Found',       r'include_directories {((\s+\S+\n)*)}'],
		 'defines':                 ['Not Found',       r'defines {((\s+\S+\n)*)}'],
		 'algo_tags':               ['Not Found',       r'\S+_algo_pdo_sources\s+=\s+"""((\s+\S+\n)*)"""'],
		 'algo_tags_specific':      ['Not Found',       r'\s+\S+_algo_pdo_sources_project_specific\s+=\s+"""((\s+\S+\n)*)"""']}
		 	
def FilterData ( Data, FilterDict ):

	for DictKey in FilterDict.keys():
		pattern = re.compile(FilterDict[DictKey][1], re.DOTALL)
		find    = pattern.search( Data )
		if find:
			if FilterDict[DictKey][0] == 'Not Found':
				FilterDict[DictKey][0]= find.group(1)
			else:
				FilterDict[DictKey][0]+= find.group(1)

def main (Args):
		parse = argparse.ArgumentParser(description='Helper for Integrating. Fast checkout only Configure Subprojects with imediately drop Sandbox')
		parse.add_argument('LstFile',   nargs='*', type=argparse.FileType('r'), default=sys.stdin, help='Input Lst File')
		parse.add_argument('-i','--Includes',      type=str,                    default=None,      help='Output File for Includes from lst file')
		parse.add_argument('-c','--CFiles',        type=str,                    default=None,      help='Output File for cFiles from lst file')
		parse.add_argument('-p','--PDO',           type=str,                    default=None,      help='Output File for cFiles from lst file')
		parse.add_argument('-d','--Defines',       type=str,                    default=None,      help='Output File for DFiles from lst file')
		parse.add_argument('-S','--Sort',          action='store_true',                            help='Sort to uniq outputs')
		#parse.add_argument( 'OutFile', nargs='?', type=argparse.FileType('w'), default=sys.stdout  help='Output file stdout is default')

		ns = parse.parse_args(Args)
		
		for i in ns.LstFile:
			DataLst = i.readlines()
			FilterData("".join(DataLst), FilterLst)

		#print (FilterLst)
		if ns.CFiles!=None:
			with open(ns.CFiles, 'w+') as fo:
				AList = FilterLst['c_source_files'][0].split()
				if ns.Sort:
					AList = list(set(AList))

				# Workaround PDO tool: Hierarchy limitation of maximum '16' levels. Hence, provide relative paths.
				# Adrian Dronca has been informed and will provide a fix soon.
				for i, val in enumerate(AList):
					AList[i] = os.path.relpath(val)

				strv = "\n".join(AList)
				strv = strv.replace("\\","/")

				#print (strv)
				fo.write(strv)
                
		if ns.PDO!=None:
			with open(ns.PDO, 'w+') as fo:
				#AList = FilterLst['algo_tags'][0].split()
				AList = FilterLst['algo_tags_specific'][0].split()
				if ns.Sort:
					AList = list(set(AList))
				strv = "\n".join(AList)
				strv = strv.replace("\\","/")

				print (strv)
				#fo.write(strv)       

		if ns.Includes!=None:
			with open(ns.Includes, 'w+') as fo:
				AList = ["\""+ i + "\"" for i in FilterLst['include_directories'][0].split()]
				if ns.Sort:
					AList = list(set(AList))
				strv = "sys_include_dirs = "
				strv = strv + ",\n".join(AList)
				strv = strv + ";"
				#strv = strv.replace("\\","/")+"\";"
				
				#print (strv)
				fo.write(strv)

		if ns.Defines!=None:
			with open(ns.Defines, 'w+') as fo:
				AList = FilterLst['defines'][0].split()
				if ns.Sort:
					AList = list(set(AList))
				strv = " ".join(AList)
				
				#print (strv)
				fo.write(strv)

#D:\prj\MFC431x\MFC431_Trunk\DPU\04_Engineering\03_Workspace\sw\pdo\sdl>c:\tools\python\2.7.10\python.exe ..\..\..\..\..\04_Engineering\03_Workspace\sw\pdo\readLstFile.py -i ..\..\..\..\..\04_Engineering\04_build\sdl\\target_headerFile.cfg -c ..\..\..\..\..\04_Engineering\04_build\sdl\\compiler_input.txt -d ..\..\..\..\..\04_Engineering\04_build\sdl\\compiler_defines.txt ..\..\..\..\..\04_Engineering\04_build\out\mfc431\release_arm-a_0\arm-a_0.lst 

main(sys.argv[1:])