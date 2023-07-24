#ifndef _viscr_smpc_hpp_
#define _viscr_smpc_hpp_

// ~CodeReview ~ID:655c51aabb6ab29572c533f5fdd7983d ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
//#include <vector>
#include <viscr_types.hpp>
#include <viscr_camera.hpp>
#include <viscr_stereo_camera.hpp>
#include <viscr_timestamp.hpp>
#include <viscr_odometry.hpp>
#include <viscr_powerflow.hpp>
#include <viscr_defs.h>
#include "sac_interface.h"
#include "viscr_correspondenceRejectionReason.hpp"
#include "viscr_rollPitchObjectiveType.hpp"

extern i8_t fine_flag;

/** @name Self calibration of Stereo Multi Purpose Camera.
 *
 * This library is taylor-made for the specifics of the Stereo Multi Purpose
 * Camera. As such it uses information that is readily available in this
 * specific ECU.
 *
 * We calibrate the three rotation angles of the rotation matrix only. The
 * reason for this is: the radial distortions most likely change very little,
 * the baseline and the camera constants influence the estimated distance only
 * linearly.
 *
 * The method to calibrate these angles is different for the roll (rotation
 * about z axis) and pitch (rotation about x axis) in contrast to the yaw
 * angle. The roll and pitch angle is computed from the essential matrix, the
 * yaw angle is computed from comparing the estimated motion of a stereo point
 * with the expected motion according to the vehicle odometry.
 *
 * \todo factor filtering heuristics in mechanism and policy
 */
/*@{*/



/// Number of parameters to estimate
#define VISCR_SMPC_PARAM_CNT 3U



/// State for calibration mode
// {{{
typedef enum { 
  /// Only get epipolar line right, median filtered
 // ~CodeReview ~ID:4ba76f95f8b7aa643f8797e4ec5e05d6 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
 // VISCR_SMPC_STATE_COARSE_EPI, 

  /// Epipolar and yaw calibration, median filtered
  // ~CodeReview ~ID:10c4939225221060051432f5278e5a1b ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //VISCR_SMPC_STATE_COARSE_ALL,
  VISCR_SMPC_STATE_BUFFER_EMPTY,

  /// Epipolar and yaw calibration, median+lowpass filtered
  // ~CodeReview ~ID:50e8c5a7b242a24ee9476bc9ffbdf7af ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //VISCR_SMPC_STATE_FINE_ALL
  VISCR_SMPC_STATE_BUFFER_FULL
} viscr_SMPC_algo_state;
/*}}}*/


/// M-estimator user data
//{{{
struct viscr_SMPC_rampme_data
{
  /** Scale factor for errors */
  viscr_float f;

  /** Minimal value of the ramp, associated with weight 1.0 */
  viscr_float rampMin;

  /** Maximal value of the ramp, associated with weight lowWeight */
  viscr_float rampMax;

  /** Lower weight for errors larger than rampMax */
  viscr_float lowWeight;


  viscr_SMPC_rampme_data() { }
};
/*}}}*/


/** \brief All parameter of the SMPC application. 
 *
 * Only the non-structural
 * parameters can be changed at any time.
 */
// {{{
struct viscr_SMPC_param
{
  /// Image size of the rectified images
  viscr_image_size size;

  /// Number of bins in horizontal direction
  viscr_uint bins_u;

  /// Number of bins in vertical direction
  viscr_uint bins_v;

  /// Number of bins in disparity
  viscr_uint bins_d;

  /// vertical pixel coordinate of horizon line in left image
  viscr_uint horizon;

  /** Minimal disparity to use. */
  viscr_uint min_disp;

  /// Maximal disparity for binning
  viscr_uint max_disp;

  /// Number of points in each bin for epipolar constraint
  viscr_uint points_per_epipolar_bin;

    /// Number of points in each bin for epipolar constraint
  viscr_uint points_per_epipolar_bin_max[4];

  /// Number of points in each bin for yaw constraint
  viscr_uint points_per_yaw_bin;

  /// Maximal number of coarse stereo points
  viscr_uint max_input_coarse;

  /** Radius of the window used for the sub-pixel accurate positioning. Actual
   * area is (2*n+1)^2 pixel.  */
  viscr_uint klt_shift_rad;

  /** Minimal grey value for klt_shift to work. Set to about 5. */
  viscr_pixel klt_shift_min_grey;

  /** Maximal grey value for klt_shift to work. Set to about max_grey-5. */
  viscr_pixel klt_shift_max_grey;

  /** M-estimator parameter for epipolar estimation. No need to set f. */
  viscr_SMPC_rampme_data rampme_epipolar;

  /** M-estimator parameter for yaw estimation. */
  viscr_SMPC_rampme_data rampme_yaw;

  /** Length of median ring buffer */
  viscr_uint median_len;

  /** Minimal flow length in pixel for yaw calibration.  */
  viscr_uint min_flow_len;

  /** Transform from Ackermann coordinate system (centre of rear axle) to
   * camera coordinate system */
  viscr_mat44 H_cam_car;

  /** Transform from camera coordinate system to Ackermann coordinate system
   * (centre of rear axle). viscr_SMPC_alloc computes this from H_cam_car. */
  viscr_mat44 H_car_cam;

  /// Low-pass coefficient for angle low pass in fine mode
  viscr_float low_pass_factor;

  /** Maximal error of a flow vector in vertical direction (pixel). Value is
   * higher due to pitching of car.
   */
  viscr_float max_flow_error_vertical;

  /// Maximal error of a flow vector in horizontal direction (pixel)
  viscr_float max_flow_error_horizontal;

  /// Number of calibrations to switch from coarse_epi to coarse_all
  viscr_uint num_calib_coarse_epi;

  /// Number of calibrations to switch from coarse_all to fine_all
  viscr_uint num_calib_coarse_all;

  /// Type of objective function used in roll pitch calibration
  RollPitchObjectiveType rollPitchObjective;

  /** Default parameters for usual stereo vision cameras. */
  viscr_SMPC_param():
    bins_u(BINS_U),
    bins_v(BINS_V),
    bins_d(BINS_D),
    min_disp(MIN_DISP),
    max_disp(MAX_DISP),
    points_per_epipolar_bin(POINTS_PER_EPIPOLAR_BIN_COARSE),//fine_flag ? POINTS_PER_EPIPOLAR_BIN_FINE : POINTS_PER_EPIPOLAR_BIN_COARSE ),
    points_per_yaw_bin(POINTS_PER_YAW_BIN),
    max_input_coarse(MAX_INPUT_COARSE),
    klt_shift_rad(KLT_SHIFT_RAD),
    klt_shift_min_grey(5),
    klt_shift_max_grey(4095-5),
    median_len(MEDIAN_LEN),
    min_flow_len(MIN_FLOW_LEN),
    low_pass_factor(0.1f),
    max_flow_error_vertical(3.0f),
    max_flow_error_horizontal(3.0f),
    num_calib_coarse_epi(3),//11),
    num_calib_coarse_all(3),//11)
    rollPitchObjective(RPOBJ_FIXED_POINT)
  { 
    rampme_epipolar.f=1.0f;
    rampme_epipolar.rampMin=0.25f;
    rampme_epipolar.rampMax=0.75f;
    rampme_epipolar.lowWeight=0.01f;
    rampme_yaw.f=1.0f;
    rampme_yaw.rampMin=0.02f;
    rampme_yaw.rampMax=0.06f;
    rampme_yaw.lowWeight=0.01f;
  }

  private:
  viscr_SMPC_param( const viscr_SMPC_param &);
};
/*}}}*/


/// Sub-pixel accurate correspondence for coarse mode
//{{{ 
struct viscr_SMPC_epipolar_corr
{
  /// Horizontal position, image 0
  viscr_float u0;
  /// Vertical position, image 0
  viscr_float v0;
  /// Horizontal position, image 1
  viscr_float u1;
  /// Vertical position, image 1
  viscr_float v1;

  viscr_SMPC_epipolar_corr() { }
  ~viscr_SMPC_epipolar_corr() { }
};
/*}}}*/


/// A single stereo result for yaw angle estimation
//{{{
struct viscr_SMPC_yaw_point
{
  /// Horizontal pixel coordinate, image 0
  viscr_coord u;

  /// Vertical pixel coordinate, image 0
  viscr_coord v;

  /// Disparity in pixels
  viscr_float d;

  /// Default constructor to make compiler happy.
  viscr_SMPC_yaw_point() { }

};
/*}}}*/

/// Correspondence for yaw angle estimation {{{
struct viscr_SMPC_yaw_corr
{

    /// Stereo result for old image
    viscr_SMPC_yaw_point pt_old;
  
    /// Stereo result for new image
    viscr_SMPC_yaw_point pt_new;

  /// erstimated delta d
  viscr_float deltaD; 

  /// Default constructor to make compiler happy.
  viscr_SMPC_yaw_corr() { }

};
/*}}}*/


// ~CodeReview ~ID:9bedeb4f8bdc8066a81fe3804a900d67 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
///// Correspondence for yaw angle estimation
////{{{
//struct viscr_SMPC_yaw_corr
//{
//  /// Transformation from last image to current image
//  /// Each correspondence might have a different motion associated
//  viscr_mat44 H_cam_new_old;
//
//  /// Transformation from current image to last image
//  /// Each correspondence might have a different motion associated
//  viscr_mat44 H_cam_old_new;
//
//  /// Stereo result for old image
//  viscr_SMPC_yaw_point pt_old;
//
//  /// Stereo result for new image
//  viscr_SMPC_yaw_point pt_new;
//
//  /// Default constructor to make compiler happy.
//  viscr_SMPC_yaw_corr() { }
//
//};
///*}}}*/


/// Main SMPC self calibration data 
//{{{
struct viscr_SMPC_data
{
  /// Parameter
  viscr_SMPC_param param;

  /// calibration data left camera
  viscr_camera calib_k0;

  /// calibration data right camera
  viscr_camera calib_k1;

  /// Stereo camera from rectification
  viscr_stereo_camera stereo_camera;

  /// Bins for the points
  //std::vector<viscr_SMPC_epipolar_corr> binned_epipolar_points;
  viscr_SMPC_epipolar_corr binned_epipolar_points[POINTS_PER_EPIPOLAR_BIN_FINE*BINS_U*BINS_V];

  /// Number of points currently in epipolar bins
  //std::vector<viscr_uint> bin_cnt_epipolar;
  viscr_uint binned_epipolar_point_index[POINTS_PER_EPIPOLAR_BIN_COARSE][BINS_U*BINS_V][2];

 
  viscr_uint bin_cnt_epipolar[BINS_U*BINS_V];

  /** Flattened binned data for bins_d*nPoints correspondences for yaw angle
   * estimation.  */
  // ~CodeReview ~ID:478981032190c668ea57c7fcfb6a25ba ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //std::vector<viscr_SMPC_yaw_corr> binned_yaw_points;
  viscr_SMPC_yaw_corr binned_yaw_points[POINTS_PER_YAW_BIN*BINS_D];

  /// Number of points currently in yaw bins
  // ~CodeReview ~ID:17bdeb9263d549eee65e388d3b68079c ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //std::vector<viscr_uint> bin_cnt_yaw;
  viscr_uint bin_cnt_yaw[BINS_D];

  /// Random order vector: \todo make groups of 100 points to reduce overhead
  // ~CodeReview ~ID:d227ab29bb05a54664794d5409213b64 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //std::vector<viscr_uint> random_point_index;
  viscr_pixel * random_point_index;
  
  /// Index into random_point_index for epipolar points.
  viscr_uint random_seed_epi;

  /// Index into random_point_index for yaw points.
  viscr_uint random_seed_yaw;

  /// algorithm state
  viscr_SMPC_algo_state algo_state;

  /// A new calibration is available
  viscr_bool new_calib_done;

  /// time of last calibration, not used yet
  viscr_timestamp last_calib_time;
    
  /** Buffer for klt */
  // ~CodeReview ~ID:691c5d98e2a74df4d04ce1e73b38502b ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //std::vector< viscr_pixel_accu> klt_accu;
  viscr_pixel_accu klt_accu[2*KLT_SHIFT_RAD+1];

  /** Ring buffer for median filter */
  // ~CodeReview ~ID:b4dc4623cc17276b7f38a78527f69d7a ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
  //std::vector< viscr_float > median_buffer[VISCR_SMPC_PARAM_CNT];
  viscr_float median_buffer[VISCR_SMPC_PARAM_CNT][MEDIAN_LEN];
  viscr_float median_buffer_rmse_epipolar[MEDIAN_LEN];
  viscr_float median_buffer_rmse_improvement[MEDIAN_LEN];

  /// State for low pass (fine mode)
  viscr_float low_pass[VISCR_SMPC_PARAM_CNT];

  /** Sorted ring buffer for median filter */
 // ~CodeReview ~ID:5a776c0d101ed15731563cee5834ede4 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
 // std::vector< viscr_uint > median_buffer_sortinfo;
  viscr_uint median_buffer_sortinfo[MEDIAN_LEN];

  /** Number of entries in median ring buffer.  */
  viscr_uint median_buffer_entries;

  /** Current rotation angles. */
  viscr_float current_angles[VISCR_SMPC_PARAM_CNT];

  /** How many calibrations have been done since state change. */
  viscr_uint num_calib_in_state;

  SACCalibQuality_t rectification_quality;

  /** Current distance error of the yaw-angle calibration */
  viscr_float currentYawError;

  /** Statistics on correspondence extraction - number of accepted correspondences in this frame */
  viscr_uint32 cCorrespondencesAccepted;

  /** Statistics on correspondence extraction - number of accepted correspondences rejected by klt-shift */
  viscr_uint32 cCorrespondencesRejectedByKlt;

  /** Statistics on correspondence extraction - number of accepted correspondences rejected by corner test at 1st feature location */
  viscr_uint32 cCorrespondencesRejectedByCornerCheck1st;

  /** Statistics on correspondence extraction - number of accepted correspondences rejected by corner test at 2nd feature location */
  viscr_uint32 cCorrespondencesRejectedByCornerCheck2nd;

  /** Statistics on correspondence extraction - number of accepted correspondences rejected because corresponding bin was already full */
  viscr_uint32 cCorrespondencesRejectedByBinFull;

  /** Default constructor to silence the compiler. */
  viscr_SMPC_data() { }
  ~viscr_SMPC_data() { }
  
  private:
    viscr_SMPC_data( const viscr_SMPC_data &);
    viscr_SMPC_data & operator=( const viscr_SMPC_data &);
};
/*}}}*/

// ~CodeReview ~ID:cab5749aa309579bb0d281c4b2809e19 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
/* viscr_int32 sac_rand(viscr_int32); */


/// Allocate all internal stores
extern void 
viscr_SMPC_alloc( 
    // ~CodeReview ~ID:6bd5573e9feee3d6f254e0a96c1173ac ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
    viscr_SMPC_data & data/*, 
    const viscr_SMPC_param & param*/);


/// Initialise to defined values, set other parameters before this call
extern void 
viscr_SMPC_init( 
    viscr_SMPC_data & data, 
    const viscr_timestamp & now);


/// Process one rectified image pair in coarse mode
extern void 
viscr_SMPC_process_coarse(
    viscr_SMPC_data & data, 
    const viscr_image & k0,
    const viscr_image & k1,
    const viscr_powerflow_result & stereo,
    const viscr_timestamp & now,
    const SACCallBackHdlr_t & callBackHandler);


/** Process the image pair for epipolar constraint only. Use this if the yaw
 * bins are already full, but the epipolar bins not.
 */
extern void
viscr_SMPC_process_fine_epi_only(
    viscr_SMPC_data & data, 
    const viscr_image & k0,
    const viscr_image & k1,
    const DisparityImage_t * disparity,
    const viscr_powerflow_result & flow,
    const FlowImage_t * pFlowImageTemporal);

#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/** Process the image pair for yaw angle constraint and epipolar constraint.
 * This is the usual image processing function. */
extern void
viscr_SMPC_process_fine_all(
    viscr_SMPC_data & data, 
    const DisparityImage_t * last_disparity,
    const DisparityImage_t * disparity,
    const viscr_powerflow_result & flow,
    const viscr_mat44 & H_car_new_old,
    const viscr_image & new_k0,
    const viscr_image & new_k1,
    const viscr_image & old_k0,
    const viscr_image & old_k1,
    const FlowImage_t * pFlowImageTemporal
    );
#endif
// ~CodeReview ~ID:4bdf4e4e704a6f16b2e3442dce6b59eb ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
#if 0 // CODE NOT USED
/** Complete the calibration over time. Call this if epipolar and yaw bins are
 * full. */
extern void viscr_SMPC_process_fine(viscr_SMPC_data & data, const viscr_timestamp & now);
#endif
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
extern void viscr_SMPC_process_fine_pitch_yaw_roll(viscr_SMPC_data & data, 
  const viscr_timestamp & now, const SACCallBackHdlr_t & callBackHandler);
#endif
#if (VISCR_SMPC_APPLYRADAR_YAW == 0)
extern void viscr_SMPC_process_fine_pitch_roll(viscr_SMPC_data & data, const viscr_timestamp & now,
  const SACCallBackHdlr_t & callBackHandler);
#endif
extern void viscr_SMPC_process_fine_pitch_roll_radaryaw(
  viscr_SMPC_data & data,
  const viscr_timestamp & now,
  const f32_t yaw,
  const SACCallBackHdlr_t & callBackHandler);

/** Put the calibration result to the internal filters. Not to be called from
 * outside.  */
extern void 
viscr_SMPC_set_rotation( 
    viscr_SMPC_data & data, 
    viscr_float const a,
    viscr_float const b,
    viscr_float const c,
    viscr_float const rmse_epipolar,
    viscr_float const rmse_improvement,
    const viscr_timestamp & now);


/// Return true if the bins for epipolar constraint input are full.
extern viscr_bool
viscr_SMPC_epipolar_bins_are_full( 
    const viscr_SMPC_data & data);

#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// Return true if the bins for yaw angle constraint input are full.
extern viscr_bool
viscr_SMPC_yaw_bins_are_full( 
    const viscr_SMPC_data & data);
#endif

/** Acknoledge that the calibration results was taken. Resets all bin
 * counters.  */
extern void
viscr_SMPC_calib_taken(
    viscr_SMPC_data & data);


/// Perform image processing for the given stereo correspondence. Do not use
/// externally.
extern void
viscr_SMPC_refine_epipolar(
    viscr_SMPC_data & data,
    CorrespondenceRectionReason & correspondenceRectionReason,
    const viscr_image & k0,
    const viscr_image & k1,
    const viscr_coord u0, 
    const viscr_coord v0,
    const viscr_coord u1,
    const viscr_coord v1,
    const viscr_int klt_shift_max
    );


/// Find the bin this point would fall into
extern viscr_uint
viscr_SMPC_coord2bin(
    const viscr_SMPC_param & param,
    const viscr_coord u,
    const viscr_coord v);

// ~CodeReview ~ID:c90afb96d20874e0fc3f708b7dccdc17 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
#if 0 // CODE NOT USED
/// Free all internal memory
extern void
viscr_SMPC_free(
    viscr_SMPC_data & data);
#endif

/** Compute the index of the median element in a list. Only the index array is
 * changed */
extern viscr_uint
viscr_SMPC_median( 
    const viscr_float values[],
    viscr_uint indices[],
    const viscr_uint nValues);


/** A calibration is made available to the outside and the state machine is
 * advanced.  */
extern void
viscr_SMPC_calib_available(
    viscr_SMPC_data & data);

/** Check if we are in a state that requires powerstereo or SGM.  */
// ~CodeReview ~ID:0598a8b3ff33165f1752a1553da55bb8 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or comment dead code
//extern viscr_bool
//viscr_SMPC_want_powerstereo(
//    viscr_SMPC_data & data);
//

/*@}*/
#endif
