#pragma once

#include <iostream>


class Date
{
public:
	Date(int day, int month, int year);

	int GetDay() const noexcept;
	int GetMonth() const noexcept;
	int GetYear() const noexcept;

private:
	int m_day{};
	int m_month{};
	int m_year{};

};

inline std::ostream& operator << (std::ostream& out, const Date& date)
{
	return out << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear();
}

inline std::ostream& operator << (std::ostream& out, const Date* date)
{
	return out << *date;
}