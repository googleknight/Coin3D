#ifndef COIN_SOMFENUM_H
#define COIN_SOMFENUM_H

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

#include <Inventor/fields/SoMField.h>
#include <Inventor/fields/SoSubField.h>

class COIN_DLL_API SoMFEnum : public SoMField {
  typedef SoMField inherited;

  SO_MFIELD_HEADER(SoMFEnum, int, int);

public:
  static void initClass(void);

  void setValue(const SbName name);
  void set1Value(const int idx, const SbName name);
  void setEnums(const int num, const int * const values,
                const SbName * const names);

  int getNumEnums(void) const;
  int getEnum(const int idx, SbName & name) const;

protected:
  virtual SbBool findEnumValue(const SbName & name, int & value);
  virtual SbBool findEnumName(int value, const SbName * & name) const;

  SbBool legalValuesSet;
  int numEnums;
  int * enumValues;
  SbName * enumNames;
};

// Macro definitions. See comment in SoSFEnum.h.

#include <Inventor/fields/SoSFEnum.h> // PRIVATE_SOENUM_SET_TYPE()

#define SO_ENGINE_SET_MF_ENUM_TYPE(_fieldname_, _enumtype_) \
  PRIVATE_SOENUM_SET_TYPE(_fieldname_, _enumtype_, inputdata)

#define SO_NODE_SET_MF_ENUM_TYPE(_fieldname_, _enumtype_) \
  PRIVATE_SOENUM_SET_TYPE(_fieldname_, _enumtype_, fieldData)

#endif // !COIN_SOMFENUM_H
