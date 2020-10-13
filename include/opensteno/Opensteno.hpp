#ifndef OPENSTENO_OPENSTENO_HPP
#define OPENSTENO_OPENSTENO_HPP
#include <opensteno/WindowSystem.hpp>
#include <opensteno/WindowSystemDriver.hpp>
#include <opensteno/CommandInterpreter.hpp>
#include <opensteno/CommandParser.hpp>
#include <opensteno/Config.hpp>
#include <logger/include/LoggerFactory.hpp>
#include <logger/include/AnsiConsoleLogger.hpp>

namespace opensteno {
  class Opensteno {
  public:
    Config config;
    logger::LoggerFactory logger;
    WindowSystem windowSystem;
    CommandInterpreter commandInterpreter;
    CommandParser commandParser;
    WindowSystemDriver driver;
    Opensteno();
    bool isRunning();
  };
} /* namespace opensteno */
#endif //OPENSTENO_OPENSTENO_HPP
