#include "RedQueen.h"

#include "Field.h"


RedQueen::RedQueen()
{
}

GameResult RedQueen::IsGameDone(const Field* field) noexcept
{
	for (int y = 0; y < field->GetHeight(); ++ y)
		for (int x = 0; x < field->GetWidth(); ++x)
		{
			if (field->Get({ x, y }) == Figure::Empty)
				continue;

			for (auto&& dir : DIRS)
			{
				if (LookMore(field, field->Get({ x, y }), { x, y }, dir, 2))
				{
					return DefineResult(field->Get({ x, y }));
				}
			}
		}

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

Coords RedQueen::ChooseMove(const Field* field) noexcept
{
	for (int y = 0; y < field->GetHeight(); ++y)
		for (int x = 0; x < field->GetWidth(); ++x)
			if (field->Get({ x, y }) == Figure::Empty)
				return { x, y };
	return Coords();
}
