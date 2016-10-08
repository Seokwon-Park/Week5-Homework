#include "Box.h"

void drawSq(const int& i0, const int& j0,
	const int& length, const float& red, 
	const float& green, const float& blue);

void Box::draw()
{
	drawSq(start_x, start_y, length, 1.0f, 0.0f, 0.0f);
}

void drawSq(const int& i0, const int& j0, const int& length, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= (i0 + length); i++)
	{
		int j = j0;
		drawPixel(i, j, red, green, blue);
		j = j0 + length;
		drawPixel(i, j, red, green, blue);
	}
	for (int j = j0; j <= (j0 + length); j++)
	{
		int i = i0;
		drawPixel(i, j, red, green, blue);
		i = i0 + length;
		drawPixel(i, j, red, green, blue);
	}
}

