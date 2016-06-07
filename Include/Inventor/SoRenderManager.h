#ifndef COIN_SORENDERMANAGER_H
#define COIN_SORENDERMANAGER_H

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

#include <Inventor/SbColor4f.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/actions/SoGLRenderAction.h>

class SbViewportRegion;
class SoEvent;
class SoGLRenderAction;
class SoAudioRenderAction;
class SoNode;
class SoCamera;
class SoNodeSensor;
class SoOneShotSensor;
class SoSensor;
class SoRenderManagerP;

typedef void SoRenderManagerRenderCB(void * userdata, class SoRenderManager * mgr);

class COIN_DLL_API SoRenderManager {
public:

  class COIN_DLL_API Superimposition {
  public:
    enum StateFlags {
      ZBUFFERON    = 0x0001,
      CLEARZBUFFER = 0x0002,
      AUTOREDRAW   = 0x0004,
      BACKGROUND   = 0x0008
    };

    Superimposition(SoNode * scene,
                    SbBool enabled,
                    SoRenderManager * manager,
                    uint32_t flags);
    ~Superimposition();

    void render(SoGLRenderAction * action, SbBool clearcolorbuffer = FALSE);
    void setEnabled(SbBool yes);
    int getStateFlags(void) const;
    void setTransparencyType(SoGLRenderAction::TransparencyType transparencytype);

  private:
    static void changeCB(void * data, SoSensor * sensor);
    class SuperimpositionP * pimpl;
  };

  enum RenderMode {
    AS_IS,
    WIREFRAME,
    POINTS,
    WIREFRAME_OVERLAY,
    HIDDEN_LINE,
    BOUNDING_BOX
  };

  enum StereoMode {
    MONO,
    ANAGLYPH,
    SEPARATE_OUTPUT,
    QUAD_BUFFER = SEPARATE_OUTPUT,
    INTERLEAVED_ROWS,
    INTERLEAVED_COLUMNS
  };

  enum BufferType {
    BUFFER_SINGLE,
    BUFFER_DOUBLE
  };

  enum AutoClippingStrategy {
    NO_AUTO_CLIPPING,
    FIXED_NEAR_PLANE,
    VARIABLE_NEAR_PLANE
  };

  SoRenderManager(void);
  virtual ~SoRenderManager();

  virtual void render(const SbBool clearwindow = TRUE,
                      const SbBool clearzbuffer = TRUE);

  virtual void render(SoGLRenderAction * action,
                      const SbBool initmatrices = TRUE,
                      const SbBool clearwindow = TRUE,
                      const SbBool clearzbuffer = TRUE);

  Superimposition * addSuperimposition(SoNode * scene,
                                       uint32_t flags =
                                       Superimposition::AUTOREDRAW |
                                       Superimposition::ZBUFFERON  |
                                       Superimposition::CLEARZBUFFER);

  void removeSuperimposition(Superimposition * s);

  virtual void setSceneGraph(SoNode * const sceneroot);
  virtual SoNode * getSceneGraph(void) const;

  void setCamera(SoCamera * camera);
  SoCamera * getCamera(void) const;

  void setAutoClipping(AutoClippingStrategy autoclipping);
  void attachRootSensor(SoNode * const sceneroot);
  void attachClipSensor(SoNode * const sceneroot);
  void detachRootSensor(void);
  void detachClipSensor(void);

  AutoClippingStrategy getAutoClipping(void) const;
  void setNearPlaneValue(float value);
  float getNearPlaneValue(void) const;
  void setTexturesEnabled(const SbBool onoff);
  SbBool isTexturesEnabled(void) const;
  void setDoubleBuffer(const SbBool enable);
  SbBool isDoubleBuffer(void) const;
  void setRenderMode(const RenderMode mode);
  RenderMode getRenderMode(void) const;
  void setStereoMode(const StereoMode mode);
  StereoMode getStereoMode(void) const;
  void setStereoOffset(const float offset);
  float getStereoOffset(void) const;

  void setRenderCallback(SoRenderManagerRenderCB * f,
                         void * const userData = NULL);

  SbBool isAutoRedraw(void) const;
  void setRedrawPriority(const uint32_t priority);
  uint32_t getRedrawPriority(void) const;

  static void nodesensorCB(void * data, SoSensor *);
  static void prerendercb(void * userdata, SoGLRenderAction * action);

  void reinitialize(void);
  void scheduleRedraw(void);
  void setWindowSize(const SbVec2s & newsize);
  const SbVec2s & getWindowSize(void) const;
  void setSize(const SbVec2s & newsize);
  const SbVec2s & getSize(void) const;
  void setOrigin(const SbVec2s & newOrigin);
  const SbVec2s & getOrigin(void) const;
  void setViewportRegion(const SbViewportRegion & newRegion);
  const SbViewportRegion & getViewportRegion(void) const;
  void setBackgroundColor(const SbColor4f & color);
  const SbColor4f & getBackgroundColor(void) const;
  void setBackgroundIndex(const int index);
  int getBackgroundIndex(void) const;
  void setRGBMode(const SbBool onOrOff);
  SbBool isRGBMode(void) const;
  virtual void activate(void);
  virtual void deactivate(void);

  void setAntialiasing(const SbBool smoothing, const int numPasses);
  void getAntialiasing(SbBool & smoothing, int & numPasses) const;
  void setGLRenderAction(SoGLRenderAction * const action);
  SoGLRenderAction * getGLRenderAction(void) const;
  void setAudioRenderAction(SoAudioRenderAction * const action);
  SoAudioRenderAction * getAudioRenderAction(void) const;

  static void enableRealTimeUpdate(const SbBool flag);
  static SbBool isRealTimeUpdateEnabled(void);
  static uint32_t getDefaultRedrawPriority(void);

  void addPreRenderCallback(SoRenderManagerRenderCB * cb, void * data);
  void removePreRenderCallback(SoRenderManagerRenderCB * cb, void * data);

  void addPostRenderCallback(SoRenderManagerRenderCB * cb, void * data);
  void removePostRenderCallback(SoRenderManagerRenderCB * cb, void * data);

protected:
  int isActive(void) const;
  void redraw(void);

  void renderScene(SoGLRenderAction * action,
                   SoNode * scene,
                   uint32_t clearmask);

  void actuallyRender(SoGLRenderAction * action,
                      const SbBool initmatrices = TRUE,
                      const SbBool clearwindow = TRUE,
                      const SbBool clearzbuffer = TRUE);

  void renderSingle(SoGLRenderAction * action,
                    SbBool initmatrices,
                    SbBool clearwindow,
                    SbBool clearzbuffer);

  void renderStereo(SoGLRenderAction * action,
                    SbBool initmatrices,
                    SbBool clearwindow,
                    SbBool clearzbuffer);

  void initStencilBufferForInterleavedStereo(void);
  void clearBuffers(SbBool color, SbBool depth);

private:
  SoRenderManagerP * pimpl;
  friend class SoRenderManagerP;
  friend class SoSceneManager;
  friend class Superimposition;

}; // SoRenderManager

#endif // !COIN_SORENDERMANAGER_H
