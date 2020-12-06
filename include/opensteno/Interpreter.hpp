#ifndef OPENSTENO_INTERPRETER_HPP
#define OPENSTENO_INTERPRETER_HPP
#include <string>
#include <vector>

namespace opensteno {
  class Interpreter {
  public:
    virtual void executeCommand(std::string commandName, std::vector <std::string> parameters) = 0;
    virtual bool executeCommand(std::string commandName) = 0;
    virtual bool hasCommand(std::string commandName) = 0;
    virtual void simulateKeypressRelease(int key, unsigned int modifiers) = 0;
    virtual void simulateKeypressRelease(int key) = 0;
  };
} /* namespace opensteno */
#endif //OPENSTENO_INTERPRETER_HPP
