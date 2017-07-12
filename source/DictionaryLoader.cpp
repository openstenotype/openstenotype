#include <opensteno/DictionaryLoader.hpp>
#include <cstring>
#include <iostream>

namespace opensteno {
  std::map <std::string, std::string> DictionaryLoader::getDictionaryFromFile(std::string filename) {
    std::map <std::string, std::string> dictionary;

    std::string fileContent = getJsonStringFromFile(filename);
    json11::Json configJson = getJsonFromJsonString(fileContent);
    dictionary = getDictionaryFromJson(configJson);

    dictionary.insert( std::pair<std::string, std::string >("KWR", "<exit>"));

    return dictionary;
  }

  json11::Json DictionaryLoader::getJsonFromJsonString(std::string jsonString){
    std::string error;
    return json11::Json::parse(jsonString, error);
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

  std::string DictionaryLoader::getJsonStringFromFile(std::string filename){
    std::string fileContent, error;
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in) {
      in.seekg(0, std::ios::end);
      fileContent.resize(in.tellg());
      in.seekg(0, std::ios::beg);
      in.read(&fileContent[0], fileContent.size());
      in.close();
    } else {
      throw std::runtime_error(std::string("Can't open ") +
                               filename + ": " +
                               std::strerror(errno));
    }

    return fileContent;
  }
} /* namespace opensteno */
