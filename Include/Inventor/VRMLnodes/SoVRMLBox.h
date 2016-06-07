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

#ifndef COIN_SOVRMLBOX_H
#define COIN_SOVRMLBOX_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/VRMLnodes/SoVRMLGeometry.h>
#include <Inventor/fields/SoSFVec3f.h>

class COIN_DLL_API SoVRMLBox : public SoVRMLGeometry
{
  typedef SoVRMLGeometry inherited;
  SO_NODE_HEADER(SoVRMLBox);

public:
  static void initClass(void);
  SoVRMLBox(void);

  SoSFVec3f size;

  virtual void GLRender(SoGLRenderAction * action);
  virtual void rayPick(SoRayPickAction * action);
  virtual void getPrimitiveCount( SoGetPrimitiveCountAction * action );

protected:
  virtual ~SoVRMLBox();

  virtual void generatePrimitives( SoAction * action );
  virtual void computeBBox( SoAction * action, SbBox3f & box,
                            SbVec3f & center );
}; // class SoVRMLBox

#endif // ! COIN_SOVRMLBOX_H
