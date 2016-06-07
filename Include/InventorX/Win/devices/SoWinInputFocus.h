#ifndef SOWIN_INPUTFOCUS_H
#define SOWIN_INPUTFOCUS_H

// src\Inventor\Win\devices\SoWinInputFocus.h.  Generated from SoGuiInputFocus.h.in by configure.

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

// *************************************************************************

class SOWIN_DLL_API SoWinInputFocus : public SoWinDevice {
  SOWIN_OBJECT_HEADER(SoWinInputFocus, SoWinDevice);

public:
  enum Events {
    ENTER_WINDOW = 1 << 0,
    LEAVE_WINDOW = 1 << 1,
    ALL_EVENTS   = ENTER_WINDOW | LEAVE_WINDOW
  };

  SoWinInputFocus(int mask = ALL_EVENTS);
  virtual ~SoWinInputFocus();

  virtual void enable(HWND widget, SoWinEventHandler * handler, void * closure);
  virtual void disable(HWND widget, SoWinEventHandler * handler, void * closure);

  virtual const SoEvent * translateEvent(MSG * event);

private:
  class SoWinInputFocusP * pimpl;
  friend class SoGuiInputFocusP;
  friend class SoWinInputFocusP;
};

#define SO_WIN_ALL_FOCUS_EVENTS SoWinInputFocus::ALL_EVENTS;

// *************************************************************************

#endif // ! SOWIN_INPUTFOCUS_H
