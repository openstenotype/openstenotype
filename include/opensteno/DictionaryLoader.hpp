#ifndef OPENSTENO_DICTIONARY_LOADER_HPP
#define OPENSTENO_DICTIONARY_LOADER_HPP

#include <string>
#include <map>
#include <json11/json11.hpp>

namespace opensteno {
  class DictionaryLoader {
  public:
    static std::map <std::string, std::string> getDictionaryFromFile(std::string filename);
  };
} /* namespace opensteno */
#endif //OPENSTENO_DICTIONARY_LOADER_HPP
