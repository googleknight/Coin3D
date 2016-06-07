#ifndef COIN_SOTEXTUREIMAGEELEMENT_H
#define COIN_SOTEXTUREIMAGEELEMENT_H

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

#include <Inventor/elements/SoReplacedElement.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/SbVec3s.h>
#include <Inventor/SbColor.h>

class SoState;

class COIN_DLL_API SoTextureImageElement : public SoReplacedElement {
  typedef SoReplacedElement inherited;

  SO_ELEMENT_HEADER(SoTextureImageElement);
public:
  static void initClass(void);
protected:
  virtual ~SoTextureImageElement();

public:
  enum Model {
    // These should match GL_BLEND, GL_MODULATE and GL_DECAL for SGI
    // Inventor compatibility (these are also used by SoTexture2 and
    // SoTexture3).
    BLEND = 0x0be2,
    MODULATE = 0x2100,
    DECAL = 0x2101,
    REPLACE = 0x1E01 // must match GL_REPLACE
  };

  enum Wrap {
    // These should match GL_CLAMP and GL_REPEAT for SGI Inventor
    // compatibility (these are also used by SoTexture2 and
    // SoTexture3).
    CLAMP = 0x2900,
    REPEAT = 0x2901,
    CLAMP_TO_BORDER = 0x812D
  };

  virtual void init(SoState * state);

  static void setDefault(SoState * const state, SoNode * const node);

  static void set(SoState * const state, SoNode * const node,
                  const SbVec2s & size, const int numComponents,
                  const unsigned char * bytes,
                  const int wrapS, const int wrapT,
                  const int model, const SbColor & blendColor);
  static void set(SoState * const state, SoNode * const node,
                  const SbVec3s & size, const int numComponents,
                  const unsigned char * bytes,
                  const int wrapS, const int wrapT, const int wrapR,
                  const int model, const SbColor & blendColor);

  static void set(SoState * const state, SoNode * const node,
                  const SbVec2s & size, const int numComponents,
                  const unsigned char * bytes,
                  const Wrap wrapS, const Wrap wrapT,
                  const Model model, const SbColor & blendColor);
  static void set(SoState * const state, SoNode * const node,
                  const SbVec3s & size, const int numComponents,
                  const unsigned char * bytes,
                  const Wrap wrapS, const Wrap wrapT, const Wrap wrapR,
                  const Model model, const SbColor & blendColor);

  static const unsigned char *get(SoState * const state,
                                  SbVec2s & size,
                                  int & numComponents,
                                  Wrap & wrapS,
                                  Wrap & wrapT,
                                  Model & model,
                                  SbColor & blendColor);
  static const unsigned char *get(SoState * const state,
                                  SbVec3s & size,
                                  int & numComponents,
                                  Wrap & wrapS,
                                  Wrap & wrapT,
                                  Wrap & wrapR,
                                  Model & model,
                                  SbColor & blendColor);

  static const unsigned char *get(SoState * const state,
                                  SbVec2s & size,
                                  int & numComponents,
                                  int & wrapS,
                                  int & wrapT,
                                  int & model,
                                  SbColor & blendColor);
  static const unsigned char *get(SoState * const state,
                                  SbVec3s & size,
                                  int & numComponents,
                                  int & wrapS,
                                  int & wrapT,
                                  int & wrapR,
                                  int & model,
                                  SbColor & blendColor);

  static const SbColor &getBlendColor(SoState * const state);
  static const unsigned char *getImage(SoState * const state,
                                       SbVec2s &size,
                                       int &numComponents);
  static const unsigned char *getImage(SoState * const state,
                                       SbVec3s &size,
                                       int &numComponents);
  static Model getModel(SoState * const state);
  static Wrap getWrapS(SoState * const state);
  static Wrap getWrapT(SoState * const state);
  static Wrap getWrapR(SoState * const state);

  static SbBool containsTransparency(SoState * const state);

  static const unsigned char *getDefault(SbVec2s & size, int & numComponents);
  static const unsigned char *getDefault(SbVec3s & size, int & numComponents);

protected:
  virtual void setElt(const SbVec2s & size, const int numComponents,
                      const unsigned char * bytes,
                      const Wrap wrapS, const Wrap wrapT,
                      const Model model, const SbColor & blendColor);
  virtual void setElt(const SbVec3s & size, const int numComponents,
                      const unsigned char * bytes,
                      const Wrap wrapS, const Wrap wrapT, const Wrap wrapR,
                      const Model model, const SbColor & blendColor);

  virtual SbBool hasTransparency(void) const;

  SbVec3s size;
  int numComponents;
  const unsigned char *bytes;
  Wrap wrapS, wrapT, wrapR;
  Model model;
  SbColor blendColor;

private:
  void setDefaultValues(void);

};

#endif // !COIN_SOTEXTUREIMAGEELEMENT_H
