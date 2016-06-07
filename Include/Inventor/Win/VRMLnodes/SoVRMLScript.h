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

#ifndef COIN_SOVRMLSCRIPT_H
#define COIN_SOVRMLSCRIPT_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/fields/SoSFBool.h>
#include <Inventor/fields/SoMFString.h>

class SoVRMLScript;
class SoVRMLScriptP;
class SoSensor;

typedef void SoVRMLScriptEvaluateCB(void * closure, SoVRMLScript * node);

class COIN_DLL_API SoVRMLScript : public SoNode
{
  typedef SoNode inherited;

public:
  static void initClass(void);
  SoVRMLScript(void);

  static SoType getClassTypeId(void);
  virtual SoType getTypeId(void) const;

  SoMFString url;
  SoSFBool directOutput;
  SoSFBool mustEvaluate;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void pick(SoPickAction * action);
  virtual void handleEvent(SoHandleEventAction * action);
  virtual void write(SoWriteAction * action);

  static void setScriptEvaluateCB(SoVRMLScriptEvaluateCB * cb,
                                  void * closure);

protected:
  virtual ~SoVRMLScript();
  virtual void copyContents(const SoFieldContainer * from, SbBool copyconn);
  virtual void notify(SoNotList * list);
private:
  static SoType classTypeId;
  static void * createInstance(void);
  SoFieldData * fielddata;
  virtual const SoFieldData * getFieldData(void) const;

private:
  virtual SbBool readInstance(SoInput * in, unsigned short flags);

  static void eval_cb(void * data, SoSensor *);
  void initFieldData(void);
  SoVRMLScriptP * pimpl;
  friend class SoVRMLScriptP;
}; // class SoVRMLScript

#endif // ! COIN_SOVRMLSCRIPT_H
