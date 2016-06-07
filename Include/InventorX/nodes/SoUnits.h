#ifndef COIN_SOUNITS_H
#define COIN_SOUNITS_H

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

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoTransformation.h>
#include <Inventor/fields/SoSFEnum.h>

class COIN_DLL_API SoUnits : public SoTransformation {
  typedef SoTransformation inherited;

  SO_NODE_HEADER(SoUnits);

public:
  static void initClass(void);
  SoUnits(void);

  // These have to match the order of the enum in SoUnitsElement
  // 100% or weird and hard to debug artifacts will show up.
  enum Units {
    METERS,
    CENTIMETERS,
    MILLIMETERS,
    MICROMETERS,
    MICRONS,
    NANOMETERS,
    ANGSTROMS,
    KILOMETERS,
    FEET,
    INCHES,
    POINTS,
    YARDS,
    MILES,
    NAUTICAL_MILES
  };

  SoSFEnum units;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void pick(SoPickAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);

protected:
  virtual ~SoUnits();
};

#endif // !COIN_SOUNITS_H
