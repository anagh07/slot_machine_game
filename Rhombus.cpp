#include "Rhombus.h"

#include <typeinfo>
#include <string>

using std::to_string;

Rhombus::Rhombus(int input_diagonal, string input_name, string input_desc) : Shape(input_name, input_desc)
{
	if (input_diagonal % 2 == 0) this->diagonal = input_diagonal + 1;
	else this->diagonal = input_diagonal;
	this->id = getObjNum();
}

string Rhombus::toString()
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

double Rhombus::getArea()
{
	return pow(static_cast<double>(this->diagonal), 2) / 2;
}

double Rhombus::getPerimeter()
{
	return 2 * sqrt(2) * this->diagonal;
}

double Rhombus::getScreenArea()
{
	double n = this->diagonal / 2;
	return 2 * n * (n + 1) + 1;
}

double Rhombus::getScreenPerimeter()
{
	return 2 * (static_cast<double>(this->diagonal) - 1);
}

Grid Rhombus::draw(char draw_char, char border_char) const
{
	// declare temporary image store
	Grid grid;
	int na = 0;

	// iterate through all rows
	for (int i = 1; i <= this->diagonal; i++)
	{
		vector<char> row_buffer;
		// upper half of diamond
		// width increases
		if (i <= (this->diagonal+1) / 2)
		{
			// blank space before
			for (int j = this->diagonal / 2; j >= i; j--)
			{
				row_buffer.push_back(border_char);
			}
			// shape character
			for (int j = 1; j <= (2*i-1); j++)
			{
				row_buffer.push_back(draw_char);
			}
			// black spaces after
			for (int j = this->diagonal / 2; j >= i; j--)
			{
				row_buffer.push_back(border_char);
			}
			na = 2 * i - 3;
		}
		// lower half of the diamond
		// width decreases
		else
		{
			// blank space before
			for (int j = (this->diagonal/2); j < i-1; j++)
			{
				row_buffer.push_back(border_char);
			}
			// shape character
			for (int j = 1; j <= na; j++)
			{
				row_buffer.push_back(draw_char);
			}
			// blank space after
			for (int j = (this->diagonal / 2); j < i - 1; j++)
			{
				row_buffer.push_back(border_char);
			}
			na = na - 2;
		}
		grid.push_back(row_buffer);
	}
	return grid;
}

int Rhombus::getBoxHeight()
{
	return this->diagonal;
}

int Rhombus::getBoxWidth()
{
	return this->diagonal;
}