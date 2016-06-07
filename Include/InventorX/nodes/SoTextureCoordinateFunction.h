#ifndef COIN_SOTEXTURECOORDINATEFUNCTION_H
#define COIN_SOTEXTURECOORDINATEFUNCTION_H

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

class COIN_DLL_API SoTextureCoordinateFunction : public SoNode {
  typedef SoNode inherited;

  SO_NODE_ABSTRACT_HEADER(SoTextureCoordinateFunction);

public:
  static void initClass(void);

  // The constructor for this class is public in Inventor. Should
  // _probably_ have been protected, but we mimic Inventor for the
  // sake of compatibility.
  SoTextureCoordinateFunction(void);

protected:
  virtual ~SoTextureCoordinateFunction();
};

#endif // !COIN_SOTEXTURECOORDINATEFUNCTION_H
