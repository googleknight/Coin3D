#ifndef COIN_SBVEC3D_H
#define COIN_SBVEC3D_H

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

#include <stdio.h>
#include <Inventor/SbBasic.h>
#ifndef NDEBUG
#include <Inventor/errors/SoDebugError.h>
#endif // !NDEBUG

class SbVec3f;
class SbVec3b;
class SbVec3s;
class SbVec3i32;
class SbDPPlane;

class COIN_DLL_API SbVec3d {
public:
  SbVec3d(void) { }
  SbVec3d(const double v[3]) { vec[0] = v[0]; vec[1] = v[1]; vec[2] = v[2]; }
  SbVec3d(double x, double y, double z) { vec[0] = x; vec[1] = y; vec[2] = z; }
  explicit SbVec3d(const SbVec3f & v) { setValue(v); }
  explicit SbVec3d(const SbVec3b & v) { setValue(v); }
  explicit SbVec3d(const SbVec3s & v) { setValue(v); }
  explicit SbVec3d(const SbVec3i32 & v) { setValue(v); }
  SbVec3d(const SbDPPlane & p0, const SbDPPlane & p1, const SbDPPlane & p2);

  SbVec3d & setValue(const double v[3]) { vec[0] = v[0]; vec[1] = v[1]; vec[2] = v[2]; return *this; }
  SbVec3d & setValue(double x, double y, double z) { vec[0] = x; vec[1] = y; vec[2] = z; return *this; }
  SbVec3d & setValue(const SbVec3d & barycentric,
                     const SbVec3d & v0,
                     const SbVec3d & v1,
                     const SbVec3d & v2);
  SbVec3d & setValue(const SbVec3f & v);
  SbVec3d & setValue(const SbVec3b & v);
  SbVec3d & setValue(const SbVec3s & v);
  SbVec3d & setValue(const SbVec3i32 & v);

  const double * getValue(void) const { return vec; }
  void getValue(double & x, double & y, double & z) const { x = vec[0]; y = vec[1]; z = vec[2]; }

  double & operator [] (const int i) { return vec[i]; }
  const double & operator [] (const int i) const { return vec[i]; }

  SbVec3d cross(const SbVec3d & v) const;
  double dot(const SbVec3d & v) const { return vec[0] * v.vec[0] + vec[1] * v.vec[1] + vec[2] * v.vec[2]; }
  SbBool equals(const SbVec3d & v, double tolerance) const;
  SbVec3d getClosestAxis(void) const;
  double length(void) const;
  double sqrLength(void) const { return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]; }
  void negate(void) { vec[0] = -vec[0]; vec[1] = -vec[1]; vec[2] = -vec[2]; }
  double normalize(void);

  SbVec3d & operator *= (double d) { vec[0] *= d; vec[1] *= d; vec[2] *= d; return *this; }
  SbVec3d & operator /= (double d) { SbDividerChk("SbVec3d::operator/=(double)", d); return operator *= (1.0 / d); }
  SbVec3d & operator += (const SbVec3d & v) { vec[0] += v[0]; vec[1] += v[1]; vec[2] += v[2]; return *this; }
  SbVec3d & operator -= (const SbVec3d & v) { vec[0] -= v[0]; vec[1] -= v[1]; vec[2] -= v[2]; return *this; }
  SbVec3d operator - (void) const { return SbVec3d(-vec[0], -vec[1], -vec[2]); }

  void print(FILE * fp) const;

private:
  double vec[3];

}; // SbVec3d

COIN_DLL_API inline SbVec3d operator * (const SbVec3d & v, double d) {
  SbVec3d val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec3d operator * (double d, const SbVec3d & v) {
  SbVec3d val(v); val *= d; return val;
}

COIN_DLL_API inline SbVec3d operator / (const SbVec3d & v, double d) {
  SbDividerChk("operator/(SbVec3d,double)", d);
  SbVec3d val(v); val /= d; return val;
}

COIN_DLL_API inline SbVec3d operator + (const SbVec3d & v1, const SbVec3d & v2) {
  SbVec3d v(v1); v += v2; return v;
}

COIN_DLL_API inline SbVec3d operator - (const SbVec3d & v1, const SbVec3d & v2) {
  SbVec3d v(v1); v -= v2; return v;
}

COIN_DLL_API inline int operator == (const SbVec3d & v1, const SbVec3d & v2) {
  return ((v1[0] == v2[0]) && (v1[1] == v2[1]) && (v1[2] == v2[2]));
}

COIN_DLL_API inline int operator != (const SbVec3d & v1, const SbVec3d & v2) {
  return !(v1 == v2);
}

#endif // !COIN_SBVEC3D_H
