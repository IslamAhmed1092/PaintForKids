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