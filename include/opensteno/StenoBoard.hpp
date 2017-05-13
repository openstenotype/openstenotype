#ifndef OPENSTENO_STENOBOARD_HPP
#define OPENSTENO_STENOBOARD_HPP
namespace opensteno {
struct StenoBoard {
public:
  //14 buttons per side
  bool s, t, p, h, k, w, r, a, o;

  void resetButtons(){
    s = t = p = h =  k = w = r = a = o = false;
  }
};
} /* namespace opensteno */
#endif //OPENSTENO_STENOBOARD_HPP
