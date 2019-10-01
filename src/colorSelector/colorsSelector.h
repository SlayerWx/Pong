#ifndef COLORSSELECTOR_H
#define COLORSSELECTOR_H
class colorsSelector
{
private:
	int _heightRectangleOptions;
	int _widthRectangleOptions;
	int startPositionToDrawRectangles;
public:
	colorsSelector(int heightRectangleOptions,int widthRectangleOptions,int startPosition);
	void draw();
	int getHeight();
	int getWidth();
	int getStartPosition();
};
#endif

