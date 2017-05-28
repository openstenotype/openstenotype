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

            for(char& character : dictionaryIterator->second) {
              //            for (std::string::reverse_iterator i = dictionaryIterator->second.rbegin();
              //                 i != dictionaryIterator->second.rend(); ++i) {
              if (character == 't') {
                windowSystem.simulateKeypress(XK_t);
              }

              if (character == 'h') {
                windowSystem.simulateKeypress(XK_h);
              }

              if (character == 'e') {
                windowSystem.simulateKeypress(XK_e);
              }

              if (character == 'o') {
                windowSystem.simulateKeypress(XK_o);
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
