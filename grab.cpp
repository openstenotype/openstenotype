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

using namespace std;

struct StenoBoard {
public:
  //14 buttons per side
  bool s = false;
  bool t = false;
  bool p = false;
  bool h = false;
  bool k = false;
  bool w = false;
  bool r = false;
  bool a = false;
  bool o = false;
};


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


int main(void)
{
  Display * display = XOpenDisplay(0x0);
  XEvent event;
  KeyCode modcode = 0;
  StenoBoard stenoboard;

  if(!display) return 1;

  Time t = CurrentTime;
  XGrabKeyboard(display, DefaultRootWindow(display), false, 
                GrabModeAsync, GrabModeAsync,t);
  int presses = 0;

  Window winFocus;
  int    revert;
  KeySym key;

  while(presses < 10)
    {

      // Window winRoot = XDefaultRootWindow(display);
      // XGetInputFocus(display, &winFocus, &revert);

      // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      // // Send a fake key press event to the window.
      // XKeyEvent event = createKeyEvent(display, winFocus, winRoot, true,  XK_M, 0);
      // XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);

      // // Send a fake key release event to the window.
      // event = createKeyEvent(display, winFocus, winRoot, false, XK_M, 0);
      // XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);
      // For key codes check http://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
      XNextEvent(display, &event);
      switch(event.type)
        {
        case KeyPress:
          cout << "Key pressed" << endl;
          presses++;
          key = XkbKeycodeToKeysym( display, event.xkey.keycode, 
                                    0, event.xkey.state & ShiftMask ? 1 : 0);
          if ((key == XK_x)) {
            stenoboard.t = true;
          }

          if ((key == XK_p)) {
            stenoboard.o = true;
          }

          if ((key == XK_i)) {
            stenoboard.k = true;
          }

          if ((key == XK_a)) {
            stenoboard.w = true;
          }

          if ((key == XK_e)) {
            stenoboard.r = true;
          }

          break;
        case KeyRelease:
          //          KeySym key_symbol = XKeycodeToKeysym(display, event.xkey.keycode, 0);
          //          KeySym key_symbol = XKeycodeToKeysym(display, event.xkey.keycode, 0);
          //          XSendEvent(display,InputFocus,True,KeyReleaseMask,&ev);
          key = XkbKeycodeToKeysym( display, event.xkey.keycode, 
                                0, event.xkey.state & ShiftMask ? 1 : 0);
          cout << "Key code" << endl;
          if (stenoboard.k && stenoboard.w && stenoboard.r) {
            cout << "Exiting" << endl;
            exit(1);
          }

          if (stenoboard.t && stenoboard.o) {
            cout << "Exiting" << endl;
            exit(1);
          }

          break;
        default:

          break;
        }
    }
}
