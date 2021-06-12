#include <iostream>

void PrintArray(double* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void PrintArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void Shift(int *array, size_t size, size_t shift)
{
    int* new_array = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
        auto new_index = ((i + shift) + size ) % size;
        new_array[new_index] = array[i];
    }
    for (size_t i = 0; i < size; ++i)
        array[i] = new_array[i];
    delete[] new_array;
}

bool HasThreshold(int* array, size_t size, size_t *bound = nullptr)
{
    if (size < 2)
        return false;

    bool result = false;
    size_t left_bound = 0;
    size_t right_bound = size - 1;
    int left_sum = 0;
    int right_sum = 0;
    while (left_bound <= right_bound)
    {
        if (left_sum <= right_sum and left_bound <= right_bound)
            left_sum += array[left_bound++];
        if (right_sum <= left_sum and left_bound <= right_bound)
            right_sum += array[right_bound--];
    }
    if (left_sum == right_sum and bound)
        *bound = left_bound < right_bound ? left_bound : right_bound;
    return left_sum == right_sum;
}

int main()
{
    // task 1
    {
        std::cout << "Task 1" << std::endl;

        constexpr size_t size = 10;
        double array[size];
        std::cout << "\tInput " << size << " numbers: ";
        for (size_t i = 0; i < size; ++i)
            std::cin >> array[i];
        std::cout << "\t";
        PrintArray(array, size);
    }
    // task 2
    {
        std::cout << "Task 2" << std::endl;

        constexpr size_t size = 10;
        int array[size];
        
        for (size_t i = 0; i < size; ++i)
            array[i] = i % 3 ? 1 : 0;
        std::cout << "\tInitial array - ";
        PrintArray(array, size);

        std::cout << "\tInverted array - ";
        for (size_t i = 0; i < size; ++i)
            std::cout << not array[i] << " ";
        std::cout << std::endl;
    }
    // task 3
    {
        std::cout << "Task 3" << std::endl;

        constexpr size_t size = 8;
        int array[size];
        for (size_t i = 0; i < size; ++i)
            array[i] = i * 3 + 1;
        std::cout << "\t";
        PrintArray(array, size);
    }
    // task 4
    {
        std::cout << "Task 4" << std::endl;

        constexpr size_t size = 20;
        int array[size];
        for (size_t i = 0; i < size; ++i)
            array[i] = i;
        {
            auto temp_arr = array;
            Shift(temp_arr, size, -3);
            std::cout << "\tShift -3, result - ";
            PrintArray(temp_arr, size);
        }
        {
            auto temp_arr = array;
            Shift(temp_arr, size, 5);
            std::cout << "\tShift 5, result - ";
            PrintArray(temp_arr, size);
        }
        {
            auto temp_arr = array;
            Shift(temp_arr, size, 123);
            std::cout << "\tShift 123, result - ";
            PrintArray(temp_arr, size);
        }
    }
    // task 5
    {
        std::cout << "Task 5" << std::endl;

        auto Test = [](int* array, size_t size)
        {
            static int index = 1;

            size_t bound = 0;
            auto result = HasThreshold(array, size, &bound);

            std::cout << "\tTest " << index++ << ", array - ";
            for (size_t i = 0; i < size; ++i)
            {
                if (result and i == bound)
                    std::cout << array[i] << " || ";
                else
                    std::cout << array[i] << " ";
            }
            std::cout << ", result - " << result << std::endl;
        };
        // test 1
        {
            constexpr size_t size = 5;
            int array[size] = { 1, 1, 1, 2, 1 };
            Test(array, size);
        }
        // test 2
        {
            constexpr size_t size = 5;
            int array[size] = { 2, 1, 1, 2, 1 };
            Test(array, size);
        }
        // test 3
        {
            constexpr size_t size = 5;
            int array[size] = { 10, 1, 2, 3, 4 };
            Test(array, size);
        }
        // test 4
        {
            constexpr size_t size = 10;
            int array[size] = { 23, 5, 6, 32, 5, 1, 1, 1, 32, 26 };
            Test(array, size);
        }
        // test 5
        {
            constexpr size_t size = 23;
            int array[size];
            for (size_t i = 0; i < size; ++i)
                array[i] = 1;
            Test(array, size);
        }
        // test 6
        {
            constexpr size_t size = 22;
            int array[size];
            for (size_t i = 0; i < size; ++i)
                array[i] = 1;
            Test(array, size);
        }
    }
}
