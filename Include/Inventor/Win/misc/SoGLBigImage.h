#ifndef COIN_SOGLBIGIMAGE_H
#define COIN_SOGLBIGIMAGE_H

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
#include <Inventor/SbVec2s.h>
#include <Inventor/SbVec2f.h>
#include <Inventor/misc/SoGLImage.h>

class COIN_DLL_API SoGLBigImage : public SoGLImage {
  typedef SoGLImage inherited;

public:

  SoGLBigImage();
  virtual void unref(SoState * state = NULL);

  static SoType getClassTypeId(void);
  virtual SoType getTypeId(void) const ;

  virtual void setData(const SbImage * image,
                       const Wrap wraps = REPEAT,
                       const Wrap wrapt = REPEAT,
                       const float quality = 0.5f,
                       const int border = 0,
                       SoState * createinstate = NULL);

  virtual void setData(const SbImage * image,
                       const Wrap wraps,
                       const Wrap wrapt,
                       const Wrap wrapr,
                       const float quality = 0.5f,
                       const int border = 0,
                       SoState * createinstate = NULL);

  int initSubImages(const SbVec2s & subimagesize) const;
  void handleSubImage(const int idx, SbVec2f & start, SbVec2f & end,
                      SbVec2f & tcmul);
  void applySubImage(SoState * state, const int idx, const float quality,
                     const SbVec2s & projsize);
  SbBool exceededChangeLimit(void);
  static int setChangeLimit(const int limit);

  // will return NULL to avoid that SoGLTextureImageElement will
  // update the texture state.
  virtual SoGLDisplayList * getGLDisplayList(SoState * state);


protected:
  virtual void unrefOldDL(SoState * state, const uint32_t maxage);

public:
  static void initClass(void);

private:
  virtual ~SoGLBigImage();

  class SoGLBigImageP * pimpl;
  friend class SoGLBigImageP;
};

#endif // !COIN_SOGLBIGIMAGE_H
