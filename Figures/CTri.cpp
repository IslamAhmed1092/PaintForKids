#include "CTri.h"

CTri::CTri(Point P1, Point P2,Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3= p3;
}
	

void CTri::Draw(Output* pOut) const
{
	//Call Output::DrawTrinalge to draw a Trianlgle on the screen	
	pOut->DrawTrinagle(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}