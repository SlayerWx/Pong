#include "Player.h"

void menu(bool &inMenu)
{
	while (inMenu)
	{

	}
}
void game(bool &gaming)
{
	while (gaming)
	{

	}
}

int main()
{
	SetTargetFPS(60);
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "PONG - By Ruffo Maximiliano");
	bool inGame = true;
	bool inMenu = true;
	bool gaming = true;
	while (inGame)
	{
		menu(inMenu);
		game(gaming);
	}
	return 0;
}