#include "SendBackAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SendBackAction::SendBackAction(ApplicationManager * pApp):Action(pApp)
{
}

void SendBackAction::ReadActionParameters() 
{	
	
}

void SendBackAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure==NULL)
		pOut->PrintMessage("select figure first");
	else
	{
		pManager->SendBack(selfigure);
		selfigure->SetSelected(false);
		pManager->SelectFig(NULL);
		selfigure = NULL;
		pOut->ClearStatusBar();
	}
}

SendBackAction::~SendBackAction(void)
{
}
