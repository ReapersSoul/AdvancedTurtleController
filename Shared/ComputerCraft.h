#pragma once
#include "Computer.h"
#include "Turtle.h"
struct ComputerAvalibilityInfo {
	bool InUse = false;
	Computer* comp;
};