#include <conio.h>
#include <cstdio>
#include <iostream>

typedef int Coordinate;
typedef int Dimension;

// Desired interface
class Rectangle
{
public:
	virtual void draw() = 0;
};

// Legacy component
class LegacyRectangle
{
public:
	LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
	{
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
		printf("LegacyRectangle: create: (%d,%d) => (%d,%d) \n", x1_, y1_, x2_, y2_);
	}
	void oldDraw()
	{
		printf("LegacyRectangle: oldDraw: (%d,%d) => (%d,%d) \n", x1_, y1_, x2_, y2_);
	}
private:
	Coordinate x1_;
	Coordinate y1_;
	Coordinate x2_;
	Coordinate y2_;
};

// Adapter wrapper
class RectangleAdapter : public Rectangle, private LegacyRectangle
{
public:
	RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) 
		: LegacyRectangle(x, y, x + w, y + h)
	{
		printf("RectangleAdapter: create. (%d,%d) width = %d height = %d \n", x, y, w, h);
	}
	virtual void draw()
	{
		printf("RectangleAdapter: draw \n");

		oldDraw();
	}
};

int main()
{

	Rectangle *r = new RectangleAdapter(0, 0, 60, 40);
	r->draw();

	system("pause");
}