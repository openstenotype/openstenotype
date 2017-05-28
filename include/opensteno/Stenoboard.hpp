#ifndef OPENSTENO_STENOBOARD_HPP
#define OPENSTENO_STENOBOARD_HPP

#include <memory>

namespace opensteno {
struct StenoboardLeft {
  bool numberBar;
  bool fn1, s1, t, p, h, asterisk1;
  bool fn2, s2, k, w, r, asterisk2;
  bool a, o;
};

struct StenoboardRight {
  bool numberBar;
  bool asterisk1, f, p, l, t, d;
  bool asterisk2, r, b, g, s, z;
  std::unique_ptr<bool> e = std::make_unique<bool>(false);
  std::unique_ptr<bool> u = std::make_unique<bool>(false);
};

struct Stenoboard {
public:
  //15 buttons per side
  StenoboardLeft  left;
  StenoboardRight right;
  void resetButtons(){
    resetLeftButtons();
    resetRightButtons();
  }
  void resetLeftButtons(){
    left.numberBar = false;
    left.fn1 = left.s1 = left.t = left.p = left.h = left.asterisk1 = false;
    left.fn2 = left.s2 = left.k = left.w = left.r = left.asterisk2 = false;
    left.a = left.o = false;
  }
  void resetRightButtons(){
    right.numberBar = false;
    right.asterisk1 = right.f = right.p = right.l = right.t = right.d = false;
    right.asterisk2 = right.r = right.b = right.g = right.s = right.z = false;
    *right.e.get() = false;
    *right.u.get() = false;
  }
};
} /* namespace opensteno */
#endif //OPENSTENO_STENOBOARD_HPP
