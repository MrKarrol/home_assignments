#include "Student.h"


Person::Person()
	: m_name("")
	, m_age(0)
	, m_is_male(false)
	, m_weight(0)
{
}

Person::Person(std::string name, int age, bool is_male, float weight)
	: m_name(name)
	, m_age(age)
	, m_is_male(is_male)
	, m_weight(weight)
{

}

void Person::SetName(std::string name) noexcept
{
	m_name = name;
}

std::string Person::Name() const noexcept
{
	return m_name;
}

void Person::SetAge(int age) noexcept
{
	m_age = age;
}

int Person::Age() const noexcept
{
	return m_age;
}

void Person::SetWeight(float weight) noexcept
{
	m_weight = weight;
}

float Person::Weight() const noexcept
{
	return m_weight;
}

bool Person::IsMale() const noexcept
{
	return m_is_male;
}

//-------------------------------------------------------------------------------------

Student::Student(std::string name, int age, bool is_male, float weight, int education_year)
	: Person(name, age, is_male, weight)
	, m_education_year(education_year)
{
}

void Student::ChangeYear(int education_year)
{
	m_education_year = education_year;
}

void Student::ToNextYear()
{
	++m_education_year;
}

int Student::Year() const noexcept
{
	return m_education_year;
}
