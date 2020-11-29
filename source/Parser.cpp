#include <opensteno/Parser.hpp>

namespace opensteno {
  bool Parser::isComplete() {
    return terminated;
  }

  bool Parser::isStarted() {
    return running;
  }

  bool Parser::hasParameters() {
    if(this->parameters.size()>0) {
      return true;
    }

    return false;
  }
  std::string Parser::getCommand() {
    return this->command;
  }
  void Parser::reset() {}
  std::vector<std::string> Parser::getParameters() {
    return this->parameters;
  }
} /* namespace opensteno */
