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

  void WindowSystemDriver::registerKeyPress(KeySym key) {
    std::map<KeySym, std::shared_ptr<bool> >::iterator keyMapIterator;
    keyMapIterator = keyMap.find(key);
    if(keyMapIterator != keyMap.end()) {
      *keyMapIterator->second.get() = true;
    }
  }

  void WindowSystemDriver::processStroke() {
    std::map<std::string, std::string>::iterator dictionaryIterator;
    std::map<std::string, KeySym>::iterator keySymMapIterator;
    dictionaryIterator = dictionary.find(stenoboard.getString());
    if (dictionaryIterator != dictionary.end()) {
      if (dictionaryIterator->second == "<exit>") {
        std::cout << "Exiting" << std::endl;
        shutdown = true;
        stenoboard.resetButtons();
      } else {
        for(char character : dictionaryIterator->second) {
          std::string characterString = charToString(character);
          keySymMapIterator = keySymMap.find(characterString);

          if(keySymMap.find(characterString) != keySymMap.end()) {
            windowSystem.simulateKeypress(keySymMapIterator->second);
          }
          stenoboard.resetButtons();
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
          processStroke();
          break;
        default:
          break;
        }
    }
} /* namespace opensteno */
