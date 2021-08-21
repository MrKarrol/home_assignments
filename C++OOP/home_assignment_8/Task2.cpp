#include "Task2.h"

task2::Ex::Ex(double _x)
	: x(_x)
{
}

task2::Bar::Bar()
	: y(0.f)
{
}

void task2::Bar::set(double a)
{
	if (y + a > 100)
		throw Ex(a * y);
	y = a;
}
