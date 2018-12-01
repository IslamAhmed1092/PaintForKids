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
#include "GUI\UI_Info.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
		
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
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case SAVE_BY_TYPE:
			pAct = new SaveTypeAction(this);
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
void ApplicationManager::SelectFig(CFigure* pFig)
{
	SelectedFig = pFig;
}

CFigure *ApplicationManager::GetSelected()
{
	return SelectedFig;
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
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
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
