#include "LoadAction.h"
#include "..\Figures\CLine.h"
#include"..\Figures\CEllipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTri.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "delfigAction.h"
LoadAction::LoadAction(string file)
{ 
	filename=file;
	count = 0;	
}
LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{
	count=0; 
}
void LoadAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter file name : ");
	filename = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}
//Execute the action
void LoadAction::Execute() 
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	file.open (filename);
	pManager->LoadAll(file,filename); 
	file.close();
	pOut->PrintMessage("File is loaded!");

}
LoadAction::~LoadAction()
{
	//for (int i=0; i<count; i++)
		//delete fig[i]; 
}
