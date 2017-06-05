#ifndef OPENSTENO_KEY_MAP_FACTORY_HPP
#define OPENSTENO_KEY_MAP_FACTORY_HPP
#include <map>
#include <memory>
#include <opensteno/WindowSystem.hpp>
#include <opensteno/Stenoboard.hpp>

namespace opensteno {
  class KeyMapFactory {
  public:
    KeyMapFactory();
    std::map <KeySym, std::shared_ptr<bool> > getNeoKeyMap(Stenoboard stenoboard);
    std::map <KeySym, std::shared_ptr<bool> > getQwertzKeyMap(Stenoboard stenoboard);
    std::map <std::string, KeySym> getSymMap();
  };
} /* namespace opensteno */
#endif //OPENSTENO_KEY_MAP_FACTORY_HPP
