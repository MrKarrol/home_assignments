#include <iostream>

#include "Power.h"
#include "RGBA.h"
#include "Stack.h"


int main()
{
    // task 1
    {
        std::cout << "Task 1" << std::endl;
        // with default
        {
            Power power;
            std::cout << "\t [with defaults]   ";
            power.Calculate();
        }
        // with some input
        {
            Power power;
            power.Set(2, 12);
            std::cout << "\t [with some input] ";
            power.Calculate();
        }
    }
    // task 2
    {
        std::cout << "Task 2" << std::endl;
        // with defaults
        {
            RGBA scheme;
            std::cout << "\t [with defaults]   ";
            scheme.Print();
        }
        // with special constructor
        {
            RGBA scheme(1, 2, 3, 15);
            std::cout << "\t [with some input] ";
            scheme.Print();
        }
    }
    // task 3
    {
        std::cout << "Task 3" << std::endl;
        Stack stack;
        stack.reset();
        std::cout << "\t";
        stack.print();
        // std::cerr << "\t";
        // stack.pop();

        stack.push(3);
        stack.push(7);
        stack.push(5);
        std::cout << "\t";
        stack.print();

        stack.pop();
        std::cout << "\t";
        stack.print();

        stack.pop();
        stack.pop();
        std::cout << "\t";
        stack.print();
    }
}
