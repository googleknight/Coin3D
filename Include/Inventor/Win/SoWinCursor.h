#ifndef SOWIN_CURSOR_H
#define SOWIN_CURSOR_H

// src\Inventor\Win\SoWinCursor.h.  Generated from SoGuiCursor.h.in by configure.

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

#include <Inventor/SbLinear.h>
#include <Inventor/Win/SoWinBasic.h>

class SOWIN_DLL_API SoWinCursor {
public:
  static void initClass(void);

  struct CustomCursor {
    SbVec2s dim;
    SbVec2s hotspot;
    unsigned char * bitmap;
    unsigned char * mask;
  };


  // FIXME: add more default shapes. 20011119 pederb.
  enum Shape {
    CUSTOM_BITMAP = -1,
    DEFAULT = 0,
    BUSY,
    CROSSHAIR,
    UPARROW
  };
  
  SoWinCursor(void);
  SoWinCursor(const Shape shape);
  SoWinCursor(const CustomCursor * cc);
  SoWinCursor(const SoWinCursor & cursor);
  ~SoWinCursor();

  SoWinCursor & operator=(const SoWinCursor & c);

  Shape getShape(void) const;
  void setShape(const Shape shape);

  const CustomCursor & getCustomCursor(void) const;

  static const SoWinCursor & getZoomCursor(void);
  static const SoWinCursor & getPanCursor(void);
  static const SoWinCursor & getRotateCursor(void);
  static const SoWinCursor & getBlankCursor(void);
  
private:
  void commonConstructor(const Shape shape, const CustomCursor * cc);

  Shape shape;
  CustomCursor * cc;
};

#endif // ! SOWIN_CURSOR_H
