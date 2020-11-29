#ifndef OPENSTENO_PARSER_HPP
#define OPENSTENO_PARSER_HPP
#include <string>
#include <vector>

namespace opensteno {
  class Parser {
  private:
    bool terminated;
    bool running;
    std::string command;
    std::vector<std::string> parameters;
  public:
    virtual void processCharacter(char commandCharacter) = 0;
    bool isStarted();
    bool isComplete();
    bool hasParameters();
    std::string getCommand();
    void reset();
    std::vector<std::string> getParameters();
  };
} /* namespace opensteno */
#endif //OPENSTENO_PARSER_HPP
