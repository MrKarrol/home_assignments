#pragma once

#include <string>


class Car
{
public:
	Car(const std::string& company, const std::string& model);
	virtual ~Car() = default;
	const std::string& company() const noexcept;
	const std::string& model() const noexcept;

private:
	std::string m_company;
	std::string m_model;

};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(const std::string& company, const std::string& model);

};

class Bus : virtual public Car
{
public:
	Bus(const std::string& company, const std::string& model);
};

class Minivan
	: public PassengerCar
	, public Bus
{
public:
	Minivan(const std::string& company, const std::string& model);

};
