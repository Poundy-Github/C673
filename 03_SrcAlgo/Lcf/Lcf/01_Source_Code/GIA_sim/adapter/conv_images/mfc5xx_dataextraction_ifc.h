/*! \file **********************************************************************

COMPANY:              Continental Automotive Lindau

PROJECT:              MFC5xx

COMPONENT:            MFC Data Extractor

MODULNAME:            mfc5xx_dataextraction_ifc.h

DESCRIPTION:          Header file with exported-interfaces declarations - UNICODE version.

AUTHOR:               Narinder Singh

CREATION DATE:        28.02.2018

VERSION:              $Revision: 1.1 $

---*/ /*---

**************************************************************************** */

#pragma once

#include "Platform_Types.h"

namespace MFC5XX
{
	#define DATA_TYPE_IMAGE_OM1  L"MFC5xx OM1 Image\0"
    #define DATA_TYPE_IMAGE_OM2  L"MFC5xx OM2 Image\0"
    #define DATA_TYPE_ALL_IMAGES (DATA_TYPE_IMAGE_OM1 DATA_TYPE_IMAGE_OM2)
    #define DATA_TYPE_ALL_DATA   L"MFC5xx Data\0"

	/*
    * @brief Pre-defined EXTRACTED_DATA_TYPE - enumeration of possible data types of the MFC 5xx device.
	                                           Caller has to give below datatype 
    */
    enum EXTRACTED_DATA_TYPE
    {
		EXTRA_DATA_PRE,                // extract only extra data pre
		EMBEDDED_DATA_PRE,             // extract only embeeded data pre
        IMAGE_DATA,                    // extract only image  
		EXTRA_DATA_POST,               // extract only extra data post
		EMBEDDED_DATA_POST,            // extract only embeeded data post
		ALL_DATA,                      /* extract all data 
		                                  ( embeeded pre + extra pre line  + 
									        image data + extra post line + embeded post ), 
									   */
    };

	/**
    * @brief Pre-defined DATAEXTRACTION_RETURNCODES - Enumeration of all return codes of the extraction function.
    */
    enum DATAEXTRACTION_RETURNCODES
    {
        SUCCEEDED = 0,        // data has been extracted Successfully
        DATA_TRUNCATED,       // dest buffer is smaller than data
        DATATYPE_NOT_FOUND,   // datatype of package does not match requested data type
        NULL_BUFFER,          // dest buffer is NULL
		CYCLE_START_END,
		INVALID_SIZE,
		INVALID_EXTRACTION_OPTION,
    };
    
	/**
    * @brief Pre-defined IMAGESOURECE_TYPE - Enumeration which define Image source .
    */
	enum IMAGE_TYPE
	{
		IMAGE_OM1_ODD = 0, //optical module odd
		IMAGE_OM1_EVEN,    //optiocal module even
		IMAGE_OM2_ODD,
        IMAGE_OM2_EVEN,
		UNKNOWN_IMAGE,     //Not able to find 
	};

    // bit field of extraction options
  // unmodified binary data received from the input package, passed back to caller
  static const uint32 OUTPUT_RAW_COPY_INPUT           = 0x01;
  // return 12 bit pixel to 16bit Gray scale, as per the EXTRACTED_DATA_TYPE given by caller
  static const uint32 OUTPUT_RAW_DATA_12_UNPACKED_16  = 0x02; 
  //a pure grayscale image with 8 bits per pixel
  static const uint32 OUTPUT_GRAYSCALE_8_MONO         = 0x03;
  //a grayscale image with 8 bits per pixel that has 24-bit RGB pixel format
  static const uint32 OUTPUT_GRAYSCALE_8_RGB24        = 0x04;
  //a color image 24-bit RGB
  static const uint32 OUTPUT_RGB24                    = 0x05;

    interface IMFC5xxDataExtraction
    {
        /**
        * Method to extract different MFC data into a specific format.
        * @param SourceData The package containing data to extract.
        * @param pDestData  The pointer to destination data - must be allocated and passed from caller of this method.
        * @param dwDestSize The size of extracted data - must be passed from caller of this method.
        * @param datatype   The type of extracted data, caller has to fill the datatype 
        * @param dwExtractionOptions The bitfield for extraction options.
        * @return Returns a DATAEXTRACTION_RETURNCODES value.
        */
        virtual uint8 ExtractData ( const SDataPackageEx& sourceData,
                                      void* pDestData,
                                      uint64& dwDestSize,
                                      EXTRACTED_DATA_TYPE datatype,
                                      uint32 dwExtractionOptions
                                    ) = 0;

        /**
        * Method to extract the width and height from data package received.
		* @param pSourceData The package containing data to extract.
		* @param datatype The type of extracted data, caller has to fill the EXTRACTED_DATA_TYPE 
        * @param unImageWidth The extracted image width.
        * @param unImageHeight The extracted image height.
        * @return Returns a DATAEXTRACTION_RETURNCODES value.
        */
        virtual uint8 ExtractImageParameters ( const SDataPackageEx& sourceData,  
        						                EXTRACTED_DATA_TYPE datatype, 
                                                 uint16&  unImageWidth, 
                                                 uint16&  unImageHeight 
                                               ) = 0;       

        /**
        * Method to extract the Image Time stamp from data package received.
        * @param Returns the image timestamp contained in the package
        * @return Returns a DATAEXTRACTION_RETURNCODES value.
        */
        virtual uint8 GetImageTimestamp( const SDataPackageEx& sourceData, 
                                           uint64& unImageTimestamp
                                          ) = 0;

        /**
        * Method to extract the Image Frame counter from data package received.
        * @param Returns the image frame counter contained in the package
        * @return Returns a DATAEXTRACTION_ERRORCODES value.
        */
        virtual uint8 GetImageFrameCounter( const SDataPackageEx& sourceData, 
                                        uint32& unImageFrameCounter
                                            ) = 0;

		/**
        * Method to extract the Image Source from data package received.
        * @param Returns the image Source contained in the package
		         ID of the image source (e.g. which video port, left/right sensor, ...)
				 As per the mta_image_frame_footer define.
        * @return Returns a DATAEXTRACTION_ERRORCODES value.
        */
        virtual uint8 GetImageSource( const SDataPackageEx& sourceData,
                                  IMAGE_TYPE& ImageSource 
                    ) = 0;   

    };
}





