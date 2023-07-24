/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSNDVEH_common.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.4 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

#ifndef LCFSNDVEH_COMMON_H_
#define LCFSNDVEH_COMMON_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include "LCFERR/errio.h"
/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

extern void LCFSND_VehCommonReset  (void);
extern void LCFSND_VehCommonProcess(void);
extern uint8 Get_T_LCFSND_ActToi_nu(void);

/*---------------------------------------------------------*
   E X T E R N A L   V A R I A B L E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/
 
 
#ifndef S_LCFERR_VehErrorToSen_btf
#define S_LCFERR_VehErrorToSen_btf   (((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_TJA_LC] & 0x01)<< LCF_ERRHNDL_TJA_LC)\
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_LDP]    & 0x01)<< LCF_ERRHNDL_LDP)   \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_RDP]    & 0x01)<< LCF_ERRHNDL_RDP)   \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_LDW]    & 0x01)<< LCF_ERRHNDL_LDW)   \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_TJA_OF] & 0x01)<< LCF_ERRHNDL_TJA_OF)\
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_RDW]    & 0x01)<< LCF_ERRHNDL_RDW)   \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_LDPOC]  & 0x01)<< LCF_ERRHNDL_LDPOC) \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_LDWOC]  & 0x01)<< LCF_ERRHNDL_LDWOC) \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_ALCA]   & 0x01)<< LCF_ERRHNDL_ALCA)  \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_SALC]   & 0x01)<< LCF_ERRHNDL_SALC)  \
									 |((ERRIOVEH_ErrStateArray[LCF_ERRHNDL_AOLC]   & 0x01)<< LCF_ERRHNDL_AOLC)  \
									 )
									 
#define GET_S_LCFERR_VehErrorToSen_btf() S_LCFERR_VehErrorToSen_btf
#endif
 
 
 
#endif /* _LCFSNDVEH_COMMON_H_ */


