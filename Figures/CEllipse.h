#ifndef CEllipse_H
#define CEllipse_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	int id;
	Point Corner1;	
public:

	CEllipse(Point , GfxInfo FigureGfxInfo );
	CEllipse();
	virtual void Draw(Output* pOut) const;
	virtual bool check(int, int);
	void Save(ofstream &OutFile);
	virtual void Load(string filename,int pos);
	void PrintInfo(Output* pOut);
	virtual string Type();
	virtual int GetCx ();
	virtual int GetCy ();
};

#endif