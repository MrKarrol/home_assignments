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
			m_field[row][col] = Figure::Empty;
	}
}

Field::~Field()
{
	if (m_field)
		for (int row = 0; row < m_height; ++row)
			delete[] m_field[row];
	delete[] m_field;
}

int Field::GetHeight() const noexcept
{
	return m_height;
}

int Field::GetWidth() const noexcept
{
	return m_width;
}

void Field::PrintField() const noexcept
{
	std::cout << "  x ";
	for (int col = 0; col < m_width; ++col)
		std::cout << std::setw(3) << std::setfill(' ') << col;
	std::cout << std::endl << "    ";
	for (int col = 0; col < m_width + 1; ++col)
		std::cout << std::setw(3) << std::setfill('_') << "_";

	std::cout << std::endl << "y" << std::endl;

	for (int row = 0; row < m_height; ++row)
	{
		std::cout << row << " | ";
		for (int col = 0; col < m_width; ++col)
		{
			std::cout << std::setw(3) << std::setfill(' ') << ToChar(m_field[row][col]);
		}
		std::cout << "   | " << std::endl;
	}

	std::cout << "    ";
	for (int col = 0; col < m_width + 1; ++col)
		std::cout << std::setw(3) << std::setfill('_') << "_";
	std::cout << std::endl;
}

bool Field::IsCoordsValid(const Coords& coords) const noexcept
{
	if (coords.x < 0 or coords.x > m_width - 1)
		return false;

	if (coords.y < 0 or coords.y > m_height - 1)
		return false;

	return true;
}

bool Field::Set(const Figure figure, const Coords &coords) noexcept
{
	if (Get(coords) != Figure::Empty)
		return false;

	m_field[coords.y][coords.x] = figure;

	return true;
}

Figure Field::Get(const Coords& coords) const noexcept
{
	return IsCoordsValid(coords) ? m_field[coords.y][coords.x] : Figure::NoFigure;
}

bool Field::Compare(const Figure figure, const Coords& coords) const noexcept
{
	return Get(coords) == figure;
}
