#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	id = ID;
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

void CLine::PrintInfo(Output* pOut)
{
	string info = "Line : id = " + to_string(id) 
		+ ", corner1(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") , corner2(" 
		+ to_string(Corner2.x) + "," + to_string(Corner2.y) + ") , color = "
		+ StringColor(FigGfxInfo.DrawClr) ;
	pOut->PrintMessage(info);
}

void CLine::Save(ofstream &OutFile)
{
	string filled = (FigGfxInfo.isFilled)? StringColor(FigGfxInfo.FillClr) : "NO_FILL";
	OutFile << "LINE   " + to_string(id) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ "   " + to_string(Corner2.x) + "    " + to_string(Corner2.y) + "    " 
		+ StringColor(FigGfxInfo.DrawClr) + "     " +  filled + "\n" ;
}