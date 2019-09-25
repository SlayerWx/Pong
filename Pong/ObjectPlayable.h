#ifndef OBJECTPLAYABLE_H
#define OBJECTPLAYABLE_H
#include "raylib.h"
#include <iostream>
class ObjectPlayable
{
public:
	enum colorType
	{
		white, Red, Blue, green, Orange, Violet
	};
	virtual void move();
	ObjectPlayable();
	ObjectPlayable(int x, int y, int newSpeed, int height, int width);
	void selectorMove(colorType enemyColorType);
	void checkCollision(Vector2 ballPosition, Vector2 ballVel);
	void setColor(Color color);
	Color getColor();
	void increaseScore();
	void increaseGlobalScore();
	void resetScore();
	void resetGlobalScore();
	void setSkin(Texture2D skin);
	Texture2D getSkin();
	Rectangle getRectangle();
	colorType getColorType();
	void setColorType(colorType newColorType);
private:
	Rectangle body;
	float speed;
	int score;
	int globalScore;
	Texture2D mySkin;
	colorType myColorType;
};
#endif