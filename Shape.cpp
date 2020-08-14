#include "Shape.h"

int Shape::objNum = 0;

Shape::Shape(string name, string desc)
{
	this->name = name;
	this->description = desc;
	// Assign unique identity number 
	this->idNum = this->objNum;
	// Increase the count
	++this->objNum;
}

int Shape::getIdNum()
{
	return this->idNum;
}

int Shape::getObjNum()
{
	return objNum;
}
string Shape::getName() const
{
	return this->name;
}

string Shape::getDesc() const
{
	return this->description;
}

void Shape::setName(const string name)
{
	this->name = name;
}

void Shape::setDesc(const string input_desc)
{
	this->description = input_desc;
}

std::ostream& operator<<(std::ostream& stream_obj, const Grid& input_grid)
{
	// Iterate through the 2D grid and use default insertion operator on each char
	// Columns
	for (size_t i = 0; i < input_grid.size(); i++)
	{
		// Rows
		for (size_t j = 0; j < input_grid[0].size(); j++)
		{
			stream_obj << input_grid[i][j];
		}
		// Insert line break after end of row
		stream_obj << endl;
	}
	return stream_obj;
}

std::ostream& operator<<(std::ostream& stream_obj, Shape& input_shape)
{
	// Use toString method on shape objects to enable the use of insertion operator
	stream_obj << input_shape.toString();

	return stream_obj;
}