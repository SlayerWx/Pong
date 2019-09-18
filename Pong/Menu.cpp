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
	DrawText("Use W and S to move Player 1", GetScreenWidth()*0.007f, posY, fontSize, WHITE);
	DrawText("Use Up Arrow and Down Arrow to move Player 2",(GetScreenWidth()*0.8f), posY,
																		fontSize, WHITE);
}
void Menu::drawOptionsColor()
{
	int beforeRectanglePos = 110;
	DrawRectangle((GetScreenWidth() / 2) - (widthRectangleOptions /2), beforeRectanglePos,
						widthRectangleOptions, heightRectangleOptions, RED);
	beforeRectanglePos += heightRectangleOptions;
	DrawRectangle((GetScreenWidth() / 2) - (widthRectangleOptions / 2), beforeRectanglePos,
						widthRectangleOptions, heightRectangleOptions, BLUE);
	beforeRectanglePos += heightRectangleOptions;
	DrawRectangle((GetScreenWidth() / 2) - (widthRectangleOptions / 2), beforeRectanglePos,
						widthRectangleOptions, heightRectangleOptions, ORANGE);
	beforeRectanglePos += heightRectangleOptions;
	DrawRectangle((GetScreenWidth() / 2) - (widthRectangleOptions / 2), beforeRectanglePos,
						widthRectangleOptions, heightRectangleOptions, VIOLET);
}
void Menu::PlayerSelectorDraw(Rectangle p1, Rectangle p2)
{
	DrawRectangle(p1.x, p1.y, p1.width, p1.height, p1.myColor);
	DrawRectangle(p2.x, p2.y, p2.width, p2.height, p2.myColor);
}
void Menu::draw(Vector2 posTitle, int fontSize, Color colorTitle,int PosYInstrucctions,
															Rectangle p1, Rectangle p2)
{
	BeginDrawing();
	ClearBackground(BLACK);
	drawOptionsColor();
	PlayerSelectorDraw(p1,p2);
	instrucctionsPlayer(fontSize/5,PosYInstrucctions);
	drawTitle(posTitle,fontSize,colorTitle);
	EndDrawing();
}