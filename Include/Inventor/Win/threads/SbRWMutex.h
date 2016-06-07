#ifndef COIN_SBRWMUTEX_H
#define COIN_SBRWMUTEX_H

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

#include <Inventor/C/threads/rwmutex.h>

class SbRWMutex {
public:
  enum Precedence {
    READ_PRECEDENCE,
    WRITE_PRECEDENCE
  };

  SbRWMutex(Precedence policy) {
    this->rwmutex = cc_rwmutex_construct_etc(
      (policy == WRITE_PRECEDENCE)? CC_WRITE_PRECEDENCE : CC_READ_PRECEDENCE);
  }
  ~SbRWMutex(void) { cc_rwmutex_destruct(this->rwmutex); }

  int writeLock(void) { 
    return cc_rwmutex_write_lock(this->rwmutex) == CC_OK ? 0 : 1; 
  }
  SbBool tryWriteLock(void) { 
    return cc_rwmutex_write_try_lock(this->rwmutex) == CC_OK; 
  }
  int writeUnlock(void) { 
    return cc_rwmutex_write_unlock(this->rwmutex) == CC_OK ? 0 : 1; 
  }
  
  int readLock(void) { 
    return cc_rwmutex_read_lock(this->rwmutex) == CC_OK ? 0 : 1; 
  }
  int tryReadLock(void) { 
    return cc_rwmutex_read_try_lock(this->rwmutex) == CC_OK; 
  }
  int readUnlock(void) { 
    return cc_rwmutex_read_unlock(this->rwmutex) == CC_OK ? 0 : 1; 
  }

private:
  cc_rwmutex * rwmutex;
};

#endif // !COIN_SBRWMUTEX_H
