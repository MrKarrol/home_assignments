#include "Master.h"

#include <iostream>

#include "Field.h"
#include "RedQueen.h"


Master::Master()
{

}

void Master::InitializeField()
{
	std::cout << "Enter field height: ";
	int height = 3;
	std::cin >> height;

	std::cout << "Enter field width: ";
	int width = 3;
	std::cin >> width;

	m_field.reset(new Field(height, width));
}

bool Master::IsGameNotDone() const noexcept
{
	return m_isGameNotDone;
}

void Master::MakeMove()	noexcept
{
	++m_turn;
	m_field->PrintField();

	auto result = RedQueen::IsGameDone(m_field.get());
	if (result != GameResult::GameContinue)
	{
		m_isGameNotDone = false;
		m_gameResult = result;
		return;
	}

	std::cout << "Move " << m_turn << std::endl;
	bool is_valid = false;
	while (not is_valid)
	{
		std::cout << "Input your x and y: ";
		int x, y = 0;
		std::cin >> x >> y;
		is_valid = m_field->Set(Figure::Cross, { x, y });
		if (not is_valid)
			std::cout << "Not valid. ";
	}
	
	auto queen_move = RedQueen::ChooseMove(m_field.get());
	if (not m_field->IsCoordsValid(queen_move))
	{
		std::cout << "Red Queen was broken, Player wins!" << std::endl;
		m_isGameNotDone = false;
	}
	else
	{
		m_field->Set(Figure::Nought, queen_move);
	}
	system("cls");
}

void Master::PrintWinner() noexcept
{
	std::cout << "GAME IS OVER" << std::endl;
	switch (m_gameResult)
	{
	case GameResult::AiWins:
	{
		std::cout << "Red Queen wins. Now all troops are destroyed, but world is save.. You will be never forgotten." << std::endl;
		break;
	}
	case GameResult::PlayerWins:
	{
		std::cout << "You wins! You turned off Red Queen and saved your life! But now all world is destroyed... Thanks to you." << std::endl;
		break;
	}
	}
}
