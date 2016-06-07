#ifndef COIN_SODRAGGER_H
#define COIN_SODRAGGER_H

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

#include <Inventor/nodekits/SoInteractionKit.h>
#include <Inventor/tools/SbPimplPtr.h>
#include <Inventor/fields/SoSFBool.h>
#include <Inventor/lists/SoCallbackList.h>
#include <Inventor/SbMatrix.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/SbViewVolume.h>
#include <Inventor/SbViewportRegion.h>
#ifndef COIN_INTERNAL
// For Open Inventor compatibility.
#include <Inventor/nodes/SoScale.h>
#endif // !COIN_INTERNAL
/*! \file SoDragger.h */

class SbRotation;
class SbVec2f;
class SbVec2s;
class SbViewVolume;
class SbViewportRegion;
class SoDragger;
class SoEvent;
class SoPickedPoint;
class SoDraggerP;

/*! Callback definition for draggers */
typedef void SoDraggerCB(void * data, SoDragger * dragger);

class COIN_DLL_API SoDragger : public SoInteractionKit {
  typedef SoInteractionKit inherited;

  SO_KIT_HEADER(SoDragger);
  SO_KIT_CATALOG_ENTRY_HEADER(motionMatrix);

public:
  SoSFBool isActive;

  enum ProjectorFrontSetting { FRONT, BACK, USE_PICK };

  // override these in case we decide to do some extra work later
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void rayPick(SoRayPickAction * action);
  virtual void search(SoSearchAction * action);
  virtual void write(SoWriteAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);

  void setProjectorEpsilon(const float epsilon);
  float getProjectorEpsilon(void) const;

  void addStartCallback(SoDraggerCB * func, void * data = NULL);
  void removeStartCallback(SoDraggerCB * func, void * data = NULL);
  void addMotionCallback(SoDraggerCB * func, void * data = NULL);
  void removeMotionCallback(SoDraggerCB * func, void * data = NULL);
  void addFinishCallback(SoDraggerCB * func, void * data = NULL);
  void removeFinishCallback(SoDraggerCB * func, void * data = NULL);
  void addValueChangedCallback(SoDraggerCB * func, void * data = NULL);
  void removeValueChangedCallback(SoDraggerCB * func, void * data = NULL);
  void setMinGesture(int pixels);
  int getMinGesture(void) const;
  SbBool enableValueChangedCallbacks(SbBool newval);
  const SbMatrix & getMotionMatrix(void);
  void addOtherEventCallback(SoDraggerCB * func, void * data = NULL);
  void removeOtherEventCallback(SoDraggerCB * func, void * data = NULL);
  void registerChildDragger(SoDragger * child);
  void unregisterChildDragger(SoDragger * child);
  void registerChildDraggerMovingIndependently(SoDragger * child);
  void unregisterChildDraggerMovingIndependently(SoDragger * child);
  SbMatrix getLocalToWorldMatrix(void);
  SbMatrix getWorldToLocalMatrix(void);
  SbVec3f getLocalStartingPoint(void);
  SbVec3f getWorldStartingPoint(void);
  void getPartToLocalMatrix(const SbName & partname, SbMatrix & parttolocalmatrix, SbMatrix & localtopartmatrix);
  void transformMatrixLocalToWorld(const SbMatrix & frommatrix, SbMatrix & tomatrix);
  void transformMatrixWorldToLocal(const SbMatrix & frommatrix, SbMatrix & tomatrix);
  void transformMatrixToLocalSpace(const SbMatrix & frommatrix, SbMatrix & tomatrix, const SbName & fromspacepartname);
  virtual void setMotionMatrix(const SbMatrix & newmatrix);
  void valueChanged(void);
  const SbMatrix & getStartMotionMatrix(void);
  virtual void saveStartParameters(void);
  const SoPath * getPickPath(void) const;
  const SoEvent * getEvent(void) const;
  SoPath * createPathToThis(void);
  const SoPath * getSurrogatePartPickedOwner(void) const;
  const SbName & getSurrogatePartPickedName(void) const;
  const SoPath * getSurrogatePartPickedPath(void) const;
  void setStartingPoint(const SoPickedPoint * newpoint);
  void setStartingPoint(const SbVec3f & newpoint);
  const SbViewVolume & getViewVolume(void);
  void setViewVolume(const SbViewVolume & vol);
  const SbViewportRegion & getViewportRegion(void);
  void setViewportRegion(const SbViewportRegion & reg);
  SoHandleEventAction * getHandleEventAction(void) const;
  void setHandleEventAction(SoHandleEventAction * newAction);
  void setTempPathToThis(const SoPath * somethingclose);
  virtual void grabEventsSetup(void);
  virtual void grabEventsCleanup(void);
  void workFieldsIntoTransform(SbMatrix & mtx);
  void setFrontOnProjector(ProjectorFrontSetting newval);
  ProjectorFrontSetting getFrontOnProjector(void) const;

  static void setMinScale(float newminscale);
  static float getMinScale(void);
  static void workValuesIntoTransform(SbMatrix & mtx, const SbVec3f * translationptr, const SbRotation * rotationptr, const SbVec3f * scalefactorptr, const SbRotation * scaleorientationptr, const SbVec3f * centerptr);
  static void getTransformFast(SbMatrix & mtx, SbVec3f & translation, SbRotation & rotation, SbVec3f & scalefactor, SbRotation & scaleorientation, const SbVec3f & center);
  static void getTransformFast(SbMatrix & mtx, SbVec3f & translation, SbRotation & rotation, SbVec3f & scalefactor, SbRotation & scaleorientation);
  static SbMatrix appendTranslation(const SbMatrix & mtx, const SbVec3f & translation, const SbMatrix * conversion = NULL);
  static SbMatrix appendScale(const SbMatrix & mtx, const SbVec3f & scale, const SbVec3f & scalecenter, const SbMatrix * conversion = NULL);
  static SbMatrix appendRotation(const SbMatrix & mtx, const SbRotation & rot, const SbVec3f & rotcenter, const SbMatrix * conversion = NULL);
  static void initClass(void);
  static void initClasses(void);

protected:
  SoDragger(void);
  virtual ~SoDragger(void);

  SbVec2f getNormalizedLocaterPosition(void);
  SbVec2s getLocaterPosition(void);
  SbVec2s getStartLocaterPosition(void) const;
  void setStartLocaterPosition(SbVec2s p);
  SbBool isAdequateConstraintMotion(void);
  virtual SbBool shouldGrabBasedOnSurrogate(const SoPath * pickpath, const SoPath * surrogatepath);
  void setCameraInfo(SoAction * action);
  virtual void handleEvent(SoHandleEventAction * ha);
  void transferMotion(SoDragger * child);
  void setIgnoreInBbox(SbBool newval);
  SbBool isIgnoreInBbox(void);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  void setActiveChildDragger(SoDragger * newchilddragger);
  SoDragger * getActiveChildDragger(void) const;
  virtual void setDefaultOnNonWritingFields(void);

  static void childTransferMotionAndValueChangedCB(void *, SoDragger *);
  static void childValueChangedCB(void *, SoDragger *);
  static void childStartCB(void *, SoDragger *);
  static void childMotionCB(void *, SoDragger *);
  static void childFinishCB(void *, SoDragger *);
  static void childOtherEventCB(void *, SoDragger *);

  // This method is not present in Open Inventor. It was moved from
  // being a private method to a protected method in Coin to make it
  // possible to construct draggers which can handle Motion3 events.
  void updateDraggerCache(const SoPath * path);

private:
  void updateElements(class SoState * state);
  SbBool isPicked(SoPath * path);
  void eventHandled(const SoEvent * event, SoHandleEventAction * action);
  static float minscale;
  
private:
  SbPimplPtr<SoDraggerP> pimpl;

  // NOT IMPLEMENTED:
  SoDragger(const SoDragger & rhs);
  SoDragger & operator = (const SoDragger & rhs);
}; // SoDragger

#endif // !COIN_SODRAGGER_H
