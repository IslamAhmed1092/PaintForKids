#pragma once
#include "Action.h"
#include <iostream>
#include <fstream>
using namespace std;

class SaveTypeAction:public Action
{
private:
	ofstream outFile;
	string filename;
	string type;
public:
	SaveTypeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute() ;
	
	~SaveTypeAction(void);
};