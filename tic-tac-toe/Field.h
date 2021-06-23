#pragma once

#include "Stuff.h"

class Field
{
public:
	explicit Field(int height, int width);
	~Field();

	void PrintField() const noexcept;

private:
	Figure** m_field;

	const int m_height;
	const int m_width;

};

