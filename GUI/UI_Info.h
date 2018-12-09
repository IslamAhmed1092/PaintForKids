#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_COLOR,
	MODE_RESIZE,
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_Line,		//Draw line item
	ITM_RECT,		//Draw rectangle item
	ITM_Tria,		//Draw triangle item
	ITM_Rhom,		//Draw rhombus item
	ITM_Elip,		//Draw ellipse item
	ITM_SEl,		//Select figure item
	ITM_DC,			//Change drawing colour item
	ITM_FC,			//Change fill colour item
	ITM_CUT,		//Cut item
	ITM_COPY,		//Copy item
	ITM_PST,		//Paste item
	ITM_DLT,		//Delete item
	ITM_SG,			//Save by Graph item
	ITM_SBT,		//Save by type item
	ITM_LOAD,		//Load item
	ITM_SWON,		//Swich to play mode item
	ITM_RZ,			//Resize item
	ITM_VC,			//switch voice item
	ITM_BACK,		//Send to back item
	ITM_FRONT,		//Bring to front item
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_PT,		//Pick by type item
	ITM_PC,		//Pick by colour item
	ITM_SWOFF,		//Swich to draw mode item

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_BLK,		//Black colour item
	ITM_WHI,		//White colour item
	ITM_BLU,		//Blue colour item
	ITM_GRN,		//Green colour item
	ITM_RED,		//Red colour item	
	ITM_DRAW1,

	COLOR_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ResizeMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_QR,
	ITM_HF,
	ITM_DL,
	ITM_QL,
	ITM_DRAW2,

	Resize_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};




__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;		//Tool Bar Color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif