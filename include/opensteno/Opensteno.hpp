#ifndef OPENSTENO_OPENSTENO_HPP
#define OPENSTENO_OPENSTENO_HPP
#include <opensteno/WindowSystem.hpp>
#include <opensteno/WindowSystemDriver.hpp>

namespace opensteno {
  class Opensteno {
  public:
    WindowSystem windowSystem;
    WindowSystemDriver driver;
    Opensteno();
    bool isRunning();
  };
} /* namespace opensteno */
#endif //OPENSTENO_OPENSTENO_HPP
