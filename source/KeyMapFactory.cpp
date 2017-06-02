#include <opensteno/KeyMapFactory.hpp>

namespace opensteno {
  KeyMapFactory::KeyMapFactory() {
  }

  std::map <std::string, KeySym> KeyMapFactory::getSymMap() {
    std::map <std::string, KeySym> keySymMap;
    keySymMap.insert( std::pair<std::string, KeySym>("a", XK_a));
    keySymMap.insert( std::pair<std::string, KeySym>("b", XK_b));
    keySymMap.insert( std::pair<std::string, KeySym>("c", XK_c));
    keySymMap.insert( std::pair<std::string, KeySym>("d", XK_d));
    keySymMap.insert( std::pair<std::string, KeySym>("e", XK_e));
    keySymMap.insert( std::pair<std::string, KeySym>("f", XK_f));
    keySymMap.insert( std::pair<std::string, KeySym>("g", XK_g));
    keySymMap.insert( std::pair<std::string, KeySym>("h", XK_h));
    keySymMap.insert( std::pair<std::string, KeySym>("i", XK_i));
    keySymMap.insert( std::pair<std::string, KeySym>("j", XK_j));
    keySymMap.insert( std::pair<std::string, KeySym>("k", XK_k));
    keySymMap.insert( std::pair<std::string, KeySym>("l", XK_l));
    keySymMap.insert( std::pair<std::string, KeySym>("m", XK_m));
    keySymMap.insert( std::pair<std::string, KeySym>("n", XK_n));
    keySymMap.insert( std::pair<std::string, KeySym>("o", XK_o));
    keySymMap.insert( std::pair<std::string, KeySym>("p", XK_p));
    keySymMap.insert( std::pair<std::string, KeySym>("q", XK_q));
    keySymMap.insert( std::pair<std::string, KeySym>("r", XK_r));
    keySymMap.insert( std::pair<std::string, KeySym>("s", XK_s));
    keySymMap.insert( std::pair<std::string, KeySym>("t", XK_t));
    keySymMap.insert( std::pair<std::string, KeySym>("u", XK_u));
    keySymMap.insert( std::pair<std::string, KeySym>("v", XK_v));
    keySymMap.insert( std::pair<std::string, KeySym>("w", XK_w));
    keySymMap.insert( std::pair<std::string, KeySym>("x", XK_x));
    keySymMap.insert( std::pair<std::string, KeySym>("y", XK_y));
    keySymMap.insert( std::pair<std::string, KeySym>("z", XK_z));
    keySymMap.insert( std::pair<std::string, KeySym>("A", XK_A));
    keySymMap.insert( std::pair<std::string, KeySym>("B", XK_B));
    keySymMap.insert( std::pair<std::string, KeySym>("C", XK_C));
    keySymMap.insert( std::pair<std::string, KeySym>("D", XK_D));
    keySymMap.insert( std::pair<std::string, KeySym>("E", XK_E));
    keySymMap.insert( std::pair<std::string, KeySym>("F", XK_F));
    keySymMap.insert( std::pair<std::string, KeySym>("G", XK_G));
    keySymMap.insert( std::pair<std::string, KeySym>("H", XK_H));
    keySymMap.insert( std::pair<std::string, KeySym>("I", XK_I));
    keySymMap.insert( std::pair<std::string, KeySym>("J", XK_J));
    keySymMap.insert( std::pair<std::string, KeySym>("K", XK_K));
    keySymMap.insert( std::pair<std::string, KeySym>("L", XK_L));
    keySymMap.insert( std::pair<std::string, KeySym>("M", XK_M));
    keySymMap.insert( std::pair<std::string, KeySym>("N", XK_N));
    keySymMap.insert( std::pair<std::string, KeySym>("O", XK_O));
    keySymMap.insert( std::pair<std::string, KeySym>("P", XK_P));
    keySymMap.insert( std::pair<std::string, KeySym>("Q", XK_Q));
    keySymMap.insert( std::pair<std::string, KeySym>("R", XK_R));
    keySymMap.insert( std::pair<std::string, KeySym>("S", XK_S));
    keySymMap.insert( std::pair<std::string, KeySym>("T", XK_T));
    keySymMap.insert( std::pair<std::string, KeySym>("U", XK_U));
    keySymMap.insert( std::pair<std::string, KeySym>("V", XK_V));
    keySymMap.insert( std::pair<std::string, KeySym>("W", XK_W));
    keySymMap.insert( std::pair<std::string, KeySym>("X", XK_X));
    keySymMap.insert( std::pair<std::string, KeySym>("Y", XK_Y));
    keySymMap.insert( std::pair<std::string, KeySym>("Z", XK_Z));

    return keySymMap;
  }

} /* namespace opensteno */
