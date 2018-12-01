#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CLine::check(int x, int y)
{
	int x1 = Corner1.x, y1 = Corner1.y, x2 = Corner2.x, y2 = Corner2.y;
	return ((y-y1) * (x2 - x1) == (y2 - y1) * (x - x1));
}