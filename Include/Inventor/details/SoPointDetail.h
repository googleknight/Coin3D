#ifndef COIN_SOPOINTDETAIL_H
#define COIN_SOPOINTDETAIL_H

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

#include <Inventor/details/SoSubDetail.h>

class COIN_DLL_API SoPointDetail : public SoDetail {
  typedef SoDetail inherited;

  SO_DETAIL_HEADER(SoPointDetail);

public:
  SoPointDetail(void);
  virtual ~SoPointDetail();
  static void initClass(void);
  virtual SoDetail * copy(void) const;

  int getCoordinateIndex(void) const;
  int getMaterialIndex(void) const;
  int getNormalIndex(void) const;
  int getTextureCoordIndex(void) const;

  void setCoordinateIndex(const int idx);
  void setMaterialIndex(const int idx);
  void setNormalIndex(const int idx);
  void setTextureCoordIndex(const int idx);

private:
  int coordindex;
  int matindex;
  int normindex;
  int texcoordindex;
};

#endif // !COIN_SOPOINTDETAIL_H
