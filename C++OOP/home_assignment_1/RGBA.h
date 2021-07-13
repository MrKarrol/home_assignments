#pragma once

#include <cstdint>


class RGBA
{
public:
	explicit RGBA();
	explicit RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
	
	void Print() const noexcept;

private:
	uint8_t m_red{};
	uint8_t m_green{};
	uint8_t m_blue{};
	uint8_t m_alpha{255};

};

