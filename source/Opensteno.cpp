#include <opensteno/Opensteno.hpp>

namespace opensteno {
  Opensteno::Opensteno():config(std::string("../data/config.json")), driver(config, windowSystem) {
  }

  bool Opensteno::isRunning() {
    return !driver.receivedShutdownCommand();
  }

} /* namespace opensteno */
