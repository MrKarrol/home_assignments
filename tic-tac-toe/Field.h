#pragma once

#include "Stuff.h"

class Field
{
public:
	explicit Field(int height, int width);
	~Field();

	int GetHeight() const noexcept;
	int GetWidth() const noexcept;

	void PrintField() const noexcept;

	bool IsCoordsValid(const Coords &coords) const noexcept;
	bool IsFree(const Coords& coords) const noexcept;

	bool Set(const Figure figure, const Coords &coords) noexcept;
	Figure Get(const Coords& coords) const noexcept;
	Figure Get(const int x, const int y) const noexcept;
	bool Compare(const Figure figure, const Coords& coords) const noexcept;

private:
	Figure** m_field;

	const int m_height;
	const int m_width;

};

