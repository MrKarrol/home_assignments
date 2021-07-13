#include <iostream>
#include <iomanip>

extern int a;
extern int b;
extern int c;
extern int d;

float GetFloat(int value)
{
    return static_cast<float>(value);
}

int main()
{
    // task 4
    {
        float result = a * (b + (GetFloat(c) / d));
        float result_with_all_float = GetFloat(a) * (GetFloat(b) + (GetFloat(c) / GetFloat(d)));
        std::cout << "Task 4 (extern): result with one static cast is " << result << ", with all static casts is " << result_with_all_float << std::endl;
    }
    // task 2
    {
        int integer = 0;
        std::cout << "Task 2: input integer: ";
        std::cin >> integer;
        std::cout << "Result of task is " << (integer <= 21 ? integer - 21 : (integer - 21) * 2) << std::endl;
    }
    // task 3
    {
        std::cout << "Task 3:" << std::endl;
        constexpr int size = 3;
        int array[size][size][size] = {};

        // fill array
        for (int first = 0; first < size; ++first)
        {
            int (*square)[size] = array[first];
            for (int second = 0; second < size; ++second)
            {
                int *line = square[second];
                for (int third = 0; third < size; ++third)
                {
                    line[third] = third + second * size + first * size * size;
                    std::cout << std::setw(4) << std::setfill(' ') << line[third];
                }
                std::cout << std::endl;
            }
            if (first != size - 1)
                std::cout << "--------------" << std::endl;
        }
        std::cout << std::endl;

        // print center
        int* center = &array[1][1][1];
        std::cout << "Value of center is " << *center << std::endl << std::endl;

        // change center
        *center = 666;

        // print middle of cube
        for (int second = 0; second < size; ++second)
        {
            for (int third = 0; third < size; ++third)
                std::cout << array[1][second][third] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl << "New value of center is " << *center << std::endl;
    }
}
