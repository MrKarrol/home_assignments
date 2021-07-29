#include "Fruits.h"

Fruit::Fruit()
{
}

Fruit::Fruit(std::string name, std::string color)
	: m_name(name)
	, m_color(color)
{
}

std::string Fruit::getName() const noexcept
{
	return m_name;
}

std::string Fruit::getColor() const noexcept
{
	return m_color;
}

Apple::Apple(std::string color)
	: Fruit("apple", color)
{
}

Apple::Apple(std::string name, std::string color)
	: Fruit(name, color)
{
}

Banana::Banana()
	: Fruit("banana", "yellow")
{

}

GrannySmith::GrannySmith()
	: Apple("Granny Smith apple", "green")
{
}
