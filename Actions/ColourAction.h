#pragma once
#include "Action.h"
#include <fstream>

class ColourAction:public Action
{
	Point Pnew;
public:
	ColourAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ColourAction(void);
};