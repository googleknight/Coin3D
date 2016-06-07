#ifndef COIN_SBLINEPROJECTOR_H
#define COIN_SBLINEPROJECTOR_H

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

#include <Inventor/projectors/SbProjector.h>

#include <Inventor/SbVec3f.h>
#include <Inventor/SbLine.h>

class COIN_DLL_API SbLineProjector : public SbProjector {
  typedef SbProjector inherited;

public:
  SbLineProjector(void);
  virtual SbProjector * copy(void) const;

  virtual SbVec3f project(const SbVec2f & point);
  virtual SbBool tryProject(const SbVec2f & point, const float epsilon, SbVec3f & result);

  void setLine(const SbLine & line);
  const SbLine & getLine(void) const;
  virtual SbVec3f getVector(const SbVec2f & viewpos1,
                            const SbVec2f & viewpos2);
  virtual SbVec3f getVector(const SbVec2f & viewpos);
  void setStartPosition(const SbVec2f & viewpos);
  void setStartPosition(const SbVec3f & point);

protected:
  SbLine line;
  SbVec3f lastPoint;
};

#endif // !COIN_SBLINEPROJECTOR_H
