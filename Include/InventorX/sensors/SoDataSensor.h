#ifndef COIN_SODATASENSOR_H
#define COIN_SODATASENSOR_H

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

#include <Inventor/sensors/SoDelayQueueSensor.h>
#include <stdlib.h> // for NULL definition

class SoNode;
class SoField;
class SoPath;
class SoNotList;

class COIN_DLL_API SoDataSensor : public SoDelayQueueSensor {
  typedef SoDelayQueueSensor inherited;

public:
  SoDataSensor(void);
  SoDataSensor(SoSensorCB * func, void * data);
  virtual ~SoDataSensor(void);

  void setDeleteCallback(SoSensorCB * function, void * data = NULL);
  SoNode * getTriggerNode(void) const;
  SoField * getTriggerField(void) const;
  SoPath * getTriggerPath(void) const;
  void setTriggerPathFlag(SbBool flag);
  SbBool getTriggerPathFlag(void) const;

  virtual void trigger(void);
  virtual void notify(SoNotList * l);
  virtual void dyingReference(void) = 0;

protected:
  void invokeDeleteCallback(void);

private:
  SoSensorCB * cbfunc;
  void * cbdata;
  SbBool findpath;
  SoField * triggerfield;
  SoNode * triggernode;
  SoPath * triggerpath;
};

#endif // !COIN_SODATASENSOR_H
