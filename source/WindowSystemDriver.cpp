#include <opensteno/WindowSystemDriver.hpp>
#include <sstream>

namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(WindowSystem& windowSystem):windowSystem(windowSystem), shutdown(false) {
    stenoboard.resetButtons();
    strokeStenoboard.resetButtons();
    keyMap = keyMapFactory.getNeoKeyMap(stenoboard);
    strokeKeyMap = keyMapFactory.getNeoKeyMap(strokeStenoboard);

    dictionary.insert( std::pair<std::string, std::string >("TO", "to"));
    dictionary.insert( std::pair<std::string, std::string >("TA", "that"));
    dictionary.insert( std::pair<std::string, std::string >("T", "the"));
    dictionary.insert( std::pair<std::string, std::string >("WUB", "one"));
    dictionary.insert( std::pair<std::string, std::string >("WU", "with you"));
    dictionary.insert( std::pair<std::string, std::string >("KWR", "<exit>"));

    keySymMap = keyMapFactory.getSymMap();
  }

  bool WindowSystemDriver::receivedShutdownCommand() {
    return shutdown;
  }

  std::string WindowSystemDriver::charToString(char character) {
    std::stringstream stringStream;
    stringStream << character;
    std::string characterString;
    stringStream >> characterString;

    return characterString;
  }

  void WindowSystemDriver::registerKey(KeySym key,
                                       std::map<KeySym, std::shared_ptr<bool> > map,
                                       bool value) {
    std::map<KeySym, std::shared_ptr<bool> >::iterator mapIterator;
    mapIterator = map.find(key);
    if(mapIterator != map.end()) {
      *mapIterator->second.get() = value;
    }
  }

  void WindowSystemDriver::registerKeyPress(KeySym key) {
    registerKey(key, keyMap, true);
    registerKey(key, strokeKeyMap, true);
  }

  void WindowSystemDriver::registerKeyRelease(KeySym key) {
    registerKey(key, keyMap, false);
  }

  void WindowSystemDriver::processStroke() {
    std::map<std::string, std::string>::iterator dictionaryIterator;
    std::map<std::string, KeySym>::iterator keySymMapIterator;
    dictionaryIterator = dictionary.find(strokeStenoboard.getString());
    if (dictionaryIterator != dictionary.end()) {
      if (dictionaryIterator->second == "<exit>") {
        std::cout << "Exiting" << std::endl;
        shutdown = true;
      } else {
        for(char character : dictionaryIterator->second) {
          std::string characterString = charToString(character);
          keySymMapIterator = keySymMap.find(characterString);

          if(keySymMap.find(characterString) != keySymMap.end()) {
            windowSystem.simulateKeypress(keySymMapIterator->second);
          }
        }
      }
    }
  }

  void WindowSystemDriver::update() {
    XEvent event = windowSystem.getNextEvent();
    KeySym key;
      switch(event.type)
        {
        case KeyPress:
          key = windowSystem.getKeySymFromEvent(event);
          registerKeyPress(key);

          break;
        case KeyRelease:
          key = windowSystem.getKeySymFromEvent(event);
          registerKeyRelease(key);
          if (stenoboard.allButtonsReleased()) {
            stenoboard.resetButtons();
            processStroke();
            strokeStenoboard.resetButtons();
          }
          break;
        default:
          break;
        }
    }
} /* namespace opensteno */
