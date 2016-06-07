#ifndef COIN_SOGLTEXTURE3ENABLEDELEMENT_H
#define COIN_SOGLTEXTURE3ENABLEDELEMENT_H

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

#include <Inventor/elements/SoTexture3EnabledElement.h>

class COIN_DLL_API SoGLTexture3EnabledElement : public SoTexture3EnabledElement {
  typedef SoTexture3EnabledElement inherited;

  SO_ELEMENT_HEADER(SoGLTexture3EnabledElement);
public:
  static void initClass(void);
protected:
  virtual ~SoGLTexture3EnabledElement();

public:
  virtual void init(SoState * state);

  virtual void push(SoState * state);
  virtual void pop(SoState * state,
                   const SoElement * prevTopElement);

  static  void set(SoState * const state, SoNode * const node,
                   const SbBool enabled);
  static  void set(SoState * const state, const SbBool enabled);

  static SbBool get(SoState * const state);
  static SbBool getDefault(void);

  virtual void setElt(int32_t value);

private:
  void updategl(void);
  SoState * state;
};

#endif // !COIN_SOGLTEXTURE3ENABLEDELEMENT_H
