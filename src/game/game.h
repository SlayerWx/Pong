#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "raylib.h"
#include "player/Player.h"
#include "menu/Menu.h"
#include "player/Player.h"
#include "campOfGame/campOfGame.h"
namespace game
{
using namespace std;
class Game
{
private:
	void menu(bool &inMenu, Player* player1, Player* player2);
	void game(bool &gaming, Player* player1, Player* player2);
public:
	void initGame();
	Game();
	~Game();
};
}
#endif
