#include "RedQueen.h"

#include <algorithm>

#include "Field.h"


RedQueen::RedQueen()
{
}

GameResult RedQueen::IsGameDone(const Field* field, int turn) noexcept
{
	bool has_empty = false;
	for (int y = 0; y < field->GetHeight(); ++ y)
		for (int x = 0; x < field->GetWidth(); ++x)
		{
			if (field->Get({ x, y }) == Figure::Empty)
			{
				has_empty = true;
				continue;
			}

			for (auto&& dir : DIRS)
			{
				if (LookMore(field, field->Get({ x, y }), { x, y }, dir, 2))
				{
					return DefineResult(field->Get({ x, y }));
				}
			}
		}

	if (not has_empty)
		return GameResult::Draw;

	return GameResult::GameContinue;
}

bool RedQueen::LookIntoDirection(const Field* field, const Figure looking_figure, const Coords& pos, const Coords& dir) noexcept
{
	return field->Compare(looking_figure, pos + dir);
}

bool RedQueen::LookMore(const Field* field, const Figure looking_figure, const Coords& pos, const Coords& dir, const int count)
{
	if (count > 1)
		return LookIntoDirection(field, looking_figure, pos, dir) ? LookMore(field, looking_figure, pos + dir, dir, count - 1) : false;
	else
		return LookIntoDirection(field, looking_figure, pos, dir);
}

struct PossibleMove
{
	int count = 0;
	Coords move;
	PossibleMove(const int _count, const Coords _move) : count(_count), move(_move) {}
};

Coords RedQueen::ChooseMove(const Field* field) noexcept
{
	Coords player_interrupt_move;
	bool has_player_interrupt_move = false;
	
	std::vector<PossibleMove> possibilities;

	for (int y = 0; y < field->GetHeight(); ++y)
		for (int x = 0; x < field->GetWidth(); ++x)
		{
			const auto coords = Coords(x, y);
			const auto figure = field->Get(coords);
			switch (figure)
			{
			case PLAYER_FIGURE:
			{
				for (auto&& dir : DIRS)
				{
					if (LookIntoDirection(field, figure, coords, dir))
					{
						if (field->IsFree(coords + dir + dir))
						{
							player_interrupt_move = coords + dir + dir;
							has_player_interrupt_move = true;
						}
						else if (field->IsFree(coords - dir))
						{
							player_interrupt_move = coords - dir;
							has_player_interrupt_move = true;
						}
					}
				}
				break;
			}
			case RED_QUEEN_FIGURE:
			{
				for (auto&& dir : DIRS)
				{
					if (LookIntoDirection(field, figure, coords, dir))
					{
						if (field->IsFree(coords + dir + dir))
						{
							return coords + dir + dir;
						}
						else if (field->IsFree(coords - dir))
						{
							return coords - dir;
						}
					}
				}
				break;
			}
			case Figure::Empty:
			{
				int count = 0;
				for (auto&& dir : DIRS)
				{
					if (field->Get(coords + dir) == Figure::Empty)
						count++;
					else
						count += 2;
				}
				possibilities.emplace_back(count, coords);
				break;
			}
			}
		}

	if (has_player_interrupt_move)
		return player_interrupt_move;

	std::sort(possibilities.begin(), possibilities.end(), [](const auto& a, const auto& b)
		{
			return a.count < b.count;
		});

	if (possibilities.size())
		return possibilities.front().move;

	return {};
}
