#include "CutAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager *pApp):Action(pApp)
{
}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{
    Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure==NULL)
		pOut->PrintMessage("select figure first");
	else
	{

		pManager->cutfigure(selfigure);
		selfigure->SetSelected(false);
		pManager->SelectFig(NULL);
		selfigure = NULL;
		pOut->ClearStatusBar();
	}
}

CutAction::~CutAction(void)
{
}
