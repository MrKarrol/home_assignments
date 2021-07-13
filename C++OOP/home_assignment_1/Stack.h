#pragma once



class Stack
{
	constexpr static size_t data_max_size = 10;
public:
	explicit Stack();
	~Stack();
	void reset();
	bool push(const int);
	int pop();
	void print() const noexcept;

private:
	size_t m_size{};
	int m_data[data_max_size]{};

};

