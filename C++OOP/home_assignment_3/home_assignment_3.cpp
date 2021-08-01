#include <iostream>

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"


void Task1()
{
    std::cout << "Task 1" << std::endl << std::endl;

    {
        Parallelogram figure(5, 4, 45);
        std::cout << "Parallelogram with sides " << figure.width() << " and " << figure.height()
            << " and angle between " << figure.alpha()
            << " degrees has area " << figure.area() << std::endl;
    }
    {
        Circle figure(7);
        std::cout << "Circle with radius " << figure.radius() << " has area " << figure.area() << std::endl;
    }
    {
        Rectangle figure(4, 14);
        if (figure.alpha() != 90.f)
            std::cerr << "ERROR!! Rectangle has angle != 90 degrees" << std::endl;
        std::cout << "Rectangle with sides " << figure.width() << " and " << figure.height()
            << " has area " << figure.area() << std::endl;
    }
    {
        Square figure(15);
        if (figure.alpha() != 90.f)
            std::cerr << "ERROR!! Square has angle != 90 degrees" << std::endl;
        if (figure.height() != figure.width())
            std::cerr << "ERROR!! Square's sides are not equal each other" << std::endl;
        std::cout << "Square with side " << figure.height() << " has area " << figure.area() << std::endl;
    }
    {
        Rhombus figure(3, 53);
        if (figure.height() != figure.width())
            std::cerr << "ERROR!! Rhombus's sides are not equal each other" << std::endl;
        std::cout << "Rhombus with side " << figure.height() << " and angle between sides " << figure.alpha()
            << " degrees has area " << figure.area() << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void Task2()
{
    std::cout << "Task 2" << std::endl << std::endl;

    std::cout << "--------------" << std::endl;
    Car car("company", "model");
    std::cout << "--------------" << std::endl;
    PassengerCar passengerCar("company", "model");
    std::cout << "--------------" << std::endl;
    Bus bus("company", "model");
    std::cout << "--------------" << std::endl;
    Minivan minivan("company", "model");

    std::cout << std::endl << std::endl;
}

void Task3()
{
    std::cout << "Task 3" << std::endl << std::endl;

    try
    {
        std::cout << "trying create fraction with demonimator 0..." << std::endl;
        Fraction failure(3, 0);
    }
    catch (std::exception& e)
    {
        std::cerr << "can't create fraction with denominator == 0" << std::endl;
    }

    Fraction a(3, 5);
    Fraction b(3, 2);

    std::cout << "using fractions a = " << a.str() << " and b =" << b.str() << " to show operators overload" << std::endl;
    {
        const auto c = a + b;
        std::cout << "Result of + is " << c.str() << std::endl;
    }
    {
        const auto c = a - b;
        std::cout << "Result of - is " << c.str() << std::endl;
    }
    {
        const auto c = a * b;
        std::cout << "Result of * is " << c.str() << std::endl;
    }
    {
        const auto c = a / b;
        std::cout << "Result of / is " << c.str() << std::endl;
    }
    {
        const auto c = -a;
        std::cout << "Result of -a is " << c.str() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << std::boolalpha;
        std::cout << "Result of a == b is " << (a == b) << std::endl;
        std::cout << "Result of a != b is " << (a != b) << std::endl;
        std::cout << "Result of a < b is " << (a < b) << std::endl;
        std::cout << "Result of a > b is " << (a > b) << std::endl;
        std::cout << "Result of a <= b is " << (a <= b) << std::endl;
        std::cout << "Result of a >= b is " << (a >= b) << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << std::boolalpha;
        std::cout << "Result of b == a is " << (b == a) << std::endl;
        std::cout << "Result of b != a is " << (b != a) << std::endl;
        std::cout << "Result of b < a is " << (b < a) << std::endl;
        std::cout << "Result of b > a is " << (b > a) << std::endl;
        std::cout << "Result of b <= a is " << (b <= a) << std::endl;
        std::cout << "Result of b >= a is " << (b >= a) << std::endl;
    }
    std::cout << std::endl;
    {
        const auto c = a;
        std::cout << "Making c == a" << std::endl;
        std::cout << "Result of a == c is " << (a == c) << std::endl;
        std::cout << "Result of a != c is " << (a != c) << std::endl;
        std::cout << "Result of a < c is " << (a < c) << std::endl;
        std::cout << "Result of a > c is " << (a > c) << std::endl;
        std::cout << "Result of a <= c is " << (a <= c) << std::endl;
        std::cout << "Result of a >= c is " << (a >= c) << std::endl;
    }

    std::cout << std::endl << std::endl;
}


int main()
{
    Task1();
    Task2();
    Task3();
}
