#ifndef OPENSTENO_STENOBOARD_HPP
#define OPENSTENO_STENOBOARD_HPP
#include <vector>
namespace opensteno {
struct StenoboardLeft {
  bool numberBar1;
  bool fn1, s1, t, p, h, asterisk1;
  bool fn2, s2, k, w, r, asterisk2;
  bool a, o;
};

struct StenoboardRight {
  bool numberBar2;
  bool asterisk3, f, p, l, t, d;
  bool asterisk4, r, b, g, s, z;
  bool e, u;
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
    left.numberBar1 = false;
    left.fn1 = left.s1 = left.t = left.p = left.h = left.asterisk1 = false;
    left.fn2 = left.s2 = left.k = left.w = left.r = left.asterisk2 = false;
    left.a = left.o = false;
  }
  void resetRightButtons(){
    right.numberBar2 = false;
    right.asterisk3 = right.f = right.p = right.l = right.t = right.d = false;
    right.asterisk4 = right.r = right.b = right.g = right.s = right.z = false;
    right.e = right.u = false;
  }
};
} /* namespace opensteno */
#endif //OPENSTENO_STENOBOARD_HPP
