#ifndef SOWINOBJECT_H
#define SOWINOBJECT_H

// src\Inventor\Win\SoWinObject.h.  Generated from SoGuiObject.h.in by configure.

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

#include <assert.h>

#include <Inventor/SbBasic.h>
#include <Inventor/SbString.h>
#include <Inventor/SoType.h>

#include <Inventor/Win/SoWinBasic.h>

// *************************************************************************

class SOWIN_DLL_API SoWinObject {
  static SoType classTypeId;

public:
  static void initClass(void);
  static SoType getClassTypeId(void);
  virtual SoType getTypeId(void) const = 0;
  SbBool isOfType(SoType type) const;

  static void init(void);

  // FIXME: gcc-4 generates a warning when a class has virtual functions 
  // but no virtual destructor. Currently this warning is suppressed using 
  // the -Wno-non-virtual-dtor option, but this should be addressed for the
  // next major version... 20060404 kyrah

#if (SOWIN_MAJOR_VERSION > 1)
#error Resolve missing virtual destructor issue for the new major release!
#endif

}; // SoWinObject

// *************************************************************************

// For a discussion about this #define, see Coin's SbBasic.h.

#define SOWIN_SUN_CC_4_0_SOTYPE_INIT_BUG 0 /* assume compiler is ok for now */

#if SOWIN_SUN_CC_4_0_SOTYPE_INIT_BUG
#define SOWIN_STATIC_SOTYPE_INIT
#else
#define SOWIN_STATIC_SOTYPE_INIT = SoType::badType()
#endif

// *************************************************************************

// The getTypeId() method should be abstract for abstract objects, but doing
// that would cause custom components derived from abstract components to
// have to include the typed object header / source, which could be a
// problem if the custom component wasn't written for Coin in the first
// place.

#define SOWIN_OBJECT_ABSTRACT_HEADER(classname, parentname) \
public: \
  static void initClass(void); \
  static SoType getClassTypeId(void); \
  virtual SoType getTypeId(void) const /* = 0 (see comment above) */; \
private: \
  typedef parentname inherited; \
  static SoType classTypeId

#define SOWIN_OBJECT_HEADER(classname, parentname) \
public: \
  static void initClass(void); \
  static SoType getClassTypeId(void); \
  virtual SoType getTypeId(void) const; \
  static void * createInstance(void); \
private: \
  typedef parentname inherited; \
  static SoType classTypeId

#define SOWIN_OBJECT_ABSTRACT_SOURCE(classname) \
void classname::initClass(void) { \
  assert(classname::classTypeId == SoType::badType()); \
  classname::classTypeId = \
    SoType::createType(inherited::getClassTypeId(), \
                        SO__QUOTE(classname)); \
} \
SoType classname::getClassTypeId(void) { \
  return classname::classTypeId; \
} \
SoType classname::getTypeId(void) const { \
  return classname::classTypeId; \
} \
SoType classname::classTypeId SOWIN_STATIC_SOTYPE_INIT

#define SOWIN_OBJECT_SOURCE(classname) \
void classname::initClass(void) { \
  assert(classname::classTypeId == SoType::badType()); \
  classname::classTypeId = \
    SoType::createType(inherited::getClassTypeId(), \
                        SO__QUOTE(classname), \
                        classname::createInstance); \
} \
SoType classname::getClassTypeId(void) { \
  return classname::classTypeId; \
} \
SoType classname::getTypeId(void) const { \
  return classname::classTypeId; \
} \
void * classname::createInstance(void) { \
  assert(classname::classTypeId != SoType::badType()); \
  return (void *) new classname; \
} \
SoType classname::classTypeId SOWIN_STATIC_SOTYPE_INIT

// *************************************************************************

#endif // ! SOWINOBJECT_H
