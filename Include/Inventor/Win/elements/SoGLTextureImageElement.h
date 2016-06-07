#ifndef COIN_SOGLTEXTUREIMAGEELEMENT_H
#define COIN_SOGLTEXTUREIMAGEELEMENT_H

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

#include <Inventor/elements/SoTextureImageElement.h>

class SoGLImage;
class SoGLDisplayList;

class COIN_DLL_API SoGLTextureImageElement : public SoTextureImageElement {
  typedef SoTextureImageElement inherited;

  SO_ELEMENT_HEADER(SoGLTextureImageElement);
public:
  static void initClass(void);
protected:
  virtual ~SoGLTextureImageElement();

public:
  virtual void init(SoState * state);
  virtual void push(SoState * state);
  virtual void pop(SoState * state,
                   const SoElement * prevTopElement);

  static void set(SoState * const state, SoNode * const node,
                  SoGLImage * image, const Model model,
                  const SbColor & blendColor);

  static SoGLImage * get(SoState * state, Model & model,
                         SbColor & blendcolor);

  static int32_t getMaxGLTextureSize(void);
  virtual SbBool isTextureSizeLegal(int xsize, int ysize, int zsize, 
                                    int bytespertexel);

  static SbBool hasTransparency(SoState * state);
protected:
  virtual SbBool hasTransparency(void) const;

private:
  void updateLazyElement(void) const;
  SoGLImage * glimage;
  SoGLDisplayList  * dlist;
  SoState * state;
};

#endif // !COIN_SOGLTEXTUREIMAGEELEMENT_H
