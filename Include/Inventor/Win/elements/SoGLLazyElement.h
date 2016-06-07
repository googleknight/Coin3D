#ifndef COIN_SOGLLAZYELEMENT_H
#define COIN_SOGLLAZYELEMENT_H

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

#include <Inventor/elements/SoLazyElement.h>
#include <Inventor/C/glue/gl.h>

class SoGLRenderCache;
class SoGLLazyElementP;
class SoVBO;

class COIN_DLL_API SoGLLazyElement : public SoLazyElement {
  typedef SoLazyElement inherited;

  SO_ELEMENT_HEADER(SoGLLazyElement);

public:
  static void initClass();
protected:
  ~SoGLLazyElement();
public:

  virtual void init(SoState *state);
  virtual void push(SoState *state);
  virtual void pop(SoState *state, const SoElement * prevtopelement);

  static void sendAllMaterial(SoState * state);
  static void sendNoMaterial(SoState * state);
  static void sendOnlyDiffuseColor(SoState * state);
  static void sendLightModel(SoState * state, const int32_t model);
  static void sendPackedDiffuse(SoState * state, const uint32_t diffuse);
  static void sendFlatshading(SoState * state, const SbBool onoff);
  static void sendVertexOrdering(SoState * state, const VertexOrdering ordering);
  static void sendTwosideLighting(SoState * state, const SbBool onoff);
  static void sendBackfaceCulling(SoState * state, const SbBool onoff);

  void sendDiffuseByIndex(const int index) const;
  static SbBool isColorIndex(SoState *state);
  static SoGLLazyElement * getInstance(const SoState *state);
  void send(const SoState *state, uint32_t mask) const;

  void sendVPPacked(SoState* state, const unsigned char* pcolor);

  void reset(SoState* state, uint32_t bitmask) const;

  typedef struct COIN_DLL_API {
    uint32_t cachebitmask;
    uint32_t diffuse;
    SbColor ambient;
    SbColor emissive;
    SbColor specular;
    float shininess;
    int32_t lightmodel;
    int32_t blending;
    int32_t blend_sfactor;
    int32_t blend_dfactor;
    int32_t alpha_blend_sfactor;
    int32_t alpha_blend_dfactor;
    int32_t stipplenum;
    int32_t vertexordering;
    int32_t culling;
    int32_t twoside;
    int32_t flatshading;
    int32_t glimageid;
    int32_t alphatest;
    uint32_t diffusenodeid;
    uint32_t transpnodeid;
    uint32_t reserved[4];
  } GLState;

  virtual void setDiffuseElt(SoNode*,  int32_t numcolors,
                             const SbColor * colors, SoColorPacker * packer);
  virtual void setPackedElt(SoNode * node, int32_t numcolors,
                            const uint32_t * colors, const SbBool packedtransparency);
  virtual void setColorIndexElt(SoNode * node, int32_t numindices,
                                const int32_t * indices);
  virtual void setTranspElt(SoNode * node, int32_t numtransp,
                            const float * transp, SoColorPacker * packer);

  virtual void setTranspTypeElt(int32_t type);
  virtual void setAmbientElt(const SbColor* color);
  virtual void setEmissiveElt(const SbColor* color);
  virtual void setSpecularElt(const SbColor* color);
  virtual void setShininessElt(float value);
  virtual void setColorMaterialElt(SbBool value);
  virtual void enableBlendingElt(int sfactor, int dfactor, int alpha_sfactor, int alpha_dfactor);
  virtual void disableBlendingElt(void);
  virtual void setLightModelElt(SoState *state, int32_t model);
  virtual void setMaterialElt(SoNode * node, uint32_t bitmask,
                              SoColorPacker * packer,
                              const SbColor * diffuse, const int numdiffuse,
                              const float * transp, const int numtransp,
                              const SbColor & ambient,
                              const SbColor & emissive,
                              const SbColor & specular,
                              const float shininess,
                              const SbBool istransparent);
  virtual void setVertexOrderingElt(VertexOrdering ordering);
  virtual void setBackfaceCullingElt(SbBool onoff);
  virtual void setTwosideLightingElt(SbBool onoff);
  virtual void setShadeModelElt(SbBool flatshading);
  virtual void setGLImageIdElt(uint32_t glimageid, SbBool alphatest);
  virtual void setAlphaTestElt(SbBool onoff);

  static void beginCaching(SoState * state,
                           SoGLLazyElement::GLState * prestate,
                           SoGLLazyElement::GLState * poststate);
  static void endCaching(SoState * state);

  static SbBool preCacheCall(SoState * state, SoGLLazyElement::GLState * prestate);
  static void postCacheCall(SoState * state, SoGLLazyElement::GLState * poststate);

  static void mergeCacheInfo(SoState * state,
                             SoGLLazyElement::GLState * childprestate,
                             SoGLLazyElement::GLState * childpoststate);

  void updateColorVBO(SoVBO * vbo);

protected:
  virtual void lazyDidSet(uint32_t mask);
  virtual void lazyDidntSet(uint32_t mask);

private:
  void sendPackedDiffuse(const uint32_t diffuse) const;
  void sendAmbient(const SbColor & color) const;
  void sendEmissive(const SbColor & color) const;
  void sendSpecular(const SbColor & specular) const;
  void sendShininess(const float shininess) const;
  void sendTransparency(const int stipplenum) const;
  void enableBlending(const int sfactor, const int dfactor) const;
  void enableSeparateBlending(const cc_glglue * glue,
                              const int sfactor, const int dfactor,
                              const int alpha_sfactor, const int alpha_dfactor) const;
  void disableBlending(void) const;

  void sendLightModel(const int32_t model) const;
  void sendFlatshading(const SbBool onoff) const;
  void sendVertexOrdering(const VertexOrdering ordering) const;
  void sendTwosideLighting(const SbBool onoff) const;
  void sendBackfaceCulling(const SbBool onoff) const;
  void sendGLImage(const uint32_t glimageid) const;
  void sendAlphaTest(const SbBool onoff) const;
  void initGL(void);
  void packColors(SoColorPacker * packer) const;

  uint32_t didsetbitmask;
  uint32_t didntsetbitmask;
  uint32_t cachebitmask;
  uint32_t opencacheflags;

  GLState glstate;
  GLState * postcachestate;
  GLState * precachestate;
  SbBool colorindex;
  SoColorPacker * colorpacker;
  const uint32_t * packedpointer;
  uint32_t transpmask;
  SoState * state;
  SoGLLazyElementP * pimpl; // for future use
};

#endif // !COIN_SOGLLAZYELEMENT_H
