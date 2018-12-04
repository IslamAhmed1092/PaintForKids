#include "CEllipse.h"
CEllipse::CEllipse(){}
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
string CEllipse::Type()
{
	return "ELLIPSE";
}
void CEllipse::Load(string filename,int pos) 
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
	{	
		col=BLACK;
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
