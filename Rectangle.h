#pragma once

#include <iostream>
#include <vector>

#include "Shape.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Rectangle : public Shape
{
public:
	// @TYPE	CONSTRUCTOR
	// @DESC	Takes in height and width with default name and desc
	Rectangle(int height, int width, string = "Rectangle", string = "Four right angles");

	// @TYPE	DESTRUCTOR
	// @DESC	Virtual destructor (default)
	virtual ~Rectangle() = default;

	// @TYPE	COPY CONSTRUCTOR
	// @DESC	Default copy constructor
	Rectangle(const Rectangle&) = default;

	// @TYPE	METHOD
	// @DESC	Convert and return string from a Rectangle obj
	virtual string toString() override;

	// @TYPE	METHOD
	// @DESC	Calc and return area
	virtual double getArea() override;

	// @TYPE	METHOD
	// @DESC	Calc and return perimeter
	virtual double getPerimeter() override;

	// @TYPE	METHOD
	// @DESC	Calc and return screen-area
	virtual double getScreenArea() override;

	// @TYPE	METHOD
	// @DESC	Calc and return screen-perimeter
	virtual double getScreenPerimeter() override;

	// @TYPE	METHOD
	// @DESC	Draws textual image of the rectangle
	virtual Grid draw(char draw_char = '*', char border_char = ' ') const override;

	// @TYPE	METHOD
	// @DESC	Calculate and return height of the bounding box
	virtual int getBoxHeight();

	// @TYPE	METHOD
	// @DESC	Calculate and return width of the bounding box
	virtual int getBoxWidth();

private:
	int id;
	int height;
	int width;
};

