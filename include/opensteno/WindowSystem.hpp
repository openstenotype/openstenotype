#ifndef OPENSTENO_WINDOW_SYSTEM_HPP
#define OPENSTENO_WINDOW_SYSTEM_HPP
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <X11/XKBlib.h>
#include <stdlib.h>
#include <chrono>
#include <thread>


namespace opensteno {
class WindowSystem {
public:
  WindowSystem();
  ~WindowSystem();
  void simulateKeypress(int key);
private:
  Display* display;
  void grabKeyboard();
  XKeyEvent createKeyEvent(Window &win, bool press, int keycode, int modifiers);
};
} /* namespace opensteno */
#endif //OPENSTENO_WINDOW_SYSTEM_HPP
