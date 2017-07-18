#ifndef OPENSTENO_OPENSTENO_HPP
#define OPENSTENO_OPENSTENO_HPP
#include <opensteno/WindowSystem.hpp>
#include <opensteno/WindowSystemDriver.hpp>
#include <opensteno/Config.hpp>

namespace opensteno {
  class Opensteno {
  public:
    Config config;
    WindowSystem windowSystem;
    WindowSystemDriver driver;
    Opensteno();
    bool isRunning();
  };
} /* namespace opensteno */
#endif //OPENSTENO_OPENSTENO_HPP
