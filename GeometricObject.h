#pragma once

#include <iostream>

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);

class GeometricObject
{
public:
	//virtual void draw() = 0;

	virtual void draw()
	{
		draw();
	}

	static GeometricObject* getGeometricObject(const std::string& name, const int& i, const int& j,
		const int& i1, const int& j1, const int& length, const int& thick, const float& r, const float& g, const float& b);
};