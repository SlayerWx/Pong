#include <iostream>
#include "raylib.h"
using namespace std;
class Game
{
private:
	void menu(bool &inMenu);
	void game(bool &gaming);
public:
	void initGame();
	Game();
	~Game();

};
