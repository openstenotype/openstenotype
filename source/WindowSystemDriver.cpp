#include <opensteno/WindowSystemDriver.hpp>
#include <opensteno/DictionaryLoader.hpp>
#include <sstream>
namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(Config& config,
                                         logger::LoggerFactory& logger,
                                         WindowSystem& windowSystem, CommandParser& commandParser):
    config(config), logger(logger), windowSystem(windowSystem), shutdown(false),
    commandParser(commandParser)
  {
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
      if (dictionaryIterator->second == "{PLOVER:QUIT}") {
        std::cout << "Exiting" << std::endl;
        logger.log(logger::LogLevel::Info, std::string("System")) << "Exiting ";
        shutdown = true;
      } else {
        commandParser.processString(dictionaryIterator->second);
      }
    }
  }

  void WindowSystemDriver::processDictionaryEntry(std::string entry) {
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
