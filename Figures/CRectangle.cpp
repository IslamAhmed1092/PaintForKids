#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0); 
}
bool CRectangle::check(int x, int y) 
{ 
	int x1 = Corner1.x , y1 = Corner1.y;
	int x2 = Corner2.x, y2 = Corner1.y;
	int x3 = Corner2.x, y3 = Corner2.y;
	int x4 = Corner1.x, y4 = Corner2.y;
    /* Calculate area of rectangle ABCD */
    float A = area(x1, y1, x2, y2, x3, y3) + area(x1, y1, x4, y4, x3, y3); 
  
    /* Calculate area of triangle PAB */
    float A1 = area(x, y, x1, y1, x2, y2); 
  
    /* Calculate area of triangle PBC */
    float A2 = area(x, y, x2, y2, x3, y3); 
  
    /* Calculate area of triangle PCD */
    float A3 = area(x, y, x3, y3, x4, y4); 
  
    /* Calculate area of triangle PAD */
    float A4 = area(x, y, x1, y1, x4, y4); 
  
    /* Check if sum of A1, A2, A3 and A4  
       is same as A */
    return (A == A1 + A2 + A3 + A4); 
} 