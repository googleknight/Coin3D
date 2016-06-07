#ifndef COIN_SBVEC3I32_H
#define COIN_SBVEC3I32_H

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

class SbVec3ui32;
class SbVec3b;
class SbVec3s;
class SbVec3f;
class SbVec3d;

class COIN_DLL_API SbVec3i32 {
public:
  SbVec3i32(void) { }
  SbVec3i32(const int32_t v[3]) { vec[0] = v[0]; vec[1] = v[1]; vec[2] = v[2]; }
  SbVec3i32(int32_t x, int32_t y, int32_t z) { vec[0] = x; vec[1] = y; vec[2] = z; }
  explicit SbVec3i32(const SbVec3ui32 & v) { setValue(v); }
  explicit SbVec3i32(const SbVec3b & v) { setValue(v); }
  explicit SbVec3i32(const SbVec3s & v) { setValue(v); }
  explicit SbVec3i32(const SbVec3f & v) { setValue(v); }
  explicit SbVec3i32(const SbVec3d & v) { setValue(v); }

  SbVec3i32 & setValue(const int32_t v[3]) { vec[0] = v[0]; vec[1] = v[1]; vec[2] = v[2]; return *this; }
  SbVec3i32 & setValue(int32_t x, int32_t y, int32_t z) { vec[0] = x; vec[1] = y; vec[2] = z; return *this; }
  SbVec3i32 & setValue(const SbVec3ui32 & v);
  SbVec3i32 & setValue(const SbVec3b & v);
  SbVec3i32 & setValue(const SbVec3s & v);
  SbVec3i32 & setValue(const SbVec3f & v);
  SbVec3i32 & setValue(const SbVec3d & v);

  const int32_t * getValue(void) const { return vec; }
  void getValue(int32_t & x, int32_t & y, int32_t & z) const { x = vec[0]; y = vec[1]; z = vec[2]; }

  int32_t & operator [] (int i) { return vec[i]; }
  const int32_t & operator [] (int i) const { return vec[i]; }

  int32_t dot(const SbVec3i32 & v) const { return vec[0] * v[0] + vec[1] * v[1] + vec[2] * v[2]; }
  void negate(void) { vec[0] = -vec[0]; vec[1] = -vec[1]; vec[2] = -vec[2]; }

  SbVec3i32 & operator *= (int d) { vec[0] *= d; vec[1] *= d; vec[2] *= d; return *this; }
  SbVec3i32 & operator *= (double d);
  SbVec3i32 & operator /= (int d) { SbDividerChk("SbVec3i32::operator/=(int)", d); vec[0] /= d; vec[1] /= d; vec[2] /= d; return *this; }
  SbVec3i32 & operator /= (double d) { SbDividerChk("SbVec3i32::operator/=(double)", d); return operator *= (1.0 / d); }
  SbVec3i32 & operator += (const SbVec3i32 & v) { vec[0] += v[0]; vec[1] += v[1]; vec[2] += v[2]; return *this; }
  SbVec3i32 & operator -= (const SbVec3i32 & v) { vec[0] -= v[0]; vec[1] -= v[1]; vec[2] -= v[2]; return *this; }
  SbVec3i32 operator - (void) const { return SbVec3i32(-vec[0], -vec[1], -vec[2]); }

protected:
  int32_t vec[3];

}; // SbVec3i32

COIN_DLL_API inline SbVec3i32 operator * (const SbVec3i32 & v, int d) {
  SbVec3i32 val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec3i32 operator * (const SbVec3i32 & v, double d) {
  SbVec3i32 val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec3i32 operator * (int d, const SbVec3i32 & v) {
  SbVec3i32 val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec3i32 operator * (double d, const SbVec3i32 & v) {
  SbVec3i32 val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec3i32 operator / (const SbVec3i32 & v, int d) {
  SbDividerChk("operator/(SbVec3i32,int)", d);
  SbVec3i32 val(v); val /= d; return val;
}

COIN_DLL_API inline SbVec3i32 operator / (const SbVec3i32 & v, double d) {
  SbDividerChk("operator/(SbVec3i32,double)", d);
  SbVec3i32 val(v); val /= d; return val;
}

COIN_DLL_API inline SbVec3i32 operator + (const SbVec3i32 & v1, const SbVec3i32 & v2) {
  SbVec3i32 v(v1); v += v2; return v;
}

COIN_DLL_API inline SbVec3i32 operator - (const SbVec3i32 & v1, const SbVec3i32 & v2) {
  SbVec3i32 v(v1); v -= v2; return v;
}

COIN_DLL_API inline int operator == (const SbVec3i32 & v1, const SbVec3i32 & v2) {
  return ((v1[0] == v2[0]) && (v1[1] == v2[1]) && (v1[2] == v2[2]));
}

COIN_DLL_API inline int operator != (const SbVec3i32 & v1, const SbVec3i32 & v2) {
  return !(v1 == v2);
}

#endif // !COIN_SBVEC3I32_H
