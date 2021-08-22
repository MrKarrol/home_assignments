#pragma once

#include <iostream>


namespace task2
{
	class Ex
	{
	public:
		explicit Ex(double _x);
		friend std::ostream& operator << (std::ostream&, const Ex&);

	private:
		double x{};
	};

	class Bar
	{
	public:
		Bar();

		void set(double a);

	private:
		double y{};
	};

	inline std::ostream& operator << (std::ostream& out, const Ex& ex)
	{
		return out << ex.x;
	}
}

