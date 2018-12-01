#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;	
public:
	CEllipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool check(int, int);
};

#endif