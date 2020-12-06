#ifndef OPENSTENO_INTERPRETER_STUB_HPP
#define OPENSTENO_INTERPRETER_STUB_HPP
#include <string>
#include <vector>
#include <opensteno/Interpreter.hpp>

namespace opensteno {
  class InterpreterStub: public Interpreter {
  public:
    InterpreterStub();
    void executeCommand(std::string commandName, std::vector <std::string> parameters);
    bool executeCommand(std::string commandName);
    bool hasCommand(std::string commandName);
    void simulateKeypressRelease(int key, unsigned int modifiers);
    void simulateKeypressRelease(int key);
  };
} /* namespace opensteno */
#endif //OPENSTENO_INTERPRETER_STUB_HPP
