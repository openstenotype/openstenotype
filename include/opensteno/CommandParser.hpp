#ifndef OPENSTENO_COMMAND_PARSER_HPP
#define OPENSTENO_COMMAND_PARSER_HPP
#include <string>
#include <map>
#include <opensteno/CommandInterpreter.hpp>
#include <opensteno/KeyMapFactory.hpp>
#include <opensteno/WindowSystemDriverHelper.hpp>

namespace opensteno {
  class CommandParser {
  public:
    CommandParser(logger::LoggerFactory& logger, CommandInterpreter& commandInterpreter);
    void processCommandString(std::string commandString);
  private:
    logger::LoggerFactory& logger;
    CommandInterpreter& commandInterpreter;
    void processCommandChar(char commandChar);
    std::map <std::string, KeySym> keySymMap;
    bool modifierParsing = false;
    std::string modifierString = "";
    unsigned int modifiers = 0;
    KeyMapFactory keyMapFactory;
    WindowSystemDriverHelper helper;
  };
} /* namespace opensteno */
#endif //OPENSTENO_COMMAND_PARSER_HPP
