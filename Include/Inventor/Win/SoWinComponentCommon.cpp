// src\Inventor\Win\SoWinComponentCommon.cpp.  Generated from SoGuiComponentCommon.cpp.in by configure.

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

/*!
  \class SoWinComponent SoWinComponent.h Inventor/Win/SoWinComponent.h
  \brief The SoWinComponent class is the base class for all GUI components.

  Components in the SoWin component library all inherit this
  abstract base class. It provides basic methods for setting and
  querying about the relationship between the component object and its
  underlying Win object(s).

  Application programmers should not need to interface any code
  against this class, unless they want to extend the SoWin library
  in entirely new directions. For making new viewer components, for
  instance, other classes further down the inheritance hierarchy would
  be better suited for subclassing.

  Note that the relationship between all SoWinComponent derived
  classes and Win widgets is one of "has-A", \e not "is-A" --
  i.e. SoWinComponent \e contains a HWND, it doesn't derive from
  or subclass it.
*/

#include <Inventor/Win/SoWin.h>
#include <Inventor/Win/SoWinComponent.h>
#include <Inventor/Win/SoWinComponentP.h>

#include <Inventor/SbPList.h>

/*!
  \fn void SoWinComponent::initClasses(void)

  This function initializes the type system for all the component
  classes.  It is called indirectly for you when you call
  SoWin::init().

  \sa SoWin::init(), SoWinDevice::initClasses()
*/

/*!
  \fn SoWinComponent::SoWinComponent(HWND const parent, const char * const name, const SbBool embed)

  This is a protected constructor, used only by derived classes.

  The \a parent argument is the parent widget of the component.  If
  you don't supply a parent, the main window (the one given to or
  returned from SoWin::init()) is used (and the \a embed argument is
  considered to be \c FALSE).

  The \a name argument is the name of the component. If you don't
  supply one, the name will default to something, depending on the
  inheritance hierarchy.

  The \a embed argument tells wether the component should be embedded
  in the \a parent widget or should create its own shell. This flag is
  only checked if the \a parent widget argument is specified (not
  \c NULL).

  If you create a non-embedded component, the component will create
  its own shell, which will be a toplevelshell type. If you embed the
  component, the component will create a formwidget type widget inside
  the \a parent widget, which you can get the handle of by calling
  SoWinComponent::getBaseWidget().
*/

/*!
  \fn SoWinComponent::~SoWinComponent()

  Destructor.
*/

/*!
  \fn void SoWinComponent::addVisibilityChangeCallback(SoWinComponentVisibilityCB * const func, void * const user)

  Add a callback which will be called whenever the widget component
  changes visibility status (because of iconification or
  deiconification, for instance).

  \sa removeVisibilityChangeCallback(), isVisible()
*/

/*!
  \fn void SoWinComponent::removeVisibilityChangeCallback(SoWinComponentVisibilityCB * const func, void * const data)

  Remove one of the callbacks from the list of visibility notification
  callbacks.

  \sa addVisibilityChangeCallback(), isVisible()
*/

/*!
  \fn void SoWinComponent::setClassName(const char * const name)

  Set class name of component.

  \sa getClassName(), componentClassName()
*/

/*!
  \fn void SoWinComponent::setBaseWidget(HWND widget)

  Set the core widget for this SoWin component. It is important that
  subclasses get this correct, as the widget set here will be the
  widget returned from query methods.

  \sa baseWidget()
*/

/*!
  \fn void SoWinComponent::show(void)

  This will show the widget, de-iconifiying and raising it if
  necessary.

  \sa hide(), isVisible()
*/

/*!
  \fn void SoWinComponent::hide(void)

  This will hide the widget.

  \sa show(), isVisible()
*/

/*!
  \fn SbBool SoWinComponent::isVisible(void)

  Returns visibility status on the widget. If any parents of this
  widget or this widget itself is hidden, returns \c FALSE.

  Note that a widget which is just obscured by other windows on the
  desktop is not hidden in this sense, and \c TRUE will be returned.

  \sa show(), hide()
*/

/*!
  \fn HWND SoWinComponent::getWidget(void) const

  Returns a pointer to the component's window system widget.

  \sa getShellWidget(), getParentWidget()
*/

/*!
  \fn HWND SoWinComponent::getBaseWidget(void) const

  An SoWinComponent may be composed of any number of widgets in
  parent-children relationships in a tree structure with any depth.
  This method will return the root widget in that tree.

  \sa setBaseWidget()
*/

/*!
  \fn SbBool SoWinComponent::isTopLevelShell(void) const

  Returns \c TRUE if this component is a toplevel shell, i.e. it has a
  window representation on the desktop.

  \sa getShellWidget()
*/

/*!
  This method returns the shell widget of the component, but only if
  it was created as a toplevel shell.  \c NULL will be returned for
  embedded components.

  (The toplevel shell is the desktop window which contains the
  component.)

  To get the toplevel shell of embedded components, you can use the
  SoWin::getShellWidget() method.

  \sa isTopLevelShell(), getWidget()
*/
HWND
SoWinComponent::getShellWidget(void) const
{
  HWND w = this->getWidget();
  // the below assert disables SoXt, so I've removed it for now
  // 20031001 larsa
  // assert(w == NULL && "widget not built yet!");
  return (this->isTopLevelShell() && w) ? SoWin::getShellWidget(w) : NULL;
}

/*!
  \fn HWND SoWinComponent::getParentWidget(void) const

  Returns the widget which is the parent (i.e. contains) this
  component's base widget.

  \sa getWidget(), baseWidget(), isTopLevelShell()
*/

/*!
  \fn void SoWinComponent::setTitle(const char * const title)

  Set the window title of this component. The title will appear on the
  window title bar, if the component manages its own window.

  \if SOQT_DOC

  Note that there is one peculiarity to be aware of if you are using
  the non-commercial version of Qt: only window titles with the
  substring "Qt" in them are allowed (!), and attempts to set a window
  title without this substring will simply be ignored.

  \endif

  \sa getTitle(), setIconTitle(), isTopLevelShell()
*/

/*!
  \fn const char * SoWinComponent::getTitle(void) const

  Returns the window title.

  If a title has been set, that title will be returned.
  If no title has been set, the default title is returned.

  \sa setTitle(), isTopLevelShell()
*/

/*!
  \fn void SoWinComponent::setIconTitle(const char * const title)

  This method sets the title of the icon representation of the window.

  The title will appear on the window icon, if the component manages
  its own window.

  \sa getIconTitle(), setTitle(), isTopLevelShell()
*/

/*!
  \fn const char * SoWinComponent::getIconTitle(void) const

  Returns the title the window has when iconfied.

  If an icon title has been set, that icon title is returned.  If no
  icon title has been set, the default icon title is returned.

  \sa setIconTitle(), isTopLevelShell()
*/

/*!
  \fn const char * SoWinComponent::getWidgetName(void) const

  Returns name of the widget.
*/

/*!
  \fn const char * SoWinComponent::getClassName(void) const

  Returns class name of widget.
*/

/*!
  This method returns the default name of a component widget class.

  It should be overridden by derived non-abstract classes for the
  topmost widget in the component to have a proper name.
*/
const char *
SoWinComponent::getDefaultWidgetName(void) const
{
  return "SoWinComponent";
}

/*!
  This method returns the default window caption string of the
  component.

  It should be overridden by derived non-abstract classes so the
  window and popup menu will get a proper title.
*/
const char *
SoWinComponent::getDefaultTitle(void) const
{
  return "Win Component";
}

/*!
  This method returns the default icon title of the component.

  It should be overridden by derived non-abstract classes so icons
  will get proper titles.
*/
const char *
SoWinComponent::getDefaultIconTitle(void) const
{
  return "Win Component";
}

/*!
  \fn void SoWinComponent::setSize(const SbVec2s size)

  Resize the component widget.

  The method assumes the caller knows what he is doing.

  \sa getSize()
*/

/*!
  \fn SbVec2s SoWinComponent::getSize(void) const

  Returns the component widget size.

  The size that is returned is a cached size value, not a value
  fetched from the GUI system.

  \sa setSize()
*/

/*!
  \fn void SoWinComponent::sizeChanged(const SbVec2s & size)

  Called internally from within the SoWin library when the widget
  embedded in a component changes it size, which is usually triggered
  by end-user interaction.

  This method is then invoked to notify the component that the size
  has changed.  It is called from the top and all the way down to the
  bottom, the size being adjusted to take into account extra
  decorations having been added at each level in the component class
  hierarchy.
*/

/*!
  \fn void SoWinComponent::setWindowCloseCallback(SoWinComponentCB * const func, void * const data)

  Set up a callback function to use when the component gets closed. A
  component must be a toplevel shell for this to have any effect.

  For toplevel shells with no close callback set, the window will
  simply be hidden. The typical action to take in the callback would
  be to delete the component.

  \sa isTopLevelShell()
*/

/*!
  \fn SbBool SoWinComponent::setFullScreen(const SbBool onoff)

  Toggle full screen mode for this component, if possible.

  Returns \c FALSE if operation failed.  This might happen if the
  toolkit doesn't support attempts at making the component cover the
  complete screen or if the component is not a toplevel window.
*/

/*!
  \fn SbBool SoWinComponent::isFullScreen(void) const

  Returns if this widget/component is in full screen mode.
*/

/*!
  \fn void SoWinComponent::setComponentCursor(const SoWinCursor & cursor)

  Sets the cursor for this component.

  Note: not part of the original SGI InventorXt API.
*/

/*!
  \fn void SoWinComponent::setWidgetCursor(HWND w, const SoWinCursor & cursor)

  Set cursor for a native widget in the underlying toolkit.

  Note: not part of the original SGI InventorXt API.
*/

/*!
  \fn void SoWinComponent::afterRealizeHook(void)

  A function "hook" / callback invoked just after the window for the
  component has been realized.

  Override this if you need specific initialization for your own
  component or viewer class to happen right after it has been made
  visible, but remember to call upwards in the inheritance hierarchy:

  \code
  void
  MyLittleViewer::afterRealizeHook(void)
  {
    <superclass>::afterRealizeHook();
    // [own initialization here]
  }
  \endcode
*/



// *************************************************************************

/*!
  This method should be used by subclasses to register the widgets
  they set up from the underlying native toolkit, so they can be
  "reverse" mapped to the owner component.

  Subclasses failing to register the widgets they use will cause the
  SoWinComponent::getComponent() method to fail with those widgets.

  \sa unregisterWidget(), getComponent()
*/
void
SoWinComponent::registerWidget(HWND widget)
{
#if SOWIN_DEBUG && 0 // debug
  SoDebugError::postInfo("SoWinComponent::registerWidget",
                         "registering widget %p", widget);
#endif // debug

  // In case widget was already present.
  void * comp;
  if (SoGuiComponentP::widget2compdict->find((unsigned long)widget, comp)) {
    if (((SoWinComponent *)comp) != this) {
#if SOWIN_DEBUG
      SoDebugError::postWarning("SoWinComponent::registerWidget",
                                "widget %p already registered on a different "
                                "component", widget);
#endif // SOWIN_DEBUG
      SoGuiComponentP::widget2compdict->remove((unsigned long)widget);
    }
    else {
      return;
    }
  }

  SoGuiComponentP::widget2compdict->enter((unsigned long)widget, (void *)this);
}

/*!
  Remove a previously registered native toolkit widget from the
  widget-to-component mappings used by
  SoWinComponent::getComponent().

  \sa registerWidget()
*/
void
SoWinComponent::unregisterWidget(HWND widget)
{
#if SOWIN_DEBUG && 0 // debug
  SoDebugError::postInfo("SoWinComponent::unregisterWidget",
                         "unregistering widget %p", widget);
#endif // debug

  // Ignore return value to allow a widget to be unregistered several
  // times (it doesn't matter, just as it doesn't matter if a widget
  // is registered multiple times).
  (void)SoGuiComponentP::widget2compdict->remove((unsigned long)widget);
}

/*!
  Finds and returns the SoWinComponent corresponding to the given
  HWND, if any. If the widget does not seem to belong to any
  SoWinComponent, \c NULL will be returned.
*/
SoWinComponent *
SoWinComponent::getComponent(HWND widget)
{
  void * comp;
  if (!SoGuiComponentP::widget2compdict->find((unsigned long)widget, comp)) {
    return NULL;
  }
  return (SoWinComponent *)comp;
}

// *************************************************************************

#ifndef DOXYGEN_SKIP_THIS

// Remaining code is for the SoGuiComponentP "private implementation"
// class.

SbDict * SoGuiComponentP::widget2compdict = NULL;
int SoGuiComponentP::nrofcomponents = 0;

SoGuiComponentP::SoGuiComponentP(SoWinComponent * publ)
{
  this->pub = publ;

  if (SoGuiComponentP::widget2compdict == NULL) {
    SoGuiComponentP::widget2compdict = new SbDict;
  }
  SoGuiComponentP::nrofcomponents++;
}

SoGuiComponentP::~SoGuiComponentP()
{
  SoGuiComponentP::nrofcomponents--;
  if (SoGuiComponentP::nrofcomponents == 0) {
#if SOWIN_DEBUG
    // Check to see if widgets were forgotten (ie missing
    // unregisterWidget() calls).
    SbPList keys, values;
    SoGuiComponentP::widget2compdict->makePList(keys, values);
    for (int i=0; i < keys.getLength(); i++) {
      SoDebugError::postWarning("SoGuiComponentP::~SoGuiComponentP",
                                "widget %p not unregistered for component %p",
                                keys[i], values[i]);
    }
#endif // SOWIN_DEBUG

    delete SoGuiComponentP::widget2compdict;
    SoGuiComponentP::widget2compdict = NULL;
  }
}

#endif // DOXYGEN_SKIP_THIS

// *************************************************************************
