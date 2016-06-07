#ifndef COIN_SOMULTITEXTURECOORDINATEELEMENT_H
#define COIN_SOMULTITEXTURECOORDINATEELEMENT_H

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

#include <Inventor/elements/SoTextureCoordinateElement.h>
#include <Inventor/elements/SoSubElement.h>
#include <Inventor/SbVec2f.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/SbVec4f.h>

class SoMultiTextureCoordinateElementP;

class COIN_DLL_API SoMultiTextureCoordinateElement : public SoElement {
  typedef SoElement inherited;

  SO_ELEMENT_HEADER(SoMultiTextureCoordinateElement);
public:
  static void initClass(void);
protected:
  virtual ~SoMultiTextureCoordinateElement();

public:

  virtual void init(SoState * state);

  static void setDefault(SoState * const state, SoNode * const node, const int unit);
  static void setFunction(SoState * const state, SoNode * const node,
                          const int unit,
                          SoTextureCoordinateFunctionCB * const func,
                          void * const userdata);

  static void set2(SoState * const state, SoNode * const node,
                   const int unit,
                   const int32_t numCoords, const SbVec2f * const coords);
  static void set3(SoState * const state, SoNode * const node,
                   const int unit,
                   const int32_t numCoords, const SbVec3f * const coords);
  static void set4(SoState * const state, SoNode * const node,
                   const int unit,
                   const int32_t numCoords, const SbVec4f * const coords);

  static SoTextureCoordinateElement::CoordType getType(SoState * const state, const int unit);
  virtual SoTextureCoordinateElement::CoordType getType(const int unit) const;

  static const SoMultiTextureCoordinateElement * getInstance(SoState * const state);

  const SbVec4f & get(const int unit,
                      const SbVec3f & point,
                      const SbVec3f & normal) const;

  int32_t getNum(const int unit) const;
  SbBool is2D(const int unit) const;
  int32_t getDimension(const int unit) const;

  const SbVec2f & get2(const int unit, const int index) const;
  const SbVec3f & get3(const int unit, const int index) const;
  const SbVec4f & get4(const int unit, const int index) const;

  const SbVec2f * getArrayPtr2(const int unit) const;
  const SbVec3f * getArrayPtr3(const int unit) const;
  const SbVec4f * getArrayPtr4(const int unit) const;

  class UnitData {
  public:
    uint32_t nodeid;
    SoTextureCoordinateElement::CoordType whatKind;
    SoTextureCoordinateFunctionCB * funcCB;
    void * funcCBData;
    int32_t numCoords;
    const SbVec2f * coords2;
    const SbVec3f * coords3;
    const SbVec4f * coords4;
    int coordsDimension;
  };

  virtual void push(SoState * state);
  virtual SbBool matches(const SoElement * elem) const;
  SoElement * copyMatchInfo(void) const;

protected:
  UnitData & getUnitData(const int unit);
  const UnitData & getUnitData(const int unit) const;
  SbVec2f convert2;
  SbVec3f convert3;
  SbVec4f convert4;

private:
  SoMultiTextureCoordinateElementP * pimpl;
};

#endif // !COIN_SOMULTITEXTURECOORDINATEELEMENT_H
