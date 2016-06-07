#ifndef SOWIN_MOUSE_H
#define SOWIN_MOUSE_H

// src\Inventor\Win\devices\SoWinMouse.h.  Generated from SoGuiMouse.h.in by configure.

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) by Kongsberg Oil & Gas Technologies.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Kongsberg Oil & Gas Technologies
 *  about acquiring a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg Oil & Gas Technologies, Bygdoy Alle 5, 0257 Oslo, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#include <Inventor/Win/devices/SoWinDevice.h>

class SoMouseButtonEvent;
class SoLocation2Event;

// *************************************************************************

class SOWIN_DLL_API SoWinMouse : public SoWinDevice {
  SOWIN_OBJECT_HEADER(SoWinMouse, SoWinDevice);

public:
  enum Events {
    BUTTON_PRESS    = 0x01,
    BUTTON_RELEASE  = 0x02,
    POINTER_MOTION  = 0x04,
    BUTTON_MOTION   = 0x08,

    ALL_EVENTS = BUTTON_PRESS | BUTTON_RELEASE | POINTER_MOTION | BUTTON_MOTION
  };

  SoWinMouse(int eventmask = ALL_EVENTS);
  virtual ~SoWinMouse(void);

  virtual void enable(HWND widget, SoWinEventHandler * handler, void * closure);
  virtual void disable(HWND widget, SoWinEventHandler * handler, void * closure);

  virtual const SoEvent * translateEvent(MSG * event);

private:
  class SoWinMouseP * pimpl;
  friend class SoWinMouseP;
  friend class SoGuiMouseP;
};

// *************************************************************************

#endif // ! SOWIN_MOUSE_H
