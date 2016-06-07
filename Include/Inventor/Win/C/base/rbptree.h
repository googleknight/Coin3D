#ifndef CC_RBPTREE_H
#define CC_RBPTREE_H

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

#include <Inventor/C/basic.h>

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct cc_rbptree_node cc_rbptree_node;

typedef struct cc_rbptree {
  cc_rbptree_node * root;
  
  /* store two items inline to avoid allocating memory for small tree */
  void * inlinepointer[2];
  void * inlinedata[2];
  uint32_t counter;
} cc_rbptree;

void cc_rbptree_init(cc_rbptree * t);
void cc_rbptree_clean(cc_rbptree * t);

void cc_rbptree_insert(cc_rbptree * t, void * p, void * data);
SbBool cc_rbptree_remove(cc_rbptree * t, void * p);
uint32_t cc_rbptree_size(const cc_rbptree * t);

/* traverse all elements */
typedef void cc_rbptree_traversecb(void * p, void * data, void * closure);
void cc_rbptree_traverse(const cc_rbptree * t, cc_rbptree_traversecb * func, void * closure);

/* only for debugging */
void cc_rbptree_debug(const cc_rbptree * t);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ! CC_RBPTREE_H */
