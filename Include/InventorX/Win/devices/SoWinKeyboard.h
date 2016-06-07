#ifndef SOWIN_KEYBOARD_H
#define SOWIN_KEYBOARD_H

// src\Inventor\Win\devices\SoWinKeyboard.h.  Generated from SoGuiKeyboard.h.in by configure.

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

class SoKeyboardEvent;

// *************************************************************************

#define SO_WIN_ALL_KEYBOARD_EVENTS SoWinKeyboard::ALL

class SOWIN_DLL_API SoWinKeyboard : public SoWinDevice {
  SOWIN_OBJECT_HEADER(SoWinKeyboard, SoWinDevice);

public:
  enum Events {
    KEY_PRESS = 0x01,
    KEY_RELEASE = 0x02,
    ALL_EVENTS = KEY_PRESS | KEY_RELEASE
  };

  SoWinKeyboard(int eventmask = ALL_EVENTS);
  virtual ~SoWinKeyboard(void);

  virtual void enable(HWND widget, SoWinEventHandler * handler, void * closure);
  virtual void disable(HWND widget, SoWinEventHandler * handler, void * closure);

  virtual const SoEvent * translateEvent(MSG * event);

private:
  class SoWinKeyboardP * pimpl;
  friend class SoWinKeyboardP;
  friend class SoGuiKeyboardP;
};

// *************************************************************************

#endif // ! SOWIN_KEYBOARD_H
