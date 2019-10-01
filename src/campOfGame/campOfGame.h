#ifndef CAMPOFGAME_H
#define CAMPOFGAME_H
#include "raylib.h"
#include "player/Player.h"
class campOfGame
{
public:
	campOfGame();
	void input(Player* p1, Player* p2);
	void update(Player* p1, Player* p2);
	void draw(Player* p1,Player* p2);
private:
};
#endif