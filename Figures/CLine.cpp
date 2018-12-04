#include "CLine.h"
CLine::CLine(){}
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

string CLine::Type()
{
	return "LINE";
}
void CLine::Load(string filename,int pos) 
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
	color col;
	if (arr[6]=="BLUE")
		col=BLUE;
	else if (arr[6]=="RED")
		col=RED;
	else if (arr[6]=="BLACK")
		col=BLACK;
	else if (arr[6]=="WHITE")
		col=WHITE;
	else if (arr[6]=="GREEN")
		col=GREEN;
	this->ChngDrawClr(col);
	this->Selected=false;
//	if (arr[6]=="BLUE")
	
	
 }