#include "TypeAction.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CEllipse.h"
#include"..\Figures\CFigure.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTri.h"

TypeAction::TypeAction(ApplicationManager *pApp):Action(pApp)

{
}

void TypeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You Choosed Pick And Hide Game By \"Type\". Click Anywhere To Continue");
	pManager->UpdateInterface();
	Point P;
	pIn->GetPointClicked(P.x,P.y);
	pOut->ClearStatusBar();
	/*ActionType Act;

	Input* pIn = pManager->GetInput();
	Act=pIn->GetUserAction();

	switch (Act){
	
	case PICK_TYPE:
		pManager->ExecuteAction(Act);
		break;

	case PICK_COLOR:
		pManager->ExecuteAction(Act);
		break;

	case TO_DRAW:
		pManager->ExecuteAction(Act);
		break;

	case EXIT:
		pManager->ExecuteAction(Act);
		throw "EXIT";
		break;

	default: break;
	}*/

}

void TypeAction::Execute()
{
	ActionType act;
	ifstream graph;
	graph.open("Graph.txt");
	pManager->LoadAll(graph, "Graph.txt");
	graph.close();
	pManager->UpdateInterface();

	ReadActionParameters();

	int win=0, loss=0, Number;

	CFigure* Random = pManager->GetRandomFigure(PICK_TYPE);
	CFigure* Choosen;

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool exit = false;
	if(Random==NULL)
		pOut->PrintMessage("You Didnt Draw Any Figures. Go To DrawMode And Draw Some.");
	
	else 
	{
		Number = pManager->RandomFigureCount(PICK_TYPE,Random);

		pOut->PrintMessage("You Should Choose All "+Random->Type()+" Shapes. Good Luck! xD");

		while(win < Number)
		{
			exit = false;
			pIn->GetPointClicked(Pnew.x,Pnew.y);
			act  = pIn->GetUserAction(Pnew);
			switch (act)
			{
			case PICK_TYPE:
				exit = true;
				break;
			case PICK_COLOR:
				exit = true;
				break;
			case TO_DRAW:
				exit = true;
				break;
			default:
				break;
			}
			if(exit)
			{
				break;
			}
			Choosen=pManager->GetFigure(Pnew.x,Pnew.y);
			
			if(Choosen!=NULL)
			{
				if(Choosen->Type()==Random->Type())
				{
					win++;
				}

				else 
				{
					loss++;
				}
				pManager->delfigure(Choosen);
				pManager->UpdateInterface();
				pOut->PrintMessage("Win= "+to_string(win)+" Loss= "+to_string(loss));//here continous grade
			}
		}
		if(!exit)
		{
			pOut->PrintMessage("Congratz!!!! You Fineshed The Game. Your Grades = "+to_string(win)+"/"+to_string(win+loss)+". Click Anywhere To Continue");
		
			Point Nothing;
		
			pIn->GetPointClicked(Nothing.x,Nothing.y);
			pOut->ClearStatusBar();
		}
		else
		{
			switch (act)
			{
			case PICK_TYPE:
				pManager->ExecuteAction(act);
				break;
			case PICK_COLOR:
				pManager->ExecuteAction(act);
				break;
			case TO_DRAW:
				pManager->ExecuteAction(act);
				break;
			default:
				break;
			}
		}
	}
}



TypeAction::~TypeAction(void)
{
}

