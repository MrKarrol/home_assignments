#include <iostream>

#include "Power.h"


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
}
