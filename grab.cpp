#include <stdio.h>
#include <cstring>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;


#define KEYCODE XK_M

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
  XEvent ev;
  KeyCode modcode = 0;

  if(!display) return 1;

  Time t = CurrentTime;
  XGrabKeyboard(display, DefaultRootWindow(display), false, 
                GrabModeAsync, GrabModeAsync,t);
  int presses = 0;

  Window winFocus;
  int    revert;


  while(presses < 10)
    {
      Window winRoot = XDefaultRootWindow(display);
      XGetInputFocus(display, &winFocus, &revert);
      //XGrabKeyboard(dpy, DefaultRootWindow(dpy), false, 
      //                   GrabModeAsync, GrabModeAsync,t);
      // XNextEvent(display, &ev);
      // modcode = XKeysymToKeycode(display, XStringToKeysym("a"));
      // XTestFakeKeyEvent(display, modcode, False, 0);
      // XFlush(display);
      // XTestFakeKeyEvent(display, modcode, True, 0);
      // XFlush(display);
      // XTestFakeKeyEvent(display, modcode, False, 0);
      // XFlush(display);
std::this_thread::sleep_for(std::chrono::milliseconds(2000));
// Send a fake key press event to the window.
   XKeyEvent event = createKeyEvent(display, winFocus, winRoot, true, KEYCODE, 0);
   XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);

// Send a fake key release event to the window.
   event = createKeyEvent(display, winFocus, winRoot, false, KEYCODE, 0);
   XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);


      switch(ev.type)
        {
        case KeyPress:
          cout << "Key pressed" << endl;
          presses++;
          //          XSendEvent(display,InputFocus,False,KeyPressMask,&ev);
          //modcode = XKeysymToKeycode(display, XStringToKeysym("a"));
          //XTestFakeKeyEvent(display, modcode, False, 0);
          // XFlush(display);
          // XTestFakeKeyEvent(display, modcode, True, 0);
          // XFlush(display);
          // XTestFakeKeyEvent(display, modcode, False, 0);
          // XFlush(display);
          break;
        case KeyRelease:
          XSendEvent(display,InputFocus,True,KeyReleaseMask,&ev);
          break;
        case ButtonPress:
          XSendEvent(display,PointerWindow,True,ButtonPressMask,&ev);
          break;
        case ButtonRelease:
          XSendEvent(display,PointerWindow,True,ButtonPressMask,&ev);
          break;
        default:

          break;
        }

      // XGrabKeyboard(dpy, DefaultRootWindow(dpy), false,                 
      //                      GrabModeAsync, GrabModeAsync,t);

    }
}
