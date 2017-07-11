#ifndef OPENSTENO_DICTIONARY_LOADER_HPP
#define OPENSTENO_DICTIONARY_LOADER_HPP

#include <tinyxml2.h>
#include <string>

namespace opensteno {
  class DictionaryLoader {
  public:
    void getDictionaryFromFile(std::string filename);
  };
} /* namespace opensteno */
#endif //OPENSTENO_DICTIONARY_LOADER_HPP
