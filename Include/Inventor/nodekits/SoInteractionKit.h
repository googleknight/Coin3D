#ifndef COIN_SOINTERACTIONKIT_H
#define COIN_SOINTERACTIONKIT_H

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

#include <Inventor/nodekits/SoSubKit.h>
#include <Inventor/nodekits/SoBaseKit.h>
#include <Inventor/fields/SoSFEnum.h>

#ifdef COIN_INTERNAL
class SoFieldSensor;
#else // !COIN_INTERNAL
// Include this header file for better Open Inventor compatibility.
#include <Inventor/sensors/SoFieldSensor.h>
#endif // !COIN_INTERNAL

class SoSensor;
class SoSeparator;

class COIN_DLL_API SoInteractionKit : public SoBaseKit {
  typedef SoBaseKit inherited;

  SO_KIT_HEADER(SoInteractionKit);

  SO_KIT_CATALOG_ENTRY_HEADER(geomSeparator);
  SO_KIT_CATALOG_ENTRY_HEADER(topSeparator);

public:
  SoSFEnum renderCaching;
  SoSFEnum boundingBoxCaching;
  SoSFEnum renderCulling;
  SoSFEnum pickCulling;

public:
  SoInteractionKit(void);
  static void initClass(void);

  enum CacheEnabled { OFF, ON, AUTO };

  virtual SbBool setPartAsPath(const SbName &partname,
                               SoPath *path);
  virtual SbBool setPartAsDefault(const SbName &partname,
                                  SoNode *node,
                                  SbBool onlyifdefault = TRUE);
  virtual SbBool setPartAsDefault(const SbName &partname,
                                  const SbName &nodename,
                                  SbBool onlyifdefault = TRUE);
  SbBool isPathSurrogateInMySubgraph(const SoPath *path,
                                     SoPath *&pathToOwner,
                                     SbName  &surrogatename,
                                     SoPath *&surrogatepath,
                                     SbBool fillargs = TRUE);
  SbBool isPathSurrogateInMySubgraph(const SoPath *path);
  static void setSwitchValue(SoNode *node, const int newVal);
  virtual SbBool setPart(const SbName & partname, SoNode * from);

protected:
  virtual ~SoInteractionKit();
  virtual void copyContents(const SoFieldContainer *fromFC,
                            SbBool copyConnections);

  virtual SbBool setPart(const int partNum, SoNode *node);
  virtual SbBool readInstance(SoInput *in, unsigned short flags);
  static void readDefaultParts(const char *fileName,
                               const char defaultBuffer[],
                               int defBufSize);
  virtual SbBool setAnyPartAsDefault(const SbName &partname,
                                     SoNode *node,
                                     SbBool anypart = TRUE,
                                     SbBool onlyifdefault = TRUE);
  virtual SbBool setAnyPartAsDefault(const SbName &partname,
                                     const SbName &nodename,
                                     SbBool anypart = TRUE,
                                     SbBool onlyifdefault = TRUE);
  SbBool setAnySurrogatePath(const SbName &name,
                             SoPath *path,
                             SbBool leafcheck = FALSE,
                             SbBool publiccheck = FALSE);
  virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);
  virtual void setDefaultOnNonWritingFields();

  SoFieldSensor *fieldSensor;
  static void fieldSensorCB(void *, SoSensor *);
  SoSeparator *oldTopSep;

  void connectSeparatorFields( SoSeparator *dest, SbBool onOff );

private:
  class SoInteractionKitP * pimpl;
  friend class SoInteractionKitP;
};

#endif // !COIN_SOINTERACTIONKIT_H
