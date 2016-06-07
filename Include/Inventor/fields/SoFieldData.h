#ifndef COIN_SOFIELDDATA_H
#define COIN_SOFIELDDATA_H

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
#include <Inventor/lists/SbList.h>

class SbName;
class SoField;
class SoFieldContainer;
class SoInput;
class SoOutput;

class SoEnumEntry;
class SoFieldEntry;

class COIN_DLL_API SoFieldData {
public:
  SoFieldData(void);
  SoFieldData(const SoFieldData & fd);
  SoFieldData(const SoFieldData * fd);
  SoFieldData(int numfields);
  ~SoFieldData();

  void addField(SoFieldContainer * base, const char * name,
                const SoField * field);

  void overlay(SoFieldContainer * to, const SoFieldContainer * from,
               SbBool copyconnections) const;

  int getNumFields(void) const;
  const SbName & getFieldName(int index) const;
  SoField * getField(const SoFieldContainer * object, int index) const;
  int getIndex(const SoFieldContainer * fc, const SoField * field) const;

  void addEnumValue(const char * enumname, const char * valuename, int value);
  void getEnumData(const char * enumname,
                   int & num, const int *& values, const SbName *& names);

  SbBool read(SoInput * input, SoFieldContainer * object,
              SbBool erroronunknownfield, SbBool & notbuiltin) const;
  SbBool read(SoInput * input, SoFieldContainer * object,
              const SbName & fieldname, SbBool & foundname) const;
  void write(SoOutput * out, const SoFieldContainer * object) const;
  void copy(const SoFieldData * src);
  SbBool isSame(const SoFieldContainer * c1,
                const SoFieldContainer * c2) const;

  SbBool readFieldDescriptions(SoInput * input, SoFieldContainer * object,
                               int numdescriptionsexpected,
                               const SbBool readfieldvalues = TRUE) const;
  void writeFieldDescriptions(SoOutput * out,
                              const SoFieldContainer * object) const;

private:
  SbBool hasField(const char * name) const;
  SbBool hasEnumValue(const char * enumname, const char * valuename);

  // Bitflags for control word in the file format.
  enum ControlWord {
    NOTBUILTIN = 0x40
  };

  int operator==(const SoFieldData * fd) const;
  int operator!=(const SoFieldData * fd) const { return ! operator==(fd); }
  int operator==(const SoFieldData & fd) const { return operator==(&fd); }
  int operator!=(const SoFieldData & fd) const { return ! operator==(&fd); }

  void freeResources(void);

  SbList<SoFieldEntry *> fields;
  SbList<SoEnumEntry *> enums;
};

#endif // !COIN_SOFIELDDATA_H
