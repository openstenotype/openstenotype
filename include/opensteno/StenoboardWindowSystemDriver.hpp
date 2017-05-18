#ifndef OPENSTENO_STENOBOARD_WINDOW_SYSTEM_DRIVER_HPP
#define OPENSTENO_STENOBOARD_WINDOW_SYSTEM_DRIVER_HPP
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>

namespace opensteno {
  class StenoboardWindowSystemDriver {
  private:
    Stenoboard stenoboard;
    WindowSystem& windowSystem;
  public:
    StenoboardWindowSystemDriver(WindowSystem& windowSystem);
    Stenoboard getStenoboard();
  };
} /* namespace opensteno */
#endif //OPENSTENO_STENOBOARD_WINDOW_SYSTEM_DRIVER_HPP
