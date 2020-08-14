#include "Rectangle.h"

#include <typeinfo>
#include <iomanip>
#include <string>

using std::to_string;

Rectangle::Rectangle(int height, int width, string input_name, string input_desc) : Shape(input_name, input_desc)
{
	this->height = height;
	this->width = width;
	this->id = getObjNum();
}

string Rectangle::toString()
{
	string buffer;

	buffer.append("Shape information");
	buffer.append("\n");
	buffer.append("-----------");
	buffer.append("\n");

	buffer.append("id:\t\t\t");
	buffer.append(to_string(id));
	buffer.append("\n");

	buffer.append("Shape name:\t\t");
	buffer.append(getName());
	buffer.append("\n");

	buffer.append("Description:\t\t");
	buffer.append(getDesc());
	buffer.append("\n");

	buffer.append("B. box width:\t\t");
	buffer.append(to_string(getBoxWidth()));
	buffer.append("\n");

	buffer.append("B. box height:\t\t");
	buffer.append(to_string(getBoxHeight()));
	buffer.append("\n");

	buffer.append("Scr area:\t\t");
	buffer.append(to_string(getScreenArea()));
	buffer.append("\n");

	buffer.append("Geo area:\t\t");
	buffer.append(to_string(getArea()));
	buffer.append("\n");

	buffer.append("Scr perimeter:\t\t");
	buffer.append(to_string(getScreenPerimeter()));
	buffer.append("\n");

	buffer.append("Geo perimeter:\t\t");
	buffer.append(to_string(getPerimeter()));
	buffer.append("\n");

	buffer.append("Static type:\t\t");
	buffer.append(typeid(this).name());
	buffer.append("\n");

	buffer.append("Dynamic type:\t\t");
	buffer.append(typeid(*this).name());
	buffer.append("\n");

	return buffer;
}

double Rectangle::getArea()
{
	return static_cast<double>(this->width) * static_cast<double>(this->height);
}

double Rectangle::getPerimeter()
{
	// use given formula
	return 2 * (static_cast<double>(this->width) + static_cast<double>(this->height));
}

double Rectangle::getScreenArea()
{
	return static_cast<double>(this->width) * static_cast<double>(this->height);
}

double Rectangle::getScreenPerimeter()
{
	return 2 * (static_cast<double>(this->width) + static_cast<double>(this->height)) - 4;
}

Grid Rectangle::draw(char draw_char, char border_char) const
{
	// Store rectangle image in a 2d vector
	// grid[i][j]
	Grid grid;

	// iterate through grid[i] (rows)
	for (int i = 0; i < this->height; i++)
	{
		// temporary buffer for each row
		vector<char> buffer;
		// iterate through grid[i][j] (columns)
		for (int j = 0; j < this->width; j++)
		{
			buffer.push_back(draw_char);
		}
		// append each column to each row
		grid.push_back(buffer);
	}

	return grid;
}

int Rectangle::getBoxHeight()
{
	return this->height;
}

int Rectangle::getBoxWidth()
{
	return this->width;
}