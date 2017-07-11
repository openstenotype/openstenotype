#include <opensteno/DictionaryLoader.hpp>
#include <cstring>
#include <iostream>

namespace opensteno {
  std::map <std::string, std::string> DictionaryLoader::getDictionaryFromFile(std::string filename) {
    std::map <std::string, std::string> dictionary;
    std::string fileContent, error;
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    std::map<std::string, std::string>::iterator dictionaryIterator;

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
    json11::Json configJson = json11::Json::parse(fileContent, error);

    std::map<std::string, json11::Json>::iterator iterator;

    json11::Json::object jsonObject = configJson.object_items();

    for (iterator = jsonObject.begin(); iterator != jsonObject.end(); ++iterator) {
      dictionary.insert( std::pair<std::string, std::string >(iterator->first, iterator->second.string_value()));
    }
    dictionary.insert( std::pair<std::string, std::string >("KWR", "<exit>"));

    return dictionary;
  }
} /* namespace opensteno */
