#ifndef COIN_SOSFIMAGE_H
#define COIN_SOSFIMAGE_H

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

#include <Inventor/fields/SoSField.h>
#include <Inventor/fields/SoSubField.h>
#include <Inventor/SbVec2s.h>

class SbImage;

class COIN_DLL_API SoSFImage : public SoSField {
  typedef SoSField inherited;

  SO_SFIELD_CONSTRUCTOR_HEADER(SoSFImage);
  SO_SFIELD_REQUIRED_HEADER(SoSFImage);

public:
  enum CopyPolicy {
    COPY,
    NO_COPY,
    NO_COPY_AND_DELETE,
    NO_COPY_AND_FREE
  };

  static void initClass(void);

  const unsigned char * getValue(SbVec2s & size, int & nc) const;
  const SbImage & getValue() const;

  void setValue(const SbVec2s & size, const int nc,
                const unsigned char * pixels, CopyPolicy copypolicy = COPY);

  int operator==(const SoSFImage & field) const;
  int operator!=(const SoSFImage & field) const { return ! operator == (field); }

  unsigned char * startEditing(SbVec2s & size, int & nc);
  void finishEditing(void);

  void setSubValue(const SbVec2s & dims, const SbVec2s & offset, unsigned char * pixels);
  void setSubValues(const SbVec2s * dims, const SbVec2s * offsets, int num, unsigned char ** pixelblocks);
  unsigned char * getSubTexture(int idx, SbVec2s & dims, SbVec2s & offset) const;
  SbBool hasSubTextures(int & numsubtextures);

  void setNeverWrite(SbBool flag);
  SbBool isNeverWrite(void) const;

  SbBool hasTransparency(void) const;

private:
  virtual SbBool readValue(SoInput * in);
  virtual void writeValue(SoOutput * out) const;

  class SoSFImageP * pimpl;
};

#endif // !COIN_SOSFIMAGE_H
