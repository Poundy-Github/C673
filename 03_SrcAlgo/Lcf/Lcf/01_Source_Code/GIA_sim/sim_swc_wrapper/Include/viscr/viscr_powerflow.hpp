/* ~CodeReview ~ID:e08ddfb20402eec29def49180e788aff ~Reviewer:CW01\uidv0048 ~Date:6/19/2012 ~Priority:3 ~Comment:Add header in order to precise version (member revision), creation date, author... */
#ifndef _viscr_powerflow_hpp_
#define _viscr_powerflow_hpp_

#include <vector>
#include <viscr_types.hpp>
#include <viscr_defs.h>

/// A single powerflow correspondences
// {{{
struct viscr_powerflow_corr
{
  /// Horizontal coordinate, first image
  viscr_coord u0;
  /// Vertical coordinate, first image
  viscr_coord v0;
  /// Horizontal coordinate, second image
  viscr_coord u1;
  /// Vertical coordinate, second image
  viscr_coord v1;
};
/*}}}*/


/// Result of powerflow processing
// {{{
struct viscr_powerflow_result
{
  /// number of points extracted
  viscr_uint nPoints;

  /// Points extracted
 // std::vector<viscr_powerflow_corr> points;
 // viscr_powerflow_corr points[512*220];
  viscr_powerflow_corr points[MAX_NPOINTS_FLOW_PER_FRAME]; 
  viscr_powerflow_result() { }

  private:
    viscr_powerflow_result( const viscr_powerflow_result &);
    viscr_powerflow_result & operator=( const viscr_powerflow_result &);
};
/*}}}*/


/// Allocate the points
//extern void 
//viscr_powerflow_result_alloc(
//    viscr_powerflow_result & data,
//    viscr_uint nPoints);

#endif

