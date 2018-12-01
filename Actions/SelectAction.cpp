#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager *pApp):Action(pApp)
{
}

void SelectAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("select a figure");
	do
	{
	pIn->GetPointClicked(p.x, p.y);
	}while  (p.y<UI.ToolBarHeight);

	pOut->ClearStatusBar();
}

//Execute the action
void SelectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure* selected = pManager->GetFigure(p.x, p.y);
	if(selected == NULL)
	{
		if(pManager->GetSelected() != NULL)
		{
			pManager->GetSelected()->SetSelected(false);
			pManager->SelectFig(NULL);
		}
	}
	else
	{
		if(pManager->GetSelected() == NULL)
		{
			selected->SetSelected(true);
			pManager->SelectFig(selected);
		}
		else
		{
			if (selected == pManager->GetSelected())
			{
				selected->SetSelected(false);
				pManager->SelectFig(NULL);
			}
			else
			{
				pManager->GetSelected()->SetSelected(false);
				selected->SetSelected(true);
				pManager->SelectFig(selected);
			}
			
		}

	}

}

SelectAction::~SelectAction(void)
{
}
