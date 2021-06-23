#include "Field.h"

#include <iostream>
#include <iomanip>

Field::Field(int height, int width)
	: m_height(height)
	, m_width(width)
{
	m_field = new Figure * [m_height];
	for (int row = 0; row < m_height; ++row)
	{
		m_field[row] = new Figure[m_width];
		for (int col = 0; col < m_width; ++col)
			m_field[row][col] = Figure::Cross;
	}
}

Field::~Field()
{
	if (m_field)
		for (int row = 0; row < m_height; ++row)
			delete[] m_field[row];
	delete[] m_field;
}

void Field::PrintField() const noexcept
{
	std::cout << "    ";
	for (int col = 0; col < m_width; ++col)
		std::cout << std::setw(3) << std::setfill(' ') << col;
	std::cout << std::endl << "    ";
	for (int col = 0; col < m_width + 1; ++col)
		std::cout << std::setw(3) << std::setfill('_') << "_";

	std::cout << std::endl << std::endl;

	for (int row = 0; row < m_height; ++row)
	{
		std::cout << row << " | ";
		for (int col = 0; col < m_width; ++col)
		{
			std::cout << std::setw(3) << std::setfill(' ') << ToChar(m_field[row][col]);
		}
		std::cout << std::endl;
	}

	std::cout << "    ";
	for (int col = 0; col < m_width + 1; ++col)
		std::cout << std::setw(3) << std::setfill('_') << "_";
	std::cout << std::endl;
}
