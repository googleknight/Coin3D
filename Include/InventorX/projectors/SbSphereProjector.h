#ifndef COIN_SBSPHEREPROJECTOR_H
#define COIN_SBSPHEREPROJECTOR_H

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

#include <Inventor/projectors/SbProjector.h>
#include <Inventor/SbSphere.h>
#include <Inventor/SbRotation.h>

class COIN_DLL_API SbSphereProjector : public SbProjector {
  typedef SbProjector inherited;

public:
  SbVec3f projectAndGetRotation(const SbVec2f & point, SbRotation & rot);
  virtual SbRotation getRotation(const SbVec3f & point1,
                                 const SbVec3f & point2) = 0;

  void setSphere(const SbSphere & sph);
  const SbSphere & getSphere(void) const;
  void setOrientToEye(const SbBool orienttoeye);
  SbBool isOrientToEye(void) const;
  void setFront(const SbBool infront);
  SbBool isFront(void) const;
  SbBool isPointInFront(const SbVec3f & point) const;
  virtual void setWorkingSpace(const SbMatrix & space);

protected:
  SbSphereProjector(const SbBool orienttoeye);
  SbSphereProjector(const SbSphere & s, const SbBool orienttoeye);

  SbBool intersectSphereFront(const SbLine & l, SbVec3f & result);

  SbBool intersectFront;
  SbSphere sphere;
  SbBool orientToEye;
  SbBool needSetup;
  SbVec3f lastPoint;
};

#endif // !COIN_SBSPHEREPROJECTOR_H
