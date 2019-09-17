#include "Player.h"
Player::Player(int x,int y,int newSpeed, int height, int width)
{
	body.x = x;
	body.y = y;
	speed = newSpeed;
	score = 0;
	globalScore = 0;
	body.height = height;
	body.width = width;
}
Player::~Player()
{

}
void Player::move(colorType enemyColorType)
{
	if (IsKeyDown(KEY_W) && body.y > 85)
	{
		body.y -= speed;
	}
	if (IsKeyDown(KEY_S) && body.y + body.height < GetScreenHeight() - body.height/2)
	{
		body.y += speed;
	}
	if (IsKeyDown(KEY_UP) && body.y > 85)
	{
		body.y -= speed;
	}
	if (IsKeyDown(KEY_DOWN) && body.y + body.height < GetScreenHeight() - body.height/2)
	{
		body.y += speed;
	}
	if (body.y < 130 && enemyColorType != Red)
	{
		myColor = RED;
		myColorType = Red;
	}
	if (body.y > 160 && body.y < 195 && enemyColorType != Blue)
	{
		myColor = BLUE;
		myColorType = Blue;
	}
	if (body.y > 230 && body.y < 250 && enemyColorType != Orange)
	{
		myColor = ORANGE;
		myColorType = Orange;
	}
	if (body.y > 285 && enemyColorType != Violet)
	{
		myColor = VIOLET;
		myColorType = Violet;
	}
}
void Player::checkCollision(Vector2 ballPosition,Vector2 ballVel)
{
}
void Player::setColor(Color color)
{
	myColor = color;
}
Color Player::getColor()
{
	return myColor;
}
void Player::increaseScore()
{
	score++;
}
void Player::increaseGlobalScore()
{
	globalScore++;
}
void Player::resetScore()
{
	score = 0;
}
void Player::resetGlobalScore()
{
	globalScore = 0;
}
void Player::setSkin(Image skin)
{
	mySkin = skin;
}
Image Player::getSkin() 
{
	return mySkin;
}