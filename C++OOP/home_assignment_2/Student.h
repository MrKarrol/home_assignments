#pragma once

#include <string>


class Person
{
public:
	Person();
	/*Weight counts in kg*/
	Person(std::string name, int age, bool is_men, float weight);

	void SetName(std::string name) noexcept;
	std::string Name() const noexcept;

	void SetAge(int age) noexcept;
	int Age() const noexcept;

	/*Set weight in kg*/
	void SetWeight(float weight) noexcept;
	/*Weight in kg*/
	float Weight() const noexcept;

	bool IsMan() const noexcept;

private:
	std::string m_name;
	int m_age{};
	bool m_is_man{};
	/*Weight counts in kg*/
	float m_weight{};

};


class Student : public Person
{
public:
	Student();
	Student(int education_year);
	/*Weight counts in kg*/
	Student(std::string name, int age, bool is_men, float weight);
	/*Weight counts in kg*/
	Student(std::string name, int age, bool is_men, float weight, int education_year);

	void ChangeYear(int education_year);
	void ToNextYear();
	int Year() const noexcept;

private:
	int m_education_year{};

};