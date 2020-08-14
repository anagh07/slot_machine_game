#include "Triangle.h"

Triangle::Triangle(int input_base, string input_name, string input_desc) : Shape(input_name, input_desc)
{
	this->base = input_base;
	// Triangle object will be set when a particular triangle is created
	this->height = 0;
}

double Triangle::getArea()
{
	return this->base * this->height / 2;
}