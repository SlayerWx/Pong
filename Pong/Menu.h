#include "raylib.h"
class Menu
{
private:
	int widthRectangleOptions;
	int heightRectangleOptions;
	void drawOptionsColor();
	void drawTitle(Vector2 pos, int fontSize, Color color);
	void instrucctionsPlayer(int fontSize, int posY);
public:
	Menu(int _widthRecOptions,int _heightRecOptions);
	void draw(Vector2 pos, int fontSize, Color color, int PosYInstrucctions);
};