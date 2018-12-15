#pragma once
#include"Action.h"
class CopyFigAction:public Action
{
public:
	CopyFigAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~CopyFigAction(void);
};

