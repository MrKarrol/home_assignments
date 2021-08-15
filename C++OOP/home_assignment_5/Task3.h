#pragma once

#include <string>

namespace task3
{
	template<typename U, typename T>
	class Pair {};

	template<typename T>
	class Pair<std::string, T>
	{
	public:
		Pair(const std::string& first, const T& second)
			: m_first(first)
			, m_second(second)
		{}
		Pair(std::string&& first, T&& second)
			: m_first(std::move(first))
			, m_second(std::move(second))
		{}

		const std::string& first() const
		{
			return m_first;
		}

		const T& second() const
		{
			return m_second;
		}

	private:
		std::string m_first;
		T m_second;

	};

	template<typename T>
	class StringValuePair : public Pair<std::string, T>
	{
	public:
		StringValuePair(const std::string& first, const T& second)
			: Pair<std::string, T>(first, second)
		{}
		StringValuePair(std::string&& first, T&& second)
			: Pair<std::string, T>(std::move(first), std::move(second))
		{}

	};

} // end of namespace task3
