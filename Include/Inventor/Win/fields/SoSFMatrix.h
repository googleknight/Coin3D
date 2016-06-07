#ifndef COIN_SOSFMATRIX_H
#define COIN_SOSFMATRIX_H

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
#include <Inventor/SbMatrix.h>

class COIN_DLL_API SoSFMatrix : public SoSField {
  typedef SoSField inherited;

  SO_SFIELD_HEADER(SoSFMatrix, SbMatrix, const SbMatrix &);

public:
  static void initClass(void);

  void setValue(const float a11, const float a12,
                const float a13, const float a14,
                const float a21, const float a22,
                const float a23, const float a24,
                const float a31, const float a32,
                const float a33, const float a34,
                const float a41, const float a42,
                const float a43, const float a44);
};

#endif // !COIN_SOSFMATRIX_H
