#ifndef OPENSTENO_GLUE_COMMAND_HPP
#define OPENSTENO_GLUE_COMMAND_HPP
#include <string>
#include <opensteno/Command.hpp>

namespace opensteno {
  class GlueCommand: public Command  {
  public:
    GlueCommand(std::string characters, Command lastCommand);
    GlueCommand(std::string characters, GlueCommand lastCommand);
    void execute(Command lastCommand);
    void execute(GlueCommand lastCommand);
  };
} /* namespace opensteno */
#endif //OPENSTENO_GLUE_COMMAND_HPP
