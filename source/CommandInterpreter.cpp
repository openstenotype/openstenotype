#include <opensteno/CommandInterpreter.hpp>

namespace opensteno {
  CommandInterpreter::CommandInterpreter(logger::LoggerFactory& logger,
                                         WindowSystem& windowSystem):
    logger(logger), windowSystem(windowSystem){
  }

  void CommandInterpreter::executeCommand(std::string commandName, std::vector <std::string> parameters) {
  }

  bool CommandInterpreter::hasCommand(std::string commandName) {
    return false;
  }

  bool CommandInterpreter::executeCommand(std::string commandName) {
    if (commandName == "<desktop-1>") {
      windowSystem.switchToDesktop(1);
    } else if (commandName == "<desktop-2>") {
      windowSystem.switchToDesktop(2);
    } else if (commandName == "<desktop-3>") {
      windowSystem.switchToDesktop(3);
    } else if (commandName == "<desktop-4>") {
      windowSystem.switchToDesktop(4);
    } else {
      return false;
    }

    return true;
  }

  void CommandInterpreter::simulateKeypressRelease(int key, unsigned int modifiers){
    windowSystem.simulateKeypressRelease(key, modifiers);
  }

  void CommandInterpreter::simulateKeypressRelease(int key){
    windowSystem.simulateKeypressRelease(key);
  }
} /* namespace opensteno */
