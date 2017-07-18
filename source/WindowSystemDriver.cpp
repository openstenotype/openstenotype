#include <opensteno/WindowSystemDriver.hpp>
#include <opensteno/DictionaryLoader.hpp>
#include <sstream>
namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(Config& config,
                                         WindowSystem& windowSystem):
    config(config), windowSystem(windowSystem), shutdown(false) {
    helper = WindowSystemDriverHelper();
    stenoboard.resetButtons();
    stroke.resetButtons();
    keyMap = keyMapFactory.getNeoKeyMap(stenoboard);
    strokeKeyMap = keyMapFactory.getNeoKeyMap(stroke);
    std::string filePath = "../data/dictionary.json";
    dictionary = DictionaryLoader::getDictionaryFromFile(filePath);
    keySymMap = keyMapFactory.getSymMap();
  }

  bool WindowSystemDriver::receivedShutdownCommand() {
    return shutdown;
  }

  void WindowSystemDriver::registerKeyPress(KeySym key) {
    helper.registerKey(key, keyMap, true);
    helper.registerKey(key, strokeKeyMap, true);
  }

  void WindowSystemDriver::registerKeyRelease(KeySym key) {
    helper.registerKey(key, keyMap, false);
  }

  void WindowSystemDriver::processStroke() {
    std::map<std::string, std::string>::iterator dictionaryIterator;
    std::map<std::string, KeySym>::iterator keySymMapIterator;
    dictionaryIterator = dictionary.find(stroke.getString());
    if (dictionaryIterator != dictionary.end()) {
      if (dictionaryIterator->second == "<exit>") {
        std::cout << "Exiting" << std::endl;
        shutdown = true;
      } else {
        for(char character : dictionaryIterator->second) {
          std::string characterString = helper.charToString(character);
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
            stroke.resetButtons();
          }
          break;
        default:
          break;
        }
    }
} /* namespace opensteno */
