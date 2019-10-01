#include "colorsSelector.h"
#include "raylib.h"
colorsSelector::colorsSelector(int heightRectangleOptions, int widthRectangleOptions, int startPosition)
{
	startPositionToDrawRectangles = startPosition;
	_heightRectangleOptions = heightRectangleOptions;
	_widthRectangleOptions = widthRectangleOptions;
}
void colorsSelector::draw()
{
	int beforeRectanglePos = startPositionToDrawRectangles;
	DrawRectangle((GetScreenWidth() / 2) - (_widthRectangleOptions / 2), beforeRectanglePos,
		_widthRectangleOptions, _heightRectangleOptions, RED);
	beforeRectanglePos += _heightRectangleOptions;
	DrawRectangle((GetScreenWidth() / 2) - (_widthRectangleOptions / 2), beforeRectanglePos,
		_widthRectangleOptions, _heightRectangleOptions, BLUE);
	beforeRectanglePos += _heightRectangleOptions;
	DrawRectangle((GetScreenWidth() / 2) - (_widthRectangleOptions / 2), beforeRectanglePos,
		_widthRectangleOptions, _heightRectangleOptions, ORANGE);
	beforeRectanglePos += _heightRectangleOptions;
	DrawRectangle((GetScreenWidth() / 2) - (_widthRectangleOptions / 2), beforeRectanglePos,
		_widthRectangleOptions, _heightRectangleOptions, VIOLET);
}
int colorsSelector::getHeight()
{
	return _heightRectangleOptions;
}
int colorsSelector::getWidth()
{
	return _widthRectangleOptions;
}
int colorsSelector::getStartPosition()
{
	return startPositionToDrawRectangles;
}