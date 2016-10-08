#pragma once

#include "GeometricObject.h"

class Line : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;
	float r, g, b;
	int thick;

public:
	Line()
	{
	}

	Line(const int& _start_x, const int& _start_y,
		const int& _end_x, const int& _end_y, const int& _thick)
	{
		initialize(_start_x, _start_y, _end_x, _end_y, _thick);
	}
	void initialize(const int& _start_x, const int& _start_y,
		const int& _end_x, const int& _end_y, const int& _thick)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
		thick = _thick;
	}
	void draw();

};
