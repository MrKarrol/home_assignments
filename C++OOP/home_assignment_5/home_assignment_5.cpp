#include <iostream>

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"


int main()
{
    // task 1
    {
        using namespace task1;
        Pair1<int> p1(6, 9);
        std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair1<double> p2(3.4, 7.8);
        std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }
    std::cout << "-----------------------------" << std::endl;
    // task 2
    {
        using namespace task2;
        Pair<int, double> p1(6, 7.8);
        std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair<double, int> p2(3.4, 5);
        std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }
    std::cout << "-----------------------------" << std::endl;
    // task 3
    {
        using namespace task3;
        StringValuePair<int> svp("Amazing", 7);
        std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    }
}
