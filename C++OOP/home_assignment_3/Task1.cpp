#include "Task1.h"

#define _USE_MATH_DEFINES
#include <cmath>
//! о переопределении метода double area() const - в реальном коде
//! правильнее будет оставить определённый метод double Parallelogram::area() const у всех его потомков
//! Также, Square лучше сделать наследником Rectangle


Parallelogram::Parallelogram(double width, double height, double alpha)
	: m_width(width)
	, m_height(height)
	, m_alpha(alpha * M_PI / 180)
{
}

double Parallelogram::area() const
{
	return m_width * m_height * std::sin(m_alpha);
}

double Parallelogram::width() const noexcept
{
	return m_width;
}

double Parallelogram::height() const noexcept
{
	return m_height;
}

double Parallelogram::alpha() const noexcept
{
	return m_alpha * 180 / M_PI;
}

//-------------------------------------------------------------------------------------

Circle::Circle(double radius)
	: m_radius(radius)
{
}

double Circle::area() const
{
	return M_PI * m_radius * m_radius;
}

double Circle::radius() const noexcept
{
	return m_radius;
}

//-------------------------------------------------------------------------------------

Rectangle::Rectangle(double width, double height)
	: Parallelogram(width, height, 90.f)
{
}

double Rectangle::area() const
{
	return m_width * m_height;
}

//-------------------------------------------------------------------------------------

Square::Square(double side)
	: Parallelogram(side, side, 90.0f)
{
}

double Square::area() const
{
	return m_width * m_width;
}

//-------------------------------------------------------------------------------------

Rhombus::Rhombus(double side, double alpha)
	: Parallelogram(side, side, alpha)
{
}

double Rhombus::area() const
{
	return m_width * m_width * std::sin(m_alpha);
}
