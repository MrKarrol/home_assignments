#include "Task3.h"

task3::OffTheField::OffTheField(int x, int y, Dir direction)
	: m_x(x), m_y(y), m_dir(direction)
{
}

task3::Robot::Robot(int x, int y)
	: m_x(x)
	, m_y(y)
{
}

void task3::Robot::move(const Dir dir)
{
	switch (dir)
	{
	case Dir::Up:
		if (m_y == 0)
			throw OffTheField(m_x, m_y, dir);
		--m_y;
		break;
	case Dir::Down:
		if (m_y == 9)
			throw OffTheField(m_x, m_y, dir);
		++m_y;
		break;
	case Dir::Left:
		if (m_x == 0)
			throw OffTheField(m_x, m_y, dir);
		--m_x;
		break;
	case Dir::Right:
		if (m_x == 9)
			throw OffTheField(m_x, m_y, dir);
		++m_x;
		break;
	default:
		throw IllegalCommand();
	}
}

bool task3::Robot::check(int x, int y) const noexcept
{
	return x == m_x and y == m_y;
}
