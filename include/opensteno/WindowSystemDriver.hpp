#ifndef OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#define OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>
#include <opensteno/WindowSystemDriverHelper.hpp>
#include <opensteno/KeyMapFactory.hpp>
#include <opensteno/Config.hpp>
#include <opensteno/CommandParser.hpp>
#include <logger/include/LoggerFactory.hpp>
#include <unordered_map>
#include <memory>

namespace opensteno {
  class WindowSystemDriver {
  private:
    Stenoboard stenoboard;
    Stenoboard stroke;
    KeyMapFactory keyMapFactory;
    Config& config;
    logger::LoggerFactory& logger;
    WindowSystem& windowSystem;
    WindowSystemDriverHelper helper;
    bool shutdown;
    CommandParser& commandParser;
    std::unordered_map <KeySym, std::shared_ptr<bool> > keyMap;
    std::unordered_map <KeySym, std::shared_ptr<bool> > strokeKeyMap;
    std::map <std::string, std::string> dictionary;
    std::unordered_map <std::string, KeySym> keySymMap;
    void registerKeyPress(KeySym key);
    void registerKeyRelease(KeySym key);
    void processStroke();
    void processDictionaryEntry(std::string);
  public:
    bool receivedShutdownCommand();
    WindowSystemDriver(Config& config, logger::LoggerFactory& logger, WindowSystem& windowSystem, CommandParser& commandParser);
    void update();
    Stenoboard getStenoboard();
  };
} /* namespace opensteno */
#endif //OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
