#ifndef OPENSTENO_DICTIONARY_LOADER_HPP
#define OPENSTENO_DICTIONARY_LOADER_HPP

#include <string>
#include <map>
#include <json11/json11.hpp>
#include <fstream>

namespace opensteno {
  class DictionaryLoader {
  public:
    static std::map <std::string, std::string> getDictionaryFromFile(std::string filename);
  private:
    static std::string getJsonStringFromFile(std::string filename);
    static json11::Json getJsonFromJsonString(std::string jsonString);
    static std::map <std::string, std::string> getDictionaryFromJson(json11::Json json);
  };
} /* namespace opensteno */
#endif //OPENSTENO_DICTIONARY_LOADER_HPP
