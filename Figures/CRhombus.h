#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Corner1;	
public:
	CRhombus(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};

#endif