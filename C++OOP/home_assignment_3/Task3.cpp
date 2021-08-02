#include "Task3.h"

#include <iostream>


Fraction::Fraction(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (m_denominator == 0)
		throw std::invalid_argument("denominator can't be zero");
}

int Fraction::numerator() const noexcept
{
	return m_numerator;
}

int Fraction::denominator() const noexcept
{
	return m_denominator;
}

std::string Fraction::str() const noexcept
{
	return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);
}

Fraction operator+(const Fraction& lv, const Fraction& rv)
{
	return Fraction(lv.m_numerator * rv.m_denominator + rv.m_numerator * lv.m_denominator, lv.m_denominator * rv.m_denominator);
}

Fraction operator-(const Fraction& lv, const Fraction& rv)
{
	return Fraction(lv.m_numerator * rv.m_denominator - rv.m_numerator * lv.m_denominator, lv.m_denominator * rv.m_denominator);
}

Fraction operator*(const Fraction& lv, const Fraction& rv)
{
	return Fraction(lv.m_numerator * rv.m_numerator, lv.m_denominator * rv.m_denominator);
}

Fraction operator/(const Fraction& lv, const Fraction& rv)
{
	return Fraction(lv.m_numerator * rv.m_denominator, lv.m_denominator * rv.m_numerator);
}

bool operator==(const Fraction& lv, const Fraction& rv)
{
	return lv.m_numerator * rv.m_denominator == rv.m_numerator * lv.m_denominator;
}

bool operator!=(const Fraction& lv, const Fraction& rv)
{
	return not (lv == rv);
}

bool operator<(const Fraction& lv, const Fraction& rv)
{
	return lv.m_numerator * rv.m_denominator < rv.m_numerator * lv.m_denominator;
}

bool operator>=(const Fraction& lv, const Fraction& rv)
{
	return not (lv < rv);
}

bool operator>(const Fraction& lv, const Fraction& rv)
{
	return lv.m_numerator * rv.m_denominator > rv.m_numerator * lv.m_denominator;
}

bool operator<=(const Fraction& lv, const Fraction& rv)
{
	return not (lv > rv);
}
