#ifndef OPENSTENO_STENOBOARD_HPP
#define OPENSTENO_STENOBOARD_HPP

#include <memory>

namespace opensteno {
struct StenoboardLeft {
  std::shared_ptr<bool> numberBar = std::make_shared<bool>(false);

  std::shared_ptr<bool> fn1 = std::make_shared<bool>(false);
  std::shared_ptr<bool> s1  = std::make_shared<bool>(false);
  std::shared_ptr<bool> t   = std::make_shared<bool>(false);
  std::shared_ptr<bool> p   = std::make_shared<bool>(false);
  std::shared_ptr<bool> h   = std::make_shared<bool>(false);
  std::shared_ptr<bool> asterisk1 = std::make_shared<bool>(false);

  std::shared_ptr<bool> fn2 = std::make_shared<bool>(false);
  std::shared_ptr<bool> s2  = std::make_shared<bool>(false);
  std::shared_ptr<bool> k   = std::make_shared<bool>(false);
  std::shared_ptr<bool> w   = std::make_shared<bool>(false);
  std::shared_ptr<bool> r   = std::make_shared<bool>(false);
  std::shared_ptr<bool> asterisk2 = std::make_shared<bool>(false);

  std::shared_ptr<bool> a   = std::make_shared<bool>(false);
  std::shared_ptr<bool> o   = std::make_shared<bool>(false);
};

struct StenoboardRight {
  bool numberBar;
  bool asterisk1, f, p, l, t, d;
  bool asterisk2, r, b, g, s, z;
  std::shared_ptr<bool> e = std::make_shared<bool>(false);
  std::shared_ptr<bool> u = std::make_shared<bool>(false);
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
    *left.numberBar.get() = false;
    *left.fn1.get() = false;
    *left.s1.get() = false;
    *left.t.get() = false;
    *left.p.get() = false;
    *left.h.get() = false;
    *left.asterisk1.get() = false;

    *left.fn2.get() = false;
    *left.s2.get() = false;
    *left.k.get() = false;
    *left.w.get() = false;
    *left.r.get() = false;
    *left.asterisk2.get() = false;

    *left.a.get() = false;
    *left.o.get() = false;
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
