#include "GeometricObject.h"

#include <vector>

#include "Line.h"
#include "Box.h"
#include "Circle.h"

double f;
//checking mouse on circle
double x, y;

GeometricObject* GeometricObject::getGeometricObject(const std::string& name, 
	const int& i, const int& j, const int& i1, const int& j1,
	const int& length, const int& thick, const float& r, const float& g, const float& b)
{
	if (name == "Line")
	{
		return new Line(i, j, i1, j1, thick);
	}
	else if (name == "Box")
	{		
		return new Box(i * 128 + (64-length/2), j* 120 + (60-length/2) , length);
	}
	else if (name == "Circle")	{
		return new Circle(i * 128 + 64, j * 120+ 60, length, r, g, b, thick);		
	}
	else
	{
		return nullptr;
	}	
}

	
