#include "Player.h"
Player::Player(int x,int y)
{
}
Player::~Player()
{

}
void Player::move()
{
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