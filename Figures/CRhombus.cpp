#include "CRhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a Rhombus on the screen	
	pOut->DrawRhombus(Corner1,FigGfxInfo, Selected);
}