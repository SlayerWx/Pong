#ifndef OBJECTPLAYABLE_H
#define OBJECTPLAYABLE_H
#include "raylib/include/raylib.h"
#include <iostream>
class ObjectPlayable
{
public:
	enum colorType
	{
		white, Red, Blue, green, Orange, Violet
	};
	ObjectPlayable();
	ObjectPlayable(float x, float y, float newSpeed, float height, float width);
	void setColor(Color color);
	Color getColor();
	void increaseScore();
	void increaseGlobalScore();
	void resetScore();
	void resetGlobalScore();
	void setSkin(Texture2D skin);
	Texture2D getSkin();
	Rectangle getBody();
	colorType getColorType();
	void setColorType(colorType newColorType);
	void setY(int Y);
private:
	int score;
	int globalScore;
	Texture2D mySkin;
	colorType myColorType;
protected:
	Rectangle body;
	float speed;
};
#endif