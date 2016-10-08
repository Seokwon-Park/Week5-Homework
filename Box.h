#pragma once

#include "GeometricObject.h"

class Box : public GeometricObject
{
public:
	int start_x, start_y;
	int length;

public:
	// constructor
	Box()
	{
	}

	Box(const int& _start_x, const int& _start_y,
		const int& _length)
	{
		initialize(_start_x, _start_y, _length);
	}
	void initialize(const int& _start_x, const int& _start_y,
		const int& _length)
	{
		start_x = _start_x;
		start_y = _start_y;
		length = _length;

	}
	void draw();
};
