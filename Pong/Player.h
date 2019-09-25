#ifndef Player_H
#define Player_H
#include "ObjectPlayable.h"
using namespace std;
class Player : public ObjectPlayable
{
public:
	Player(int x,int y, int newSpeed,int height,int width);
	~Player();
	void move(int x, int y);

};
#endif
