#include <opensteno/DictionaryLoader.hpp>

namespace opensteno {
  std::map <std::string, std::string> DictionaryLoader::getDictionaryFromFile(std::string filename) {
    std::map <std::string, std::string> dictionary;
    dictionary.insert( std::pair<std::string, std::string >("TO", "to"));
    dictionary.insert( std::pair<std::string, std::string >("TA", "that"));
    dictionary.insert( std::pair<std::string, std::string >("T", "the"));
    dictionary.insert( std::pair<std::string, std::string >("WUB", "one"));
    dictionary.insert( std::pair<std::string, std::string >("WU", "with you"));
    dictionary.insert( std::pair<std::string, std::string >("KWR", "<exit>"));

    return dictionary;
  }
} /* namespace opensteno */
