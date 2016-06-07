#ifndef COIN_SOGUILABEL_H
#define COIN_SOGUILABEL_H

// src\Inventor\Win\nodes\SoGuiLabel.h.  Generated from Label.h.in by configure.

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
#endif // !SOWIN_INTERNAL

#include <Inventor/fields/SoSFShort.h>
#include <Inventor/fields/SoMFString.h>
#include <Inventor/nodekits/SoBaseKit.h>

class SoGuiLabel : public SoBaseKit {
  typedef SoBaseKit inherited;
  SO_KIT_HEADER(SoGuiLabel);
  SO_KIT_CATALOG_ENTRY_HEADER(scene);

public:
  static void initClass(void);
  SoGuiLabel(void);

  SoMFString text;
  SoSFShort which;

protected:
  ~SoGuiLabel(void);

private:
  void * internals;

};

#endif // !COIN_SOGUILABEL_H
