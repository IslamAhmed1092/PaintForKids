#include "CRhombus.h"
CRhombus::CRhombus(){}
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
void CRhombus::Load(string filename,int pos) 
 {
	string STRING[200];
	ifstream file;
	file.open (filename);
	int i=0;
   if (file.is_open())
   {
        while(!file.eof()) // To get you all the lines.
        {
			
	        getline(file,STRING[i]); // Saves the line in STRING.
	        
				if (i==pos)

				break;
			i++;
        }
	file.close();
    }
   	std::string str =STRING[i] ;
	std::istringstream stm(str) ;
	string word ;
	string arr [10];
	int k=0; 
	while( stm >> word ) // read white-space delimited tokens one by one 
	{
	  arr[k]=word;
	  k++;
		// put word into array
	}
	this->id=stoi(arr[1]);
	this->Corner1.x=stoi(arr[2]);
	this->Corner1.y=stoi(arr[3]);


	color col;
	if (arr[4]=="BLUE")
		col=BLUE;
	else if (arr[4]=="RED")
		col=RED;
	else if (arr[4]=="BLACK")
		col=BLACK;
	else if (arr[4]=="WHITE")
		col=WHITE;
	else 
		col=GREEN;
	this->ChngDrawClr(col);
	this->SetSelected(false);
	if (arr[5]=="NO_FILL")
	{
		this->notfilled();
	}
	else if (arr[5]=="BLUE")
	{
					col=BLUE;
					this->ChngFillClr(col);
	}
	else if (arr[5]=="BLACK")
	{			col=BLACK;
				    this->ChngFillClr(col);

	}
	else if (arr[5]=="WHITE")
		{
		col=WHITE;
		    this->ChngFillClr(col);
        }
	else if (arr[5]=="GREEN")
	{
				col=GREEN;
		    this->ChngFillClr(col);
	}
	else if (arr[5]=="RED")
	{
				col=RED;
		    this->ChngFillClr(col);
	}
 }
