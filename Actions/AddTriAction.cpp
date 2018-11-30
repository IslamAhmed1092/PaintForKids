#include "AddTriAction.h"
#include "..\Figures\CTri.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	do
	{
	pIn->GetPointClicked(P1.x, P1.y);
	}while  (P1.y<UI.ToolBarHeight);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	do
	{
	pIn->GetPointClicked(P2.x, P2.y);
	}while  (P2.y<UI.ToolBarHeight);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3d corner and store in point P3
	do
	{
	pIn->GetPointClicked(P3.x, P3.y);
	}while  (P3.y<UI.ToolBarHeight);
	
	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CTri *R=new CTri(P1, P2,P3,RectGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(R);

}