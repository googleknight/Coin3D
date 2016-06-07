#ifndef COIN_SOBYTESTREAM_H
#define COIN_SOBYTESTREAM_H

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

#include <Inventor/system/inttypes.h>
#include <Inventor/SbBasic.h>

class SoNode;
class SoPath;
class SoPathList;


class COIN_DLL_API SoByteStream {

public:
  SoByteStream(void);
  ~SoByteStream();

  void convert(SoNode * node, SbBool binary = TRUE);
  void convert(SoPath * path, SbBool binary = TRUE);
  void convert(SoPathList * pl, SbBool binary = TRUE);

  void * getData(void);
  uint32_t getNumBytes(void);

  static SoPathList * unconvert(SoByteStream * stream);
  static SoPathList * unconvert(void * data, uint32_t bytesinstream);

  void copy(void * d, size_t len);
  SbBool isRawData(void) const;

private:
  // Placeholder for any data for the instance. Just added for the
  // sake of making it possible to implement this class after release
  // without breaking ABI compatibility.
  void * pimpl;
};

#endif // !COIN_SOBYTESTREAM_H
