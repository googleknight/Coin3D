#ifndef COIN_SOVECTORIZEACTION_H
#define COIN_SOVECTORIZEACTION_H

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

#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/actions/SoSubAction.h>
#include <Inventor/SbVec2f.h>
#include <Inventor/SbColor.h>

class SoVectorOutput;
class SbViewportRegion;
class SoVectorizeItem;
class SoVectorizeActionP;
class SbBSPTree;

// *************************************************************************

class COIN_DLL_API SoVectorizeAction : public SoCallbackAction {
  typedef SoCallbackAction inherited;
  
  SO_ACTION_HEADER(SoVectorizeAction);

public:
  SoVectorizeAction(void);
  virtual ~SoVectorizeAction();

  SoVectorOutput * getOutput(void) const;
  
  static void initClass(void);

  enum DimensionUnit { INCH, MM, METER };
  enum Orientation { PORTRAIT, LANDSCAPE };

  enum PageSize {
    A0 = 0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,
    A8,
    A9,
    A10
  };

  virtual void apply(SoNode * node);
  virtual void apply(SoPath * path);
  virtual void apply(const SoPathList & pathlist, SbBool obeysrules = FALSE);
  
  void beginStandardPage(const PageSize & pagesize, const float border = 10.0f);
  
  virtual void beginPage(const SbVec2f & startpagepos, 
                         const SbVec2f & pagesize, 
                         DimensionUnit u = MM);
  virtual void endPage(void);

  virtual void calibrate(const SbViewportRegion & vp);

  virtual void beginViewport(const SbVec2f & startpos = SbVec2f(-1.0f, 1.0f),
                             const SbVec2f & size = SbVec2f(-1.0f, -1.0f),
                             DimensionUnit u = MM);
  virtual void endViewport(void);

  virtual void setOrientation(Orientation o);
  virtual Orientation getOrientation(void) const;

  virtual void setBackgroundColor(SbBool bg, const SbColor & col = SbColor(0.0f, 0.0f, 0.0f));
  virtual SbBool getBackgroundColor(SbColor & col) const;

  virtual void setNominalWidth(float w, DimensionUnit u = MM);
  virtual float getNominalWidth(DimensionUnit u = MM) const;

  virtual void setPixelImageSize(float w, DimensionUnit u = MM);
  virtual float getPixelImageSize(DimensionUnit u = MM) const;

  enum PointStyle {
    CIRCLE,
    SQUARE
  };

  virtual void setPointStyle(const PointStyle & style);
  virtual PointStyle getPointStyle(void) const;

  const SbVec2f & getPageStartpos(void) const;
  const SbVec2f & getPageSize(void) const;

public:
  // for TGS OIV compatibility. Might be implemented in the future
  enum ColorTranslationMethod { REVERSE_ONLY_BLACK_AND_WHITE, AS_IS, REVERSE };

  enum JoinLineStyle { NO_JOIN, MITERED_JOIN, MITERED_BEVELED_JOIN,
                       BEVELED_JOIN, TRIANGULAR_JOIN, ROUNDED_JOIN } ;
  enum EndLineStyle { BUTT_END, SQUARE_END, TRIANGULAR_END, ROUND_END };
  enum HLHSRMode { NO_HLHSR, HLHSR_SIMPLE_PAINTER, HLHSR_PAINTER,
                   HLHSR_PAINTER_SURFACE_REMOVAL, HIDDEN_LINES_REMOVAL };

  virtual void setDrawingDimensions(const SbVec2f & d, DimensionUnit u = MM);
  virtual void setDrawingDimensions(float w, float h, DimensionUnit u = MM) { this->setDrawingDimensions(SbVec2f(w, h), u); }
  virtual SbVec2f getDrawingDimensions(DimensionUnit u = MM) const;

  virtual void setStartPosition(const SbVec2f & p, DimensionUnit u = MM);
  virtual void setStartPosition(float x, float y, DimensionUnit u = MM) { this->setStartPosition(SbVec2f(x, y), u); }
  virtual SbVec2f getStartPosition(DimensionUnit u = MM) const;

  virtual void setColorTranslationMethod(ColorTranslationMethod method);
  virtual ColorTranslationMethod getColorTranslationMethod(void) const;

  virtual void setLineEndStyle(EndLineStyle style);
  virtual EndLineStyle getLineEndStyle(void) const;

  virtual void setLineJoinsStyle(JoinLineStyle style);
  virtual JoinLineStyle getLineJoinsStyle(void) const;

  virtual void setHLHSRMode(HLHSRMode mode);
  HLHSRMode getHLHSRMode(void) const;
  
  virtual void setBorder(float width);  
  virtual void setBorder (float width, SbColor color); 
  
  virtual void setMiterLimit(float limit);
  virtual float getMiterLimit(void) const;

  virtual void setPenDescription(int num_pens, 
                                 const SbColor* colors = 0, 
                                 const float * widths = 0, 
                                 DimensionUnit u = MM);
  virtual void getPenDescription(SbColor * colors, 
                                 float * widths, 
                                 DimensionUnit u = MM) const;
  virtual int getPenNum(void) const;

  virtual void setColorPriority(SbBool priority); 
  virtual SbBool getColorPriority(void) const;

  virtual void enableLighting(SbBool flag);
  SbBool isLightingEnabled(void) const;

protected:
  void setOutput(SoVectorOutput * output);

  virtual float pixelsToUnits(const int pixels);
  virtual void printHeader(void) const = 0;
  virtual void printFooter(void) const;
  virtual void printBackground(void) const;
  virtual void printItem(const SoVectorizeItem * item) const = 0;
  virtual void printViewport(void) const;

  SbVec2f getRotatedViewportStartpos(void) const;
  SbVec2f getRotatedViewportSize(void) const;

  const SbBSPTree & getBSPTree(void) const;

private:
  SoVectorizeActionP * pimpl;
  friend class SoVectorizeActionP;
};

// *************************************************************************

#ifndef COIN_INTERNAL
// For SGI / TGS Open Inventor compile-time compatibility.
#include <Inventor/nodes/SoImage.h>
#endif // COIN_INTERNAL

// *************************************************************************

#endif // !COIN_SOVECTORIZEACTION_H
