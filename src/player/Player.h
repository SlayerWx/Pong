#ifndef Player_H
#define Player_H
#include "objectPlayable/ObjectPlayable.h"
using namespace std;
class Player : public ObjectPlayable
{
private:
	KeyboardKey Key_UP;
	KeyboardKey Key_DOWN;
public:
	Player(float x,float y, float newSpeed,float height,float width, KeyboardKey Up,KeyboardKey Down);
	~Player();
	void move();
	void selectorMove(colorType enemyColorType,int startPositionRectangles,int heightRectangles);

};
#endif
