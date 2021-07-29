#pragma once

#include <cstdint>
#include <string>


class Fruit
{
public:
	Fruit();
	Fruit(std::string name, std::string color);

	std::string getName() const noexcept;
	std::string getColor() const noexcept;

private:
	std::string m_name;
	std::string m_color;

};

class Apple : public Fruit
{
public:
	Apple(std::string color);
	Apple(std::string name, std::string color);

};

class GrannySmith : public Apple
{
public:
	GrannySmith();

};

class Banana : public Fruit
{
public:
	Banana();

};