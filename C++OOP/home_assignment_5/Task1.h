#pragma once

namespace task1
{

	template<typename T>
	class Pair1
	{
	public:
		Pair1(const T& first, const T& second)
			: m_first(first)
			, m_second(second)
		{}

		Pair1(T&& first, T&& second)
			: m_first(std::move(first))
			, m_second(std::move(second))
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


