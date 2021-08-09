#include <iostream>

#include "Task1.h"
#include "Task2.h"


void Task1()
{
    using namespace task1;
    std::cout << "Task 1" << std::endl;

    Vector<int> vector;
    vector.push_back(6);
    vector.push_back(4);
    vector.push_back(2);
    vector.print();
    // sort
    auto compare = [](const int& a, const int& b) { return a < b; };
    vector.sort(compare);
    std::cout << "vector is sorted. new vector: ";
    vector.print();
    // pop_back
    auto back = vector.pop_back();
    std::cout << "popped from back element is " << back << std::endl;
    vector.print();
    // pop_front
    auto front = vector.pop_front();
    std::cout << "popped from front element is " << front << std::endl;
    vector.print();
    std::cout << "element with index 0 is " << vector[0] << std::endl;
    std::cout << std::endl << std::endl;
}

void Task2()
{
    using namespace task2;
    std::cout << "Task2" << std::endl;
    // test 1
    {
        std::vector<int> data{};
        assert(GetDifferentItemsCount(data) == 0);
    }
    // test 2
    {
        std::vector<int> data{ 1, 3, 5, 7, 10 };
        assert(GetDifferentItemsCount(data) == 5);
    }
    // test 3
    {
        std::vector<int> data{ 1, 1, 1, 1, 1, 1, 1 };
        assert(GetDifferentItemsCount(data) == 1);
    }
    // task 4
    {
        std::vector<int> data{ 1, 3, 3, 5, 7, 7, 9, 2, 2, 1, 5, 5, 7, 16, 25, 2, 3, 35, 3, 4, 5, 157, 26 };
        assert(GetDifferentItemsCount(data) == 12);
    }
    std::cout << "All assertion has passed" << std::endl;
}

int main()
{
    Task1();
    Task2();
}
