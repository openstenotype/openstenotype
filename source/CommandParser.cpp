#include <opensteno/CommandParser.hpp>

namespace opensteno {
  CommandParser::CommandParser(logger::LoggerFactory& logger,
                               CommandInterpreter& commandInterpreter):
    logger(logger), commandInterpreter(commandInterpreter) {
    keySymMap = keyMapFactory.getSymMap();
  }
  void CommandParser::processCommandString(std::string commandString) {
    if(!commandInterpreter.executeCommand(commandString)){
      for(char character : commandString) {
        processCommandChar(character);
      }
    }
  }

  void CommandParser::processCommandChar(char character){
    std::unordered_map<std::string, KeySym>::iterator keySymMapIterator;
    if (character == '<') {
      modifierParsing = true;
    }
    if (character == '>') {
      if (modifierString == "mod") {
        modifiers = Mod4Mask;
      }
      if (modifierString == "ctrl") {
        modifiers = ControlMask;
      }
      if (modifierString == "shift") {
        modifiers = ShiftMask;
      }
      modifierParsing = false;
      modifierString = "";
    }
    if (modifierParsing) {
      if (character != '<' && character != '>') {
        modifierString.append(helper.charToString(character));
      }
    } else {
      std::string characterString = helper.charToString(character);
      keySymMapIterator = keySymMap.find(characterString);
      if(keySymMap.find(characterString) != keySymMap.end()) {
        std::vector<std::string> parameters = {};
        commandInterpreter.simulateKeypressRelease(keySymMapIterator->second, modifiers);
        modifiers = 0;
        modifierString = "";
      }
    }
  }
} /* namespace opensteno */
