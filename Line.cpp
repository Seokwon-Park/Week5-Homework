
#include "Line.h"

void drawLine(const int& i0, const int& j0, const int& i1,
	const int& j1, const int& thick, const float& red,
	const float& green, const float& blue);

void Line::draw()
{
	drawLine(start_x, start_y, end_x, end_y, thick , 1.0f, 0.0f, 0.0f);
}

void drawLine(const int& i0, const int& j0, const int& i1, 
	const int& j1, const int& thick, const float& red,
	const float& green, const float& blue)
{
	int thickness = thick;

	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		for (int m = 0; m < thickness; m++)
		{
			for (int n = 0; n < thickness; n++)
			{
				drawPixel(i, j, red, green, blue);
				drawPixel(i+m, j, red, green, blue);
				drawPixel(i, j+n, red, green, blue);
				drawPixel(i+m, j + n, red, green, blue);
			}
		}
	}
}