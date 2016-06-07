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

#ifndef COIN_SOVRMLTIMESENSOR_H
#define COIN_SOVRMLTIMESENSOR_H

#include <Inventor/engines/SoNodeEngine.h>
#include <Inventor/engines/SoSubNodeEngine.h>
#include <Inventor/engines/SoEngineOutput.h>
#include <Inventor/fields/SoSFTime.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFBool.h>

class SoSensor;

class COIN_DLL_API SoVRMLTimeSensor : public SoNodeEngine
{
  typedef SoNodeEngine inherited;
  SO_NODEENGINE_HEADER(SoVRMLTimeSensor);

public:
  static void initClass(void);
  SoVRMLTimeSensor(void);

  SoSFTime cycleInterval;
  SoSFBool enabled;
  SoSFBool loop;
  SoSFTime startTime;
  SoSFTime stopTime;

  virtual void notify(SoNotList * list);
  virtual void handleEvent(SoHandleEventAction * action);
  virtual void write(SoWriteAction * action);

  SoEngineOutput cycleTime; // (SoSFTime)
  SoEngineOutput fraction_changed; // (SoSFFloat)
  SoEngineOutput isActive; // (SoSFBool)
  SoEngineOutput time; // (SoSFTime)

protected:
  virtual ~SoVRMLTimeSensor();
  virtual void inputChanged(SoField * whichInput);

private:
  virtual void evaluate(void);
  SoSFTime timeIn;
  class SoVRMLTimeSensorP * pimpl;
}; // class SoVRMLTimeSensor

#endif // ! COIN_SOVRMLTIMESENSOR_H
