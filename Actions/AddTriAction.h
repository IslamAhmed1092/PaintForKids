#ifndef ADD_Tri_ACTION_H
#define ADD_Tri_ACTION_H
#include "Action.h"

//Add triangle Action class
class AddTriAction: public Action
{
private:
	Point P1, P2,P3; //triangle Corners
	GfxInfo RectGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();
	
	//Add triangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif