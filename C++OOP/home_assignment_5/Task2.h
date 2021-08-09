#pragma once

namespace task2
{

	template<typename T, typename N>
	class Pair
	{
	public:
		Pair(T&& first, N&& second)
			: m_first(std::forward<T>(first))
			, m_second(std::forward<N>(second))
		{}
		const T& first() const
		{
			return m_first;
		}
		const N& second() const
		{
			return m_second;
		}

	private:
		T m_first;
		N m_second;

	};

} // end of namespace task2
