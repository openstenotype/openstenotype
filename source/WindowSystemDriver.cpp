#include <opensteno/WindowSystemDriver.hpp>
#include <opensteno/DictionaryLoader.hpp>
#include <sstream>
namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(Config& config,
                                         logger::LoggerFactory& logger,
                                         WindowSystem& windowSystem):
    config(config), logger(logger), windowSystem(windowSystem), shutdown(false) {
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
    logger.log(logger::LogLevel::Info, std::string("System")) << "Stroked: " << stroke.getString();
    dictionaryIterator = dictionary.find(stroke.getString());
    if (dictionaryIterator != dictionary.end()) {
      if (dictionaryIterator->second == "<desktop-1>") {
        windowSystem.switchToDesktop(1);
      } else if (dictionaryIterator->second == "<desktop-2>") {
        windowSystem.switchToDesktop(2);
      } else if (dictionaryIterator->second == "<desktop-3>") {
        windowSystem.switchToDesktop(3);
      } else if (dictionaryIterator->second == "<desktop-4>") {
        windowSystem.switchToDesktop(4);
      } else if (dictionaryIterator->second == "<exit>") {
        std::cout << "Exiting" << std::endl;
        logger.log(logger::LogLevel::Info, std::string("System")) << "Exiting ";
        shutdown = true;
      } else {
        processDictionaryEntry(dictionaryIterator->second);
      }
    }
  }

  void WindowSystemDriver::processDictionaryEntry(std::string entry) {
    std::map<std::string, KeySym>::iterator keySymMapIterator;
    bool modifierParsing = false;
    std::string modifierString;
    unsigned int modifiers = 0;
    for(char character : entry) {
      if (character == '<') {
        modifierParsing = true;
      }
      if (character == '>') {
        if (modifierString == "mod") {
          modifiers = Mod4Mask;
        }
        if (modifierString == "ctrl") {
          modifiers = ControlMask;
        }
        if (modifierString == "shift") {
          modifiers = ShiftMask;
        }
        modifierParsing = false;
        modifierString = "";
      }
      if (modifierParsing) {
        if (character != '<' && character != '>') {
          modifierString.append(helper.charToString(character));
        }
      } else {
        std::string characterString = helper.charToString(character);
        keySymMapIterator = keySymMap.find(characterString);
        if(keySymMap.find(characterString) != keySymMap.end()) {
          windowSystem.simulateKeypressRelease(keySymMapIterator->second, modifiers);
          modifiers = 0;
          modifierString = "";
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
