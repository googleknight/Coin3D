#ifndef COIN_SBIMAGE_H
#define COIN_SBIMAGE_H

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

#include <Inventor/SbVec2s.h>
#include <Inventor/SbVec3s.h>
#include <Inventor/SbString.h>
#include <stddef.h> // for NULL

class SbImage;

typedef SbBool SbImageScheduleReadCB(const SbString &, SbImage *, void *);
typedef SbBool SbImageReadImageCB(const SbString &, SbImage *, void *);

class COIN_DLL_API SbImage {
public:
  SbImage(void);
  SbImage(const unsigned char * bytes,
          const SbVec2s & size, const int bytesperpixel);
  SbImage(const unsigned char * bytes,
          const SbVec3s & size, const int bytesperpixel);
  ~SbImage();

  void setValue(const SbVec2s & size, const int bytesperpixel,
                const unsigned char * bytes);
  void setValue(const SbVec3s & size, const int bytesperpixel,
                const unsigned char * bytes);
  void setValuePtr(const SbVec2s & size, const int bytesperpixel,
                   const unsigned char * bytes);
  void setValuePtr(const SbVec3s & size, const int bytesperpixel,
                   const unsigned char * bytes);
  unsigned char * getValue(SbVec2s & size, int & bytesperpixel) const;
  unsigned char * getValue(SbVec3s & size, int & bytesperpixel) const;
  SbVec3s getSize(void) const;

  SbBool readFile(const SbString & filename,
                  const SbString * const * searchdirectories = NULL,
                  const int numdirectories = 0);

  int operator==(const SbImage & image) const;
  int operator!=(const SbImage & image) const {
    return ! operator == (image);
  }
  SbImage & operator=(const SbImage & image);

  static void addReadImageCB(SbImageReadImageCB * cb, void * closure);
  static void removeReadImageCB(SbImageReadImageCB * cb, void * closure);

  static SbString searchForFile(const SbString & basename,
                                const SbString * const * dirlist,
                                const int numdirs);

  SbBool hasData(void) const;

private:

  class SbImageP * pimpl;
  
public:

  // methods for delaying image loading until it is actually needed.
  void readLock(void) const;
  void readUnlock(void) const;

  SbBool scheduleReadFile(SbImageScheduleReadCB * cb,
                          void * closure,
                          const SbString & filename,
                          const SbString * const * searchdirectories = NULL,
                          const int numdirectories = 0);
};

#endif // !COIN_SBIMAGE_H
