#include <opensteno/Opensteno.hpp>

namespace opensteno {
  Opensteno::Opensteno():driver(windowSystem) {

  }

  bool Opensteno::isRunning() {
    return !driver.receivedShutdownCommand();
  }

} /* namespace opensteno */
