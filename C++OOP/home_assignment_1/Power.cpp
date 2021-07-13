#include "Power.h"

#include <iostream>


Power::Power()
	: m_number_1(5)
	, m_number_2(5)
{
}

void Power::Set(float number_1, float number_2) noexcept
{
	m_number_1 = number_1;
	m_number_2 = number_2;
}

void Power::Calculate() const noexcept
{
	std::cout << m_number_1 << " to the power of " << m_number_2 << " is " << std::pow(m_number_1, m_number_2) << std::endl;
}
