#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 55;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;	//status bar color
	UI.ToolBarColor = WHITE;		//tool bar color
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_Tria] = "images\\MenuItems\\Menu_Tria.jpg";
	MenuItemImages[ITM_Elip] = "images\\MenuItems\\Menu_Elip.jpg";
	MenuItemImages[ITM_Rhom] = "images\\MenuItems\\Menu_Rhom.jpg";
	MenuItemImages[ITM_Line] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_SEl] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_DC] = "images\\MenuItems\\DrawColor.jpg";
	MenuItemImages[ITM_FC] = "images\\MenuItems\\FillColor.jpg";
	MenuItemImages[ITM_BLK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_WHI] = "images\\MenuItems\\White.jpg";
	MenuItemImages[ITM_BLU] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_GRN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Red.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_PST] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_DLT] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_SG] = "images\\MenuItems\\SaveGraph.jpg";
	MenuItemImages[ITM_SBT] = "images\\MenuItems\\SaveByType.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_SWON] = "images\\MenuItems\\SwitchPlay.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
	///TODO: write code to create Play mode menu


void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[ITM_PC] = "images\\MenuItems\\PickColor.jpg";
	MenuItemImages[ITM_PT] = "images\\MenuItems\\PickType.jpg";
	MenuItemImages[ITM_SWOFF] = "images\\MenuItems\\SwitchDraw.jpg";


	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}


void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo,bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LineGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,1);
	drawstyle style;	
		style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}


void Output::DrawTrinagle(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo,bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = TriGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (TriGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,  P3.x, P3.y, style);
}


void Output::DrawEllipes(Point P1, GfxInfo ElipseGfxInfo,bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = ElipseGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (ElipseGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(ElipseGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawEllipse(P1.x - 100, P1.y + 50, P1.x + 100, P1.y - 50, style);
}


void Output::DrawRhombus(Point P1,GfxInfo RhombusGfxInfo,bool selected) const  //Draw a Rhombus	
{	
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RhombusGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RhombusGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RhombusGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	int xarr[4]={P1.x,P1.x+100,P1.x,P1.x-100};
	int yarr[4]={P1.y+100,P1.y,P1.y-100,P1.y};
	pWind->DrawPolygon(xarr,yarr,4,style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

