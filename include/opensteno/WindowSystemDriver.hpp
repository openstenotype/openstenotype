#ifndef OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#define OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>
#include <opensteno/WindowSystemDriverHelper.hpp>
#include <opensteno/KeyMapFactory.hpp>
#include <opensteno/Config.hpp>
#include <map>
#include <memory>

namespace opensteno {
  class WindowSystemDriver {
  private:
    Stenoboard stenoboard;
    Stenoboard stroke;
    KeyMapFactory keyMapFactory;
    Config& config;
    WindowSystem& windowSystem;
    WindowSystemDriverHelper helper;
    bool shutdown;
    std::map <KeySym, std::shared_ptr<bool> > keyMap;
    std::map <KeySym, std::shared_ptr<bool> > strokeKeyMap;
    std::map <std::string, std::string> dictionary;
    std::map <std::string, KeySym> keySymMap;
    void registerKeyPress(KeySym key);
    void registerKeyRelease(KeySym key);
    void processStroke();
  public:
    bool receivedShutdownCommand();
    WindowSystemDriver(Config& config, WindowSystem& windowSystem);
    void update();
    Stenoboard getStenoboard();
  };
} /* namespace opensteno */
#endif //OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
