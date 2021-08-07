#pragma once

#include <functional>
#include <cassert>
#include <iostream>


namespace task1
{

template<typename T>
class Vector
{
public:
	Vector<T>() {}
	~Vector<T>()
	{
		delete[] m_data;
		m_size = 0;
		m_capacity = 0;
	}

	void push_back(const T& new_element)
	{
		if (m_size < m_capacity)
		{
			m_data[m_size] = new_element;
			++m_size;
			return;
		}

		m_capacity = (m_size + 1) * 2;
		T* new_data = new T[m_capacity];

		for (size_t i = 0u; i < m_size; ++i)
			new_data[i] = m_data[i];
		new_data[m_size] = new_element;

		if (m_data)
			delete[] m_data;
		m_data = new_data;
		++m_size;
	}

	T pop_back()
	{
		if (m_size == 0)
			throw std::length_error("");

		--m_size;
		return m_data[m_size];
	}

	T pop_front()
	{
		if (m_size == 0)
			throw std::length_error("");

		T front_element = m_data[0];
		for (size_t i = 1u; i < m_size; ++i)
			m_data[i - 1] = m_data[i];
		--m_size;
		return front_element;
	}

	void sort(std::function<bool(const T&, const T&)> compare)
	{
		fast_sort(m_data, m_size, compare);
	}

	void print()
	{
		for (size_t i = 0u; i < m_size; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	T& operator[](int index)
	{
		if (not (index >= 0 and index < m_size))
			throw std::out_of_range("");

		return m_data[index];
	}

	size_t size() const noexcept
	{
		return m_size;
	}

	size_t capacity() const noexcept
	{
		return m_capacity;
	}

private:
	void fast_sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare)
	{
		if (size < 2)
			return;

		size_t first = 0;
		size_t last = size - 1;
		T mid = data[size / 2];

		do
		{
			while (compare(data[first], mid))
				++first;

			while (compare(mid, data[last]))
				--last;

			if (first <= last)
			{
				T temp = data[first];
				data[first] = data[last];
				data[last] = temp;

				++first;
				--last;
			}
		} while (first <= last);

		if (last > 0)
			fast_sort(data, last + 1, compare);

		if (first < size)
			fast_sort(&data[first], size - first, compare);
	}

private:
	T* m_data = nullptr;
	size_t m_size{};
	size_t m_capacity{};

};


} // end of namespace task1

