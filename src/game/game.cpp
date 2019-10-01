#include "game.h"
namespace game
{
Game::Game()
{
	cout << "inicializando juego..." << endl;
}
Game::~Game()
{
	cout << "Juego finalizado..." << endl;
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
	Player* player1 = new Player(GetScreenWidth() / 6.20f, GetScreenHeight() / 3.0f, 300.0f, 100.0f, 30.0f, KEY_W, KEY_S);
	Player* player2 = new Player(GetScreenWidth() / 1.20f, GetScreenHeight() / 1.5f, 300.0f, 100.0f, 30.0f, KEY_UP, KEY_DOWN);
	while (inGame && !WindowShouldClose())
	{
		menu(inMenu,player1,player2);
		game(gaming,player1,player2);
	}
	delete player2;
	delete player1;
}
void Game::menu(bool &inMenu,Player* player1,Player* player2)
{
	const int maxScoreSet = 7;
	Menu* menu = new Menu(370, 130, 110,"Play!",RAYWHITE);
	while (inMenu && !WindowShouldClose())
	{
		menu->input(player1, player2);
		menu->update(inMenu);
		menu->draw(Vector2{ GetScreenWidth() / 2.0f, 10.0f }, 50, WHITE, 70, player1->getBody(),player2->getBody());
	}
	delete menu;
}
void Game::game(bool &gaming, Player* player1, Player* player2)
{
	campOfGame* theGameCamp = new campOfGame();
	player1->setY(GetScreenHeight() / 2);
	player2->setY(GetScreenHeight() / 2);
	while (gaming && !WindowShouldClose())
	{
		theGameCamp->input(player1, player2);
		theGameCamp->update(player1, player2);
		theGameCamp->draw(player1,player2);
	}
	delete theGameCamp;
}
}
