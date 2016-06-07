#ifndef COIN_SBLINEAR_H
#define COIN_SBLINEAR_H

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

#ifdef COIN_INTERNAL
/* Detect erroneous include statements in library code. Application
   programmers can ignore this. */
#error "Do not include SbLinear.h in internal library code."
#endif // COIN_INTERNAL

/*
 * Note to application programmers: include this header file in your
 * application code instead of the specific class header files below
 * if you want to be sourcecode compatible with the SGI and TGS
 * Inventor implementations.
 *
 * (All the class definitions below are placed in the SbLinear.h file
 * in SGI and TGS Inventor, and the following header files are not
 * part of the SDK.)
 */

#include <Inventor/SbVec2f.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/SbVec3s.h>
#include <Inventor/SbVec4f.h>
#include <Inventor/SbSphere.h>
#include <Inventor/SbRotation.h>
#include <Inventor/SbLine.h>
#include <Inventor/SbCylinder.h>
#include <Inventor/SbPlane.h>
#include <Inventor/SbMatrix.h>
#include <Inventor/SbRotation.h>
#include <Inventor/SbPlane.h>
#include <Inventor/SbViewVolume.h>

#endif // !COIN_SBLINEAR_H
