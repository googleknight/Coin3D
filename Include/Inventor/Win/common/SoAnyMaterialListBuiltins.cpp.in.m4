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

// @configure_input@

#if SO@GUI@_DEBUG
static const char rcsid[] =
  "$Id$";
#endif // SO@GUI@_DEBUG

/**************************************************************************
 * IMPORTANT NOTICE
 * Be aware that the file So@Gui@MaterialListBuiltins.cpp is generated from
 * the file So@Gui@MaterialListBuiltins.cpp.m4, so changes has to be done in
 * the source file with the m4 macros.  The generation is done manually,
 * since it is no point in making this project depend on the user having
 * m4 installed.
 **************************************************************************/

#include <assert.h>
#include <string.h>

#include <Inventor/@Gui@/SoAnyMaterialList.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#ifdef WITH_STATIC_DEFAULTS
#include <materials/materials.h>
#endif // WITH_STATIC_DEFAULTS

include(libm4.m4)
divert(0)dnl
// *************************************************************************
define([SOANY_BUILTIN_MATERIAL_GROUPS], [13])dnl
define([SOANY_BUILTIN_MATERIAL_GROUP_SIZE], [35])dnl

#ifdef WITH_STATIC_DEFAULTS
static
const char *
changequote(,)dnl
builtin_material_names[] = {
changequote([,])dnl
define([matnum], 0)dnl
m4_foreach([material], [artdeco, autumn, glass, metal, neon, rococo, santafe,
                        sheen, silky, spring, summer, tropical, winter], [dnl
  "material",
m4_for([num], 0, m4_eval(SOANY_BUILTIN_MATERIAL_GROUP_SIZE-1),,
[dnl
    "material.num",
])dnl
define([matnum], m4_eval(matnum+1))dnl
])dnl
  NULL
}; // builtin_material_names
#endif // WITH_STATIC_DEFAULTS

// *************************************************************************

/*!
  \internal

  This method fills in the So@Gui@MaterialDirectory structure with the builtin
  material data.
*/

void
SoAnyMaterialList::setupBuiltinMaterials( // private
  So@Gui@MaterialDirectory * const index ) const
{
  assert( index != NULL );
  index->numGroups = 0;
  index->groups = NULL;
#ifdef WITH_STATIC_DEFAULTS
changequote(,)dnl
  index->flags |= SO@GUI@_BUILTIN_MATERIALS;
  index->numGroups = SOANY_BUILTIN_MATERIAL_GROUPS;
  index->groups = new So@Gui@MaterialGroup * [ SOANY_BUILTIN_MATERIAL_GROUPS ];
  for ( int i = 0; i < index->numGroups; i++ ) {
    index->groups[i] = new So@Gui@MaterialGroup;
    index->groups[i]->numMaterials = SOANY_BUILTIN_MATERIAL_GROUP_SIZE;
    index->groups[i]->materials = new So@Gui@Material * [ SOANY_BUILTIN_MATERIAL_GROUP_SIZE ];
    for ( int j = 0; j < SOANY_BUILTIN_MATERIAL_GROUP_SIZE; j++ ) {
      index->groups[i]->materials[j] = new So@Gui@Material;
    }
  }

changequote([,])dnl
define([matnum], 0)dnl
m4_foreach([material], [artdeco, autumn, glass, metal, neon, rococo, santafe,
                        sheen, silky, spring, summer, tropical, winter], [dnl
changequote(<,>)dnl
  index->groups[matnum]->name = builtin_material_names[m4_eval(matnum*(SOANY_BUILTIN_MATERIAL_GROUP_SIZE+1))];
changequote([,])dnl
m4_for([num], 0, m4_eval(SOANY_BUILTIN_MATERIAL_GROUP_SIZE-1),,
[changequote(<,>)dnl
  index->groups[matnum]->materials[num]->name = builtin_material_names[m4_eval(matnum*(SOANY_BUILTIN_MATERIAL_GROUP_SIZE+1)+num+1)];
  index->groups[matnum]->materials[num]->data = material<>num<>_iv;
changequote([,])dnl
])dnl
define([matnum], m4_eval(matnum+1))dnl
])dnl
#endif // ! WITH_STATIC_DEFAULTS
} // setupBuiltinMaterials()

// *************************************************************************

#if SO@GUI@_DEBUG
static const char * getSoAnyMaterialListBuiltinsRCSId(void) { return rcsid; }
#endif // SO@GUI@_DEBUG

