#ifndef COIN_SORAYPICKACTION_H
#define COIN_SORAYPICKACTION_H

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

#include <Inventor/actions/SoPickAction.h>

class SbBox3f;
class SbLine;
class SbMatrix;
class SbVec2f;
class SbVec2s;
class SbVec3f;
class SbViewVolume;
class SbViewportRegion;
class SoPickedPoint;
class SoPickedPointList;
class SoRayPickActionP;

class COIN_DLL_API SoRayPickAction : public SoPickAction {
  typedef SoPickAction inherited;

  SO_ACTION_HEADER(SoRayPickAction);

public:
  SoRayPickAction(const SbViewportRegion & viewportregion);
  virtual ~SoRayPickAction();
  static void initClass(void);

  void setPoint(const SbVec2s & viewportPoint);
  void setNormalizedPoint(const SbVec2f & normpoint);
  void setRadius(const float radiusinpixels);
  void setRay(const SbVec3f & start, const SbVec3f & direction,
              float neardistance = -1.0,
              float fardistance = -1.0);
  void setPickAll(const SbBool flag);
  SbBool isPickAll(void) const;
  const SoPickedPointList & getPickedPointList(void) const;
  SoPickedPoint * getPickedPoint(const int index = 0) const;


  void computeWorldSpaceRay(void);
  SbBool hasWorldSpaceRay(void) const;
  void setObjectSpace(void);
  void setObjectSpace(const SbMatrix & matrix);
  SbBool intersect(const SbVec3f & v0, const SbVec3f & v1, const SbVec3f & v2,
                   SbVec3f & intersection, SbVec3f & barycentric,
                   SbBool & front) const;
  SbBool intersect(const SbVec3f & v0, const SbVec3f & v1,
                   SbVec3f & intersection) const;
  SbBool intersect(const SbVec3f & point) const;
  SbBool intersect(const SbBox3f & box, const SbBool usefullviewvolume = TRUE);
  SbBool intersect(const SbBox3f & box, SbVec3f & intersection,
                   const SbBool usefullviewvolume = TRUE);
  const SbViewVolume & getViewVolume(void);
  const SbLine & getLine(void);
  SbBool isBetweenPlanes(const SbVec3f & intersection) const;
  SoPickedPoint * addIntersection(const SbVec3f & objectspacepoint, SbBool frontpick = TRUE);

  void reset(void);

protected:
  virtual void beginTraversal(SoNode * node);

private:
  SbPimplPtr<SoRayPickActionP> pimpl;

  // NOT IMPLEMENTED:
  SoRayPickAction(const SoRayPickAction & rhs);
  SoRayPickAction & operator = (const SoRayPickAction & rhs);
}; // SoRayPickAction

#endif // !COIN_SORAYPICKACTION_H
