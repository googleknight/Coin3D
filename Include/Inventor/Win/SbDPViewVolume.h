#ifndef COIN_SBDPVIEWVOLUME_H
#define COIN_SBDPVIEWVOLUME_H

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
#include <Inventor/SbVec3d.h>

class SbBox3f;
class SbDPLine;
class SbDPMatrix;
class SbPlane;
class SbDPRotation;
class SbVec2d;
class SbViewVolume;

class COIN_DLL_API SbDPViewVolume {
public:
  enum ProjectionType { ORTHOGRAPHIC = 0, PERSPECTIVE = 1 };

public:
  SbDPViewVolume(void);
  ~SbDPViewVolume(void);
  void getMatrices(SbDPMatrix& affine, SbDPMatrix& proj) const;
  SbDPMatrix getMatrix(void) const;
  SbDPMatrix getCameraSpaceMatrix(void) const;
  void projectPointToLine(const SbVec2d& pt, SbDPLine& line) const;
  void projectPointToLine(const SbVec2d& pt,
                          SbVec3d& line0, SbVec3d& line1) const;
  void projectToScreen(const SbVec3d& src, SbVec3d& dst) const;
  SbPlane getPlane(const double distFromEye) const;
  SbVec3d getSightPoint(const double distFromEye) const;
  SbVec3d getPlanePoint(const double distFromEye,
                        const SbVec2d& normPoint) const;
  SbDPRotation getAlignRotation(SbBool rightAngleOnly = FALSE) const;
  double getWorldToScreenScale(const SbVec3d& worldCenter,
                              double normRadius) const;
  SbVec2d projectBox(const SbBox3f& box) const;
  SbDPViewVolume narrow(double left, double bottom,
                      double right, double top) const;
  SbDPViewVolume narrow(const SbBox3f& box) const;
  void ortho(double left, double right,
             double bottom, double top,
             double nearval, double farval);
  void perspective(double fovy, double aspect,
                   double nearval, double farval);
  void frustum(double left, double right,
               double bottom, double top,
               double nearval, double farval);
  void rotateCamera(const SbDPRotation& q);
  void translateCamera(const SbVec3d& v);
  SbVec3d zVector(void) const;
  SbDPViewVolume zNarrow(double nearval, double farval) const;
  void scale(double factor);
  void scaleWidth(double ratio);
  void scaleHeight(double ratio);
  ProjectionType getProjectionType(void) const;
  const SbVec3d& getProjectionPoint(void) const;
  const SbVec3d& getProjectionDirection(void) const;
  double getNearDist(void) const;
  double getWidth(void) const;
  double getHeight(void) const;
  double getDepth(void) const;

  void print(FILE * fp) const;
  void getViewVolumePlanes(SbPlane planes[6]) const;
  void transform(const SbDPMatrix &matrix);
  SbVec3d getViewUp(void) const;

  void copyValues(SbViewVolume & vv);

private:

  ProjectionType type;
  SbVec3d projPoint;
  SbVec3d projDir;
  double nearDist;
  double nearToFar;
  SbVec3d llf;
  SbVec3d lrf;
  SbVec3d ulf;

  void getPlaneRectangle(const double depth, SbVec3d & lowerleft,
                         SbVec3d & lowerright, SbVec3d & upperleft,
                         SbVec3d & upperright) const;
};

#endif // !COIN_SBDPVIEWVOLUME_H
