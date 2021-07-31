#include <iostream>

#include "Task1.h"


int main()
{
    // task 1
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
    }
}