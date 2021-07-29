#pragma once

#include <string>


class Person
{
public:
	Person();
	/*Weight counts in kg*/
	Person(std::string name, int age, bool is_male, float weight);

	void SetName(std::string name) noexcept;
	std::string Name() const noexcept;

	void SetAge(int age) noexcept;
	int Age() const noexcept;

	/*Set weight in kg*/
	void SetWeight(float weight) noexcept;
	/*Weight in kg*/
	float Weight() const noexcept;

	bool IsMale() const noexcept;

private:
	std::string m_name;
	int m_age{};
	bool m_is_male{};
	/*Weight counts in kg*/
	float m_weight{};

};


class Student : public Person
{
public:
	/*Weight counts in kg*/
	Student(std::string name, int age, bool is_male, float weight, int education_year);

	void ChangeYear(int education_year);
	void ToNextYear();
	int Year() const noexcept;

private:
	int m_education_year{};

};