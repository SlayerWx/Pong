#ifndef MENU_H
#define MENU_H
#include "raylib.h"
#include "player/Player.h"
#include "colorSelector/colorsSelector.h"
class Menu
{
private:
	void drawOptionsColor();
	void drawTitle(Vector2 pos, int fontSize, Color color);
	void instrucctionsPlayer(int fontSize, int posY);
	void PlayerSelectorDraw(Rectangle p1, Rectangle p2);
	colorsSelector* rectanglesToSelector;
	Color PlayColorMenu;
	string namePlayButton;
	bool outOfMenu;
public:
	void input(Player* p1, Player* p2);
	void update(bool &inMenu);
	Menu(int _widthRecOptions,int _heightRecOptions, int startPositionRectangles,string playButton,Color newPlayColorMenu);
	void draw(Vector2 pos, int fontSize, Color color, int PosYInstrucctions,Rectangle p1, Rectangle p2);
	void playButton();
};
#endif