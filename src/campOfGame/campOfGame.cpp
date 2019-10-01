#include "campOfGame.h"
campOfGame::campOfGame()
{
}
void campOfGame::input(Player* p1, Player* p2)
{
	p1->move();
	p2->move();
}
void campOfGame::update(Player* p1, Player* p2)
{
}
void campOfGame::draw(Player* p1, Player* p2)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawRectangle(10, static_cast<int>(p1->getBody().y), 
				  static_cast<int>(p1->getBody().width), static_cast<int>(p1->getBody().height), p1->getBody().myColor);
	DrawRectangle(static_cast<int>(GetScreenWidth()-(p2->getBody().width)-10), static_cast<int>(p2->getBody().y),
				  static_cast<int>(p2->getBody().width), static_cast<int>(p2->getBody().height), p2->getBody().myColor);
	EndDrawing();
}