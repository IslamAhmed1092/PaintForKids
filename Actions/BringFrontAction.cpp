#include "BringFrontAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BringFrontAction::BringFrontAction(ApplicationManager * pApp):Action(pApp)
{
}

void BringFrontAction::ReadActionParameters() 
{	
	
}

void BringFrontAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure==NULL)
		pOut->PrintMessage("select figure first");
	else
	{
		pManager->BringFront(selfigure);
		selfigure->SetSelected(false);
		pManager->SelectFig(NULL);
		selfigure = NULL;
		pOut->ClearStatusBar();
	}
}

BringFrontAction::~BringFrontAction(void)
{
}
