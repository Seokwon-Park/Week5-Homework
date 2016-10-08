#pragma once

#include "GeometricObject.h"

void drawCircle(int x0, int y0, int radius, int thick, const float& red, const float& green, const float& blue);

class Circle : public GeometricObject
{
public:
	int x, y, r, thick;
	float red, blue, green;

public:
	Circle()
	{
	}

	Circle(const int& _start_x, const int& _start_y,
		const int& _radius, const float& _red, const float& _green,
		const float& _blue, const int& _thick)
	{
		initialize(_start_x, _start_y, _radius, _red, _green, _blue, _thick);
	}
	void initialize(const int& _start_x, const int& _start_y,
		const int& _radius, const float& _red, const float& _green,
		const float& _blue, const int& _thick)
	{
		x = _start_x;
		y = _start_y;
		r = _radius;
		red = _red;
		green = _green;
		blue = _blue;
		thick = _thick;
	}
	void draw();
};