#pragma once

#include <string>


class Fraction
{
public:
	Fraction(int numerator, int denominator);
	int numerator() const noexcept;
	int denominator() const noexcept;

	friend Fraction operator+(const Fraction& lv, const Fraction& rv);
	friend Fraction operator-(const Fraction& lv, const Fraction& rv);
	friend Fraction operator*(const Fraction& lv, const Fraction& rv);
	friend Fraction operator/(const Fraction& lv, const Fraction& rv);

	friend bool operator==(const Fraction& lv, const Fraction& rv);
	friend bool operator!=(const Fraction& lv, const Fraction& rv);
	friend bool operator<(const Fraction& lv, const Fraction& rv);
	friend bool operator>(const Fraction& lv, const Fraction& rv);
	friend bool operator<=(const Fraction& lv, const Fraction& rv);
	friend bool operator>=(const Fraction& lv, const Fraction& rv);

	Fraction operator-() const
	{
		return Fraction(-m_numerator, -m_denominator);
	}

	std::string str() const noexcept;

private:
	int m_numerator{};
	int m_denominator{1};

};

Fraction operator+(const Fraction& lv, const Fraction& rv);
Fraction operator-(const Fraction& lv, const Fraction& rv);
Fraction operator*(const Fraction& lv, const Fraction& rv);
Fraction operator/(const Fraction& lv, const Fraction& rv);

bool operator==(const Fraction& lv, const Fraction& rv);
bool operator!=(const Fraction& lv, const Fraction& rv);
bool operator<(const Fraction& lv, const Fraction& rv);
bool operator>=(const Fraction& lv, const Fraction& rv);
bool operator>(const Fraction& lv, const Fraction& rv);
bool operator<=(const Fraction& lv, const Fraction& rv);
