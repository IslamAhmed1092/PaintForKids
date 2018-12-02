#include "delfigAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

delfigAction::delfigAction(ApplicationManager *pApp):Action(pApp)
{
}

void delfigAction::ReadActionParameters() 
{	
}

//Execute the action
void delfigAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	CFigure* selfigure = pManager->GetSelected();
	if (selfigure==NULL)
		pOut->PrintMessage("select figure first");
	else
	{
		pManager->delfigure(selfigure); 
		pManager->SelectFig(NULL);
		selfigure = NULL;
		pOut->ClearStatusBar();
	}
}

delfigAction::~delfigAction(void)
{

}
