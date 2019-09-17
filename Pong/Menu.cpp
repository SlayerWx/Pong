#include "Menu.h"
Menu::Menu(int widthRecOptions, int heightRecOptions)
{
	widthRectangleOptions = widthRecOptions;
	heightRectangleOptions = heightRecOptions;
}
void Menu::drawTitle(Vector2 pos,int fontSize,Color color)
{
	DrawText("PONG",pos.x - (fontSize+20), pos.y, fontSize, color);
}
void Menu::instrucctionsPlayer(int fontSize,int posY)
{
	DrawText("Use W and S to move Player 1", 10, posY, fontSize, WHITE);
	DrawText("Use Up Arrow and Down Arrow to move Player 2",(GetScreenWidth()/1.46), posY,
																		fontSize, WHITE);
}
void Menu::drawOptionsColor()
{
	DrawRectangle(GetScreenWidth() / 3, 110, widthRectangleOptions, heightRectangleOptions, RED);
	DrawRectangle(GetScreenWidth() / 3, 170, widthRectangleOptions, heightRectangleOptions, BLUE);
	DrawRectangle(GetScreenWidth() / 3, 230, widthRectangleOptions, heightRectangleOptions, ORANGE);
	DrawRectangle(GetScreenWidth() / 3, 290, widthRectangleOptions, heightRectangleOptions, VIOLET);
}
void Menu::draw(Vector2 posTitle, int fontSize, Color colorTitle,int PosYInstrucctions)
{
	BeginDrawing();
	ClearBackground(BLACK);
	drawOptionsColor();
	instrucctionsPlayer(fontSize/5,PosYInstrucctions);
	drawTitle(posTitle,fontSize,colorTitle);
	EndDrawing();
}