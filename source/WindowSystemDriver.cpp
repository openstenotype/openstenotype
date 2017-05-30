#include <opensteno/WindowSystemDriver.hpp>

namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(WindowSystem& windowSystem):windowSystem(windowSystem), shutdown(false) {
    stenoboard.resetButtons();
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_c, stenoboard.left.h));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_e, stenoboard.left.r));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_x, stenoboard.left.t));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_p, stenoboard.left.o));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_i, stenoboard.left.k));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_a, stenoboard.left.w));
    keyMap.insert( std::pair<KeySym, std::shared_ptr<bool>  >(XK_e, stenoboard.left.r));

    dictionary.insert( std::pair<std::string, std::string >("TO", "to"));
    dictionary.insert( std::pair<std::string, std::string >("T", "the"));
    dictionary.insert( std::pair<std::string, std::string >("WUB", "one"));
    dictionary.insert( std::pair<std::string, std::string >("WU", "with you"));

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
  }

  bool WindowSystemDriver::receivedShutdownCommand() {
    return shutdown;
  }

  void WindowSystemDriver::update() {
    XEvent event = windowSystem.getNextEvent();
    KeySym key;
    bool allReleased = true;
    std::map<KeySym, std::shared_ptr<bool> >::iterator keyMapIterator;
    std::map<std::string, std::string>::iterator dictionaryIterator;
    std::map<std::string, KeySym>::iterator keySymMapIterator;

      switch(event.type)
        {
        case KeyPress:
          key = windowSystem.getKeySymFromEvent(event);

          keyMapIterator = keyMap.find(key);
          if(keyMapIterator != keyMap.end()) {
            *keyMapIterator->second.get() = true;
          }

          break;
        case KeyRelease:
          if (allReleased && *stenoboard.left.k.get() &&
              *stenoboard.left.w.get() && *stenoboard.left.r.get()) {
            std::cout << "Exiting" << std::endl;
            shutdown = true;
            stenoboard.resetButtons();
          }

          dictionaryIterator = dictionary.find(stenoboard.getString());
          if(dictionaryIterator != dictionary.end()) {
            for(char character : dictionaryIterator->second) {
              std::string characterString(&character);
              keySymMapIterator = keySymMap.find(characterString);
              std::cout << characterString << std::endl;
              std::cout << "." << std::endl;
              if(keySymMapIterator != keySymMap.end()) {
                std::cout << "simulating" << std::endl;
                windowSystem.simulateKeypress(keySymMapIterator->second);
              }
              stenoboard.resetButtons();
            }
          }
          break;
        default:
          break;
        }
    }
} /* namespace opensteno */
