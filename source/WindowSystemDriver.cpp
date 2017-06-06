#include <opensteno/WindowSystemDriver.hpp>
#include <sstream>

namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(WindowSystem& windowSystem):windowSystem(windowSystem), shutdown(false) {
    stenoboard.resetButtons();
    keyMap = keyMapFactory.getNeoKeyMap(stenoboard);

    dictionary.insert( std::pair<std::string, std::string >("TO", "to"));
    dictionary.insert( std::pair<std::string, std::string >("TA", "that"));
    dictionary.insert( std::pair<std::string, std::string >("T", "the"));
    dictionary.insert( std::pair<std::string, std::string >("WUB", "one"));
    dictionary.insert( std::pair<std::string, std::string >("WU", "with you"));

    keySymMap = keyMapFactory.getSymMap();
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
              std::stringstream stringStream;
              stringStream << character;
              std::string characterString;
              stringStream >> characterString;
              keySymMapIterator = keySymMap.find(characterString);

              if(keySymMap.find(characterString) != keySymMap.end()) {
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
