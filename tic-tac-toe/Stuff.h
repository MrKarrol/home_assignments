#pragma once

#include <iostream>

enum class Figure
{
	Empty = 0,
	Nought,
	Cross
};

inline char ToChar(Figure f)
{
	switch (f)
	{
	case Figure::Empty:
		return ' ';
	case Figure::Nought:
		return '0';
	case Figure::Cross:
		return 'X';
	default:
		std::cerr << "it's message must never be" << std::endl;
		return ' ';
	}
}