#ifndef COIN_SOINDEXEDNURBSSURFACE_H
#define COIN_SOINDEXEDNURBSSURFACE_H

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
#include <Inventor/nodes/SoShape.h>
#include <Inventor/fields/SoSFInt32.h>
#include <Inventor/fields/SoMFInt32.h>
#include <Inventor/fields/SoMFFloat.h>

template<class Master> class SoNurbsP;

class COIN_DLL_API SoIndexedNurbsSurface : public SoShape {
    typedef SoShape inherited;

  SO_NODE_HEADER(SoIndexedNurbsSurface);

public:
  static void initClass(void);
  SoIndexedNurbsSurface(void);

  SoSFInt32 numUControlPoints;
  SoSFInt32 numVControlPoints;
  SoMFInt32 coordIndex;
  SoMFFloat uKnotVector;
  SoMFFloat vKnotVector;
  SoSFInt32 numSControlPoints;
  SoSFInt32 numTControlPoints;
  SoMFInt32 textureCoordIndex;
  SoMFFloat sKnotVector;
  SoMFFloat tKnotVector;

  virtual void GLRender(SoGLRenderAction * action);
  virtual void rayPick(SoRayPickAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
  void sendPrimitive(SoAction *,  SoPrimitiveVertex *);

protected:
  virtual ~SoIndexedNurbsSurface();

  virtual void generatePrimitives(SoAction * action);
  virtual void computeBBox(SoAction * action, SbBox3f & box, SbVec3f & center);
  SoDetail * createTriangleDetail(SoRayPickAction * action,
                                  const SoPrimitiveVertex * v1,
                                  const SoPrimitiveVertex * v2,
                                  const SoPrimitiveVertex * v3,
                                  SoPickedPoint * pp);
private:
  class SoIndexedNurbsSurfaceP * pimpl;
  friend class SoIndexedNurbsSurfaceP;
  friend class SoNurbsP<SoIndexedNurbsSurface>;
};

#endif // !COIN_SOINDEXEDNURBSSURFACE_H
