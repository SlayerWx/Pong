#include "Menu.h"
Menu::Menu(int widthRecOptions, int heightRecOptions,int startPositionRectangles,string playButton,Color newPlayColorMenu)
{
	rectanglesToSelector = new colorsSelector(heightRecOptions,widthRecOptions,startPositionRectangles);
	namePlayButton = playButton;
	PlayColorMenu = newPlayColorMenu;
}
void Menu::drawTitle(Vector2 pos,int fontSize,Color color)
{
	DrawText("PONG",static_cast<int>(pos.x - (fontSize+20)), static_cast<int>(pos.y), fontSize, color);
}
void Menu::instrucctionsPlayer(int fontSize,int posY)
{
	DrawText("Use W and S to move Player 1", static_cast<int>(GetScreenWidth()*0.007f), posY, fontSize, WHITE);
	DrawText("Use Up Arrow and Down Arrow to move Player 2", static_cast<int>(GetScreenWidth()*0.8f), posY,fontSize, WHITE);
}
void Menu::drawOptionsColor()
{
	rectanglesToSelector->draw();
}
void Menu::PlayerSelectorDraw(Rectangle p1, Rectangle p2)
{
	DrawRectangle(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p1.width), static_cast<int>(p1.height),p1.myColor);
	DrawRectangle(static_cast<int>(p2.x), static_cast<int>(p2.y), static_cast<int>(p2.width), static_cast<int>(p2.height), p2.myColor);
}
void Menu::draw(Vector2 posTitle, int fontSize, Color colorTitle,int PosYInstrucctions,Rectangle p1, Rectangle p2)
{
	BeginDrawing();
	ClearBackground(BLACK);
	drawOptionsColor();
	PlayerSelectorDraw(p1,p2);
	instrucctionsPlayer(fontSize/5,PosYInstrucctions);
	drawTitle(posTitle,fontSize,colorTitle);
	playButton();
	EndDrawing();
}
void Menu::input(Player* p1, Player* p2)
{
	p1->selectorMove(p2->getColorType(), rectanglesToSelector->getStartPosition(), rectanglesToSelector->getHeight());
	p2->selectorMove(p1->getColorType(), rectanglesToSelector->getStartPosition(), rectanglesToSelector->getHeight());
}
void Menu::update(bool &inMenu) 
{ 
	if(outOfMenu)
	{
		inMenu = false;
	}
	outOfMenu = false;
}
void Menu::playButton()
{
	if (GetMouseY() < GetScreenHeight() - 10 && GetMouseY() > GetScreenHeight() - 85 &&
		GetMouseX() > (GetScreenWidth() / 2) - 75 && GetMouseX() < (GetScreenWidth() / 2) + 50)
	{
		PlayColorMenu = YELLOW;
		if (IsMouseButtonReleased(0))
		{
			outOfMenu = true;
		}
	}
	else
	{
		PlayColorMenu = RAYWHITE;
	}
	DrawText(namePlayButton.c_str(), (GetScreenWidth() / 2) - (namePlayButton.length())*(50/4) , GetScreenHeight() - 75, 50, PlayColorMenu);

}