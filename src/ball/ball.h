#ifndef BALL_H
#define BALL_H
#include "raylib.h"
class ball
{
private:
	Vector2 VelBallon;
	Vector2 ballPosition;
public:
	ball();
	void goPosition();
	void move();
	void drawMe();
};
#endif