#include <opensteno/InterpreterStub.hpp>

namespace opensteno {
  InterpreterStub::InterpreterStub(){
  }

  void InterpreterStub::executeCommand(std::string commandName, std::vector <std::string> parameters) {
  }

  bool InterpreterStub::hasCommand(std::string commandName) {
    return false;
  }

  bool InterpreterStub::executeCommand(std::string commandName) {
    return false;
  }

  void InterpreterStub::simulateKeypressRelease(int key, unsigned int modifiers){
  }

  void InterpreterStub::simulateKeypressRelease(int key){
  }

} /* namespace opensteno */
