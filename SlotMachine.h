#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <array>

#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class SlotMachine
{
public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine&) = delete;
	SlotMachine(SlotMachine&&) = delete;
	SlotMachine& operator=(const SlotMachine&) = delete;
	SlotMachine& operator=(SlotMachine&&) = delete;
	virtual ~SlotMachine() = default;
	void run();
	int currentTCount, tWon, bet;

private:
	std::array<std::unique_ptr<Shape>, 3> reel{};
	void make_shapes();
	// void make_shape(int k);
	string display();
};
