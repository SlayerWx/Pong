#ifndef Player_H
#define Player_H
#include "raylib.h"
#include <iostream>
using namespace std;
class Player
{
private:
	Rectangle body;
	float speed;
	int score;
	int globalScore;
	Texture2D mySkin;
	enum colorType
	{
		white, Red, Blue, green, Orange, Violet
	};
	colorType myColorType;
public:
	Player(int x,int y, int newSpeed,int height,int width);
	~Player();
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
	void move(int x, int y);

};
#endif
