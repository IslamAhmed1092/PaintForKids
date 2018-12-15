#include "CFigure.h"

int CFigure::ID = 0;
CFigure::CFigure(){}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	++ID;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
GfxInfo CFigure:: GetGfx() {return FigGfxInfo;}

Point CFigure::GetP1(){Point p ;return p; }
Point CFigure::GetP2(){Point p ;return p; }
Point CFigure::GetP3(){Point p ;return p; }
void CFigure::SetSelected(bool s)
{	Selected = s; }
bool CFigure::IsSelected() const
{	return Selected; }
void CFigure::notfilled() 
{
	FigGfxInfo.isFilled=false;
}
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


string StringColor(color clr)
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
