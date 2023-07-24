#ifndef viscr_eol_stereo_debug_h__
#define viscr_eol_stereo_debug_h__

#ifdef PC_SIM // only if we are in pc simulation mode

#include <viscr_eol_stereo.hpp>
#include <viscr_eol_mono.hpp>
#include <viscr_eol_filter1.hpp>
#include <viscr_eol_filter2.hpp>

// create a datatype that can hold debuging data
namespace SAC
{
  namespace EOL
  {
    /// Class contaning all debug information needed to
    /// visualize the eol calibration
    class CStereoCalibrationDebugData
    {
    public:
      viscr_eol_stereo_input  m_input;
      viscr_eol_stereo_output m_output;
      boolean_t               m_valid;

      struct SMonoData
      {
        viscr_eol_mono_input  input;
        viscr_eol_mono_output output;
        boolean_t             valid;

        viscr_eol_filter1_input  filter1Input;
        viscr_eol_filter1_output filter1Output;
        viscr_eol_filter1        filter1Instance;
        boolean_t                filter1valid;

        viscr_eol_filter2_input  filter2Input;
        viscr_eol_filter2_output filter2Output;
        viscr_eol_filter2        filter2Data[2];
        boolean_t                filter2valid;

        SMonoData() : valid(false), filter1valid(false), filter2valid(false) {}
      };

      SMonoData m_left;
      SMonoData m_right;

      enum ESide
      {
        S_LEFT  = 0,
        S_RIGHT
      };

      ESide m_currentSide;
      void setSide (const ESide& side) { m_currentSide = side; }
      SMonoData& monoData () { return (m_currentSide == S_LEFT) ? m_left : m_right; }

      static CStereoCalibrationDebugData* instance() { assert (m_instance != 0); return m_instance; }
      static void setInstance (CStereoCalibrationDebugData* _instance) { m_instance = _instance; }

      CStereoCalibrationDebugData() : m_valid(false), m_currentSide(S_LEFT) {}

    private:
      static CStereoCalibrationDebugData* m_instance;
    };
  }
}
#endif

#endif // viscr_eol_stereo_debug_h__
