#include "CTri.h"

CTri::CTri(Point P1, Point P2,Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	id = ID;
	Corner1 = P1;
	Corner2 = P2;
	Corner3= p3;
}

CTri::CTri(){}	

void CTri::Draw(Output* pOut) const
{
	//Call Output::DrawTrinalge to draw a Trianlgle on the screen	
	pOut->DrawTrinagle(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

float triarea(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  
/* A function to check whether point P(x, y) lies inside the triangle formed  
   by A(x1, y1), B(x2, y2) and C(x3, y3) */ 
bool CTri::check(int x, int y) 
{
	int x1 = Corner1.x, y1 = Corner1.y, x2 = Corner2.x, y2 = Corner2.y, x3 = Corner3.x, y3 = Corner3.y;
   /* Calculate area of triangle ABC */
	float A = triarea (x1, y1, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PBC */   
	float A1 = triarea (x, y, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PAC */   
	float A2 = triarea (x1, y1, x, y, x3, y3); 
  
   /* Calculate area of triangle PAB */    
	float A3 = triarea (x1, y1, x2, y2, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
	return (A == A1 + A2 + A3); 
} 

void CTri::PrintInfo(Output* pOut)
{
	string info = "Triangle : id = " + to_string(id) 
		+ ", corner1(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") , corner2(" 
		+ to_string(Corner2.x) + "," + to_string(Corner2.y) + ") , corner3("
		+ to_string(Corner3.x) + "," + to_string(Corner3.y) + ") , color = "
		+ StringColor(FigGfxInfo.DrawClr) ;
	pOut->PrintMessage(info);
}

void CTri::Save(ofstream &OutFile)
{
	string filled = (FigGfxInfo.isFilled)? StringColor(FigGfxInfo.FillClr) : "NO_FILL";
	OutFile << "TRIANG    " + to_string(id) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ "   " + to_string(Corner2.x) + "    " + to_string(Corner2.y) + "    " 
		+ "   " + to_string(Corner3.x) + "    " + to_string(Corner3.y) + "    " 
		+ StringColor(FigGfxInfo.DrawClr) + "     " +  filled + "\n";
}

string CTri::Type()
{
	return "TRIANGLE";
}
int CTri :: GetCx ()
{
	return ((Corner1.x+Corner2.x+Corner3.x))/3;
}
int CTri :: GetCy ()
{
	return ((Corner1.y+Corner2.y+Corner3.y))/3;
}
Point CTri:: GetP1(){return Corner1;}
Point CTri:: GetP2(){return Corner2;}
Point CTri:: GetP3(){return Corner3;}

void CTri::Load(string filename,int pos) 
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
	this->Corner2.x=stoi(arr[4]);
	this->Corner2.y=stoi(arr[5]);
	this->Corner3.x=stoi(arr[6]);
	this->Corner3.y=stoi(arr[7]);
	color col;
	if (arr[8]=="BLUE")
		col.setcolor(0, 0, 255);
	else if (arr[8]=="RED")
		col.setcolor(255, 0, 0);
	else if (arr[8]=="BLACK")
		col.setcolor(0, 0, 0);
	else if (arr[8]=="WHITE")
		col.setcolor(255, 255, 255);
	else if (arr[8]=="GREEN")
		col.setcolor(0, 255, 0);
	this->ChngDrawClr(col);
	this->SetSelected(false);
	if (arr[9]=="NO_FILL")
	{
		this->notfilled();
	}
	else if (arr[9]=="BLUE")
	{
			col.setcolor(0, 0, 255);
		    this->ChngFillClr(col);
	}
	else if (arr[9]=="BLACK")
	{	col.setcolor(0, 0, 0);
				    this->ChngFillClr(col);

	}
	else if (arr[9]=="WHITE")
		{col.setcolor(255, 255, 255);
		    this->ChngFillClr(col);
        }
	else if (arr[9]=="GREEN")
	{
		col.setcolor(255, 255, 255);
		    this->ChngFillClr(col);
	}
	else if (arr[9]=="RED")
	{
		col.setcolor(255, 0, 0);
		    this->ChngFillClr(col);
	}
 }