#ifndef Player_H
#define Player_H
#include "raylib.h"
#include <iostream>
class Player
{
private:
	~Player();
	Rectangle body;
	float speed;
	int score;
	int globalScore;
	Image mySkin;
	Color myColor;
public:
	Player(int x,int y);
	void move();
	void checkCollision(Vector2 ballPosition, Vector2 ballVel);
	void setColor(Color color);
	Color getColor();
	void increaseScore();
	void increaseGlobalScore();
	void resetScore();
	void resetGlobalScore();
	void setSkin(Image skin);
	Image getSkin();

};
#endif
