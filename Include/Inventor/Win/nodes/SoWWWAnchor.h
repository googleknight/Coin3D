#ifndef COIN_SOWWWANCHOR_H
#define COIN_SOWWWANCHOR_H

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

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoLocateHighlight.h>
#include <Inventor/fields/SoSFString.h>
#include <Inventor/fields/SoSFEnum.h>

class SoWWWAnchor;
class SoWWWAnchorP;

typedef void SoWWWAnchorCB(const SbString & url, void * data,
                           SoWWWAnchor * node);

// *************************************************************************

class COIN_DLL_API SoWWWAnchor : public SoLocateHighlight {
  typedef SoLocateHighlight inherited;

  SO_NODE_HEADER(SoWWWAnchor);

public:
  static void initClass(void);
  SoWWWAnchor(void);

  enum Mapping {
    NONE, POINT
  };

  SoSFString name;
  SoSFString description;
  SoSFEnum map;

  void setFullURLName(const SbString & url);
  const SbString & getFullURLName(void);

  virtual void handleEvent(SoHandleEventAction * action);

  static void setFetchURLCallBack(SoWWWAnchorCB * f, void * userData);
  static void setHighlightURLCallBack(SoWWWAnchorCB * f, void * userData);

protected:
  virtual ~SoWWWAnchor();
  virtual void redrawHighlighted(SoAction * act, SbBool isNowHighlighting);

private:
  SoWWWAnchorP * pimpl;
};

#endif // !COIN_SOWWWANCHOR_H
