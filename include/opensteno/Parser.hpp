#ifndef OPENSTENO_PARSER_HPP
#define OPENSTENO_PARSER_HPP
#include <string>
#include <vector>
#include <opensteno/CommandInterpreter.hpp>

namespace opensteno {
  class Parser {
  private:
    std::string command;
    std::vector<std::string> parameters;
  protected:
    bool terminated;
    bool running;
  public:
    virtual void processCharacter(char commandCharacter, CommandInterpreter& commandInterpreter) = 0;
    bool isStarted();
    bool isComplete();
    bool hasParameters();
    std::string getCommand();
    void reset();
    std::vector<std::string> getParameters();
  };
} /* namespace opensteno */
#endif //OPENSTENO_PARSER_HPP
