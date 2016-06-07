#ifndef COIN_SBOCTTREE_H
#define COIN_SBOCTTREE_H

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

#include <Inventor/SbVec3f.h>
#include <Inventor/lists/SbList.h>
#include <Inventor/SbBox3f.h>
#include <stdio.h>

class SbSphere;
class SbOctTreeNode;
class SbPlane;

// *************************************************************************

typedef struct
{
  SbBool (*ptinsidefunc)(void * const item, const SbVec3f & pt);
  SbBool (*insideboxfunc)(void * const item, const SbBox3f & box);
  SbBool (*insidespherefunc)(void * const item, const SbSphere & sphere);
  SbBool (*insideplanesfunc)(void * const item,
                             const SbPlane * const planes,
                             const int numplanes);
} SbOctTreeFuncs;

// *************************************************************************

class COIN_DLL_API SbOctTree {
public:
  SbOctTree(const SbBox3f & bbox,
            const SbOctTreeFuncs & itemfuncs,
            const int maxitemspernode = 64);
  ~SbOctTree();

  void addItem(void * const item);
  void removeItem(void * const item);
  void findItems(const SbVec3f & pos,
                 SbList <void*> & destarray,
                 const SbBool removeduplicates = TRUE) const;
  void findItems(const SbBox3f & box,
                 SbList <void*> & destarray,
                 const SbBool removeduplicates = TRUE) const;
  void findItems(const SbSphere & sphere,
                 SbList <void*> & destarray,
                 const SbBool removeduplicates = TRUE) const;
  void findItems(const SbPlane * const planes,
                 const int numplanes,
                 SbList <void*> & destarray,
                 const SbBool removeduplicates= TRUE) const;

  const SbBox3f & getBoundingBox(void) const;
  void clear(void);
  void debugTree(FILE * fp);

private:
  SbOctTreeNode * topnode;
  SbOctTreeFuncs itemfuncs;
  int maxitemspernode;
};

// *************************************************************************

#endif // !COIN_SBOCTTREE_H
