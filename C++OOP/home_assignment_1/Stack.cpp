#include "Stack.h"

#include <iostream>


Stack::Stack()
{
	reset();
}

Stack::~Stack()
{
}

void Stack::reset()
{
	for (int i = 0; i < data_max_size; ++i)
		m_data[i] = 0;
	m_size = 0;
}

bool Stack::push(const int new_member)
{
	if (m_size == 10)
		return false;

	m_data[m_size] = new_member;
	m_size++;
	return true;
}

int Stack::pop()
{
	if (m_size == 0)
	{
		std::cerr << "stack size is " << m_size << ", can't pop" << std::endl;
		return 0;
	}
	const auto poppped_item = m_data[m_size];
	m_size--;
	return poppped_item;
}

void Stack::print() const noexcept
{
	std::cout << "( ";

	if (m_size == 0)
	{
		std::cout << ")" << std::endl;
		return;
	}

	for (int i = 0; i < m_size; ++i)
		std::cout << m_data[i] << " ";

	std::cout << ")" << std::endl;
}
