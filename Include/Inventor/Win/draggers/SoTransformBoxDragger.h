#ifndef COIN_SOTRANSFORMBOXDRAGGER_H
#define COIN_SOTRANSFORMBOXDRAGGER_H

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
#include <Inventor/tools/SbLazyPimplPtr.h>
#include <Inventor/fields/SoSFRotation.h>
#include <Inventor/fields/SoSFVec3f.h>

class SoSensor;
class SoFieldSensor;
class SoTransformBoxDraggerP;

class COIN_DLL_API SoTransformBoxDragger : public SoDragger {
  typedef SoDragger inherited;

  SO_KIT_HEADER(SoTransformBoxDragger);
  SO_KIT_CATALOG_ENTRY_HEADER(antiSquish);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator1);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator1Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator1Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator2);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator2Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator2Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator3);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator3Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(rotator3Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(scaler);
  SO_KIT_CATALOG_ENTRY_HEADER(surroundScale);
  SO_KIT_CATALOG_ENTRY_HEADER(translator1);
  SO_KIT_CATALOG_ENTRY_HEADER(translator1Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(translator1Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(translator2);
  SO_KIT_CATALOG_ENTRY_HEADER(translator2Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(translator2Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(translator3);
  SO_KIT_CATALOG_ENTRY_HEADER(translator3Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(translator3Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(translator4);
  SO_KIT_CATALOG_ENTRY_HEADER(translator4Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(translator4Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(translator5);
  SO_KIT_CATALOG_ENTRY_HEADER(translator5Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(translator5Sep);
  SO_KIT_CATALOG_ENTRY_HEADER(translator6);
  SO_KIT_CATALOG_ENTRY_HEADER(translator6Rot);
  SO_KIT_CATALOG_ENTRY_HEADER(translator6Sep);

public:
  static void initClass(void);
  SoTransformBoxDragger(void);

  SoSFRotation rotation;
  SoSFVec3f translation;
  SoSFVec3f scaleFactor;

protected:
  virtual ~SoTransformBoxDragger(void);
  virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);
  virtual void setDefaultOnNonWritingFields(void);

  static void invalidateSurroundScaleCB(void * f, SoDragger * d);
  static void fieldSensorCB(void * f, SoSensor * s);
  static void valueChangedCB(void * f, SoDragger * d);

  SoFieldSensor * rotFieldSensor;
  SoFieldSensor * translFieldSensor;
  SoFieldSensor * scaleFieldSensor;

private:
  void addChildDragger(SoDragger * child);
  void removeChildDragger(SoDragger * child);

private:
  SbLazyPimplPtr<SoTransformBoxDraggerP> pimpl;

  // NOT IMPLEMENTED:
  SoTransformBoxDragger(const SoTransformBoxDragger & rhs);
  SoTransformBoxDragger & operator = (const SoTransformBoxDragger & rhs);
}; // SoTransformBoxDragger

#endif // !COIN_SOTRANSFORMBOXDRAGGER_H
