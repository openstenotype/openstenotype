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
  }

  bool WindowSystemDriver::receivedShutdownCommand() {
    return shutdown;
  }

  void WindowSystemDriver::update() {
    XEvent event = windowSystem.getNextEvent();
    KeySym key;
    bool allReleased = true;
    std::map<KeySym, std::shared_ptr<bool> >::iterator keyMapIterator;

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

          if (allReleased && *stenoboard.left.t.get() && *stenoboard.left.o.get()) {
            windowSystem.simulateKeypress(XK_t);
            windowSystem.simulateKeypress(XK_o);
            stenoboard.resetButtons();
          }
          break;
        default:
          break;
        }
    }
} /* namespace opensteno */
