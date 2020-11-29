#ifndef OPENSTENO_TEXT_COMMAND_HPP
#define OPENSTENO_TEXT_COMMAND_HPP
#include <opensteno/Command.hpp>

namespace opensteno {
  class TextCommand {
  public:
    TextCommand(std::string characters, Command lastCommand);
  };
} /* namespace opensteno */
#endif //OPENSTENO_TEXT_COMMAND_HPP
