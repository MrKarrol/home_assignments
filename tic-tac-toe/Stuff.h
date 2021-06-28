#pragma once

#include <iostream>
#include <vector>


enum class Figure
{
	NoFigure = 0,
	Empty,
	Nought,
	Cross
};

const Figure PLAYER_FIGURE = Figure::Cross;
const Figure RED_QUEEN_FIGURE = Figure::Nought;

inline char ToChar(Figure f)
{
	switch (f)
	{
	case Figure::Empty:
		return ' ';
	case Figure::Nought:
		return '0';
	case Figure::Cross:
		return 'X';
	default:
		std::cerr << "it's message must never be" << std::endl;
		return '?';
	}
}

enum class GameResult
{
	NoResult = 0,
	GameContinue,
	AiWins,
	PlayerWins,
	Draw
};

inline GameResult DefineResult(const Figure figure)
{
	switch (figure)
	{
	case PLAYER_FIGURE:
		return GameResult::PlayerWins;
	case RED_QUEEN_FIGURE:
		return GameResult::AiWins;
	default:
	{
		std::cerr << "Error while defining who wins" << std::endl;
		return GameResult::NoResult;
	}

	}
}

struct Coords
{
	int x = 0;
	int y = 0;
	Coords() {}
	Coords(const int _x, const int _y) : x(_x), y(_y) {}
};

inline Coords operator +(const Coords& lv, const Coords& rv)
{
	return { lv.x + rv.x, lv.y + rv.y };
}

inline Coords operator -(const Coords& lv, const Coords& rv)
{
	return { lv.x - rv.x, lv.y - rv.y };
}

const std::vector<Coords> DIRS = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };