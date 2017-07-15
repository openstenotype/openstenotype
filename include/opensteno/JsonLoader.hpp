#ifndef OPENSTENO_JSON_LOADER_HPP
#define OPENSTENO_JSON_LOADER_HPP

#include <string>
#include <map>
#include <json11/json11.hpp>
#include <fstream>

namespace opensteno {
  class JsonLoader {
  public:
    static json11::Json getJsonFromFile(std::string filename);
  private:
    static std::string getJsonStringFromFile(std::string filename);
    static json11::Json getJsonFromJsonString(std::string jsonString);
  };
} /* namespace opensteno */
#endif //OPENSTENO_JSON_LOADER_HPP
