#ifndef COIN_SOGUICOLOREDITOR_H
#define COIN_SOGUICOLOREDITOR_H

// src\Inventor\Win\nodes\SoGuiColorEditor.h.  Generated from ColorEditor.h.in by configure.

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

#include <Inventor/fields/SoSFBool.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFColor.h>
#include <Inventor/nodekits/SoBaseKit.h>

class SoGuiColorEditor : public SoBaseKit {
  typedef SoBaseKit inherited;
  SO_KIT_HEADER(SoGuiColorEditor);
  SO_KIT_CATALOG_ENTRY_HEADER(root);

public:
  static void initClass(void);
  SoGuiColorEditor(void);

  enum Sliders {
    NONE,
    INTENSITY,
    RGB,
    HSV,
    RGB_V,
    RGB_HSV
  };

  enum Update {
    CONTINUOUS,
    AFTER_ACCEPT
  };

  SoSFEnum sliders;
  SoSFEnum update;
  SoSFBool wysiwyg;
  SoSFColor color;

protected:
  ~SoGuiColorEditor(void);

private:
  void * internals;

};

#endif // !COIN_SOGUICOLOREDITOR_H
