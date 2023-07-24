/*!  \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC

CPU:            PC

COMPONENT:      COD - Object detection

MODULNAME:      csv_parser.c  

DESCRIPTION:    Implementation of CSV file parser
AUTHOR:         Andreas Jahnke

CREATION DATE:  07.11.2013

VERSION:        $Revision: 1.1 $

CHANGES:        $Log: csv_parser.cpp  $
CHANGES:        Revision 1.1 2021/12/13 21:33:44CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/03_Workspace/Component_Workspace/CML_sim/cml_evm_hil/vh28/C66xx/cantata_target_testing/project.pj
CHANGES:        Revision 1.4 2016/10/28 13:22:59CEST Jagannath-EXT, Anu (uid42056) 
CHANGES:        Added function for writing the hex output.
CHANGES:        Revision 1.4 2016/10/28 13:22:59CEST Jagannath-EXT, Anu (uid42056) 
CHANGES:        Added function for writing the hex output.
CHANGES:        Revision 1.4 2016/10/28 13:22:59CEST Jagannath-EXT, Anu (uid42056) 
CHANGES:        Added function for writing the hex output.
CHANGES:        Revision 1.3 2016/09/21 08:48:23CEST Naik, Balachandra (uidp1547) 
CHANGES:        Updated for mismatch in MSVC csv and the Target csv write
CHANGES:        Revision 1.2 2016/08/26 16:18:33CEST Naik, Balachandra (uidp1547) 
CHANGES:        Updated for linear memory parser implementation.
CHANGES:        Revision 1.1 2016/08/26 07:49:21CEST Naik, Balachandra (uidp1547) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/03_Workspace/algo/cml_sim/cml_evm_hil/vh28/evm_hil_projects/C66xx/cantata_target_testing/project.pj
CHANGES:        Revision 1.4 2016/06/06 06:31:03CEST Nuggu-EXT, Satish (uidp3554) 
CHANGES:        updated source file for AL_CML_01.09.09_INT-1_RC
CHANGES:        Revision 1.3 2016/03/31 06:00:57CEST Sansthanik, Vadiraj (uidr1064) 
CHANGES:        parser files for AL_CML_01.09.08_INT-1
CHANGES:        Revision 1.1 2015/02/27 16:51:03CET Maramreddy, Jayalakshmi (uidj4450) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/05_Testing/05_Test_Environment/algo/modtests/B2B_tests/cml_trigo/project.pj
CHANGES:        Revision 1.5 2014/06/13 13:42:26CEST Jahnke, Andreas (uidw8971) 
CHANGES:        added line at end of file
CHANGES:        --- Added comments ---  uidw8971 [Jun 13, 2014 1:42:27 PM CEST]
CHANGES:        Change Package : 186292:31 http://mks-psad:7002/im/viewissue?selection=186292
CHANGES:        Revision 1.4 2014/02/20 17:31:55CET Jahnke-EXT, Andreas (uidw8971) 
CHANGES:        Member moved from csv_parser.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VCL_VehicleDetection/05_Testing/05_Test_Environment/algo/modtests/cantata_tests/vcl/common/project.pj to csv_parser.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VCL_VehicleDetection/05_Testing/05_Test_Environment/algo/modtests/cantata_tests/vcl/Framework/project.pj.
CHANGES:        Revision 1.3 2013/11/12 18:32:04CET Jahnke-EXT, Andreas (uidw8971) 
CHANGES:        bugfix accessing file read buffer
CHANGES:        --- Added comments ---  uidw8971 [Nov 12, 2013 6:32:04 PM CET]
CHANGES:        Change Package : 186292:23 http://mks-psad:7002/im/viewissue?selection=186292
CHANGES:        Revision 1.2 2013/11/11 18:09:39CET Jahnke-EXT, Andreas (uidw8971) 
CHANGES:        fixed access violation
CHANGES:        --- Added comments ---  uidw8971 [Nov 11, 2013 6:09:39 PM CET]
CHANGES:        Change Package : 186292:16 http://mks-psad:7002/im/viewissue?selection=186292
CHANGES:        Revision 1.1 2013/11/08 09:20:04CET Jahnke-EXT, Andreas (uidw8971) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VCL_VehicleDetection/05_Testing/03_ModuleTest/vcl/02_Environment/common/project.pj

**************************************************************************** */

#include "csv_parser.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#include <sys/types.h>
//#include <sys/stat.h>

#ifndef NULL
#define NULL 0
#endif

#define CSV_PARSE_BUFLEN 256

#if 0
/***********************************************************************
Description:      Parses a CSV (comma separated value) string
Input parameter:  - a_src string to parse
- a_len string length
Output parameter: 
In/Out parameter: - a_Data CSV data parsed from input string
Return value:
Description:  CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
Preconditions:    - a_src != NULL
- a_len != NULL
- a_Data != NULL
Postconditions:   Iterate over a_Data and free the dynamic memory using the
free() function if data no longer needed.
**************************************************************************** */
int CSV_ParseString (const char* a_src, const size_t a_len, csv_data_t** a_Data)
{
	/* return value */
	int ret = CSV_PARSER_ERROR;

	/* Are parameters valid */
	if ((a_src != NULL) && (a_len > 0) && (a_Data != NULL))
	{
		/* points to the beginning of the CSV value */
		char* p_Start = (char*)a_src;
		/* points to the end of the CSV value*/
		char* p_End = NULL;

		/* search for delimiter */
		p_End = strstr (p_Start, CSV_DELIMITER);

		/* Delimiter found? */
		if (p_End != NULL)
		{
			/* YES - crete node and parse the rest of the string */

			/* CSV data structure */
			csv_data_t* p_Node = NULL;

			/* result string length */
			size_t u_ResLen = (size_t)(p_End - p_Start);

			/* resting length */
			size_t u_NewLen = a_len - u_ResLen;
			if ((u_NewLen > 0) && (*p_End == CSV_DELIMITER_CHAR))
			{
				u_NewLen = u_NewLen - 1;
			}

			/* create node */
			p_Node = (csv_data_t*)malloc (sizeof(csv_data_t));

			/* node successfully created? */
			if (p_Node != NULL)
			{
				/* YES - copy data and parse the rest */

				memset (p_Node, 0, sizeof(csv_data_t));

				/* allocate memory for the value */
				p_Node->value = (char*)calloc (u_ResLen, sizeof(char));
				/* memory allocation succeeded? */
				if (p_Node->value != NULL)
				{
					/* YES - copy data and parse the rest */
					memcpy (p_Node->value, p_Start, u_ResLen);
					p_Node->len = u_ResLen;


					/* set output param */
					*a_Data = p_Node;

					/* set new start position */
					p_Start = p_End + 1;

					/* end-of-string not reached? */
					if (u_NewLen > 0)
					{
						/* YES - recurion
						*/
						ret = CSV_ParseString (p_Start, u_NewLen, &p_Node->next);
					}
					else
					{
						/* NO - parsing finished */
						ret = CSV_PARSER_OK;
					}
				}
				else
				{
					/* NO - return error on memory allocation error */
					ret = CSV_PARSER_ERROR;
				}
			}
		}
		else
		{
			/* NO - only one CSV value */

			/* bytes to copy into CSV value */
			size_t u_ToCopy = a_len;

			/* copy data */
			csv_data_t* p_Node = (csv_data_t*)malloc (sizeof(csv_data_t));

			/* node created? */
			if (p_Node != NULL)
			{
				/* YES - copy value */
				memset (p_Node, 0, sizeof(csv_data_t));
				/* allocate buffer for the value */
				p_Node->value = (char*)calloc (u_ToCopy, sizeof(char));
				/* memory allocation succeeded? */
				if (p_Node->value != NULL)
				{
					/* YES - fill data */
					memcpy (p_Node->value, p_Start, u_ToCopy);
					p_Node->len = u_ToCopy;
					/* set output param */
					*a_Data = p_Node;

					/* set return value */
					ret = CSV_PARSER_OK;
				}
				else
				{
					/* NO - return error because of memory allocation error */
					ret = CSV_PARSER_ERROR;
				}
			}
			else
			{
				/* NO - return error because of memory allocation error */
				ret = CSV_PARSER_ERROR;
			}
		}
	}
	return ret;
}



/***********************************************************************
Description:      Parses a CSV (comma separated value) file
Input parameter:  - a_Path path to the source file
Output parameter: 
In/Out parameter: - a_Data CSV data parsed from source file
Return value:
Description:  CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
Preconditions:    - a_Path != NULL
- a_Path is not an empty-string
- a_Path is nul-terminated
- read access to file pointed by a_Path
- a_Data != NULL
Postconditions:   Output data will be stored in heap memory.
Iterate over a_Data and free the dynamic memory using the
free() function if data no longer needed.
**************************************************************************** */
int CSV_ParseCsvFile (const char *a_Path, csv_data_t** a_Data)
{
	int ret = CSV_PARSER_ERROR;
	if ((a_Data != NULL) && (a_Path != NULL))
	{
		/* file statistic */
		struct _stat fileInfo;
		/* return value of _stat() function */
		int i_FileStatRet = 0;
		/* file size */
		unsigned long u_FileSize = 0;
		/* number of bytes read */
		unsigned long u_TotalBytesRead = 0;

		memset (&fileInfo, 0, sizeof(fileInfo));

		/* get file information */
		i_FileStatRet = _stat (a_Path, &fileInfo);

		/* file information read successfully? */
		if (i_FileStatRet == 0)
		{
			/* YES - read file and parse content */

			/* open file for reading */
			FILE *fp = fopen (a_Path, "r");

			/* get file size */
			u_FileSize = (unsigned long)fileInfo.st_size;

			/* file opened successfully?       */
			if (fp != NULL)
			{
				/* YES - read and parse file */

				/* allocate buffer of size 'filesize' */
				char* p_FileBuf = (char*)calloc (u_FileSize, sizeof(char));

				/* memory allocation succeeded? */
				if (p_FileBuf != NULL)
				{
					/* YES - read and parse file */

					/* number of currently read bytes */
					size_t u_NumReadBytes = 0;
					/* pointer to current position in read buffer */
					char* p_ReadPtr = NULL;

					/* initialize read buffer */
					memset (p_FileBuf, 0, sizeof(char) * u_FileSize);

					/* read complete file */
					do
					{
						/* offset in read buffer */
						unsigned long u_Offset = u_TotalBytesRead;
						/* number of remaining bytes to read */
						unsigned long u_RemainingBytes = u_FileSize - u_TotalBytesRead;

						/* go to next position in read buffer */
						p_ReadPtr = p_FileBuf + u_Offset;

						/* read next amount of bytes */
						u_NumReadBytes = fread (p_ReadPtr, sizeof(char), u_RemainingBytes, fp);

						/* increase byte counter */
						if (u_NumReadBytes > 0)
						{
							u_TotalBytesRead = u_TotalBytesRead + u_NumReadBytes;
						}
					}
					while ((u_NumReadBytes > 0) && (u_TotalBytesRead < u_FileSize));

					/* parse file content */
					ret = CSV_ParseString (p_FileBuf, u_TotalBytesRead, a_Data);          

					/* free dynamic memory */
					free (p_FileBuf);
				}
				/* close file */
				fclose (fp);
			}
		}
	}
	return ret;
}


/***********************************************************************
Description:      Releases memory of CSV data chain
Input parameter:
Output parameter: 
In/Out parameter: - a_Data CSV data parsed from source file
Return value:
Preconditions:    - a_Data != NULL
- csv_data_t::value allocated as dynamic memory or NULL
Postconditions:   Output data will be stored in heap memory.
Iterate over a_Data and free the dynamic memory using the
free() function if data no longer needed.
Note that a_Data->next will point to invalid memory
location.
**************************************************************************** */
void CSV_FreeCsvData (csv_data_t *a_Data)
{
	csv_data_t* p_Current = a_Data;
	while (p_Current != NULL)
	{
		csv_data_t* p_Next = p_Current->next;
		if (p_Current->value != NULL)
		{
			free (p_Current->value);
		}
		free (p_Current);
		p_Current = p_Next;
	}
}


/***********************************************************************
Description:      Writes CSV data structure to file/output stream.
Input parameter:  - a_File pointer to open, write-enabled output stream
- a_Data CSV data parsed from source file
Output parameter: 
In/Out parameter:
Return value:
Description:  CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
Preconditions:    - a_Data != NULL
- csv_data_t::value allocated as dynamic memory or NULL
Postconditions:   Output data will be stored in heap memory.
Iterate over a_Data and free the dynamic memory using the
free() function if data no longer needed.
Note that a_Data->next will point to invalid memory
location.
**************************************************************************** */
int CSV_WriteData (FILE *a_File, const csv_data_t *a_Data)
{
	int ret = CSV_PARSER_ERROR;
	if (a_File != NULL)
	{
		const csv_data_t* p_Current = a_Data;
		ret = CSV_PARSER_OK;

		while (p_Current != NULL)
		{
			if ((p_Current->value != NULL) && (p_Current->len > 0))
			{
				size_t u_Written = fwrite (p_Current->value, sizeof(char), p_Current->len, a_File);
				if (u_Written < p_Current->len)
				{
					ret = CSV_PARSER_ERROR;
				}
			}
			if (p_Current->next != NULL)
			{
				if (fwrite (CSV_DELIMITER, sizeof(char), 1, a_File) < 1)
				{
					ret = CSV_PARSER_ERROR;
				}
			}
			fflush (a_File);
			p_Current = p_Current->next;
		}
	}
	return ret;
}
#endif


#ifdef LINKED_LIST_PARSER
/***********************************************************************
Description:      Writes CSV data structure to file/output stream.
Input parameter:  - a_File pointer to open, write-enabled output stream
- a_Data CSV data parsed from source file
Output parameter: 
In/Out parameter:
Return value:
Description:  CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
Preconditions:    - a_Data != NULL
- csv_data_t::value allocated as dynamic memory or NULL
Postconditions:   Output data will be stored in heap memory.
Iterate over a_Data and free the dynamic memory using the
free() function if data no longer needed.
Note that a_Data->next will point to invalid memory
location.
**************************************************************************** */
int CSV_WriteData_float32 (FILE *a_File, const csv_data_float_t *a_Data)
{
	int ret = CSV_PARSER_ERROR;
	if (a_File != NULL)
	{
		const csv_data_float_t* p_Current = a_Data;
		ret = CSV_PARSER_OK;

		while (p_Current != NULL)
		{
			if ((p_Current->value != NULL) && (p_Current->len > 0))
			{
				size_t u_Written = fprintf(a_File, "%6.6f",*(p_Current->value));
				if (u_Written < p_Current->len)
				{
					ret = CSV_PARSER_ERROR;
				}
			}
			if (p_Current->next != NULL)
			{
				if (fwrite (CSV_DELIMITER, sizeof(char), 1, a_File) < 1)
				{
					ret = CSV_PARSER_ERROR;
				}
			}
			fflush (a_File);
			p_Current = p_Current->next;
		}
	}
	return ret;
}
#else
int CSV_WriteData_float32 (FILE *a_File, csv_data_float_t *p_Current)
{
	int ret = CSV_PARSER_ERROR;
	if (a_File != NULL)
	{
		ret = CSV_PARSER_OK;

		while (p_Current->dataBufferSize)
		{
			if ((p_Current->value != NULL) && (p_Current->len > 0))
			{
				size_t u_Written = fprintf(a_File, "%6.6f",*(p_Current->value++));
				if (u_Written < p_Current->len)
				{
					ret = CSV_PARSER_ERROR;
				}
			}
			
			if (p_Current->dataBufferSize != 0)
			{
				if(p_Current->dataBufferSize > 1)
				{
					if (fwrite (CSV_DELIMITER, sizeof(char), 1, a_File) < 1)
					{
						ret = CSV_PARSER_ERROR;
					}
				}
				p_Current->dataBufferSize--;
			}
			fflush (a_File);			
		}
	}
	return ret;
}

int CSV_WriteData_hex (FILE *a_File, csv_data_float_t *p_Current)
{
	int ret = CSV_PARSER_ERROR;
	float32 tmp;
	float32 *f_tmp;
	uint32 *i_tmp;
	if (a_File != NULL)
	{
		ret = CSV_PARSER_OK;

		while (p_Current->dataBufferSize)
		{
			if ((p_Current->value != NULL) && (p_Current->len > 0))
			{
				f_tmp = p_Current->value++;
				i_tmp = (uint32 *)f_tmp;			
				size_t u_Written = fprintf(a_File, "%x",*i_tmp);
				if (u_Written < p_Current->len)
				{
					ret = CSV_PARSER_ERROR;
				}
			}
			
			if (p_Current->dataBufferSize != 0)
			{
				if(p_Current->dataBufferSize > 1)
				{
					if (fwrite (CSV_DELIMITER, sizeof(char), 1, a_File) < 1)
					{
						ret = CSV_PARSER_ERROR;
					}
				}
				p_Current->dataBufferSize--;
			}
			fflush (a_File);			
		}
	}
	return ret;
}
#endif