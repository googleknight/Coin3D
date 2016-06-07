#ifndef COIN_SOSUBELEMENT_H
#define COIN_SOSUBELEMENT_H

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

/*
 * This file contains macro definitions with common declarations and
 * definitions used in Coin elements.
 *
 * FIXME: document macros and how they are used to set up a new
 * user-extension skeleton element class (or just point to the example
 * code in examples/advanced/elements/). 19991209 mortene.
 *
 */

// *************************************************************************

#include <Inventor/SbBasic.h> // for SO__QUOTE() definition
#include <Inventor/SbName.h>
#include <Inventor/C/tidbits.h>
#include <assert.h>
// Include SoElement.h to be Open Inventor compatible at compile-time.
#include <Inventor/elements/SoElement.h>

// *************************************************************************

#define SO_ELEMENT_ABSTRACT_HEADER(_class_) \
public: \
  static SoType getClassTypeId(void); \
  static int getClassStackIndex(void); \
protected: \
  _class_(void); \
private: \
  /* classStackIndex is protected in the OIV UNIX distribution in */ \
  /* SoSubElement.h and private in the Win32 distribution. Since */ \
  /* there is a getClassStackIndex() access method, it seems more */ \
  /* sensible to keep it private.  20000808 mortene. */ \
  static int classStackIndex; \
  static SoType classTypeId; \
  static void cleanupClass(void) { SoType::removeType(_class_::classTypeId.getName()); _class_::classTypeId STATIC_SOTYPE_INIT; }

// *************************************************************************

#define SO_ELEMENT_HEADER(_class_) \
  SO_ELEMENT_ABSTRACT_HEADER(_class_); \
public: \
  static void * createInstance(void)

// *************************************************************************

#define PRIVATE_SOELEMENT_VARIABLES(_class_) \
int _class_::classStackIndex; \
SoType _class_::classTypeId STATIC_SOTYPE_INIT; \
SoType _class_::getClassTypeId(void) { return _class_::classTypeId; } \
int _class_::getClassStackIndex(void) { return _class_::classStackIndex; }


#define SO_ELEMENT_ABSTRACT_SOURCE(_class_) \
PRIVATE_SOELEMENT_VARIABLES(_class_) \
_class_::_class_(void) { }

#define SO_ELEMENT_SOURCE(_class_) \
PRIVATE_SOELEMENT_VARIABLES(_class_) \
_class_::_class_(void) { this->setTypeId(_class_::classTypeId); \
                         this->setStackIndex(_class_::classStackIndex); } \
/*! \COININTERNAL */ \
void * _class_::createInstance(void) { return static_cast<void *>(new _class_); }

/*
  Specific to Coin. Added 2003-10-27.
*/
#define SO_ELEMENT_CUSTOM_CONSTRUCTOR_SOURCE(_class_) \
PRIVATE_SOELEMENT_VARIABLES(_class_) \
/*! \COININTERNAL */ \
void * _class_::createInstance(void) { return static_cast<void *>(new _class_); }

// *************************************************************************

#define PRIVATE_SOELEMENT_INIT(_class_, _parent_, _instantiate_) \
  do { \
    assert(_class_::classTypeId == SoType::badType()); \
    assert(_parent_::getClassTypeId() != SoType::badType()); \
    _class_::classTypeId = SoType::createType(_parent_::getClassTypeId(), \
                                              SO__QUOTE(_class_), \
                                              _instantiate_); \
    if (_parent_::getClassStackIndex() < 0) _class_::classStackIndex = _class_::createStackIndex(_class_::classTypeId); \
    else _class_::classStackIndex = _parent_::getClassStackIndex(); \
    cc_coin_atexit_static_internal(reinterpret_cast<coin_atexit_f*>(_class_::cleanupClass)); \
  } while (0)


#define SO_ELEMENT_INIT_ABSTRACT_CLASS(_class_, _parent_) \
  PRIVATE_SOELEMENT_INIT(_class_, _parent_, NULL)

#define SO_ELEMENT_INIT_CLASS(_class_, _parent_) \
  PRIVATE_SOELEMENT_INIT(_class_, _parent_, &_class_::createInstance)

// *************************************************************************

#endif // !COIN_SOSUBELEMENT_H
