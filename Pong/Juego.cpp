#include "Juego.h"
#include "Player.h"
#include "Menu.h"
Game::Game()
{
	cout << "inicializando juego..." << endl;
}

Game::~Game()
{
	cout << "Juego finalizado... liberando memoria" << endl;
}
void Game::initGame()
{
	SetTargetFPS(60);
	const int screenWidth = 1280;
	const int screenHeight = 720;
	InitWindow(screenWidth, screenHeight, "PONG - By Ruffo Maximiliano");
	bool inGame = true;
	bool inMenu = true;
	bool gaming = true;
	while (inGame && !WindowShouldClose())
	{
		menu(inMenu);
		game(gaming);
	}
}

void Game::menu(bool &inMenu)
{
	const int maxScoreSet = 7;
	Menu* menu = new Menu(370, 130);
	Player* player1 = new Player(GetScreenWidth() / 6.20f, GetScreenHeight() / 3, 15, 100, 30);
	Player* player2 = new Player(GetScreenWidth()/1.20f, GetScreenHeight() / 1.5f, 15, 100, 30);
	while (inMenu && !WindowShouldClose())
	{
		menu->draw(Vector2{ GetScreenWidth() / 2.0f, 10.0f}, 50, WHITE,70,player1->getRectangle(),
																		player2->getRectangle());
	}
	delete player2;
	delete player1;
	delete menu;
}
void Game::game(bool &gaming)
{
	while (gaming && !WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}
}
