#include <opensteno/Opensteno.hpp>
namespace opensteno {
  Opensteno::Opensteno():
    config(std::string("../data/config.json")),
    logger(*new logger::AnsiConsoleLogger()),
    commandInterpreter(logger, windowSystem),
    commandParser(logger),
    driver(config, logger, windowSystem, commandParser, commandInterpreter)
  {
    logger.log(logger::LogLevel::Info, std::string("System")) << "Opensteno Started";
  }

  bool Opensteno::isRunning() {
    return !driver.receivedShutdownCommand();
  }

} /* namespace opensteno */
