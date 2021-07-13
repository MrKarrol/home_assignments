#include <iostream>

#include "Power.h"
#include "RGBA.h"


int main()
{
    // task 1
    {
        std::cout << "Task 1" << std::endl;
        // with default
        {
            Power power;
            std::cout << "\t";
            power.Calculate();
        }
        // with some input
        {
            Power power;
            power.Set(2, 12);
            std::cout << "\t";
            power.Calculate();
        }
    }
    // task 2
    {
        std::cout << "Task 2" << std::endl;
        // with defaults
        {
            RGBA scheme;
            std::cout << "\t";
            scheme.Print();
        }
        // with special constructor
        {
            RGBA scheme(1, 2, 3, 15);
            std::cout << "\t";
            scheme.Print();
        }
    }
}
