#include "CFigure.h"

int CFigure::ID = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	++ID;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::StringColor(color clr)
{
	if (clr == RED)
		return "RED";
	else if(clr == WHITE)
		return "WHITE";
	else if(clr == BLUE)
		return "BLUE";
	else if (clr == GREEN)
		return "GREEN";
	else
		return "BLACK";
}
