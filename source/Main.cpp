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
#include <opensteno/Stenoboard.hpp>
#include <opensteno/WindowSystem.hpp>

using namespace opensteno;

// Function to create a keyboard event
XKeyEvent createKeyEvent(Display *display, Window &win,
                           Window &winRoot, bool press,
                           int keycode, int modifiers)
{
   XKeyEvent event;

   event.display     = display;
   event.window      = win;
   event.root        = winRoot;
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

void simulateKeypress(Display* display, int key) {
  Window winRoot = XDefaultRootWindow(display);
  Window winFocus;
  int revert;
  XGetInputFocus(display, &winFocus, &revert);

  // Send a key press event to the window.
  XKeyEvent event = createKeyEvent(display, winFocus, winRoot, true,  key, 0);
  XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
  std::this_thread::sleep_for(std::chrono::milliseconds(2));
  // Send a key release event to the window.
  event = createKeyEvent(display, winFocus, winRoot, false, key, 0);
  XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
  // For key codes check http://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

}

int main(void)
{
  Display* display = XOpenDisplay(0x0);
  XEvent event;
  Stenoboard stenoboard;
  stenoboard.resetButtons();

  if(!display) return 1;

  XGrabKeyboard(display, DefaultRootWindow(display), false, 
                GrabModeAsync, GrabModeAsync, CurrentTime);
  KeySym key;
  bool allReleased = true;
  bool running = true;
  while(running) {
      XNextEvent(display, &event);
      switch(event.type)
        {
        case KeyPress:
          key = XkbKeycodeToKeysym( display, event.xkey.keycode, 
                                    0, event.xkey.state & ShiftMask ? 1 : 0);
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
            running = false;
            stenoboard.resetButtons();
          }

          if (allReleased && stenoboard.t && stenoboard.o) {
            simulateKeypress(display, XK_t);
            simulateKeypress(display, XK_o);
            stenoboard.resetButtons();
          }
          break;
        default:
          break;
        }
    }
  XFree(display);
}
