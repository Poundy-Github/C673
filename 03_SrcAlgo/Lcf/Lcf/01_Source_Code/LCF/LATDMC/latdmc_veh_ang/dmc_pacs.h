/* $Header: dmc_pacs.h 1.6 2019/04/26 16:03:34CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
***************************************************************************************************
 Confidential and proprietary. This document and its contents are the exclusive property of
 Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
 associated companies. They are not to be copied, distributed, or otherwise disclosed or used
 without the prior written consent of Teves and Temic. All rights reserved.
 ABS/EBD/TCS/ESC-Controller Software.
***************************************************************************************************
Detailed informations to rebuild this code:
$TracibilityInfo$

***************************************************************************************************
$FunctionModelName$
***************************************************************************************************
Change record:
No change record because auto code generated.
***************************************************************************************************
*/

#ifndef DMC_PACS_H_INCLUDED
#define DMC_PACS_H_INCLUDED



/* ------------------------- */
/*         PARAMETERS        */
/* ------------------------- */

   #ifndef Lat_requested_steer_trq_table        
      typedef const unsigned_int16_t Lat_requested_steer_trq_table_array_t[5 * 10];  /* create a linear array type to cast into */
      #define Lat_requested_steer_trq_table (*((Lat_requested_steer_trq_table_array_t*)(Lat_requested_steer_trq_table_array)))     /* create a cast access to that linear type */
   #endif  /* Lat_requested_steer_trq_table */     
        
   #ifndef Lat_requested_steer_trq_tab_eco        
      typedef const unsigned_int16_t Lat_requested_steer_trq_tab_eco_array_t[5 * 10];  /* create a linear array type to cast into */
      #define Lat_requested_steer_trq_tab_eco (*((Lat_requested_steer_trq_tab_eco_array_t*)(Lat_requested_steer_trq_tab_eco_array)))     /* create a cast access to that linear type */
   #endif  /* Lat_requested_steer_trq_tab_eco */     
        
   #ifndef Lat_requested_steer_trq_normal        
      typedef const unsigned_int16_t Lat_requested_steer_trq_normal_array_t[5 * 10];  /* create a linear array type to cast into */
      #define Lat_requested_steer_trq_normal (*((Lat_requested_steer_trq_normal_array_t*)(Lat_requested_steer_trq_normal_array)))     /* create a cast access to that linear type */
   #endif  /* Lat_requested_steer_trq_normal */     
        
   #ifndef Lat_requested_steer_trq_sport        
      typedef const unsigned_int16_t Lat_requested_steer_trq_sport_array_t[5 * 10];  /* create a linear array type to cast into */
      #define Lat_requested_steer_trq_sport (*((Lat_requested_steer_trq_sport_array_t*)(Lat_requested_steer_trq_sport_array)))     /* create a cast access to that linear type */
   #endif  /* Lat_requested_steer_trq_sport */     
        

#endif  /* DMC_PACS_H_INCLUDED */
