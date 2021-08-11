#pragma once

namespace task2
{

	template<typename T, typename N>
	class Pair
	{
	public:
		Pair(const T& first, const N& second)
			: m_first(first)
			, m_second(second)
		{}
		Pair(T&& first, N&& second)
			: m_first(std::move(first))
			, m_second(std::move(second))
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
