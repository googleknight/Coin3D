#ifndef COIN_SOTRANSFORM_H
#define COIN_SOTRANSFORM_H

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
#include <Inventor/fields/SoSFRotation.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/nodes/SoTransformation.h>
#include <Inventor/SbMatrix.h>
#include <Inventor/SbVec3f.h>

class COIN_DLL_API SoTransform : public SoTransformation {
  typedef SoTransformation inherited;

  SO_NODE_HEADER(SoTransform);

public:
  static void initClass(void);
  SoTransform(void);

  SoSFVec3f translation;
  SoSFRotation rotation;
  SoSFVec3f scaleFactor;
  SoSFRotation scaleOrientation;
  SoSFVec3f center;

  void pointAt(const SbVec3f & frompoint, const SbVec3f & topoint);
  void getScaleSpaceMatrix(SbMatrix & mat, SbMatrix & inv) const;
  void getRotationSpaceMatrix(SbMatrix & mat, SbMatrix & inv) const;
  void getTranslationSpaceMatrix(SbMatrix & mat, SbMatrix & inv) const;
  void multLeft(const SbMatrix & mat);
  void multRight(const SbMatrix & mat);
  void combineLeft(SoTransformation * nodeonright);
  void combineRight(SoTransformation * nodeonleft);
  void setMatrix(const SbMatrix & mat);
  void recenter(const SbVec3f & newcenter);

  virtual void doAction(SoAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void pick(SoPickAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);

protected:
  virtual ~SoTransform();
};

#endif // !COIN_SOTRANSFORM_H
