#include <opensteno/Opensteno.hpp>
namespace opensteno {
  Opensteno::Opensteno():
    config(std::string("../data/config.json")),
    logger(*new logger::AnsiConsoleLogger()),
    driver(config, logger, windowSystem)
  {
    logger.log(logger::LogLevel::Info, std::string("System")) << "Opensteno Started";
  }

  bool Opensteno::isRunning() {
    return !driver.receivedShutdownCommand();
  }

} /* namespace opensteno */
