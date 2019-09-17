#include "Juego.h"
void main()
{
	Game* Pong = new Game();
	Pong->initGame();
	delete Pong;
}