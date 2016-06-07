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

#ifndef COIN_SOVRMLGROUP_H
#define COIN_SOVRMLGROUP_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/VRMLnodes/SoVRMLParent.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFVec3f.h>

class SoState;
class SoVRMLGroupP;

class COIN_DLL_API SoVRMLGroup : public SoVRMLParent
{
  typedef SoVRMLParent inherited;
  SO_NODE_HEADER(SoVRMLGroup);

public:
  static void initClass(void);
  SoVRMLGroup(void);
  SoVRMLGroup(int numChildren);

  enum CacheEnabled {
    OFF,
    ON,
    AUTO
  };

  SoSFEnum renderCaching;
  SoSFEnum boundingBoxCaching;
  SoSFEnum renderCulling;
  SoSFEnum pickCulling;
  SoSFVec3f bboxCenter;
  SoSFVec3f bboxSize;

  static void setNumRenderCaches(int num);
  static int getNumRenderCaches(void);

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void rayPick(SoRayPickAction * action);
  virtual void search(SoSearchAction * action);
  virtual void write(SoWriteAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
  virtual void audioRender(SoAudioRenderAction * action);

  virtual void GLRenderBelowPath(SoGLRenderAction * action);
  virtual void GLRenderInPath(SoGLRenderAction * action);
  virtual void GLRenderOffPath(SoGLRenderAction * action);

  virtual void notify(SoNotList * list);

protected:
  virtual ~SoVRMLGroup();

  virtual SbBool cullTest(SoState * state);

  static int numRenderCaches;

private:
  SoVRMLGroupP * pimpl;

  SbBool cullTestNoPush(SoState * state);
  void commonConstructor(void);

}; // class SoVRMLGroup

#endif // ! COIN_SOVRMLGROUP_H
