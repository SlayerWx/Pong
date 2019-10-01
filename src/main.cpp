#include "game/game.h"
using namespace game;
int main()
{
	Game* Pong = new Game();
	Pong->initGame();
	delete Pong;
	return 0;
}