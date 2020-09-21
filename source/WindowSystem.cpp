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

  XEvent WindowSystem::getNextEvent() {
    XEvent event;
    XNextEvent(display, &event);

    return event;
  }

  KeySym WindowSystem::getKeySymFromEvent(XEvent event) {
    KeySym key;
    key = XkbKeycodeToKeysym(display, event.xkey.keycode,
                              0, event.xkey.state & ShiftMask ? 1 : 0);
    return key;
  }

  void WindowSystem::simulateKeypressRelease(int key) {
    simulateKeypressRelease(key, 0);
  }

  void WindowSystem::simulateKeypressRelease(int key, unsigned int modifiers) {
    simulateKeypress(key, modifiers);
    simulateKeyrelease(key, modifiers);
    // For key codes check http://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
  }

  void WindowSystem::simulateKeypress(int key, unsigned int modifiers) {
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);
    XKeyEvent event = createKeyEvent(winFocus, true,  key, modifiers);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
    std::this_thread::sleep_for(std::chrono::milliseconds(4));
  }

  void WindowSystem::simulateKeyrelease(int key, unsigned int modifiers) {
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);
    XKeyEvent event = createKeyEvent(winFocus, false, key, modifiers);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
  }

  XKeyEvent WindowSystem::createKeyEvent(Window &win, bool press, int keycode, unsigned int modifiers) {
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
