#ifndef CLine_H
#define CLine_H
#include "CFigure.h"
#include "..\ApplicationManager.h"

class CLine : public CFigure
{
private:
	int id;
	Point Corner1;	
	Point Corner2;
public:
	CLine();
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual bool check(int, int);
	virtual void Draw(Output* pOut) const;

	virtual void Load(string filename,int pos);
	void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
	virtual string Type();
	virtual int GetCx ();
	virtual int GetCy ();
};

#endif