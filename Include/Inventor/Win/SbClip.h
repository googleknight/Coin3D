#ifndef COIN_SBCLIP_H
#define COIN_SBCLIP_H
 
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

#include <Inventor/lists/SbList.h>
#include <Inventor/SbVec3f.h>
#include <stddef.h>

class SbPlane;
class SbVec2f;

typedef void * SbClipCallback(const SbVec3f & v0, void * vdata0, 
                              const SbVec3f & v1, void * vdata1,
                              const SbVec3f & newvertex,
                              void * userdata);

class COIN_DLL_API SbClip {
public:
  SbClip(SbClipCallback * callback = NULL, void * userdata = NULL);
  
  void addVertex(const SbVec3f &v, void * vdata = NULL);  
  void reset(void);

  void clip(const SbPlane & plane);

  int getNumVertices(void) const;
  void getVertex(const int idx, SbVec3f & v, void ** vdata = NULL) const; 
  void * getVertexData(const int idx) const;
  
private:
  class SbClipData {
  public:
    SbClipData(void) {}
    SbClipData(const SbVec3f & v, void * data) 
      : vertex(v),
        data(data) {}
  public:
    void get(SbVec3f &v, void *& dataref) {
      v = this->vertex;
      dataref = this->data;
    }

    SbVec3f vertex;
    void * data;
  };

  SbClipCallback * callback;
  void * cbdata;
  SbList <SbClipData> array[2];
  int curr;
  void outputVertex(const SbVec3f &v, void * data);
};


#endif // !COIN_SBCLIP_H
