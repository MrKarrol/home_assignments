#include "Master.h"

#include <iostream>

#include "Field.h"
#include "RedQueen.h"


Master::Master()
{

}

void Master::InitializeField()
{
	int height = 3;
	do
	{
		std::cout << "Enter field height: ";

		std::cin >> height;
		if (height < 3)
			std::cout << "Height must be >= 3. ";
	} while (height < 3);
	
	int width = 3;
	do
	{
		std::cout << "Enter field width: ";
		
		std::cin >> width;
		if (width < 3)
			std::cout << "Width must be >= 3. ";
	} while (width < 3);

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

	auto result = RedQueen::IsGameDone(m_field.get(), m_turn);
	
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
		if (not m_field->IsFree({ x, y }))
		{
			std::cout << "Not valid. ";
			continue;
		}
		is_valid = m_field->Set(PLAYER_FIGURE, { x, y });
		if (not is_valid)
			std::cout << "Not valid. ";
	}

	result = RedQueen::IsGameDone(m_field.get(), m_turn);
	if (result != GameResult::GameContinue)
	{
		system("cls");
		return;
	}
	
	auto queen_move = RedQueen::ChooseMove(m_field.get());
	std::cout << "Queen choosing " << queen_move.x << " " << queen_move.y << std::endl;
	if (not m_field->IsCoordsValid(queen_move))
	{
		std::cout << "Red Queen was broken, Player wins!" << std::endl;
		m_isGameNotDone = false;
	}
	else
	{
		m_field->Set(RED_QUEEN_FIGURE, queen_move);
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
	case GameResult::Draw:
	{
		std::cout << "Wow. Draw. You made up talk with Red Queen. Maybe you will leave this place..." << std::endl;
		break;
	}
	}
}
