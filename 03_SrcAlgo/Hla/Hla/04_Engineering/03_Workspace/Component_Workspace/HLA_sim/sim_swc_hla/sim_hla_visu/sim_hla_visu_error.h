/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_error.h

  DESCRIPTION:            Drawing of error messages

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.4 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_ERROR_H
#define SIM_HLA_VISU_ERROR_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"

#include "hla_defs.h"
#include "hla_errorhandling.h"

#include "sim_visu_type.h"
#include "sim_hla_visu_head.h"
#include "sim_hla_visu_utils.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class CSimHlaVisuError
  :public virtual CSimHlaVisuHead,
   public virtual CSimHlaVisuUtils
{
public:
  CSimHlaVisuError();

  ~CSimHlaVisuError();

  void Init();

  void drawErrorStack( const ISimRenderContext*          pContext,
                       const bool                        m_algoWasExecuted,
                       const int                         activePlane,
                       const int                         activeErrorList,
                       const t_ErrorHandling_ErrorStack* pHLAErrorStack,
                             int&                        textPosX,
                             int                         menuHeight = 0
                      );


private:
  /* counters for delayed fading out of the error list */
  struct s_delayedErrorList
  {
    static const int fadeOutFrames = 80;

    typedef struct 
    {
      int counter;
      int errSource;
      uint32 errBit;
    } ErrorItem;
    typedef std::vector<ErrorItem> ErrorList;
    ErrorList m_errorList;
    ErrorList m_warningList;
    ErrorList m_informationList;

    void insertError( const int         errSource, 
                      const uint32      errorBit
                    );                               
    void insertWarning( const int         errSource, 
                        const uint32      errorBit
                      );                               
    void insertInformation( const int         errSource, 
                            const uint32      errorBit
                          );         
    void insertElement( const int         errSource, 
                        const uint32      errorBit,
                              ErrorList&  list
                      );         
    void update();
    void updateList(ErrorList& list);
  }; 

  void fillDelayedErrorList( const t_ErrorHandling_ErrorStack* pHLAErrorStack,
                             const int                         errSource,
                                   s_delayedErrorList&         errorList
                            );


  s_delayedErrorList m_delayedErrorList[VISU_MAX+1];

  s_delayedErrorList m_delayedErrorListVis;

  void drawErrors( const ISimRenderContext* pContext,
                   const s_delayedErrorList delayedErrorList,
                         bool               drawdebug,
                         int&               textPosX,
                         int                textPosY
                 );
  void drawWarnings( const ISimRenderContext* pContext,
                     const s_delayedErrorList delayedErrorList,
                           int&               textPosX,
                           int                textPosY
                   );

  void drawInformation( const ISimRenderContext* pContext,
                        const s_delayedErrorList delayedErrorList,
                              int&               textPosX,
                              int                textPosY
                      );
 
};

#endif // SIM_HLA_VISU_ERROR_H
