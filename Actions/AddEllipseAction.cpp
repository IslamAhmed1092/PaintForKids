#include "..\Actions\AddEllipseAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <Windows.h>
#include <MMSystem.h>

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp):Action(pApp)
{}

void AddEllipseAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (pManager->getVoice())
		PlaySound(TEXT("Ellipse.wav"), NULL, SND_SYNC);
	
	pOut->PrintMessage("New Ellipse: Click at center");
	
	//Read 1st corner and store in point P1
	do
	{
	pIn->GetPointClicked(P1.x, P1.y);
	}while  (P1.y<UI.ToolBarHeight+50);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a Ellispe with the parameters read from the user
	CEllipse *R=new CEllipse(P1,RectGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->AddFigure(R);
}
