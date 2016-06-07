#ifndef COIN_SONODEKITCATALOG_H
#define COIN_SONODEKITCATALOG_H

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

#include <Inventor/SoType.h>
#include <Inventor/lists/SbList.h>

class SbName;


#define SO_CATALOG_NAME_NOT_FOUND -1


class COIN_DLL_API SoNodekitCatalog {
public:
  static void initClass(void);

  SoNodekitCatalog(void);
  ~SoNodekitCatalog();

  int getNumEntries(void) const;
  int getPartNumber(const SbName & name) const;
  const SbName & getName(int part) const;

  SoType getType(int part) const;
  SoType getType(const SbName & name) const;
  SoType getDefaultType(int part) const;
  SoType getDefaultType(const SbName & name) const;
  SbBool isNullByDefault(int part) const;
  SbBool isNullByDefault(const SbName & name) const;

  SbBool isLeaf(int part) const;
  SbBool isLeaf(const SbName & name) const;
  const SbName & getParentName(int part) const;
  const SbName & getParentName(const SbName & name) const;
  int getParentPartNumber(int part) const;
  int getParentPartNumber(const SbName & name) const;
  const SbName & getRightSiblingName(int part) const;
  const SbName & getRightSiblingName(const SbName & name) const;
  int getRightSiblingPartNumber(int part) const;
  int getRightSiblingPartNumber(const SbName & name) const;

  SbBool isList(int part) const;
  SbBool isList(const SbName & name) const;
  SoType getListContainerType(int part) const;
  SoType getListContainerType(const SbName & name) const;
  const SoTypeList & getListItemTypes(int part) const;
  const SoTypeList & getListItemTypes(const SbName & name) const;

  SbBool isPublic(int part) const;
  SbBool isPublic(const SbName & name) const;

  SoNodekitCatalog * clone(SoType type) const;

  SbBool addEntry(const SbName & name, SoType type, SoType defaulttype,
                  SbBool isdefaultnull, const SbName & parent,
                  const SbName & rightsibling, SbBool islist,
                  SoType listcontainertype, SoType listitemtype,
                  SbBool ispublic);
  void addListItemType(int part, SoType type);
  void addListItemType(const SbName & name, SoType type);

  void narrowTypes(const SbName & name, SoType newtype, SoType newdefaulttype);
  void setNullByDefault(const SbName & name, SbBool nullbydefault);

  SbBool recursiveSearch(int part, const SbName & name,
                         SoTypeList * checked) const;

  void printCheck(void) const;

private:
  SbBool hasEntry(const SbName & name) const;
  SbBool hasListItemType(const SbName & name, SoType type) const;
  SbBool reallyAddEntry(class CatalogItem * newitem);

  int getPartNumber(const SbList<class CatalogItem *> & l,
                    const SbName & name) const;
  void addListItemType(const SbList<class CatalogItem *> & l,
                       int part, SoType type);
  SbBool addListItemType(const SbList<class CatalogItem *> & l,
                         const SbName & name, SoType type);

  SbList<class CatalogItem *> items;
  SbList<class CatalogItem *> delayeditems;
};

#endif // !COIN_SONODEKITCATALOG_H
