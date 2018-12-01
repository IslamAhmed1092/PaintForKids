#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	int id;
	Point Corner1;	
	Point Corner2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual bool check(int, int);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
};

#endif