#pragma once
#include "Action.h"
class VoiceAction:public Action
{
public:
	VoiceAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~VoiceAction(void);
};

