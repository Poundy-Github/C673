#ifndef viscr_correspondence_extractionReason_hpp_
#define viscr_correspondence_extractionReason_hpp_

//! Reason for rejecting a correspondence from coarse/fine roll pitch calibration
enum CorrespondenceRectionReason {
  RejectionReason_NotRejected = 0,
  RejectionReason_KLT,
  RejectionReason_CornerCheck2nd,
  RejectionReason_BinFull
};

#endif