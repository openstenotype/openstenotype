#include <opensteno/KeyMapFactory.hpp>

namespace opensteno {
  KeyMapFactory::KeyMapFactory() {
  }

  std::unordered_map <KeySym, std::shared_ptr<bool> > KeyMapFactory::getNeoKeyMap(Stenoboard stenoboard) {
    std::unordered_map <KeySym, std::shared_ptr<bool> > keyMap;
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_3, stenoboard.numberBar));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_w, stenoboard.asterisk1));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_o, stenoboard.asterisk2));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_x, stenoboard.left.s1));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_v, stenoboard.left.t));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_l, stenoboard.left.p));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_c, stenoboard.left.h));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_u, stenoboard.left.s2));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_i, stenoboard.left.k));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_a, stenoboard.left.w));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_e, stenoboard.left.r));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_adiaeresis, stenoboard.left.a));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_p, stenoboard.left.o));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_h, stenoboard.right.f));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_g, stenoboard.right.p));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_f, stenoboard.right.l));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_q, stenoboard.right.t));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_ssharp, stenoboard.right.d));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_n, stenoboard.right.r));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_r, stenoboard.right.g));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_t, stenoboard.right.b));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_d, stenoboard.right.s));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_y, stenoboard.right.z));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_b, stenoboard.right.e));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_m, stenoboard.right.u));

    return keyMap;
  }

  std::unordered_map <KeySym, std::shared_ptr<bool> > KeyMapFactory::getQwertzKeyMap(Stenoboard stenoboard) {
    std::unordered_map <KeySym, std::shared_ptr<bool> > keyMap;
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_3, stenoboard.numberBar));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_t, stenoboard.asterisk1));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_g, stenoboard.asterisk2));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_q, stenoboard.left.s1));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_w, stenoboard.left.t));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_e, stenoboard.left.p));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_r, stenoboard.left.h));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_a, stenoboard.left.s2));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_s, stenoboard.left.k));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_d, stenoboard.left.w));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_f, stenoboard.left.r));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_c, stenoboard.left.a));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_v, stenoboard.left.o));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_u, stenoboard.right.f));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_i, stenoboard.right.p));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_o, stenoboard.right.l));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_p, stenoboard.right.t));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_bracketleft, stenoboard.right.d));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_j, stenoboard.right.r));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_k, stenoboard.right.g));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_l, stenoboard.right.b));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_semicolon, stenoboard.right.s));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_comma, stenoboard.right.z));

    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_n, stenoboard.right.e));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_m, stenoboard.right.u));

    return keyMap;
  }

  std::unordered_map <std::string, KeySym> KeyMapFactory::getSymMap() {
    std::unordered_map <std::string, KeySym> keySymMap;
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
    keySymMap.insert( std::pair<std::string, KeySym>("0", XK_0));
    keySymMap.insert( std::pair<std::string, KeySym>("1", XK_1));
    keySymMap.insert( std::pair<std::string, KeySym>("2", XK_2));
    keySymMap.insert( std::pair<std::string, KeySym>("3", XK_3));
    keySymMap.insert( std::pair<std::string, KeySym>("4", XK_4));
    keySymMap.insert( std::pair<std::string, KeySym>("5", XK_5));
    keySymMap.insert( std::pair<std::string, KeySym>("6", XK_6));
    keySymMap.insert( std::pair<std::string, KeySym>("7", XK_7));
    keySymMap.insert( std::pair<std::string, KeySym>("8", XK_8));
    keySymMap.insert( std::pair<std::string, KeySym>("9", XK_9));
    keySymMap.insert( std::pair<std::string, KeySym>("mod", XK_Super_L));
    keySymMap.insert( std::pair<std::string, KeySym>("ctrl", XK_Control_L));
    return keySymMap;
  }

  std::unordered_map <std::string, unsigned int> KeyMapFactory::getModifierMap() {
    std::unordered_map <std::string, unsigned int> modifierMap;
    modifierMap.insert(std::pair<std::string, unsigned int>("Control_L", ControlMask));
    modifierMap.insert(std::pair<std::string, unsigned int>("Super_L", Mod4Mask));
    modifierMap.insert(std::pair<std::string, unsigned int>("Shift", ShiftMask));
    modifierMap.insert(std::pair<std::string, unsigned int>("Shift_L", ShiftMask));
    return modifierMap;
  }
} /* namespace opensteno */
