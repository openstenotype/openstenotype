#include <opensteno/JsonLoader.hpp>
#include <cstring>
#include <iostream>

namespace opensteno {
  json11::Json JsonLoader::getJsonFromFile(std::string filename){

    return getJsonFromJsonString(getJsonStringFromFile(filename));
  }

  json11::Json JsonLoader::getJsonFromJsonString(std::string jsonString){
    std::string error;
    return json11::Json::parse(jsonString, error);
  }

  std::string JsonLoader::getJsonStringFromFile(std::string filename){
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
