#pragma once

namespace task1
{

	template<typename T>
	class Pair1
	{
	public:
		Pair1(T&& first, T&& second)
			: m_first(std::forward<T>(first))
			, m_second(std::forward<T>(second))
		{}

		const T& first() const
		{
			return m_first;
		}
		const T& second() const
		{
			return m_second;
		}

	private:
		T m_first;
		T m_second;

	};

} // end of namespace task1


