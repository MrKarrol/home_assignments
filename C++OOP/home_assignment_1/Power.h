#pragma once

class Power
{
public:
	explicit Power();
	void Set(float number_1, float number_2) noexcept;
	void Calculate() const noexcept;

private:
	float m_number_1{};
	float m_number_2{};

};

