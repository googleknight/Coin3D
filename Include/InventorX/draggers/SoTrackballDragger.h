#ifndef COIN_SOTRACKBALLDRAGGER_H
#define COIN_SOTRACKBALLDRAGGER_H

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

#include <Inventor/draggers/SoDragger.h>
#include <Inventor/tools/SbPimplPtr.h>
#include <Inventor/fields/SoSFRotation.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/SbVec2f.h>
#include <Inventor/SbTime.h>

class SoSensor;
class SoFieldSensor;
class SbSphereProjector;
class SbCylinderProjector;
class SbLineProjector;
class SoTimerSensor;
class SoTrackballDraggerP;

class COIN_DLL_API SoTrackballDragger : public SoDragger {
  typedef SoDragger inherited;

  SO_KIT_HEADER(SoTrackballDragger);
  SO_KIT_CATALOG_ENTRY_HEADER(XRotator);
  SO_KIT_CATALOG_ENTRY_HEADER(XRotatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(XRotatorSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(YRotator);
  SO_KIT_CATALOG_ENTRY_HEADER(YRotatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(YRotatorSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(ZRotator);
  SO_KIT_CATALOG_ENTRY_HEADER(ZRotatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(ZRotatorSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(antiSquish);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator);
  SO_KIT_CATALOG_ENTRY_HEADER(rotatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(rotatorSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(surroundScale);
  SO_KIT_CATALOG_ENTRY_HEADER(userAxis);
  SO_KIT_CATALOG_ENTRY_HEADER(userAxisActive);
  SO_KIT_CATALOG_ENTRY_HEADER(userAxisRotation);
  SO_KIT_CATALOG_ENTRY_HEADER(userAxisSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(userRotator);
  SO_KIT_CATALOG_ENTRY_HEADER(userRotatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(userRotatorSwitch);

public:
  static void initClass(void);
  SoTrackballDragger(void);

  SoSFRotation rotation;
  SoSFVec3f scaleFactor;

  SbBool isAnimationEnabled(void);
  void setAnimationEnabled(SbBool newval);

protected:
  virtual ~SoTrackballDragger(void);
  virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);
  virtual void setDefaultOnNonWritingFields(void);

  void dragStart(void);
  void drag(void);
  void dragFinish(void);
  void setAllPartsActive(SbBool onoroff);

  static void startCB(void * f, SoDragger * d);
  static void motionCB(void * f, SoDragger * d);
  static void finishCB(void * f, SoDragger * d);
  static void metaKeyChangeCB(void * f, SoDragger * d);
  static void fieldSensorCB(void * f, SoSensor * s);
  static void valueChangedCB(void * f, SoDragger * d);

  SoFieldSensor * rotFieldSensor;
  SoFieldSensor * scaleFieldSensor;

private:
  SoNode * getNodeFieldNode(const char *fieldname);
  void updateUserAxisSwitches(const SbBool setactive = FALSE);
  static void timerSensorCB(void *, SoSensor *);

private:
  SbPimplPtr<SoTrackballDraggerP> pimpl;
  friend class SoTrackballDraggerP;

  // NOT IMPLEMENTED:
  SoTrackballDragger(const SoTrackballDragger & rhs);
  SoTrackballDragger & operator = (const SoTrackballDragger & rhs);
}; // SoTrackballDragger

#endif // !COIN_SOTRACKBALLDRAGGER_H
