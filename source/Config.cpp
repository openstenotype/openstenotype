#include <opensteno/Config.hpp>
#include <opensteno/JsonLoader.hpp>

namespace opensteno {
  Config::Config(std::string filename) {
    loadConfigFromFile(filename);
  }

  std::string Config::getString(std::string key, std::string fallback){

    return json[0][key].string_value();
  }
  int Config::getInt(std::string key, int fallback){
    return json[0][key].int_value();
  }
  int Config::getBool(std::string key, bool fallback){
    return json[0][key].bool_value();
  }
  void Config::loadConfigFromFile(std::string filename){
    json = JsonLoader::getJsonFromFile(filename);
  }
} /* namespace opensteno */
