#ifndef OPENSTENO_STENOBOARD_WINDOW_SYSTEM_DRIVER_HPP
#define OPENSTENO_STENOBOARD_WINDOW_SYSTEM_DRIVER_HPP
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>

namespace opensteno {
  class StenoboardWindowSystemDriver {
  public:
    StenoboardWindowSystemDriver(WindowSystem& windowSystem);
    StenoBoard getStenoboard();
  };
} /* namespace opensteno */
#endif //OPENSTENO_STENOBOARD_WINDOW_SYSTEM_DRIVER_HPP
