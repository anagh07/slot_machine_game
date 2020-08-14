#pragma once

#include <iostream>
#include <vector>

using std::endl;
using std::string;
using std::vector;
using Grid = vector<vector<char>>;

class Shape
{
public:
	// @TYPE	CONSTRUCTOR
	// @DESC	Takes in name and description
	Shape(string name, string desc);

	// @TYPE	DESTRUCTOR
	// @DESC	Virtual destructor
	virtual ~Shape() = default;

	// @TYPE	METHOD
	// @DESC	Getter method for idNum
	int getIdNum();

	// @TYPE	METHOD
	// @DESC	Getter method for idNum
	static int getObjNum();

	// @TYPE	METHOD
	// @DESC	Getter method for name
	string getName() const;

	// @TYPE	METHOD
	// @DESC	Getter method for description
	string getDesc() const;

	// @TYPE	METHOD
	// @DESC	Setter method for name
	void setName(const string);

	// @TYPE	METHOD
	// @DESC	Setter method for description
	void setDesc(const string);

	// @TYPE	METHOD
	// @DESC	Generates and returns string representation of shape
	//			Set to be overriden in sub-classes
	virtual string toString() = 0;

	// @TYPE	METHOD
	// @DESC	Calculate and return area
	//			Set to be overriden in sub-classes
	virtual double getArea() = 0;

	// @TYPE	METHOD
	// @DESC	Calculate and return perimeter
	//			Set to be overriden in sub-classes
	virtual double getPerimeter() = 0;

	// @TYPE	METHOD
	// @DESC	Calculate and return screen-area
	//			Screen area is the number of characters forming the shape
	virtual double getScreenArea() = 0;

	// @TYPE	METHOD
	// @DESC	Calculate and return screen-perimeter
	//			Number of char in the borders
	virtual double getScreenPerimeter() = 0;

	// @TYPE	METHOD
	// @DESC	Draws textual image of the shape
	//			Set to be overriden in sub-classes
	virtual Grid draw(char draw_char = '*', char border_char = ' ') const = 0;

	// @TYPE	METHOD
	// @DESC	Calculate and return height of the bounding box
	//			Set to be overriden in sub-classes
	virtual int getBoxHeight() = 0;

	// @TYPE	METHOD
	// @DESC	Calculate and return width of the bounding box
	//			Set to be overriden in sub-classes
	virtual int getBoxWidth() = 0;

private:
	int idNum;
	string name;
	string description;
	static int objNum;
};

// @TYPE	OPERATOR OVERLOAD
// @DESC	Overload the insertion operator to handle Grid objects
std::ostream& operator<<(std::ostream&, const Grid&);

// @TYPE	OPERATOR OVERLOAD
// @DESC	Overload the insertion operator to handle Shape objects
std::ostream& operator<<(std::ostream&, const Shape&);
