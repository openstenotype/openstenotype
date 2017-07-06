#ifndef OPENSTENO_WINDOW_SYSTEM_DRIVER_HELPER_HPP
#define OPENSTENO_WINDOW_SYSTEM_DRIVER_HELPER_HPP
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>
#include <opensteno/KeyMapFactory.hpp>
#include <map>
#include <memory>

namespace opensteno {
  class WindowSystemDriverHelper {
  public:
    void registerKey(KeySym key,
                     std::map<KeySym, std::shared_ptr<bool>> map,
                     bool value);
    std::string charToString(char character);
  };
} /* namespace opensteno */
#endif //OPENSTENO_WINDOW_SYSTEM_DRIVER_HELPER_HPP
