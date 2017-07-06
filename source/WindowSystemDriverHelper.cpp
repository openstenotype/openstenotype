#include <opensteno/WindowSystemDriverHelper.hpp>
#include <sstream>

namespace opensteno {
  std::string WindowSystemDriverHelper::charToString(char character) {
    std::stringstream stringStream;
    stringStream << character;
    std::string characterString;
    stringStream >> characterString;

    return characterString;
  }

  void WindowSystemDriverHelper::registerKey(KeySym key,
                                       std::map<KeySym, std::shared_ptr<bool> > map,
                                       bool value) {
    std::map<KeySym, std::shared_ptr<bool> >::iterator mapIterator;
    mapIterator = map.find(key);
    if(mapIterator != map.end()) {
      *mapIterator->second.get() = value;
    }
  }
} /* namespace opensteno */
