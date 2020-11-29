#include <opensteno/GlueCommand.hpp>
#include <opensteno/Word.hpp>

namespace opensteno {
  GlueCommand::GlueCommand(std::string characters) {

  }

  void execute(Command lastCommand, Word currentWord) {
    //    renderWhiteSpace();
    //    render();
  }
  void execute(GlueCommand lastCommand, Word currentWord) {
    //    render();
  }
  void undo(Command lastCommand, Word currentWord) {
    //    hitBackspaceTwice();
  }

  void undo(Command lastCommand, Word currentWord) {
    //    hitBackspaceOnce();
  }

} /* namespace opensteno */
