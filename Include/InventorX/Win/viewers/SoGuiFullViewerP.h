#ifndef SOGUIFULLVIEWERP_H
#define SOGUIFULLVIEWERP_H

// src\Inventor\Win\viewers\SoGuiFullViewerP.h.  Generated from SoGuiFullViewerP.h.in by configure.

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

#ifndef SOWIN_INTERNAL
#error this is a private header file
#endif /* !SOWIN_INTERNAL */

#include <Inventor/SbString.h>
#include <Inventor/Win/viewers/SoWinViewer.h>

class SoWinFullViewer;

// ************************************************************************

// This class contains private data and methods used within the
// SoGuiFullViewer class.

class SoGuiFullViewerP
{
public:
  ~SoGuiFullViewerP();

  enum SoWinFullViewerPopupMenuItem {
    // FIXME: there's code in (some of) the popupmenu widgets which
    // assumes the root id is equal to 0.  Yup, lousy design. :-/
    // Anyway, don't change it until those cases are fixed.
    // 20010810 mortene.
    ROOT_MENU = 0,
      ROOT_MENU_TITLE,

      FUNCTIONS_MENU,
      HOME_ITEM,
      SET_HOME_ITEM,
      VIEW_ALL_ITEM,
      SEEK_ITEM,

      DRAWSTYLES_MENU,
      DRAWSTYLES_STILL_MENU,
      AS_IS_ITEM,
      HIDDEN_LINE_ITEM,
      WIREFRAME_OVERLAY_ITEM,
      NO_TEXTURE_ITEM,
      LOW_RESOLUTION_ITEM,
      WIREFRAME_ITEM,
      POINTS_ITEM,
      BOUNDING_BOX_ITEM,

      DRAWSTYLES_ANIMATING_MENU,
      MOVE_SAME_AS_STILL_ITEM,
      MOVE_NO_TEXTURE_ITEM,
      MOVE_LOW_RES_ITEM,
      MOVE_WIREFRAME_ITEM,
      MOVE_LOW_RES_WIREFRAME_ITEM,
      MOVE_POINTS_ITEM,
      MOVE_LOW_RES_POINTS_ITEM,
      MOVE_BOUNDING_BOX_ITEM,

      TRANSPARENCY_TYPE_MENU,
      SCREEN_DOOR_TRANSPARENCY_ITEM,
      ADD_TRANSPARENCY_ITEM,
      DELAYED_ADD_TRANSPARENCY_ITEM,
      SORTED_OBJECT_ADD_TRANSPARENCY_ITEM,
      BLEND_TRANSPARENCY_ITEM,
      DELAYED_BLEND_TRANSPARENCY_ITEM,
      SORTED_OBJECT_BLEND_TRANSPARENCY_ITEM,
      // These are Coin extensions.
      SORTED_OBJECT_SORTED_TRIANGLE_ADD_TRANSPARENCY_ITEM,
      SORTED_OBJECT_SORTED_TRIANGLE_BLEND_TRANSPARENCY_ITEM,
      SORTED_LAYERS_BLEND_ITEM,
      NONE_TRANSPARENCY_ITEM,

      RENDER_BUFFER_TYPE_MENU,
      SINGLE_BUFFER_ITEM,
      DOUBLE_BUFFER_ITEM,
      INTERACTIVE_BUFFER_ITEM,

      EXAMINING_ITEM,
      DECORATION_ITEM,
      HEADLIGHT_ITEM,
      FULLSCREEN_ITEM,

      STEREO_MENU,
        STEREO_OFF_ITEM,
        STEREO_ANAGLYPH_ITEM,
        STEREO_QUADBUFFER_ITEM,
        STEREO_INTERLEAVED_ROWS_ITEM,
        STEREO_INTERLEAVED_COLUMNS_ITEM
      };

  enum SoWinViewerPopupMenuRadioGroup {
    STILL_GROUP = 1,
      MOVE_GROUP,
      TRANSPARENCY_GROUP,
      BUFFER_GROUP,
      STEREO_GROUP
      };

  class SoWinPopupMenu * setupStandardPopupMenu(void);
  void prepareMenu(class SoWinPopupMenu * menu);
  void menuSelection(int menuitemid);
  static void menuSelectionCallback(int menuitemid, void * userdata);
  SbString popupmenutitle;

  void setDrawStyleMenuActivation(SoWinViewer::DrawType type,
                                  SoWinViewer::DrawStyle value);
  void drawstyleActivated(int menuitemid);

  static void pan(SoCamera * cam,
                  float aspectratio, const SbPlane & panplane,
                  const SbVec2f & currpos, const SbVec2f & prevpos);
  static void zoom(SoCamera * cam, const float diffvalue);

protected:
  SoGuiFullViewerP(SoWinFullViewer * publ);
  SoWinFullViewer * pub;
};

// ************************************************************************

#endif // ! SOGUIFULLVIEWERP_H
