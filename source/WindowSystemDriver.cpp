#include <opensteno/WindowSystemDriver.hpp>

namespace opensteno {
  WindowSystemDriver::WindowSystemDriver(WindowSystem& windowSystem):windowSystem(windowSystem), shutdown(false) {
    stenoboard.resetButtons();
  }

  bool WindowSystemDriver::receivedShutdownCommand() {
    return shutdown;
  }

  void WindowSystemDriver::update() {
    XEvent event = windowSystem.getNextEvent();
    KeySym key;
    bool allReleased = true;

      switch(event.type)
        {
        case KeyPress:
          key = windowSystem.getKeySymFromEvent(event);

          if (key == XK_x) {
            stenoboard.left.t = true;
          }

          if (key == XK_p) {
            stenoboard.left.o = true;
          }

          if (key == XK_i) {
            stenoboard.left.k = true;
          }

          if (key == XK_a) {
            stenoboard.left.w = true;
          }

          if (key == XK_e) {
            stenoboard.left.r = true;
          }

          break;
        case KeyRelease:
          if (allReleased && stenoboard.left.k && stenoboard.left.w && stenoboard.left.r) {
            std::cout << "Exiting" << std::endl;
            shutdown = true;
            stenoboard.resetButtons();
          }

          if (allReleased && stenoboard.left.t && stenoboard.left.o) {
            windowSystem.simulateKeypress(XK_t);
            windowSystem.simulateKeypress(XK_o);
            stenoboard.resetButtons();
          }
          break;
        default:
          break;
        }
    }
} /* namespace opensteno */
