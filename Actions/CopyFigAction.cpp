#include "CopyFigAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyFigAction::CopyFigAction(ApplicationManager *pApp):Action(pApp)
{
}

void CopyFigAction::ReadActionParameters()
{
}

void CopyFigAction::Execute()
{
    Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure==NULL)
		pOut->PrintMessage("select figure first");
	else
	{
		pManager->copyfigure(selfigure);
		pOut->ClearStatusBar();
	}
}

CopyFigAction::~CopyFigAction(void)
{
}
