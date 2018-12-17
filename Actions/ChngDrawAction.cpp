#include "ChngDrawAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ChngDrawAction::ChngDrawAction(ApplicationManager * pApp):Action(pApp)
{}
void ChngDrawAction::ReadActionParameters()
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


void ChngDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure)
	{
		ReadActionParameters();
		selfigure->ChngDrawClr(c);
		UI.DrawColor = c;
		selfigure->SetSelected(false);
		pManager->SelectFig(NULL);
		selfigure = NULL;
	}
	else
		pOut->PrintMessage("select figure first");
}

ChngDrawAction::~ChngDrawAction()
{
}
