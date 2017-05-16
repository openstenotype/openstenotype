#include <opensteno/WindowSystem.hpp>

namespace opensteno {
  WindowSystem::WindowSystem() {
    display = XOpenDisplay(0x0);
    if(!display) {
      std::cout << "No screen found!" << std::endl;
      exit(1);
    };

    grabKeyboard();
  }

  WindowSystem::~WindowSystem() {
    XCloseDisplay(display);
  }

  void WindowSystem::grabKeyboard() {
    XGrabKeyboard(display, DefaultRootWindow(display), false,
                  GrabModeAsync, GrabModeAsync, CurrentTime);
  }

  void WindowSystem::createKeyEvent() {
  }
} /* namespace opensteno */
