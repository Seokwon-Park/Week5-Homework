#include "Circle.h"

void drawCircle(int x0, int y0, int radius,int thick, const float& red, const float& green, const float& blue);

void Circle::draw()
{
	drawCircle(x, y, r ,thick ,red, blue, green);
}

void drawCircle(int x0, int y0, int radius, int thick,const float& red, const float& green, const float& blue)
{
	int x = radius;
	int y = 0;
	int err = 0;
	int thickness = thick;

	while (x >= y)
	{
		//
		for (int i = 0; i < thickness; i++)
		{
			for (int j = 0; j < thickness; j++)
			{
				drawPixel(x0 + x + i, y0 + y + j, red, green, blue);
				drawPixel(x0 + y + j, y0 + x + i, red, green, blue);
				drawPixel(x0 - y - j, y0 + x + i, red, green, blue);
				drawPixel(x0 - x - i, y0 + y + j, red, green, blue);
				drawPixel(x0 - x - i, y0 - y - j, red, green, blue);
				drawPixel(x0 - y - j, y0 - x - i, red, green, blue);
				drawPixel(x0 + y + j, y0 - x - i, red, green, blue);
				drawPixel(x0 + x + i, y0 - y - j, red, green, blue);
			}
		}
		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}