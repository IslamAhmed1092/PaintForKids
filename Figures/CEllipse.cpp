#include "CEllipse.h"

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a Ellipse on the screen	
	pOut->DrawEllipes(Corner1,FigGfxInfo, Selected);
}