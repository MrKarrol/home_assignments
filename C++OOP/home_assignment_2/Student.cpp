#include "Student.h"


Person::Person()
	: m_name("")
	, m_age(0)
	, m_is_man(false)
	, m_weight(0)
{
}

Person::Person(std::string name, int age, bool is_men, float weight)
	: m_name(name)
	, m_age(age)
	, m_is_man(is_men)
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

bool Person::IsMan() const noexcept
{
	return m_is_man;
}

Student::Student()
	: Person()
{
}

Student::Student(int education_year)
	: Person()
	, m_education_year(education_year)
{
}

Student::Student(std::string name, int age, bool is_men, float weight)
	: Person(name, age, is_men, weight)
{
}

Student::Student(std::string name, int age, bool is_men, float weight, int education_year)
	: Person(name, age, is_men, weight)
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
