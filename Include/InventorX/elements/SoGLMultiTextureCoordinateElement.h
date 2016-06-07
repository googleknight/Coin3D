#ifndef COIN_SOGLMULTITEXTURECOORDINATEELEMENT_H
#define COIN_SOGLMULTITEXTURECOORDINATEELEMENT_H

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

#include <Inventor/elements/SoMultiTextureCoordinateElement.h>
#include <Inventor/elements/SoGLTextureCoordinateElement.h>

class SoGLMultiTextureCoordinateElementP;

class COIN_DLL_API SoGLMultiTextureCoordinateElement : public SoMultiTextureCoordinateElement {
  typedef SoMultiTextureCoordinateElement inherited;

  SO_ELEMENT_HEADER(SoGLMultiTextureCoordinateElement);
public:
  static void initClass(void);
protected:
  virtual ~SoGLMultiTextureCoordinateElement();

public:
  virtual void init(SoState * state);
  virtual void push(SoState * state);
  virtual void pop(SoState * state,
                   const SoElement * prevTopElement);

  static  void setTexGen(SoState * const state, SoNode * const node,
                         const int unit,
                         SoTexCoordTexgenCB * const texgenFunc,
                         void * const texgenData = NULL,
                         SoTextureCoordinateFunctionCB * const func = NULL,
                         void * const funcData = NULL);

  virtual SoTextureCoordinateElement::CoordType getType(const int unit) const;

  static const SoGLMultiTextureCoordinateElement * getInstance(SoState * const state);

  void send(const int unit, const int index) const;
  void send(const int unit, const int index, const SbVec3f &c, const SbVec3f &n) const;

  class GLUnitData {
  public:
    SoTexCoordTexgenCB * texgenCB;
    void * texgenData;
  };
  
  void initRender(const SbBool * enabled, const int maxenabled) const;

protected:
  virtual void setElt(const int unit,
                      SoTexCoordTexgenCB *func,
                      void *data = NULL);

private:
  void doCallback(const int unit) const;
  SoGLMultiTextureCoordinateElementP * pimpl;
};

#endif // !COIN_SOGLMULTITEXTURECOORDINATEELEMENT_H
