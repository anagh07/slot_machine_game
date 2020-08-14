#include "AcuteTriangle.h"

#include <string>
#include <typeinfo>

using std::to_string;

AcuteTriangle::AcuteTriangle(int input_base, string input_name, string input_desc) : Triangle(input_base, input_name, input_desc)
{
	if (input_base % 2 == 0)
	{
		this->base = input_base + 1;
	}
	this->height = (input_base + 1) / 2;
	this->id = getObjNum();
}

string AcuteTriangle::toString()
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

double AcuteTriangle::getPerimeter()
{
	double buffer = this->base + sqrt(pow(this->base, 2) + 4 * pow(this->height, 2));
	return buffer;
}

double AcuteTriangle::getScreenArea()
{
	return pow(static_cast<double>(this->height), 2);
}

double AcuteTriangle::getScreenPerimeter()
{
	return 4 * (static_cast<double>(this->height) -1);
}

Grid AcuteTriangle::draw(char draw_char, char border_char) const
{
	// Buffer for temporary storage of image
	Grid grid;

	// rows
	for (int i = 1; i <= this->height; i++)
	{
		vector<char> buffer;
		// blanks
		for (int k = this->height -1; k >= i; k--)
		{
			buffer.push_back(border_char);
		}
		// draw
		for (int j = 1; j <= (2 * i - 1); j++)
		{
			buffer.push_back(draw_char);
		}
		// blanks
		for (int k = this->height - 1; k >= i; k--)
		{
			buffer.push_back(border_char);
		}

		grid.push_back(buffer);
	}
	return grid;
}

int AcuteTriangle::getBoxHeight()
{
	return this->height;
}

int AcuteTriangle::getBoxWidth()
{
	return this->base;
}