#include "Task2.h"

#include <iostream>


Car::Car(const std::string& company, const std::string& model)
    : m_company(company)
    , m_model(model)
{
    std::cout << "Car" << std::endl;
}

const std::string& Car::company() const noexcept
{
    return m_company;
}

const std::string& Car::model() const noexcept
{
    return m_model;
}

PassengerCar::PassengerCar(const std::string& company, const std::string& model)
    : Car(company, model)
{
    std::cout << "PassengerCar" << std::endl;
}

Bus::Bus(const std::string& company, const std::string& model)
    : Car(company, model)
{
    std::cout << "Bus" << std::endl;
}

Minivan::Minivan(const std::string& company, const std::string& model)
    : PassengerCar(company, model)
    , Bus(company, model)
    , Car(company, model)
{
    std::cout << "Minivan" << std::endl;
}
