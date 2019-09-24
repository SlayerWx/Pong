#ifndef MENU_H
#define MENU_H
#include "raylib.h"
#include "Player.h"
class Menu
{
private:
	int widthRectangleOptions;
	int heightRectangleOptions;
	void drawOptionsColor();
	void drawTitle(Vector2 pos, int fontSize, Color color);
	void instrucctionsPlayer(int fontSize, int posY);
	void PlayerSelectorDraw(Rectangle p1, Rectangle p2);
public:
	void update(Player* p1, Player* p2);
	Menu(int _widthRecOptions,int _heightRecOptions);
	void draw(Vector2 pos, int fontSize, Color color, int PosYInstrucctions,Rectangle p1, Rectangle p2);
};
#endif