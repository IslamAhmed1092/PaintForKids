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
	ifstream graph;
	graph.open("Graph.txt");
	pManager->LoadAll(graph, "Graph.txt");
	graph.close();
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}

SwitchToDrawAction::~SwitchToDrawAction(void)
{
}
