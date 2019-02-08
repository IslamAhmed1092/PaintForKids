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
color CFigure:: GetColor() {return FigGfxInfo.FillClr;}

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

void CFigure:: setgfxold(GfxInfo old) {flag=old;}
GfxInfo CFigure:: getgfxold() {return flag;}
void CFigure:: setgfx(GfxInfo gf) {FigGfxInfo=gf;}

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
