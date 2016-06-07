#ifndef SOWIN_WIN32API_H
#define SOWIN_WIN32API_H

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

// *************************************************************************
// 
// This is an internal class which wraps most of the Win32 API
// functions we use in SoWin -- to do robust checking of return values
// etc.
//
// This way, we should be able to early detect programming errors on
// our behalf, while still keeping the sourcecode nice and clean.

// *************************************************************************

#include <windows.h>
#include <winuser.h>
#include <Inventor/SbString.h>
#include <string>

// *************************************************************************

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#ifndef HAVE_LONG_PTR_TYPE
// FIXME: can we do better? use a 64-bit type from Coin's inttypes.h,
// for instance? need to know more about how exactly LONG_PTR is
// defined in the MSVS SDKs to figure this out.  -mortene.
#define LONG_PTR LONG
#define ULONG_PTR DWORD
#endif // !HAVE_LONG_PTR_TYPE

// these defines for Set/GetWindowLongPtr() and Set/GetClassLongPtr()
// which we use, is missing from MSVC 6 SDK.
#ifndef GLCP_HCURSOR
#define GCLP_HCURSOR (-12)
#endif // ! GLCP_HCURSOR
#ifndef GWLP_WNDPROC
#define GWLP_WNDPROC (-4)
#endif // ! GWLP_WNDPROC
#ifndef GWLP_USERDATA
#define GWLP_USERDATA (-21)
#endif // ! GWLP_USERDATA

// *************************************************************************

namespace Win32 {
  // Must suffix these two to other names than the originals, as they
  // seem to be #define macros.
  HWND CreateWindow_(LPCTSTR, LPCTSTR, DWORD, int, int, int, int, HWND, HMENU, HANDLE, LPVOID);
  HWND CreateWindowEx_(DWORD, LPCTSTR, LPCTSTR, DWORD, int, int, int, int, HWND, HMENU, HANDLE, LPVOID);

  void BitBlt(HDC, int, int, int, int, HDC, int, int, DWORD);
  void EnableWindow(HWND, BOOL);
  void GetTextExtentPoint(HDC, LPCTSTR, int, LPSIZE);
  void MoveWindow(HWND, int, int, int, int, BOOL);
  HGDIOBJ SelectObject(HDC, HGDIOBJ);
  void DeleteObject(HGDIOBJ);
  void SwapBuffers(HDC);
  HDC GetDC(HWND);  
  void DeleteDC(HDC);
  void ReleaseDC(HWND, HDC);
  HDC BeginPaint(HWND, LPPAINTSTRUCT);
  void EndPaint(HWND, CONST PAINTSTRUCT *);
  ATOM RegisterClass(CONST WNDCLASS *);
  void UnregisterClass(LPCTSTR, HINSTANCE);
  void DestroyWindow(HWND);
  void SetWindowText(HWND, LPCTSTR);
  void InvalidateRect(HWND, CONST RECT *, BOOL);
  void GetWindowRect(HWND, LPRECT);
  void GetClientRect(HWND, LPRECT); 
  void SetWindowPos(HWND, HWND, int, int, int, int, UINT);
  HHOOK SetWindowsHookEx(int, HOOKPROC, HINSTANCE, DWORD);
  void UnhookWindowsHookEx(HHOOK);
  void ModifyMenu(HMENU,UINT,UINT,UINT,LPCTSTR);
  void EnableMenuItem(HMENU, UINT, UINT);
  void GetMenuItemInfo(HMENU, UINT, BOOL, LPMENUITEMINFO);
  void SetMenuItemInfo(HMENU, UINT, BOOL, LPMENUITEMINFO);
  void InsertMenuItem(HMENU, UINT, BOOL, LPMENUITEMINFO);
  void InsertMenu(HMENU, UINT, UINT, UINT, LPCTSTR);
  void RemoveMenu(HMENU, UINT, UINT);
  HMENU CreatePopupMenu(VOID);
  void DestroyMenu(HMENU);
  DWORD CheckMenuItem(HMENU, UINT, UINT);
  HCURSOR CreateCursor(HINSTANCE, int, int, int, int,
                              CONST VOID *, CONST VOID *);
  HCURSOR LoadCursor(HINSTANCE, LPCTSTR);
  void ClientToScreen(HWND, LPPOINT);
  HWND SetFocus(HWND);
  UINT_PTR SetTimer(HWND, UINT_PTR, UINT, TIMERPROC);
  void KillTimer(HWND, UINT_PTR);

  LONG_PTR SetWindowLongPtr(HWND, int, LONG_PTR);
  LONG_PTR GetWindowLongPtr(HWND, int);
  ULONG_PTR SetClassLongPtr(HWND, int, LONG_PTR);
  ULONG_PTR GetClassLongPtr(HWND, int);

  // Internal and external interface to GetLastError() + FormatMessage().
  SbString getWin32Err(DWORD & lasterr);
  std::string GetOSDisplayString();

  //Hide this
  void showLastErr(void);
};

// *************************************************************************

#endif // ! SOWIN_WIN32API_H
