#ifndef ADD_LINE_ACTION_H
#define ADD_Line_ACTION_H
#include "Action.h"

//Add Line Action class
class AddLineAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif