#ifndef OPENSTENO_COMMAND_PARSER_HPP
#define OPENSTENO_COMMAND_PARSER_HPP
#include <string>
#include <unordered_map>
#include <opensteno/Parser.hpp>
#include <opensteno/CommandInterpreter.hpp>
#include <opensteno/KeyMapFactory.hpp>
#include <opensteno/WindowSystemDriverHelper.hpp>

namespace opensteno {
  class CommandParser : public Parser {
  public:
    CommandParser(logger::LoggerFactory& logger);
    void processString(std::string commandString, CommandInterpreter& commandInterpreter);
    virtual void processCharacter(char commandChar, CommandInterpreter& commandInterpreter);
  private:
    logger::LoggerFactory& logger;
    std::unordered_map <std::string, KeySym> keySymMap;
    std::unordered_map <std::string, unsigned int> modifierMap;
    bool modifierParsing = false;
    std::string modifierString = "";
    unsigned int modifiers = 0;
    KeyMapFactory keyMapFactory;
    WindowSystemDriverHelper helper;
  };
} /* namespace opensteno */
#endif //OPENSTENO_COMMAND_PARSER_HPP
