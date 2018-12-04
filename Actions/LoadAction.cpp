#include "LoadAction.h"
#include "..\Figures\CLine.h"
#include"..\Figures\CEllipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTri.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{

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
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	string STRING[200];
	ifstream file;
	int	j=0;
	file.open (filename);
	int i=0;
    CFigure * fig[200];

   if (file.is_open())
   {
        while(!file.eof()) // To get you all the lines.
        {
			
			getline(file,STRING[i]); // Saves the line in STRING.
			if (i<2)
			{
				i++;
				continue;
			}
			if(STRING[2]=="")
			{
				pOut->PrintMessage("this file is empty    press ENTER to contiue");
				pIn->GetSrting(pOut);
				pOut->ClearStatusBar();
				break;
			}
		   if (STRING[i].find("LINE")!=-1)
				{
				fig[j]=new CLine;
				fig[j]->Load(filename,i);
				pManager->AddFigure(fig[j]);
				j++;

		   }
		   else if(STRING[i].find("RECT")!=-1)
			{
				fig[j]=new CRectangle;
				fig[j]->Load(filename,i);
				pManager->AddFigure(fig[j]);
				j++;
		   }
		  else if(STRING[i].find("TRIANG")!=-1)
		   {
				fig[j]=new CTri;
				fig[j]->Load(filename,i);
				pManager->AddFigure(fig[j]);
				j++;
		   }
	
		  else if(STRING[i].find("ELLIPSE")!=-1)
			{	
				fig[j] = new CEllipse;
	 			fig[j]->Load(filename,i);
				pManager->AddFigure(fig[j]);
				j++;
			 }
		  else if(STRING[i].find("RHOMBUS")!=-1)
	     	{
				fig[j] = new CRhombus;
	   			fig[j]->Load(filename,i);
				pManager->AddFigure(fig[j]);
				j++;
	}	                                          
		i++;
		 }
		
  file.close();
	
    }
   else 
   {
	   pOut->PrintMessage("there is no file "+filename+"    Press ENTER to continue");
	   pIn->GetSrting(pOut);
	   pOut->ClearStatusBar();
   }

}
LoadAction::~LoadAction(void)
{
}
