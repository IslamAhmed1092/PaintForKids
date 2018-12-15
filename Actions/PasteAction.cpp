#include "PasteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PasteAction::PasteAction(ApplicationManager *pApp):Action(pApp)
{
}
void PasteAction::ReadActionParameters()
{}
void PasteAction::Execute() 
{
    Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetClipboard();
	if(selfigure==NULL)
	pOut->PrintMessage("Copy figure first");
	else
		{
		pManager->pastefigure(selfigure);
		selfigure->SetSelected(false);
		pManager->SelectFig(NULL);
		selfigure = NULL;
		pOut->ClearStatusBar();
	    }
}

PasteAction::~PasteAction()
{
}
