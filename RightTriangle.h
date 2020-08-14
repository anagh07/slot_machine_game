#pragma once

#include <string>

#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
	// @TYPE	CONSTRUCTOR
	// @DESC	Takes in base name and desc
	RightTriangle(int input_base, string = "Ladder", string = "One right angle and two acute angles");

	// @TYPE	DESTRUCTOR
	// @DESC	Virtual destructor (default)
	virtual ~RightTriangle() = default;

	// @TYPE	METHOD
	// @DESC	Convert and return string from a AcuteTriangle obj
	virtual string toString() override;

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
	// @DESC	Draws textual image of the acute triangle
	virtual Grid draw(char draw_char = '*', char border_char = ' ') const override;

	// @TYPE	METHOD
	// @DESC	Calculate and return height of the bounding box
	virtual int getBoxHeight();

	// @TYPE	METHOD
	// @DESC	Calculate and return width of the bounding box
	virtual int getBoxWidth();

private:
	int id;
};

