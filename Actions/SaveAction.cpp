#include "SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Enter file name: ");
	filename = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

//Execute the action
void SaveAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	outFile.open(filename);
	pManager->SaveAll(outFile);
	outFile.close();
	pOut->PrintMessage("Saved!");
	
}

SaveAction::~SaveAction(void)
{
}
