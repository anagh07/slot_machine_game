#pragma once

#include <iostream>
#include <vector>

#include "Shape.h"

using std::string;

class Triangle : public Shape
{
public:
	// @TYPE	CONSTRUCTOR
	// @DESC	Takes in base name and desc
	Triangle(int input_base, string input_name, string input_desc);

	// @TYPE	DESTRUCTOR
	// @DESC	Virtual destructor (default)
	virtual ~Triangle() = default;

	// @TYPE	METHOD
	// @DESC	Calc and return area
	virtual double getArea() override;

protected:
	int height;
	int base;
};

