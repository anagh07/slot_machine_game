#include "RightTriangle.h"

#include <string>
#include <typeinfo>

using std::to_string;

RightTriangle::RightTriangle(int input_base, string input_name, string input_desc) : Triangle(input_base, input_name, input_desc)
{
	this->height = input_base;
	this->id = getObjNum();
}

string RightTriangle::toString()
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
	buffer.append(to_string(Triangle::getArea()));
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

double RightTriangle::getPerimeter()
{
	return (2 + sqrt(2)) * static_cast<double>(this->height);
}

double RightTriangle::getScreenArea()
{
	return static_cast<double>(this->height) * (static_cast<double>(this->height) + 1) / 2;
}

double RightTriangle::getScreenPerimeter()
{
	return 3 * (static_cast<double>(this->height) - 1);
}

Grid RightTriangle::draw(char draw_char, char border_char) const
{
	// Buffer for temporary storage of image
	Grid grid;

	// rows
	for (int i = 1; i <= this->height; i++)
	{
		vector<char> buffer;
		// draw
		for (int j = 1; j <= i ; j++)
		{
			buffer.push_back(draw_char);
		}
		// blanks
		for (int k = 1; k <= (this->height - 1); k++)
		{
			buffer.push_back(border_char);
		}

		grid.push_back(buffer);
	}
	return grid;
}

int RightTriangle::getBoxHeight()
{
	return this->height;
}

int RightTriangle::getBoxWidth()
{
	return this->base;
}