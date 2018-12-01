#pragma once
#include "Action.h"
#include <iostream>
#include <fstream>
using namespace std;

class SaveAction:public Action
{
private:
	ofstream outFile;
	string filename;
public:
	SaveAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute() ;
	
	~SaveAction(void);
};

