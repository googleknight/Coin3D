#ifndef COIN_SBVEC2B_H
#define COIN_SBVEC2B_H

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
#include <Inventor/system/inttypes.h>
#ifndef NDEBUG
#include <Inventor/errors/SoDebugError.h>
#endif // !NDEBUG

class SbVec2ub;
class SbVec2s;
class SbVec2i32;
class SbVec2f;
class SbVec2d;

class COIN_DLL_API SbVec2b {
public:
  SbVec2b(void) { }
  SbVec2b(const int8_t v[2]) { vec[0] = v[0]; vec[1] = v[1]; }
  SbVec2b(int8_t x, int8_t y) { vec[0] = x; vec[1] = y; }
  explicit SbVec2b(const SbVec2ub & v) { setValue(v); }
  explicit SbVec2b(const SbVec2s & v) { setValue(v); }
  explicit SbVec2b(const SbVec2i32 & v) { setValue(v); }
  explicit SbVec2b(const SbVec2f & v) { setValue(v); }
  explicit SbVec2b(const SbVec2d & v) { setValue(v); }

  SbVec2b & setValue(const int8_t v[2]) { vec[0] = v[0]; vec[1] = v[1]; return *this; }
  SbVec2b & setValue(int8_t x, int8_t y) { vec[0] = x; vec[1] = y; return *this; }
  SbVec2b & setValue(const SbVec2ub & v);
  SbVec2b & setValue(const SbVec2s & v);
  SbVec2b & setValue(const SbVec2i32 & v);
  SbVec2b & setValue(const SbVec2f & v);
  SbVec2b & setValue(const SbVec2d & v);

  const int8_t * getValue(void) const { return vec; }
  void getValue(int8_t & x, int8_t & y) const { x = vec[0]; y = vec[1]; }

  int8_t & operator [] (int i) { return vec[i]; }
  const int8_t & operator [] (int i) const { return vec[i]; }

  int32_t dot(SbVec2b v) const { return vec[0] * v[0] + vec[1] * v[1]; }
  void negate(void) { vec[0] = -vec[0]; vec[1] = -vec[1]; }

  SbVec2b & operator *= (int d) { vec[0] *= d; vec[1] *= d; return *this; }
  SbVec2b & operator *= (double d);
  SbVec2b & operator /= (int d) { SbDividerChk("SbVec2b::operator/=(int)", d); vec[0] /= d; vec[1] /= d; return *this; }
  SbVec2b & operator /= (double d) { SbDividerChk("SbVec2b::operator/=(double)", d); return operator *= (1.0 / d); }
  SbVec2b & operator += (SbVec2b v) { vec[0] += v[0]; vec[1] += v[1]; return *this; }
  SbVec2b & operator -= (SbVec2b v) { vec[0] -= v[0]; vec[1] -= v[1]; return *this; }
  SbVec2b operator - (void) const { return SbVec2b(-vec[0], -vec[1]); }

protected:
  int8_t vec[2];

}; // SbVec2b

COIN_DLL_API inline SbVec2b operator * (SbVec2b v, int d) {
  SbVec2b val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec2b operator * (SbVec2b v, double d) {
  SbVec2b val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec2b operator * (int d, SbVec2b v) {
  SbVec2b val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec2b operator * (double d, SbVec2b v) {
  SbVec2b val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec2b operator / (SbVec2b v, int d) {
  SbDividerChk("operator/(SbVec2b,int)", d);
  SbVec2b val(v); val /= d; return val;
}

COIN_DLL_API inline SbVec2b operator / (SbVec2b v, double d) {
  SbDividerChk("operator/(SbVec2b,double)", d);
  SbVec2b val(v); val /= d; return val;
}

COIN_DLL_API inline SbVec2b operator + (SbVec2b v1, SbVec2b v2) {
  SbVec2b v(v1); v += v2; return v;
}

COIN_DLL_API inline SbVec2b operator - (SbVec2b v1, SbVec2b v2) {
  SbVec2b v(v1); v -= v2; return v;
}

COIN_DLL_API inline int operator == (SbVec2b v1, SbVec2b v2) {
  return ((v1[0] == v2[0]) && (v1[1] == v2[1]));
}

COIN_DLL_API inline int operator != (SbVec2b v1, SbVec2b v2) {
  return !(v1 == v2);
}

#endif // !COIN_SBVEC2B_H
