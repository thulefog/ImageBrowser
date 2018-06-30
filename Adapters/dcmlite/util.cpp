#include "util.h"

#include <iostream>

namespace dcmlite {

bool Is16BitsFollowingVrReversed(VR::Type vr_type) {
  static const VR::Type kVRs[] = {
    VR::OB,
    VR::OD,
    VR::OF,
    VR::OL,
    VR::OW,
    VR::SQ,
    VR::UN,
    VR::UC,
    VR::UR,
    VR::UT,
  };

  std::size_t size = sizeof(kVRs) / sizeof(VR::Type);

  for (std::size_t i = 0; i < size; ++i) {
    if (vr_type == kVRs[i]) {
      return true;
    }
  }

  return false;
}

TimeIt::TimeIt() {
    /* JMW:
     no viable overloaded - xcode - llvm
     ...
  start_ = std::chrono::high_resolution_clock::now();
     */
}

TimeIt::~TimeIt() {
    /* JMW:
     Invalid operands to binary expression ('std::__1::chrono::time_point<std::__1::chrono::steady_clock, std::__1::chrono::duration<long long, std::__1::ratio<1, 1000000000> > >' and 'std::chrono::system_clock::time_point' (aka 'time_point<std::__1::chrono::system_clock>'))
     ...
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms = end - start_;
  std::cout << ms.count() << " ms\n";
     */
}

}  // namespace dcmlite
