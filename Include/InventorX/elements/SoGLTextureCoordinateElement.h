#ifndef COIN_SOGLTEXTURECOORDINATEELEMENT_H
#define COIN_SOGLTEXTURECOORDINATEELEMENT_H

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

typedef void SoTexCoordTexgenCB(void * data);

class COIN_DLL_API SoGLTextureCoordinateElement : public SoTextureCoordinateElement {
  typedef SoTextureCoordinateElement inherited;

  SO_ELEMENT_HEADER(SoGLTextureCoordinateElement);
public:
  static void initClass(void);
protected:
  virtual ~SoGLTextureCoordinateElement();

public:
  virtual void init(SoState * state);
  virtual void push(SoState * state);
  virtual void pop(SoState * state,
                   const SoElement * prevTopElement);

  static  void setTexGen(SoState * const state, SoNode * const node,
                         SoTexCoordTexgenCB * const texgenFunc,
                         void * const texgenData = NULL,
                         SoTextureCoordinateFunctionCB * const func = NULL,
                         void * const funcData = NULL);

  virtual CoordType getType() const;

  static const SoGLTextureCoordinateElement *
  getInstance(SoState * const state);

  void send(const int index) const;
  void send(const int index, const SbVec3f &c, const SbVec3f &n) const;

  void initMulti(SoState * state) const;

protected:
  virtual void setElt(SoTexCoordTexgenCB *func,
                      void *data = NULL);

private:
  SoTexCoordTexgenCB *texgenCB;

  class PImpl;
  PImpl * pimpl;

  void doCallback() const;
};

#endif // !COIN_SOGLTEXTURECOORDINATEELEMENT_H
