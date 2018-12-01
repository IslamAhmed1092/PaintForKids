#include "CEllipse.h"

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	id = ID;
	Corner1 = P1;
}
	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a Ellipse on the screen	
	pOut->DrawEllipes(Corner1,FigGfxInfo, Selected);
}

bool CEllipse::check(int x, int y)
{
	int h = Corner1.x, k = Corner1.y, a = 100, b = 50; 
	return (pow((x - h), 2) / pow(a, 2)) + (pow((y - k), 2) / pow(b, 2)) <= 1;
}

void CEllipse::PrintInfo(Output* pOut)
{
	string info = "Ellipse : id = " + to_string(id) 
		+ ", center(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") , color = " 
		+ StringColor(FigGfxInfo.DrawClr) ;
	pOut->PrintMessage(info);
}

void CEllipse::Save(ofstream &OutFile)
{
	string filled = (FigGfxInfo.isFilled)? StringColor(FigGfxInfo.FillClr) : "NO_FILL";
	OutFile << "ELLIPSE   " + to_string(id) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ StringColor(FigGfxInfo.DrawClr) + "     " +  filled + "\n" ;
}