#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <iostream>
using namespace std;

#include <fstream>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure * fig[MaxFigCount];
	int count; 
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	bool Voice;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void deletallfig();
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SelectFig(CFigure*);
	CFigure *GetSelected(); 
	void SaveAll(ofstream &OutFile);
	void LoadAll(ifstream &file,string filename);
	void setVoice(bool);
	bool getVoice();
	CFigure* GetRandomFigure(ActionType act) const;
	int RandomFigureCount(ActionType act,CFigure* Rand);
	void SaveType(ofstream &OutFile, string);
	void copyfigure(CFigure* cfig);
	void cutfigure(CFigure* cfig);
	void pastefigure(CFigure* cfig);
	void delfigure(CFigure *);
	void SendBack(CFigure *);
	void BringFront(CFigure *);
	CFigure* GetClipboard ();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif