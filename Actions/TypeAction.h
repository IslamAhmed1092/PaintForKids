#pragma once
#include "Action.h"

class TypeAction:public Action
{
private:
	Point Pnew;
public:
	TypeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~TypeAction(void);
};