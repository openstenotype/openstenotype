#ifndef OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#define OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>
#include <opensteno/KeyMapFactory.hpp>
#include <map>
#include <memory>

namespace opensteno {
  class WindowSystemDriver {
  private:
    Stenoboard stenoboard;
    Stenoboard strokeStenoboard;
    KeyMapFactory keyMapFactory;
    WindowSystem& windowSystem;
    bool shutdown;
    std::map <KeySym, std::shared_ptr<bool> > keyMap;
    std::map <KeySym, std::shared_ptr<bool> > strokeKeyMap;
    std::map <std::string, std::string> dictionary;
    std::map <std::string, KeySym> keySymMap;
    void registerKey(KeySym key,
                     std::map<KeySym, std::shared_ptr<bool>> map,
                     bool value);
    void registerKeyPress(KeySym key);
    void registerKeyRelease(KeySym key);
    void processStroke();
    std::string charToString(char character);
  public:
    bool receivedShutdownCommand();
    WindowSystemDriver(WindowSystem& windowSystem);
    void update();
    Stenoboard getStenoboard();
  };
} /* namespace opensteno */
#endif //OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
