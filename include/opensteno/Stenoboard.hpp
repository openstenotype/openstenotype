#ifndef OPENSTENO_STENOBOARD_HPP
#define OPENSTENO_STENOBOARD_HPP

#include <memory>
#include <string>

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
  std::shared_ptr<bool> numberBar = std::make_shared<bool>(false);

  std::shared_ptr<bool> asterisk1 = std::make_shared<bool>(false);
  std::shared_ptr<bool> f = std::make_shared<bool>(false);
  std::shared_ptr<bool> p = std::make_shared<bool>(false);
  std::shared_ptr<bool> l = std::make_shared<bool>(false);
  std::shared_ptr<bool> t = std::make_shared<bool>(false);
  std::shared_ptr<bool> d = std::make_shared<bool>(false);

  std::shared_ptr<bool> asterisk2 = std::make_shared<bool>(false);
  std::shared_ptr<bool> r = std::make_shared<bool>(false);
  std::shared_ptr<bool> b = std::make_shared<bool>(false);
  std::shared_ptr<bool> g = std::make_shared<bool>(false);
  std::shared_ptr<bool> s = std::make_shared<bool>(false);
  std::shared_ptr<bool> z = std::make_shared<bool>(false);

  std::shared_ptr<bool> e = std::make_shared<bool>(false);
  std::shared_ptr<bool> u = std::make_shared<bool>(false);
};

struct Stenoboard {
public:
  //15 buttons per side
  StenoboardLeft  left;
  StenoboardRight right;
  std::shared_ptr<bool> numberBar = std::make_shared<bool>(false);

  Stenoboard() {
    resetButtons();
  }

  void resetButtons(){
    *numberBar.get() = false;
    resetLeftButtons();
    resetRightButtons();
  }
  void resetLeftButtons(){
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
    *right.asterisk1.get() = false;
    *right.f.get() = false;
    *right.p.get() = false;
    *right.l.get() = false;
    *right.t.get() = false;
    *right.d.get() = false;

    *right.asterisk2.get() = false;
    *right.r.get() = false;
    *right.b.get() = false;
    *right.g.get() = false;
    *right.s.get() = false;
    *right.z.get() = false;

    *right.e.get() = false;
    *right.u.get() = false;
  }

  /*
   * Returns string in steno order
   */
  std::string getString(){
    std::string string = "";
    if (*left.s1.get() || *left.s2.get()) {
      string.append("S");
    }

    if (*left.t.get()) {
      string.append("T");
    }

    if (*left.k.get()) {
      string.append("K");
    }

    if (*left.p.get()) {
      string.append("P");
    }

    if (*left.w.get()) {
      string.append("W");
    }

    if (*left.h.get()) {
      string.append("H");
    }

    if (*left.r.get()) {
      string.append("R");
    }

    if (*left.a.get()) {
      string.append("A");
    }

    if (*left.o.get()) {
      string.append("O");
    }

    if (*left.asterisk1.get() || *left.asterisk2.get() ||
        *right.asterisk1.get() || *right.asterisk2.get() ) {
      string.append("*");
    }

    if (*right.e.get()) {
      string.append("E");
    }

    if (*right.u.get()) {
      string.append("U");
    }

    if (*right.f.get()) {
      string.append("F");
    }

    if (*right.r.get()) {
      string.append("R");
    }

    if (*right.p.get()) {
      string.append("P");
    }

    if (*right.b.get()) {
      string.append("B");
    }

    if (*right.l.get()) {
      string.append("L");
    }

    if (*right.g.get()) {
      string.append("G");
    }

    if (*right.t.get()) {
      string.append("T");
    }

    if (*right.s.get()) {
      string.append("S");
    }

    if (*right.d.get()) {
      string.append("D");
    }

    if (*right.z.get()) {
      string.append("Z");
    }

    return string;
  }
};
} /* namespace opensteno */
#endif //OPENSTENO_STENOBOARD_HPP
