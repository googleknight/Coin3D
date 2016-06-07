// src\Inventor\Win\viewers\SoWinConstrainedViewer.h.  Generated from SoGuiConstrainedViewer.h.in by configure.

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

#ifndef SOWIN_CONSTRAINEDVIEWER_H
#define SOWIN_CONSTRAINEDVIEWER_H

#include <Inventor/Win/viewers/SoWinFullViewer.h>

// ************************************************************************

class SOWIN_DLL_API SoWinConstrainedViewer : public SoWinFullViewer {
  SOWIN_OBJECT_ABSTRACT_HEADER(SoWinConstrainedViewer, SoWinFullViewer);

public:
  void setUpDirection(const SbVec3f & dir);
  const SbVec3f & getUpDirection(void) const;

  virtual void setCamera(SoCamera * newcam);
  virtual void saveHomePosition(void);
  virtual void resetToHomePosition(void);

protected:
  SoWinConstrainedViewer(HWND parent,
                           const char * const name,
                           SbBool embed,
                           SoWinFullViewer::BuildFlag flag, 
                           SoWinViewer::Type type, 
                           SbBool build);

  ~SoWinConstrainedViewer();

  virtual void tiltCamera(float delta);
  virtual void bottomWheelMotion(float value);
  virtual void leftWheelMotion(float value);

  virtual void changeCameraValues(SoCamera * camera);
  void findUpDirection(SbVec2s mouselocation);
  void checkForCameraUpConstrain(void);

private:
  class SoWinConstrainedViewerP * pimpl;
};

// ************************************************************************

#endif // ! SOWIN_CONSTRAINEDVIEWER_H
