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

#ifndef COIN_SOCALCULATOR_H
#define COIN_SOCALCULATOR_H

#include <Inventor/engines/SoSubEngine.h>
#include <Inventor/engines/SoEngineOutput.h>
#include <Inventor/fields/SoMFFloat.h>
#include <Inventor/fields/SoMFVec3f.h>
#include <Inventor/fields/SoMFString.h>
#include <Inventor/lists/SbList.h>

class SoCalculatorP;

class COIN_DLL_API SoCalculator : public SoEngine {
  typedef SoEngine inherited;

  SO_ENGINE_HEADER(SoCalculator);

public:
  // inputs
  SoMFFloat a, b, c, d, e, f, g, h;
  SoMFVec3f A, B, C, D, E, F, G, H;
  SoMFString expression;

  // outputs
  SoEngineOutput oa, ob, oc, od; // (SoMFFloat)
  SoEngineOutput oA, oB, oC, oD; // (SoMFVec3f)

  SoCalculator(void);

  static void initClass(void);

protected:
  virtual ~SoCalculator(void);

  virtual void inputChanged(SoField * which);

private:
  virtual void evaluate(void);

  static void readfieldcb(const char *name, float *data, void *cbdata);
  static void writefieldcb(const char *name, float *data, int comp, void *cbdata);

  void evaluateExpression(struct so_eval_node *node, const int fieldidx);
  void findUsed(struct so_eval_node *node, char *inused, char *outused);

  SoCalculatorP * pimpl;
};

#endif // !COIN_SOCALCULATOR_H
