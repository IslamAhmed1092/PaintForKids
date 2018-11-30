#ifndef ADD_Ellipse_ACTION_H
#define ADD_Ellipse_ACTION_H

#include "Action.h"

//Add Ellipse Action class
class AddEllipseAction: public Action
{
private:
	Point P1; //Ellipse Corners
	GfxInfo RectGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads Ellipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager
	virtual void Execute() ;
	
};

#endif