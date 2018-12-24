#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\AddRhombusAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\SaveAction.h"
#include "Actions\SaveTypeAction.h"
#include "Actions\delfigAction.h"
#include "GUI\UI_Info.h"
#include "Actions\LoadAction.h"
#include "Figures\CFigure.h"
#include "Figures\CEllipse.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CRhombus.h"
#include "Figures\CTri.h"
#include "Actions\BringFrontAction.h"
#include "Actions\SendBackAction.h"
#include "Actions\VoiceAction.h"
#include "Actions\CopyFigAction.h"
#include "Actions\PasteAction.h"
#include "Actions\ChngDrawAction.h"
#include "Actions\ChngFillAction.h"
#define MAXSPACE 25
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	Clipboard=NULL;
	Voice = false;
	FigCount = 0;
	count=0; 
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_LINE:
			///create AddLineAction here
			pAct = new AddLineAction(this);
			break;
		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;
		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case DRAWING_AREA:
			if (SelectedFig != NULL)
			{
				SelectedFig->SetSelected(false);
				SelectedFig = NULL;
			}
			pOut->ClearStatusBar();
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;
		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;
		case DEL:
			pAct=new delfigAction (this);
			break;
		case COPY:
			pAct=new CopyFigAction(this);
			break;
		case PASTE:
			pAct=new PasteAction(this);
			break;
		case LOAD:
			pAct= new LoadAction (this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case SAVE_BY_TYPE:
			pAct = new SaveTypeAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChngDrawAction(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new ChngFillAction(this);
			break;
		case BK:
			pAct = new SendBackAction(this);
			break;
		case FT:
			pAct = new BringFrontAction(this);
			break;
		case VC:
			pAct = new VoiceAction(this);
			break;
		case EXIT:
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--)
		if(FigList[i]->check(x, y))
			return FigList[i];
		
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::deletallfig()
{
	for (int i = FigCount - 1; i >= 0; i--)
		{
			delete FigList[i];
			FigList[i]=NULL;
			FigCount--;
		}	
}
void ApplicationManager::SelectFig(CFigure* pFig)
{
	SelectedFig = pFig;
}

CFigure *ApplicationManager::GetSelected()
{
	return SelectedFig;
}

void ApplicationManager::setVoice(bool b)
{
	Voice = b;
}

bool ApplicationManager::getVoice()
{
	return Voice;
}

void ApplicationManager::SaveAll(ofstream &OutFile)
{
	OutFile << StringColor(UI.DrawColor) + "    "  + StringColor(UI.FillColor) + "\n";
	OutFile << to_string(FigCount) + "\n";
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}
void ApplicationManager::LoadAll(ifstream &file,string filename)
{
	Output* pOut =GetOutput();
	Input* pIn = GetInput();
	string STRING[200];
	int i=0;
	bool empty=false; 
        while(!file.eof()) // To get you all the lines.
        {
			
			getline(file,STRING[i]); // Saves the line in STRING.
			if (i<2)
			{
				i++;
				continue;
			}
			if(STRING[2]=="")
			{
				pOut->PrintMessage("this file is empty    press ENTER to contiue");
				pIn->GetSrting(pOut);
				pOut->ClearStatusBar();
				empty=true;
				break;
			}
		 if (!empty)
		 {
			 deletallfig();
			 pOut->ClearDrawArea();
			 empty=true;
		 }
		   if (STRING[i].find("LINE")!=-1)
				{
				fig[count]=new CLine;
				fig[count]->Load(filename,i);
				AddFigure(fig[count]);
				count++;

		   }
		   else if(STRING[i].find("RECT")!=-1)
			{
				fig[count]=new CRectangle;
				fig[count]->Load(filename,i);
				AddFigure(fig[count]);
				count++;
		   }
		  else if(STRING[i].find("TRIANG")!=-1)
		   {
				fig[count]=new CTri;
				fig[count]->Load(filename,i);
				AddFigure(fig[count]);
				count++;
		   }
	
		  else if(STRING[i].find("ELLIPSE")!=-1)
			{	
				fig[count] = new CEllipse;
	 			fig[count]->Load(filename,i);
				AddFigure(fig[count]);
				count++;
			 }
		  else if(STRING[i].find("RHOMBUS")!=-1)
	     	{
				fig[count] = new CRhombus;
	   			fig[count]->Load(filename,i);
				AddFigure(fig[count]);
				count++;
	}	                                          
		i++;
		 }	

}

void ApplicationManager::SaveType(ofstream &OutFile, string type)
{
	int typecount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->Type() == type)
			typecount++;
	}
	OutFile << StringColor(UI.DrawColor) + "    "  + StringColor(UI.FillColor) + "\n";
	OutFile << to_string(typecount) + "\n";
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->Type() == type)
			FigList[i]->Save(OutFile);
	}
}

void ApplicationManager::copyfigure(CFigure* cfig)
{
		for (int i = 0; i < FigCount; i++)
		if(FigList[i] == cfig)
		{	Clipboard = FigList[i];  break; }
}

void ApplicationManager::pastefigure(CFigure* cfig)
{
	Point P1;
	CFigure *pst;
	pOut->PrintMessage("Please, click new cerntre point of figure");
	pIn->GetPointClicked(P1.x, P1.y);
	int xc=P1.x;
	int yc=P1.y;

	if(dynamic_cast<CEllipse*>(cfig)) //Done
	{
		CEllipse *c=new CEllipse(P1,cfig->GetGfx());
		AddFigure(c);
	}
	else if(dynamic_cast<CTri*>(cfig)) //Done    
	{
    int cxx=cfig->GetCx();
	int cyy=cfig->GetCy();
	int deltax,deltay;
	deltax=xc-cxx;
	deltay=yc-cyy;
	Point t1,t2,t3;
	t1=cfig->GetP1();
	t2=cfig->GetP2();
	t3=cfig->GetP3();
	t1.x+=deltax;
	t2.x+=deltax;
	t3.x+=deltax;
	t1.y+=deltay;
	t2.y+=deltay;
	t3.y+=deltay;
	CTri *t=new CTri(t1,t2,t3,cfig->GetGfx());
	AddFigure(t);
	}
	else if(dynamic_cast<CLine*>(cfig))   //Done
	{
		int cxx=cfig->GetCx();
		int cyy=cfig->GetCy();
		int p1x=xc+cxx;
		int p1y=yc+cyy;
		int p2x=xc-cxx;
		int p2y=yc-cyy;
		Point Pl1,Pl2;
		Pl1.x=p1x;
		Pl1.y=p1y;
		Pl2.x=p2x;
		Pl2.y=p2y;
		CLine *l=new CLine(Pl1,Pl2,cfig->GetGfx());
		AddFigure(l);
	}
	else if(dynamic_cast<CRectangle*>(cfig)) //Done
	{
        int cxx=cfig->GetCx();
		int cyy=cfig->GetCy();
		int p1x=xc+cxx;
		int p1y=yc+cyy;
		int p2x=xc-cxx;
		int p2y=yc-cyy;
		Point Pl1,Pl2;
		Pl1.x=p1x;
		Pl1.y=p1y;
		Pl2.x=p2x;
		Pl2.y=p2y;
		CRectangle *r=new CRectangle(Pl1,Pl2,cfig->GetGfx());
		AddFigure(r);
	}
	else if(dynamic_cast<CRhombus*>(cfig)) //Done
	{
		CRhombus *rh=new CRhombus(P1,cfig->GetGfx());
		AddFigure(rh);
	}
}
CFigure* ApplicationManager::GetClipboard() {return Clipboard; } 
void ApplicationManager::delfigure(CFigure * dFig)
{
	int i;
	for (i=FigCount-1; i >= 0; i--)
	{
		if(FigList[i]==dFig)
		{
			
			delete FigList[i];
			FigList[i]=NULL;
			break;
		}
	}
	for (i; i <FigCount-1; i++)
	{
		FigList[i]=FigList[i+1];
	}
	FigList[FigCount - 1] = NULL;
	FigCount--;

}
void ApplicationManager::SendBack(CFigure* pfigure)
{
	CFigure* temp = NULL;
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i] == pfigure)
		{
			temp = FigList[i];
			for(i; i > 0; i--)
			FigList[i] = FigList[i-1];
			FigList[0] = temp;
			temp = NULL;
			break;
		}
	}
}

void ApplicationManager::BringFront(CFigure* pfigure)
{
	CFigure* temp = NULL;
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i] == pfigure)
		{
			temp = FigList[i];
			for(i; i < FigCount - 1; i++)
				FigList[i] = FigList[i+1];
			FigList[FigCount-1] = temp;
			temp = NULL;
			break;
		}
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	Output * pOut = GetOutput();
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	        
	delete pIn;
	delete pOut;
	
}
