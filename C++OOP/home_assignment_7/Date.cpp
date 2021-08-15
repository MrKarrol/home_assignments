#include "Date.h"


Date::Date(int day, int month, int year)
	: m_day(day)
	, m_month(month)
	, m_year(year)
{}

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
