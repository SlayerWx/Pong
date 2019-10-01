#include "ObjectPlayable.h"
ObjectPlayable::ObjectPlayable(float x, float y, float newSpeed, float height, float width)
{
	body.x = x;
	body.y = y;
	speed = newSpeed;
	body.height = height;
	body.width = width;
}
ObjectPlayable::ObjectPlayable()
{
	std::cout << "CUIDADO:objecto creado sin parametros" << std::endl;
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
Rectangle ObjectPlayable::getBody()
{
	return body;
}
ObjectPlayable::colorType ObjectPlayable::getColorType()
{
	return myColorType;
}
void ObjectPlayable::setColorType(colorType newColorType)
{
	myColorType = newColorType;
}
void ObjectPlayable::setY(int Y)
{
	body.y = Y;
}