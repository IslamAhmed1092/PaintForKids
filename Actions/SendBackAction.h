#pragma once
#include "Action.h"
class SendBackAction:public Action
{
public:
	SendBackAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~SendBackAction(void);
};

