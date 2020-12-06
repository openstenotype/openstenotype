#include <opensteno/CommandParser.hpp>

namespace opensteno {
  CommandParser::CommandParser(logger::LoggerFactory& logger):
    logger(logger) {
    keySymMap = keyMapFactory.getSymMap();
    modifierMap = keyMapFactory.getModifierMap();
  }

  void CommandParser::processString(std::string commandString, CommandInterpreter& commandInterpreter) {
    if(!commandInterpreter.executeCommand(commandString)){
      for(char character : commandString) {
        processCharacter(character, commandInterpreter);
      }
    }
  }

  void CommandParser::processCharacter(char character, CommandInterpreter& commandInterpreter){
    std::unordered_map<std::string, KeySym>::iterator keySymMapIterator;
    std::unordered_map<std::string, unsigned int>::iterator modifierMapIterator;
    if (character == '{') {
      modifierParsing = true;
      running = true;
    }
    if (character == '}') {
      modifierMapIterator = modifierMap.find(modifierString);
      if(modifierMap.find(modifierString) != modifierMap.end()) {
        modifiers = modifierMapIterator->second;
      }
      modifierParsing = false;
      running = false;
      terminated = true;
      modifierString = "";
    }
    if (modifierParsing) {
      if (character != '{' && character != '}') {
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
