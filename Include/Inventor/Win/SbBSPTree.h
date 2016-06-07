#ifndef COIN_SBBSPTREE_H
#define COIN_SBBSPTREE_H

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

#include <stddef.h> // for NULL definition
#include <Inventor/lists/SbList.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/SbBox3f.h>

#ifdef COIN_INTERNAL
 #define COIN_ALLOW_SBINTLIST
 #include <Inventor/lists/SbIntList.h>
 #undef COIN_ALLOW_SBINTLIST
#else
 #include <Inventor/lists/SbIntList.h>
#endif // COIN_INTERNAL

class SbSphere;
class coin_bspnode;

// *************************************************************************

class COIN_DLL_API SbBSPTree {
public:
  SbBSPTree(const int maxnodepts = 64, const int initsize = 4);
  ~SbBSPTree();

  int numPoints() const;
  SbVec3f getPoint(const int idx) const;
  void getPoint(const int idx, SbVec3f & pt) const;
  void * getUserData(const int idx) const;
  void setUserData(const int idx, void * const data);

  int addPoint(const SbVec3f & pt, void * const userdata = NULL);
  int removePoint(const SbVec3f & pt);
  void removePoint(const int idx);
  int findPoint(const SbVec3f & pos) const;
  int findClosest(const SbVec3f & pos) const;
  void clear(const int initsize = 4);
  void findPoints(const SbSphere & sphere, SbIntList & array) const;
  int findClosest(const SbSphere & sphere, SbIntList & array) const;

  const SbBox3f & getBBox() const;
  const SbVec3f * getPointsArrayPtr() const;

  // Please stop using these two functions. They will be removed in
  // Coin 3.0. Use the SbIntList versions instead.
  void findPoints(const SbSphere & sphere, SbList <int> & array) const;
  int findClosest(const SbSphere & sphere, SbList <int> & array) const;

private:
  friend class coin_bspnode;
  SbList <SbVec3f> pointsArray;
  SbList <void *> userdataArray;
  coin_bspnode * topnode;
  int maxnodepoints;
  SbBox3f boundingBox;
};

#endif // !COIN_SBBSPTREE_H
