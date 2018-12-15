#ifndef CTri_H
#define CTri_H

#include "CFigure.h"

class CTri: public CFigure
{
private:
	int id;
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	
	CTri();
	CTri(Point , Point,Point, GfxInfo FigureGfxInfo );
	virtual bool check(int, int);
	virtual void Draw(Output* pOut) const;
	virtual void Load(string filename,int pos) ;
	void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
	virtual string Type();
	virtual int GetCx ();
    virtual int GetCy ();
	virtual Point GetP1();
	virtual Point GetP2();
	virtual Point GetP3();

};

#endif