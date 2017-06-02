#ifndef OPENSTENO_KEY_MAP_FACTORY_HPP
#define OPENSTENO_KEY_MAP_FACTORY_HPP
#include <map>
#include <opensteno/WindowSystem.hpp>

namespace opensteno {
  class KeyMapFactory {
  public:
    KeyMapFactory();
    std::map <std::string, KeySym> getSymMap();
  };
} /* namespace opensteno */
#endif //OPENSTENO_KEY_MAP_FACTORY_HPP
