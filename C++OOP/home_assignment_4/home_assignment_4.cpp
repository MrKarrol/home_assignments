#include <iostream>

#include "Task1.h"


void Task1()
{
    using namespace task1;
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
}

int main()
{
    Task1();
}
