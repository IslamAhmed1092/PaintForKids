#pragma once
#include "Action.h"


class ChngFillAction:public Action
{
private:
	color c;
	bool chngd;
public:
	ChngFillAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();	~ChngFillAction(void);
};

