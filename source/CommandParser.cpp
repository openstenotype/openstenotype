#include <opensteno/CommandParser.hpp>

namespace opensteno {
  CommandParser::CommandParser(logger::LoggerFactory& logger,
                               CommandInterpreter& commandInterpreter):
    logger(logger), commandInterpreter(commandInterpreter) {
    keySymMap = keyMapFactory.getSymMap();
    modifierMap = keyMapFactory.getModifierMap();
  }

  void CommandParser::processString(std::string commandString) {
    if(!commandInterpreter.executeCommand(commandString)){
      for(char character : commandString) {
        processCharacter(character);
      }
    }
  }

  void CommandParser::processCharacter(char character){
    std::unordered_map<std::string, KeySym>::iterator keySymMapIterator;
    std::unordered_map<std::string, unsigned int>::iterator modifierMapIterator;
    if (character == '{') {
      modifierParsing = true;
    }
    if (character == '}') {
      modifierMapIterator = modifierMap.find(modifierString);
      if(modifierMap.find(modifierString) != modifierMap.end()) {
        modifiers = modifierMapIterator->second;
      }
      modifierParsing = false;
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
