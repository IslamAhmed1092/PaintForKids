#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	int id;
	Point Corner1;	
public:
	CRhombus(Point , GfxInfo FigureGfxInfo );
	virtual bool check(int, int);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
	virtual string Type();
};

#endif