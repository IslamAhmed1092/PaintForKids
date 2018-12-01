#include "SwitchToDrawAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager *pApp):Action(pApp)
{
}

void SwitchToDrawAction::ReadActionParameters()
{
}

void SwitchToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}

SwitchToDrawAction::~SwitchToDrawAction(void)
{
}
