#ifndef COIN_SOSEPARATOR_H
#define COIN_SOSEPARATOR_H

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
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/nodes/SoGroup.h>
#include <Inventor/tools/SbPimplPtr.h>

class SoState;
class SoSeparatorP;

class COIN_DLL_API SoSeparator : public SoGroup {
  typedef SoGroup inherited;

  SO_NODE_HEADER(SoSeparator);

public:
  static void initClass(void);
  SoSeparator(void);
  SoSeparator(const int nchildren);

  enum CacheEnabled {
    OFF, ON, AUTO
  };

  SoSFEnum renderCaching;
  SoSFEnum boundingBoxCaching;
  SoSFEnum renderCulling;
  SoSFEnum pickCulling;

  virtual void doAction(SoAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void GLRenderBelowPath(SoGLRenderAction * action);
  virtual void GLRenderInPath(SoGLRenderAction * action);
  virtual void GLRenderOffPath(SoGLRenderAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void handleEvent(SoHandleEventAction * action);
  virtual void rayPick(SoRayPickAction * action);
  virtual void search(SoSearchAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
  virtual void audioRender(SoAudioRenderAction * action);

  virtual void notify(SoNotList * nl);

  static void setNumRenderCaches(const int howmany);
  static int getNumRenderCaches(void);
  virtual SbBool affectsState(void) const;

protected:
  virtual ~SoSeparator();

  virtual SbBool cullTest(SoState * state);
  virtual SbBool cullTest(SoGLRenderAction * action, int & cullresults);
  virtual SbBool readInstance(SoInput * in, unsigned short flags);

private:
  void commonConstructor(void);
  SbBool cullTestNoPush(SoState * state);

  static int numrendercaches;

  SbPimplPtr<SoSeparatorP> pimpl;

  // NOT IMPLEMENTED
  SoSeparator(const SoSeparator & rhs);
  SoSeparator & operator = (const SoSeparator & rhs);

};

#endif // !COIN_SOSEPARATOR_H
