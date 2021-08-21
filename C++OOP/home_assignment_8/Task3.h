#pragma once

#include <iostream>


namespace task3
{
	enum class Dir
	{
		NoDir = 0,
		Up,
		Down,
		Left,
		Right
	};

	inline Dir GetFromInput(char input)
	{
		switch (input)
		{
		case 'u':
			return Dir::Up;
		case 'd':
			return Dir::Down;
		case 'l':
			return Dir::Left;
		case 'r':
			return Dir::Right;
		default:
			return Dir::NoDir;
		}
	}

	class IllegalCommand
	{
	public:
		friend std::ostream& operator << (std::ostream&, const IllegalCommand&);
	};

	inline std::ostream& operator << (std::ostream& out, const IllegalCommand &)
	{
		return out << "this is illegal direction, try another";
	}

	inline std::string DirToStr(const Dir dir)
	{
		switch (dir)
		{
		case Dir::Up:
			return "Up";
		case Dir::Down:
			return "Down";
		case Dir::Left:
			return "Left";
		case Dir::Right:
			return "Right";
		default:
			throw IllegalCommand();
		}
	}

	class OffTheField
	{
	public:
		OffTheField(int x, int y, Dir direction);
		friend std::ostream& operator << (std::ostream&, const OffTheField&);

	private:
		int m_x{};
		int m_y{};
		Dir m_dir = Dir::NoDir;
	};

	inline std::ostream& operator << (std::ostream& out, const OffTheField& obj)
	{
		return out << "trying off the field from [" << obj.m_x << ", " << obj.m_y << "], going " << DirToStr(obj.m_dir);
	}

	class Robot
	{
	public:
		Robot(int x, int y);

		void move(const Dir);
		bool check(int x, int y) const noexcept;
		friend std::ostream& operator << (std::ostream&, const Robot&);

	private:
		int m_x{ 5 };
		int m_y{ 5 };

	};

	inline std::ostream& operator << (std::ostream& out, const Robot& robo)
	{
		return out << "Robot is placed in [" << robo.m_x << ", " << robo.m_y << "]";
	}
}
