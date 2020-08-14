#include <iostream>
#include <vector>
#include <string>

#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include "SlotMachine.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main ()
{
	Rectangle rect(4, 7, "rectan", "drawing");
	cout << rect.toString();
	cout << endl;
	Grid rectangle_image;
	rectangle_image = rect.draw();
	cout << rectangle_image << endl;

	Rhombus rhom(12, "rhom", "my_rhom");
	cout << rhom.toString();
	cout << endl;
	Grid rhombus_image;
	rhombus_image = rhom.draw();
	cout << rhombus_image << endl;

	AcuteTriangle act(13, "acute", "my_acute");
	cout << act.toString();
	cout << endl;
	Grid acute_image;
	acute_image = act.draw();
	cout << acute_image << endl;

	RightTriangle rat(8, "right", "my_rightangle");
	cout << rat.toString();
	cout << endl;
	Grid right_image;
	right_image = rat.draw();
	cout << right_image << endl;

	SlotMachine slots;
	slots.run();
}