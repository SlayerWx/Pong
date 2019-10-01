#include "ball.h"

ball::ball()
{
	VelBallon = { 0, 0 };
	ballPosition = {GetScreenWidth()/2,GetScreenHeight()/2};
}
void ball::goPosition()
{
	ballPosition = { GetScreenWidth() / 2,GetScreenHeight() / 2 };
}
void ball::move()
{
	ballPosition.x += VelBallon.x * GetFrameTime();
	ballPosition.y += VelBallon.y * GetFrameTime();
}
void ball::drawMe()
{
	DrawCircle(ballPosition.x, ballPosition.y, 15, WHITE);
}
