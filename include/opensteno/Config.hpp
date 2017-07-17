#ifndef OPENSTENO_CONFIG_HPP
#define OPENSTENO_CONFIG_HPP

#include <string>
#include <map>
#include <json11/json11.hpp>
#include <fstream>

namespace opensteno {
  class Config {
  public:
    Config(std::string filename);
    std::string getString(std::string key, std::string fallback);
    int getInt(std::string key, int fallback);
    int getBool(std::string key, bool fallback);
  private:
    json11::Json json;
    void loadConfigFromFile(std::string filename);
  };
} /* namespace opensteno */
#endif //OPENSTENO_CONFIG_LOADER_HPP
