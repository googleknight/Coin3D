#ifndef CC_THREADCOMMON_H
#define CC_THREADCOMMON_H

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

#include <Inventor/C/basic.h>  /* COIN_DLL_API */

/* ********************************************************************** */

/* Implementation note: it is important that this header file can be
   included even when Coin was built with no threads support.

   (This simplifies client code, as we get away with far less #ifdef
   HAVE_THREADS wrapping.) */

/* ********************************************************************** */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ********************************************************************** */

  typedef struct cc_sched cc_sched;
  typedef struct cc_wpool cc_wpool;
  typedef struct cc_worker cc_worker;
  typedef struct cc_thread cc_thread;
  typedef struct cc_mutex cc_mutex;
  typedef struct cc_rwmutex cc_rwmutex;
  typedef struct cc_condvar cc_condvar;
  typedef struct cc_storage cc_storage;
  typedef struct cc_fifo cc_fifo;
  typedef struct cc_barrier cc_barrier;
  typedef struct cc_recmutex cc_recmutex;

  /* used by rwmutex - read_precedence is default */
  enum cc_precedence {
    CC_READ_PRECEDENCE,
    CC_WRITE_PRECEDENCE
  };

  enum cc_threads_implementation {
    CC_NO_THREADS = -1,
    CC_PTHREAD    = 0,
    CC_W32THREAD
  };

  enum cc_retval {
    CC_ERROR = 0,
    CC_OK = 1,
    CC_TIMEOUT,
    CC_BUSY
  };

  typedef enum cc_precedence cc_precedence;
  typedef enum cc_threads_implementation cc_threads_implementation;
  typedef enum cc_retval cc_retval;

  /* ********************************************************************** */

  COIN_DLL_API int cc_thread_implementation(void);

  /* ********************************************************************** */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ! CC_THREADCOMMON_H */
