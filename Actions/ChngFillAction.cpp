#include "ChngFillAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ChngFillAction::ChngFillAction(ApplicationManager *pApp):Action(pApp)
{}

void ChngFillAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType Act;

	pOut->PrintMessage("Choose a color");
	pOut->ClearToolBar();
	pOut->CreateColorToolBar();
	do
	{
		Act = pIn->GetUserAction();
		switch (Act)
		{
		case RD: c = RED; 
			break;
		case BL: c = BLUE; 
			break;
		case BLK: c = BLACK; 
			break;
		case WT: c = WHITE; 
			break;
		case GRN: c = GREEN; 
			break;
		default:
			c = GRAY;
			break;
		}
	}while(c == GRAY);
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();	
}

void ChngFillAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure)
	{
		ReadActionParameters();
		selfigure->ChngFillClr(c);
		UI.FillColor = c;
		selfigure->SetSelected(false);
		pManager->SelectFig(NULL);
		selfigure = NULL;
	}
	else
		pOut->PrintMessage("select figure first");
	
}

ChngFillAction::~ChngFillAction(void)
{
}
