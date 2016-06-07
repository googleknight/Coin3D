#ifndef SOWIN_H
#define SOWIN_H

// src\Inventor\Win\SoWin.h.  Generated from SoGui.h.in by configure.

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

#include <Inventor/Win/SoWinBasic.h>

// FIXME: use configure defines for the header files.
// 20020613 mortene.

#ifdef __COIN_SOQT__

#if QT_VERSION >= 0x040000
#include <QtCore/QObject>
#else
#include <qobject.h>
#endif

#endif // __COIN_SOQT__
#ifdef __COIN_SOXT__
#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#endif // __COIN_SOXT__
#ifdef __COIN_SOGTK__
// Fetch stdlib.h, so NULL is defined before glib.h is (indirectly)
// included. Otherwise we get a compile error with KCC on some
// systems.
#include <stdlib.h>
#include <gtk/gtk.h>
class SoGtkComponent;
class SbPList;
#endif // __COIN_SOGTK__
#ifdef __COIN_SOWIN__
#include <windows.h>
#endif // __COIN_SOWIN__

#include <Inventor/SbBasic.h>
#include <Inventor/SbLinear.h>
#include <Inventor/SbString.h>
#include <Inventor/SoDB.h>
#include <Inventor/errors/SoDebugError.h>

// *************************************************************************

class SOWIN_DLL_API SoWin
{

public:
  static HWND init(const char * appname, const char * classname = "SoWin");
  static HWND init(int & argc, char ** argv,
                       const char * appname, const char * classname = "SoWin");
  static void init(HWND toplevelwidget);

  static void mainLoop(void);
  static void exitMainLoop(void);
  static void done(void);

  static HWND getTopLevelWidget(void);
  static HWND getShellWidget(const HWND w);

  static void show(HWND const widget);
  static void hide(HWND const widget);

  static void setWidgetSize(HWND const widget, const SbVec2s size);
  static SbVec2s getWidgetSize(const HWND widget);

  static void createSimpleErrorDialog(HWND widget,
                                      const char * title,
                                      const char * string1,
                                      const char * string2 = NULL);

  static void getVersionInfo(int * major = NULL,
                             int * minor = NULL,
                             int * micro = NULL);
  static const char * getVersionString(void);
  static const char * getVersionToolkitString(void);

  enum FatalErrors {
    UNSPECIFIED_ERROR = 0,
    NO_OPENGL_CANVAS,
    INTERNAL_ASSERT
  };
  typedef void FatalErrorCB(const SbString errmsg, SoWin::FatalErrors errcode,
                            void * userdata);
  static FatalErrorCB * setFatalErrorHandler(SoWin::FatalErrorCB * cb,
                                             void * userdata);

  static SbBool isDebugLibrary(void);
  static SbBool isCompatible(unsigned int major, unsigned int minor);

  enum ABIType { DLL, LIB, UNKNOWN };
  static ABIType getABIType(void);

  static void lockGL(void);
  static void unlockGL(void);

private:
  // Since the class consists solely of static functions, hide the
  // default constructor and the destructor so nobody can instantiate
  // it.
  SoWin(void);
  virtual ~SoWin();

  friend class SoGuiP;
  friend class SoWinP;


  // FIXME!: audit and remove as much as possible of the remaining
  // toolkit specific parts below. 20020117 mortene.

#ifdef __COIN_SOXT__
public:
  static void nextEvent(XtAppContext, XEvent *);
  static Boolean dispatchEvent(XEvent * event);
  static XtAppContext getAppContext(void);
  static Display * getDisplay(void);
  static XmString encodeString(const char * const str);
  static char * decodeString(XmString xstring);
  static void getPopupArgs(Display * display, int screen,
                           ArgList args, int * n);

  static void registerColormapLoad(Widget widget, Widget shell);
  static void addColormapToShell(Widget widget, Widget shell);
  static void removeColormapFromShell(Widget widget, Widget shell);

  static void addExtensionEventHandler(Widget widget,
                                       int eventType, XtEventHandler proc,
                                       XtPointer clientData);
  static void removeExtensionEventHandler(Widget widget,
                                          int eventType, XtEventHandler proc,
                                          XtPointer clientData);

protected:
  static void getExtensionEventHandler(XEvent * event, Widget & widget,
                                       XtEventHandler & proc,
                                       XtPointer & clientData);
#endif // __COIN_SOXT__

#ifdef __COIN_SOGTK__
public:
  friend class SoGtkComponent;
  enum SoGtkComponentAction { CREATION, DESTRUCTION, CHANGE };
  typedef void SoGtkComponentActionCallback(SoGtkComponent *, SoGtk::SoGtkComponentAction, void *);

  static void addComponentActionCallback(SoGtkComponentActionCallback *, void *);
  static void removeComponentActionCallback(SoGtkComponentActionCallback *, void *);

  static int getComponents(SbPList & components);

protected:
  static void invokeComponentActionCallbacks(SoGtkComponent * component,
                                             SoGtkComponentAction action);

  static gint componentCreation(SoGtkComponent * component);
  static gint componentDestruction(SoGtkComponent * component);
  static gint componentChange(SoGtkComponent * component);

private:
  static gint timerSensorCB(gpointer data);
  static gint idleSensorCB(gpointer data);
  static gint delaySensorCB(gpointer data);

  static GtkWidget * mainWidget;
  static SbPList * components;
  static SbPList * component_callbacks;
#endif // __COIN_SOGTK__
};

// *************************************************************************
// Here's something InventorWin provides for convenience. Belongs more
// in the application code domain, imo, but we provide these macros
// for better compile time compatibility with InventorWin.  -mortene

#define SOWIN_ENTER_GL_SECTION() do { SoWin::lockGL(); } while(FALSE)
#define SOWIN_LEAVE_GL_SECTION() do { SoWin::unlockGL(); } while(FALSE)

// *************************************************************************

#endif // ! SOWIN_H
