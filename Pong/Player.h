#ifndef Player_H
#define Player_H
#include "raylib.h"
class Player
{
private:
	Rectangle body;
	float speed;
	int score;
	int globalScore;
	Image mySkin;
	Color myColor;
	enum colorType
	{
		white, Red, Blue, green, Orange, Violet
	};
	colorType myColorType;
public:
	Player(int x,int y, int newSpeed,int height,int width);
	~Player();
	void move(colorType enemyColorType);
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
