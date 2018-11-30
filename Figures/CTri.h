#ifndef CTri_H
#define CTri_H

#include "CFigure.h"

class CTri: public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTri(Point , Point,Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};

#endif