#include "Date.h"

#include <exception>


Date::Date(int day, int month, int year)
	: m_day(day)
	, m_month(month)
	, m_year(year)
{
	if (m_day < 0 or m_day > 31)
		throw std::invalid_argument("day must be within [0, 31]");
	else if (m_month < 0 or m_month > 12)
		throw std::invalid_argument("month must be within [0, 12]");
}

int Date::GetDay() const noexcept
{
	return m_day;
}

int Date::GetMonth() const noexcept
{
	return m_month;
}

int Date::GetYear() const noexcept
{
	return m_year;
}
