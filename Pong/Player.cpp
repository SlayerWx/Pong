#include "Player.h"
Player::Player(int x,int y,int newSpeed, int height, int width)
{
	ObjectPlayable::ObjectPlayable(x,y,newSpeed,height,width);
}
Player::~Player()
{
	cout << "Player Destruido" << endl;
}
void Player::move(int x,int y) 
{

}
