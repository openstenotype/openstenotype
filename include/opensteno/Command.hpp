#ifndef OPENSTENO_COMMAND_HPP
#define OPENSTENO_COMMAND_HPP

namespace opensteno {
  class Command {
  public:
    static const bool isCommandStackCommand;
    Command();
    void execute();
    void undo();
  };
} /* namespace opensteno */
#endif //OPENSTENO_COMMAND_HPP
