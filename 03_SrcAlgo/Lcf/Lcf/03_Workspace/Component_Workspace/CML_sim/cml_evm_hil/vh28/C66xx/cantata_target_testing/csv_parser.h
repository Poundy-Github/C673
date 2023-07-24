/*!  \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC

  CPU:            PC

  COMPONENT:      COD - Object detection

  MODULNAME:      csv_parser.h  

  DESCRIPTION:    Interface of CSV file parser
  AUTHOR:         Andreas Jahnke

  CREATION DATE:  07.11.2013

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: csv_parser.h  $
  CHANGES:        Revision 1.1 2021/12/13 21:33:44CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/03_Workspace/Component_Workspace/CML_sim/cml_evm_hil/vh28/C66xx/cantata_target_testing/project.pj
  CHANGES:        Revision 1.3 2016/10/28 13:24:49CEST Jagannath-EXT, Anu (uid42056) 
  CHANGES:        Added function for writing the hex output.
  CHANGES:        Revision 1.3 2016/10/28 13:24:49CEST Jagannath-EXT, Anu (uid42056) 
  CHANGES:        Added function for writing the hex output.
  CHANGES:        Revision 1.3 2016/10/28 13:24:49CEST Jagannath-EXT, Anu (uid42056) 
  CHANGES:        Added function for writing the hex output.
  CHANGES:        Revision 1.2 2016/08/26 16:19:09CEST Naik, Balachandra (uidp1547) 
  CHANGES:        Updated for linear memory parser implementation.
  CHANGES:        Revision 1.1 2016/08/26 07:49:22CEST Naik, Balachandra (uidp1547) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/03_Workspace/algo/cml_sim/cml_evm_hil/vh28/evm_hil_projects/C66xx/cantata_target_testing/project.pj
  CHANGES:        Revision 1.4 2016/06/06 06:31:37CEST Nuggu-EXT, Satish (uidp3554) 
  CHANGES:        updated source file for AL_CML_01.09.09_INT-1_RC
  CHANGES:        Revision 1.3 2016/03/31 06:00:58CEST Sansthanik, Vadiraj (uidr1064) 
  CHANGES:        parser files for AL_CML_01.09.08_INT-1
  CHANGES:        Revision 1.1 2015/02/27 16:51:05CET Maramreddy, Jayalakshmi (uidj4450) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/05_Testing/05_Test_Environment/algo/modtests/B2B_tests/cml_trigo/project.pj
  CHANGES:        Revision 1.3 2014/02/20 17:31:55CET Jahnke, Andreas (uidw8971) 
  CHANGES:        Member moved from csv_parser.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VCL_VehicleDetection/05_Testing/05_Test_Environment/algo/modtests/cantata_tests/vcl/common/project.pj to csv_parser.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VCL_VehicleDetection/05_Testing/05_Test_Environment/algo/modtests/cantata_tests/vcl/Framework/project.pj.
  CHANGES:        Revision 1.2 2013/11/11 18:10:41CET Jahnke-EXT, Andreas (uidw8971) 
  CHANGES:        added doxygen-compatible source documentation
  CHANGES:        --- Added comments ---  uidw8971 [Nov 11, 2013 6:10:42 PM CET]
  CHANGES:        Change Package : 186292:16 http://mks-psad:7002/im/viewissue?selection=186292
  CHANGES:        Revision 1.1 2013/11/08 09:20:08CET Jahnke-EXT, Andreas (uidw8971) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VCL_VehicleDetection/05_Testing/03_ModuleTest/vcl/02_Environment/common/project.pj

**************************************************************************** */

#ifndef CSV_PARSER
#define CSV_PARSER

/*! error return value */
#define CSV_PARSER_ERROR -1
/*! return value success */
#define CSV_PARSER_OK 0

/*! CSV delimiter string */
#define CSV_DELIMITER ","
/*! CSV delimiter character */
#define CSV_DELIMITER_CHAR ','

#include <stdio.h>
#include "cml_type.h"

/*!
 * CSV data structure is a linked list and contains the data, data length and link to the next value
 */
typedef
struct _csv_data_t
{
  /*! CSV data buffer will be allocated in dynamic memory (calloc()), binary data */
  char *value;
  /*! length of value buffer */
  size_t len;
  /*! pointer to next csv data structure, NULL means end of linked list */
  struct _csv_data_t *next;  
}csv_data_t;

/*!
 * CSV data float32 structure is a linked list and contains the data, data length and link to the next value
 */
typedef
struct _csv_data_float_t
{
  /*! CSV data buffer will be allocated in dynamic memory (calloc()), binary data */
  float32 *value;
  /*! length of value buffer */
  size_t len;
  /*! pointer to next csv data structure, NULL means end of linked list */
#ifdef LINKED_LIST_PARSER
  struct _csv_data_float_t *next;  
#else
  size_t dataBufferSize; 
#endif
}csv_data_float_t;

/***********************************************************************e
Functionname: CSV_ParseString                                    */ /*!
 @brief Parses a CSV (comma separated value) string
 @param[in] a_src string to parse
 @param[in] a_len string length
 @param[in,out] a_Data CSV data parsed from input string
 @return  CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
 @pre a_src != NULL
 @pre a_len != NULL
 @pre a_Data != NULL
 @post Output data will be stored in dynamic memory
**************************************************************************** */
int CSV_ParseString (const char* a_src, const size_t a_len, csv_data_t** a_Data);


/*****************************************************************************
Functionname: CSV_ParseCsvFile                                    */ /*!
 @brief Parses a CSV (comma separated value) file
 @param[in] a_Path path to source file
 @param[in,out] a_Data output structure will be filled with CSV data
 @return CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
 @pre a_Path != NULL
 @pre a_Path is not an empty-string
 @pre a_Path is a nul-terminated string
 @pre read access to file pointed to by a_Path
 @pre a_Data != NULL
 @post Output data will be stored in dynamic memory
*****************************************************************************/
int CSV_ParseCsvFile (const char *a_Path, csv_data_t** a_Data);


/*****************************************************************************
Functionname: CSV_FreeCsvData                                    */ /*!
 @brief Releases memory of CSV data chain
 @param[in,out] a_Data CSV data parsed from source file
 @return void
 @pre a_Path != NULL
 @pre a_Path stored in dynamic meory.
*****************************************************************************/
void CSV_FreeCsvData (csv_data_t *a_Data);


/*****************************************************************************
Functionname: CSV_WriteData                                    */ /*!
 @brief Writes CSV data structure to file/output stream
 @param[in,out]  a_File pointer to open, write-enabled output stream
 @param[in]  a_Data CSV data
 @return CSV_PARSER_OK on success, CSV_PARSER_ERROR on any error
 @pre p_File not a null-pointer
 @pre p_File is an output stream with write-access
 @pre a_Data not a null-pointer
 @post p_File not closed
*****************************************************************************/
int CSV_WriteData (FILE *a_File, const csv_data_t *a_Data);

#ifdef LINKED_LIST_PARSER
int CSV_WriteData_float32 (FILE *a_File, const csv_data_float_t *a_Data);
#else
int CSV_WriteData_float32 (FILE *a_File, csv_data_float_t *a_Data);
int CSV_WriteData_hex (FILE *a_File, csv_data_float_t *a_Data);
#endif

#endif
