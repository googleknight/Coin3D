// src\Inventor\Win\devices\SoWinInputFocusCommon.cpp.  Generated from SoGuiInputFocus.cpp.in by configure.

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

/*!
  \class SoWinInputFocus SoWinInputFocus.h Inventor/Win/devices/SoWinInputFocus.h
  \brief The SoWinInputFocus class is an abstraction for widget focus events as an input device.
  \ingroup devices

  This device class is a "virtual device" which can be used to get
  events when the mouse pointer enters or leaves a specific widget.
*/

// *************************************************************************

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#include <Inventor/Win/devices/SoWinInputFocus.h>
#include <Inventor/Win/devices/SoGuiInputFocusP.h>

// *************************************************************************

SOWIN_OBJECT_SOURCE(SoWinInputFocus);

// *************************************************************************

/*!
  \enum SoWinInputFocus::Events

  Bit-wise enumeration over events handled by the SoWinInputFocus
  device class.  Used in the SoWinInputFocus constructor.
*/

/*!
  \var SoWinInputFocus::Events SoWinInputFocus::ENTER_WINDOW

  Maskbit for receiving events when focus comes to a widget.
*/

/*!
  \var SoWinInputFocus::Events SoWinInputFocus::LEAVE_WINDOW

  Maskbit for receiving events when focus leaves a widget.
*/

/*!
  \var SoWinInputFocus::Events SoWinInputFocus::ALL_EVENTS

  Combined bitmask for all possible events.
*/

/*!
  \fn SoWinInputFocus::SoWinInputFocus(int mask)

  Constructor. The \a mask specifies which focus-related events to
  handle. Others will just be ignored.
*/

// *************************************************************************

SoGuiInputFocusP::SoGuiInputFocusP(SoWinInputFocus * p)
{
  this->pub = p;
}

SoGuiInputFocusP::~SoGuiInputFocusP()
{
}

// *************************************************************************
