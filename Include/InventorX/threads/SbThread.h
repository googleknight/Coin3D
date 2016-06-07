#ifndef COIN_SBTHREAD_H
#define COIN_SBTHREAD_H

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

#include <Inventor/SbBasic.h>
#include <Inventor/C/threads/thread.h>

class SbThread {
public:
  static SbThread * create(void *(*func)(void *), void * closure) {
    return new SbThread(cc_thread_construct(func, closure));
  }
  static void destroy(SbThread * thread) {
    cc_thread_destruct(thread->thread);
    delete thread;
  }

  SbBool join(void ** retval = 0L) {
    return cc_thread_join(this->thread, retval) == CC_OK;
  }
  static SbBool join(SbThread * thread, void ** retval = 0L) {
    return cc_thread_join(thread->thread, retval) == CC_OK;
  }

protected:
  SbThread(cc_thread * thrd) { this->thread = thrd; }
  ~SbThread(void) {}

private:
  cc_thread * thread;
};

#endif // !COIN_SBTHREAD_H
