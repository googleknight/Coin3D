#ifndef COIN_SOLINEDETAIL_H
#define COIN_SOLINEDETAIL_H

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

#include <Inventor/details/SoPointDetail.h>

class COIN_DLL_API SoLineDetail : public SoDetail {
  typedef SoDetail inherited;

  SO_DETAIL_HEADER(SoLineDetail);

public:
  SoLineDetail(void);
  virtual ~SoLineDetail();

  static void initClass(void);
  virtual SoDetail * copy(void) const;

  const SoPointDetail * getPoint0(void) const;
  const SoPointDetail * getPoint1(void) const;

  int getLineIndex(void) const;
  int getPartIndex(void) const;

  void setPoint0(const SoPointDetail * const detail);
  void setPoint1(const SoPointDetail * const detail);
  void setLineIndex(const int idx);
  void setPartIndex(const int idx);

  void incLineIndex(void);
  void incPartIndex(void);

private:
  SoPointDetail points[2];
  int lineindex;
  int partindex;
};

#endif // !COIN_SOLINEDETAIL_H
