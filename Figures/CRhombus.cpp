#include "CRhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	id = ID;
	Corner1 = P1;
}
	

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a Rhombus on the screen	
	pOut->DrawRhombus(Corner1,FigGfxInfo, Selected);
}

float trarea(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool CRhombus::check(int x, int y)
{
	if (y >= Corner1.y)
	{
		int x1 = Corner1.x - 100, y1 = Corner1.y, x2 = Corner1.x + 100, y2 = Corner1.y, x3 = Corner1.x, y3 = Corner1.y + 100;
	   /* Calculate area of triangle ABC */
		float A = trarea (x1, y1, x2, y2, x3, y3); 
  
	   /* Calculate area of triangle PBC */   
		float A1 = trarea (x, y, x2, y2, x3, y3); 
  
	   /* Calculate area of triangle PAC */   
		float A2 = trarea (x1, y1, x, y, x3, y3); 
  
	   /* Calculate area of triangle PAB */    
		float A3 = trarea (x1, y1, x2, y2, x, y); 
    
	   /* Check if sum of A1, A2 and A3 is same as A */ 
		return (A == A1 + A2 + A3);
	}
	else
	{
		int x1 = Corner1.x - 100, y1 = Corner1.y, x2 = Corner1.x + 100, y2 = Corner1.y, x3 = Corner1.x, y3 = Corner1.y - 100;
	   /* Calculate area of triangle ABC */
		float A = trarea (x1, y1, x2, y2, x3, y3); 
  
	   /* Calculate area of triangle PBC */   
		float A1 = trarea (x, y, x2, y2, x3, y3); 
  
	   /* Calculate area of triangle PAC */   
		float A2 = trarea (x1, y1, x, y, x3, y3); 
  
	   /* Calculate area of triangle PAB */    
		float A3 = trarea (x1, y1, x2, y2, x, y); 
    
	   /* Check if sum of A1, A2 and A3 is same as A */ 
		return (A == A1 + A2 + A3);
	}
}

void CRhombus::PrintInfo(Output* pOut)
{
	string info = "Rhombus : id = " + to_string(id) 
		+ ", center(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") , color = " 
		+ StringColor(FigGfxInfo.DrawClr) ;
	pOut->PrintMessage(info);
}

void CRhombus::Save(ofstream &OutFile)
{
	string filled = (FigGfxInfo.isFilled)? StringColor(FigGfxInfo.FillClr) : "NO_FILL";
	OutFile << "Rhombus   " + to_string(id) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ StringColor(FigGfxInfo.DrawClr) + "     " +  filled + "\n";
}

string CRhombus::Type()
{
	return "RHOMBUS";
}