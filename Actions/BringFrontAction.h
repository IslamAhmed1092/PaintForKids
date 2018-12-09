#pragma once
#include "Action.h"
class BringFrontAction:public Action
{
public:
	BringFrontAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~BringFrontAction(void);
};

