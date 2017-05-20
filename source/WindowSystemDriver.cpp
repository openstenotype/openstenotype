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
            stenoboard.t = true;
          }

          if (key == XK_p) {
            stenoboard.o = true;
          }

          if (key == XK_i) {
            stenoboard.k = true;
          }

          if (key == XK_a) {
            stenoboard.w = true;
          }

          if (key == XK_e) {
            stenoboard.r = true;
          }

          break;
        case KeyRelease:
          if (allReleased && stenoboard.k && stenoboard.w && stenoboard.r) {
            std::cout << "Exiting" << std::endl;
            shutdown = true;
            stenoboard.resetButtons();
          }

          if (allReleased && stenoboard.t && stenoboard.o) {
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
