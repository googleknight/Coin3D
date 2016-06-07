#include<windows.h>
#include <Inventor/Win/SoWin.h>
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>
#include<Inventor/nodes/SoTransform.h>
#include<Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCylinder.h>
#include <Inventor/nodes/SoLineSet.h>
#include <Inventor/nodes/SoCoordinate3.h>
#include<Inventor\actions\SoWriteAction.h>
#include<Inventor\nodes\SoText2.h>
#include<string>

SoSeparator* makeaxis(SbVec3f *ver,float *color,char *txt)
{
	SoSeparator *axis = new SoSeparator;
	SoText2 *label = new SoText2;
	label->string.setValue(txt);
	SoTransform *labelTransform = new SoTransform;
	labelTransform->translation.setValue(ver[1]);
	SoCoordinate3 *coord = new SoCoordinate3();
	coord->point.setValues(0, 2, ver);
	SoLineSet *line = new SoLineSet();
	line->numVertices.set1Value(0, 2);
	SoMaterial *linecolor = new SoMaterial;
	linecolor->diffuseColor.setValue(color);
	axis->addChild(linecolor);
	axis->addChild(coord);
	axis->addChild(line);
	axis->addChild(labelTransform);
	axis->addChild(label);
	return axis;
}
SoSeparator* getCompass(void)
{
	SoSeparator *compass = new SoSeparator;
	char axisLabel[3][10] = {
		"X-axis",
		"Y-axis",
		"Z-axis"
	};
	SbVec3f axis[3][2]=
	{
		{{-10,0,0},
		{10,0,0}},
		{{ 0,-10,0 },
		{ 0,10,0 }},
		{ { 0,0,-10 },
		{ 0,0,10 } }

	};
	float color[3][3] = 
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	for (int index = 0; index < 3; index++)
		compass->addChild(makeaxis(axis[index],color[index],axisLabel[index]));
		return compass;
}