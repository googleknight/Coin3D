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

#ifndef COIN_SOVRMLNAVIGATIONINFO_H
#define COIN_SOVRMLNAVIGATIONINFO_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/fields/SoMFString.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoMFFloat.h>
#include <Inventor/fields/SoSFBool.h>

class SoVRMLNavigationInfoP;

class COIN_DLL_API SoVRMLNavigationInfo : public SoNode
{
  typedef SoNode inherited;
  SO_NODE_HEADER(SoVRMLNavigationInfo);

public:
  static void initClass(void);
  SoVRMLNavigationInfo(void);

  SoMFString type;
  SoSFFloat speed;
  SoMFFloat avatarSize;
  SoSFFloat visibilityLimit;
  SoSFBool headlight;

  virtual void GLRender( SoGLRenderAction * action );

protected:
  virtual ~SoVRMLNavigationInfo();

  SoSFBool set_bind;
  SoSFBool isBound;

private:
  SoVRMLNavigationInfoP * pimpl;
};

#endif // ! COIN_SOVRMLNAVIGATIONINFO_H
