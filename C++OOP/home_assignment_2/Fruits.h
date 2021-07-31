#pragma once

#include <cstdint>
#include <string>


class Fruit
{
public:
	Fruit();
	Fruit(const std::string &name, const std::string &color);

	std::string getName() const noexcept;
	std::string getColor() const noexcept;

private:
	std::string m_name;
	std::string m_color;

};


class Apple : public Fruit
{
public:
	explicit Apple(const std::string &color);
	Apple(const std::string &name, const std::string &color);

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