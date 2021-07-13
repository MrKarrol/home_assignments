#include "RGBA.h"

#include <iostream>


RGBA::RGBA()
{
}

RGBA::RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	: m_red(red)
	, m_green(green)
	, m_blue(blue)
	, m_alpha(alpha)
{
}

void RGBA::Print() const noexcept
{
	std::cout << "Color scheme is: red - "   << static_cast<uint32_t>(m_red) << 
							    ", green - " << static_cast<uint32_t>(m_green) << 
							    ", blue - "  << static_cast<uint32_t>(m_blue) <<
							    ", alpha - " << static_cast<uint32_t>(m_alpha) << std::endl;
}
