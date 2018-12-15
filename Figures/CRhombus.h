#ifndef CRhombus_H
#define CRhombus_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	int id;
	Point Corner1;	

public:
	CRhombus();
	CRhombus(Point , GfxInfo FigureGfxInfo );
	virtual bool check(int, int);
	virtual void Draw(Output* pOut) const;
	virtual void Load(string filename,int pos) ;
	void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
	virtual string Type();
	virtual int GetCx ();
	virtual int GetCy ();
};

#endif