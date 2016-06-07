#ifndef SOGUICOMPONENTP_H
#define SOGUICOMPONENTP_H

// src\Inventor\Win\SoGuiComponentP.h.  Generated from SoGuiComponentP.h.in by configure.

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

#ifndef SOWIN_INTERNAL
#error this is a private header file
#endif /* !SOWIN_INTERNAL */

#include <Inventor/SbDict.h>

class SoWinComponent;

// ************************************************************************

// This class contains private data and methods used within the
// SoGuiComponent class.

class SoGuiComponentP
{
public:
  ~SoGuiComponentP();

  static SbDict * widget2compdict;

  static int nrofcomponents;

protected:
  SoGuiComponentP(SoWinComponent * publ);
  SoWinComponent * pub;
};

// ************************************************************************

#endif // !SOGUICOMPONENTP_H
