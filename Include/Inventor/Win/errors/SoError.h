#ifndef COIN_SOERROR_H
#define COIN_SOERROR_H

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

#include <Inventor/SbBasic.h>
#include <Inventor/SbString.h>
#include <Inventor/C/errors/error.h>
#include <Inventor/SoType.h>

class SoBase;
class SoNode;
class SoPath;
class SoEngine;

typedef void SoErrorCB(const class SoError * error, void * data);
typedef SoErrorCB * SoErrorCBPtr;


class COIN_DLL_API SoError {
public:
  SoError(void) { cc_error_init(&this->err); }
  virtual ~SoError() { cc_error_clean(&this->err); }

  static void setHandlerCallback(SoErrorCB * const func, void * const data);
  static SoErrorCB * getHandlerCallback(void);
  static void * getHandlerData(void);

  const SbString & getDebugString(void) const;

  static SoType getClassTypeId(void);
  virtual SoType getTypeId(void) const;
  SbBool isOfType(const SoType type) const;

  static void post(const char * const format, ...);

  static SbString getString(const SoNode * const node);
  static SbString getString(const SoPath * const path);
  static SbString getString(const SoEngine * const engine);

  static void initClass(void);
  static void initClasses(void);

protected:
  static void defaultHandlerCB(const SoError * error, void * userdata);
  virtual SoErrorCBPtr getHandler(void * & data) const;

  void setDebugString(const char * const str);
  void appendToDebugString(const char * const str);

  void handleError(void);

private:
  SoError(const cc_error * error);
  static void generateBaseString(SbString & str, const SoBase * const base,
                                 const char * const what);

  static void callbackForwarder(const cc_error * err, void * data);

  static SoType classTypeId;
  static SoErrorCB * callback;
  static void * callbackData;
  SbString debugstring;

  cc_error err;
};

#endif // !COIN_SOERROR_H
