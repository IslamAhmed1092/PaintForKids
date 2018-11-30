#ifndef ADD_Rhombus_ACTION_H
#define ADD_Rhombus_ACTION_H
#include "Action.h"

//Add Rhomubs Action class
class AddRhombusAction: public Action
{
private:
	Point P1; //Rhombus Corners
	GfxInfo RectGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads Rhombus parameters
	virtual void ReadActionParameters();
	
	//Add Rhmbus to the ApplicationManager
	virtual void Execute() ;
	
};

#endif