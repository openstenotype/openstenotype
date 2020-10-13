#ifndef OPENSTENO_COMMAND_INTERPRETER_HPP
#define OPENSTENO_COMMAND_INTERPRETER_HPP
#include <opensteno/WindowSystem.hpp>
#include <opensteno/Config.hpp>
#include <logger/include/LoggerFactory.hpp>
#include <vector>

namespace opensteno {
  class CommandInterpreter {
  private:
    logger::LoggerFactory& logger;
    WindowSystem& windowSystem;
  public:
    CommandInterpreter(logger::LoggerFactory& logger,
                                       WindowSystem& windowSystem);
    void executeCommand(std::string commandName, std::vector <std::string> parameters);
    bool executeCommand(std::string commandName);
    bool hasCommand(std::string commandName);
    void simulateKeypressRelease(int key, unsigned int modifiers);
    void simulateKeypressRelease(int key);
  };
} /* namespace opensteno */
#endif //OPENSTENO_COMMAND_INTERPRETER_HPP
