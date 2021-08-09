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
		Pair(std::string&& first, T&& second)
			: m_first(std::forward<std::string>(first))
			, m_second(std::forward<T>(second))
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
		StringValuePair(std::string&& first, T&& second)
			: Pair<std::string, T>(std::forward<std::string>(first), std::forward<T>(second))
		{}

	};

} // end of namespace task3
