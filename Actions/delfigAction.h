#pragma once

#include "Action.h"

class delfigAction:public Action
{
private:
public:
	delfigAction(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();
	virtual void Execute() ;

	~delfigAction(void);
};