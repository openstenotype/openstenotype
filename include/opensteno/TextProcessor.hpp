#ifndef OPENSTENO_TEXT_PROCESSOR_HPP
#define OPENSTENO_TEXT_PROCESSOR_HPP
#include <string>
#include <vector>
#include <opensteno/Command.hpp>
#include <opensteno/Word.hpp>

namespace opensteno {
  enum CommandType { text, glue, upper, lower };
  //  enum CaseModifier { none, upper, lower };
  class TextProcessor {
  private:
    //    CaseModifier caseModifier;
    std::string delimiter;
    std::vector<Word> wordBuffer;
    std::vector<Command> commandBuffer;
  public:
    TextProcessor();
  };
} /* namespace opensteno */
#endif //OPENSTENO_TEXT_PROCESSOR_HPP
