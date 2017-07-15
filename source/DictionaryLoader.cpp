#include <opensteno/DictionaryLoader.hpp>
#include <opensteno/JsonLoader.hpp>
#include <cstring>
#include <iostream>

namespace opensteno {
  std::map <std::string, std::string> DictionaryLoader::getDictionaryFromFile(std::string filename) {
    std::map <std::string, std::string> dictionary;

    json11::Json json = JsonLoader::getJsonFromFile(filename);
    dictionary = getDictionaryFromJson(json);

    return dictionary;
  }

  std::map <std::string, std::string> DictionaryLoader::getDictionaryFromJson(json11::Json json){
    std::map<std::string, json11::Json>::iterator iterator;
    std::map <std::string, std::string> dictionary;
    json11::Json::object jsonObject = json.object_items();

    for (iterator  = jsonObject.begin();
         iterator != jsonObject.end();
         ++iterator){
      dictionary.insert( std::pair<std::string, std::string >(iterator->first,
                                                              iterator->second.string_value()));
    }

    return dictionary;
  }
} /* namespace opensteno */
