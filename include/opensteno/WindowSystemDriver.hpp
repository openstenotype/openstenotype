#ifndef OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#define OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
#include <opensteno/Opensteno.hpp>
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>

namespace opensteno {
  class WindowSystemDriver {
  private:
    Stenoboard stenoboard;
    WindowSystem& windowSystem;
    bool shutdown;
  public:
    bool receivedShutdownCommand();
    WindowSystemDriver(WindowSystem& windowSystem);
    void update();
    Stenoboard getStenoboard();
  };
} /* namespace opensteno */
#endif //OPENSTENO_WINDOW_SYSTEM_DRIVER_HPP
