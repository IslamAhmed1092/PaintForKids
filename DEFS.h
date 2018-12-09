#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	//Drawing area actions
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	EXIT,	//Exit the application
	SELECT,		//Select a figure
	BLK,		//Black color
	WT,			//White color
	BL,			//Blue color
	GRN,		//Green color
	RD,			//Red color
	X2,			//double figure size
	X4,			//size figure * 4
	X025,		//size figure * 0.25
	X05,		//size figure * 0.5
	RZ,			//Resize figure
	VC,			//switch voice
	BK,			//send to back
	FT,			//bring to front
	CUT,		//Cutting the selected figure
	COPY,		//Copy the selected figure
	PASTE,		//Paste the selected figure
	TO_PLAY,			//Switch interface to Play mode

	//Playing area actions
	PICK_TYPE,		//Pick and hide by type
	PICK_COLOR,		//Pick and hide by figure
	TO_DRAW,		//Switch interface to Draw mode

	//General actions
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY		//A click on empty place in the toolbar

};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif