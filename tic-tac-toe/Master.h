#pragma once

#include <memory>

#include "Stuff.h"

class Field;

class Master
{
public:
	explicit Master();

	void InitializeField();

	bool IsGameNotDone() const noexcept;

	void MakeMove() noexcept;

	void PrintWinner() noexcept;

private:
	std::unique_ptr<Field> m_field;

private:
	bool m_isGameNotDone = true;
	int m_turn = 0;
	GameResult m_gameResult{ GameResult::GameContinue };
};

