#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "raylib.h"
#include "Player.h"
#include "Menu.h"
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
#endif
