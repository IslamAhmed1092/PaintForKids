#include "SaveTypeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveTypeAction::SaveTypeAction(ApplicationManager *pApp):Action(pApp)
{
	type = "";
}

void SaveTypeAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Choose a type to save");
	do
	{
		ActionType Act = pManager->GetUserAction();
		switch (Act)
		{
		case DRAW_LINE:
			type = "LINE";
			break;
		case DRAW_RECT:
			type = "RECTANGLE";
			break;
		case DRAW_ELLIPSE:
			type = "ELLIPSE";
			break;
		case DRAW_RHOMBUS:
			type = "RHOMBUS";
			break;
		case DRAW_TRI:
			type = "TRIANGLE";
			break;
		default:
			break;
		}
	}while( type != "LINE" && type != "RECTANGLE" && type != "ELLIPSE" && type != "RHOMBUS" && type != "TRIANGLE");
	pOut->PrintMessage("Enter file name: ");
	filename = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

//Execute the action
void SaveTypeAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	outFile.open(filename);
	pManager->SaveType(outFile, type);
	outFile.close();
	pOut->PrintMessage("Saved!");
	
}

SaveTypeAction::~SaveTypeAction(void)
{
}
