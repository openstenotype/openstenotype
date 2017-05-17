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

  void WindowSystem::simulateKeypress(int key) {
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);

    // Send a key press event to the window.
    XKeyEvent event = createKeyEvent(winFocus, true,  key, 0);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    // Send a key release event to the window.
    event = createKeyEvent(winFocus, false, key, 0);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
    // For key codes check http://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
  }

  XKeyEvent WindowSystem::createKeyEvent(Window &win, bool press, int keycode, int modifiers) {
    XKeyEvent event;

    event.display     = display;
    event.window      = win;
    event.root        = XDefaultRootWindow(display);
    event.subwindow   = None;
    event.time        = CurrentTime;
    event.x           = 1;
    event.y           = 1;
    event.x_root      = 1;
    event.y_root      = 1;
    event.same_screen = True;
    event.keycode     = XKeysymToKeycode(display, keycode);
    event.state       = modifiers;

    if(press)
      event.type = KeyPress;
    else
      event.type = KeyRelease;

    return event;
  }
} /* namespace opensteno */
