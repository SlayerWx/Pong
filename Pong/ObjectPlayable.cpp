#include "ObjectPlayable.h"
ObjectPlayable::ObjectPlayable(int x, int y, int newSpeed, int height, int width)
{
}
ObjectPlayable::ObjectPlayable()
{
	std::cout << "CUIDADO:objecto creado sin parametros" << std::endl;
}
void ObjectPlayable::selectorMove(colorType enemyColorType)
{
	/*if (IsKeyDown(KEY_W) && body.y > 85)
	{
		body.y -= speed;
	}
	if (IsKeyDown(KEY_S) && body.y + body.height < GetScreenHeight() - body.height / 2)
	{
		body.y += speed;
	}
	if (IsKeyDown(KEY_UP) && body.y > 85)
	{
		body.y -= speed;
	}
	if (IsKeyDown(KEY_DOWN) && body.y + body.height < GetScreenHeight() - body.height / 2)
	{
		body.y += speed;
	}
	if (body.y < 130 && enemyColorType != Red)
	{
		body.myColor = RED;
		myColorType = Red;
	}
	if (body.y > 160 && body.y < 195 && enemyColorType != Blue)
	{
		body.myColor = BLUE;
		myColorType = Blue;
	}
	if (body.y > 230 && body.y < 250 && enemyColorType != Orange)
	{
		body.myColor = ORANGE;
		myColorType = Orange;
	}
	if (body.y > 285 && enemyColorType != Violet)
	{
		body.myColor = VIOLET;
		myColorType = Violet;
	}*/
}
void ObjectPlayable::checkCollision(Vector2 ballPosition, Vector2 ballVel)
{
}
void ObjectPlayable::setColor(Color color)
{
	body.myColor = color;
}
Color ObjectPlayable::getColor()
{
	return body.myColor;
}
void ObjectPlayable::increaseScore()
{
	score++;
}
void ObjectPlayable::increaseGlobalScore()
{
	globalScore++;
}
void ObjectPlayable::resetScore()
{
	score = 0;
}
void ObjectPlayable::resetGlobalScore()
{
	globalScore = 0;
}
void ObjectPlayable::setSkin(Texture2D skin)
{
	mySkin = skin;
}
Texture2D ObjectPlayable::getSkin()
{
	return mySkin;
}
Rectangle ObjectPlayable::getRectangle()
{
	return body;
}
ObjectPlayable::colorType ObjectPlayable::getColorType()
{
	return ObjectPlayable::myColorType;
}
void ObjectPlayable::setColorType(colorType newColorType)
{
	ObjectPlayable::myColorType = newColorType;
}
void ObjectPlayable::move()
{

}