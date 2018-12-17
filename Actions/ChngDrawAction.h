#pragma once
#include "Action.h"

class ChngDrawAction: public Action
{
private:
	color c;
public:
	ChngDrawAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	
	virtual void Execute();
	
	~ChngDrawAction(void);
};

