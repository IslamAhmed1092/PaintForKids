#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	int id;
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual bool check(int, int);
	virtual void Draw(Output* pOut) const;
	virtual void Load(string filename,int pos) ;
	void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
	virtual string Type();
    virtual	int GetCx ();
    virtual int GetCy ();
};

#endif