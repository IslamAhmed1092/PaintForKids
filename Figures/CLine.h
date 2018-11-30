#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};

#endif