#pragma once

#include <vector>

#include "Stuff.h"

class Field;

class RedQueen
{
public:
	explicit RedQueen();

	static GameResult IsGameDone(const Field* field) noexcept;
	static bool LookIntoDirection(const Field* field, const Figure looking_figure, const Coords &pos, const Coords &dir) noexcept;
	static bool LookMore(const Field* field, const Figure looking_figure, const Coords& pos, const Coords& dir, const int count);

	static Coords ChooseMove(const Field* field) noexcept;

};

