#pragma once

class Figure
{
public:
	virtual ~Figure() = default;
	virtual double area() const = 0;
};

class Parallelogram : public Figure
{
public:
	/*alpha in degrees*/
	Parallelogram(double width, double height, double alpha);
	double area() const override;

	double width() const noexcept;
	double height() const noexcept;
	/*in degrees*/
	double alpha() const noexcept;

protected:
	double m_width{};
	double m_height{};
	/*in radians*/
	double m_alpha{};

};

class Circle : public Figure
{
public:
	explicit Circle(double radius);
	double area() const override;

	double radius() const noexcept;

protected:
	double m_radius{};

};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double width, double height);
	double area() const override;

};

class Square : public Parallelogram
{
public:
	explicit Square(double side);
	double area() const override;

};

class Rhombus : public Parallelogram
{
public:
	/*alpha in degrees*/
	Rhombus(double side, double alpha);
	double area() const override;

};
