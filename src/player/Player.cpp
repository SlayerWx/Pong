#include "Player.h"
Player::Player(float x,float y,float newSpeed, float height, float width, KeyboardKey Up, KeyboardKey Down):ObjectPlayable(x, y, newSpeed, height, width)
{
	Key_UP = Up;
	Key_DOWN = Down;
}
Player::~Player()
{
	cout << "Player Destruido" << endl;
}
void Player::move() 
{
	if (IsKeyDown(Key_UP) && body.y > 0) 
	{
		body.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(Key_DOWN) && body.y < GetScreenHeight() - body.height)
	{
		body.y += speed * GetFrameTime();
	}
}
void Player::selectorMove(colorType enemyColorType,int startPositionRectangles,int heightRectangles)
{
	move();
	startPositionRectangles += heightRectangles / 2;
	if (getBody().y < startPositionRectangles &&
		getBody().y > startPositionRectangles - getBody().height && enemyColorType != Red)
	{
		body.myColor = RED;
		setColorType(Red);
	}
	startPositionRectangles += heightRectangles;
	if (getBody().y < startPositionRectangles &&
		getBody().y > startPositionRectangles - getBody().height && enemyColorType != Blue)
	{
		body.myColor = BLUE;
		setColorType(Blue);
	}
	startPositionRectangles += heightRectangles;
	if (getBody().y < startPositionRectangles &&
		getBody().y > startPositionRectangles - getBody().height && enemyColorType != Orange)
	{
		body.myColor = ORANGE;
		setColorType(Orange);
	}
	startPositionRectangles += heightRectangles;
	if (getBody().y < startPositionRectangles &&
	    getBody().y > startPositionRectangles - getBody().height && enemyColorType != Violet)
	{
		body.myColor = VIOLET;
		setColorType(Violet);
	}
}