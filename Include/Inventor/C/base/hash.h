#ifndef CC_HASH_H
#define CC_HASH_H

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

/* This interface is OBSOLETE -- please do not use it in your
   application code, as it will be removed from Coin 3 and onwards. */

#include <stdlib.h>
#include <Inventor/C/basic.h>

#if defined(COIN_INTERNAL) && !defined(COIN_ALLOW_CC_HASH)
#error prefer cc_dict over cc_hash for internal code
#endif /* COIN_INTERNAL */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  typedef uintptr_t cc_hash_key;
  typedef struct cc_hash cc_hash;
  typedef cc_hash_key cc_hash_func(const cc_hash_key key);
  typedef void cc_hash_apply_func(cc_hash_key key, void * val, void * closure);

  COIN_DLL_API cc_hash * cc_hash_construct(unsigned int size, float loadfactor);
  COIN_DLL_API void cc_hash_destruct(cc_hash * ht);
  COIN_DLL_API void cc_hash_clear(cc_hash * ht);

  COIN_DLL_API SbBool cc_hash_put(cc_hash * ht, cc_hash_key key, void * val);
  COIN_DLL_API SbBool cc_hash_get(cc_hash * ht, cc_hash_key key, void ** val);
  COIN_DLL_API SbBool cc_hash_remove(cc_hash * ht, cc_hash_key key);
  COIN_DLL_API void cc_hash_apply(cc_hash * ht, cc_hash_apply_func * func, void * closure);

  COIN_DLL_API unsigned int cc_hash_get_num_elements(cc_hash * ht);

  COIN_DLL_API void cc_hash_set_hash_func(cc_hash * ht, cc_hash_func * func);
  COIN_DLL_API void cc_hash_print_stat(cc_hash * ht);

/* ********************************************************************** */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ! CC_HASH_H */
