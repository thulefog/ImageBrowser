#ifndef DCMLITE_UTIL_H_
#define DCMLITE_UTIL_H_
#pragma once

#include <chrono>
#include "vr.h"

// Misc utilities.

namespace dcmlite {

// For VRs of OB, OD, OF, OL, OW, SQ, UN and UC, UR, UT, the 16 bits
// following the two character VR Field are reserved for use by later
// versions of the DICOM Standard.
// See PS 3.5 Section 7.1.2 - Data Element Structure with Explicit VR.
bool Is16BitsFollowingVrReversed(VR::Type vr_type);

// Usage:
// {
//   TimeIt ti;
//   <You code to measure the time>
// }
class TimeIt {
public:
  TimeIt();
  ~TimeIt();

private:
  std::chrono::system_clock::time_point start_;
};

}  // namespace dcmlite

#endif  // DCMLITE_UTIL_H_
