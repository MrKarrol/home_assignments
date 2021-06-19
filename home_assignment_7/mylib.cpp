#include "mylib.h"

#include <random>
#include <iostream>


void task_5::InitializeArray(float* arr, const size_t size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> GetElement(-100, 100);

    for (size_t i = 0; i < size; ++i)
        arr[i] = GetElement(gen);
}

void task_5::PrintArray(float* arr, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void task_5::CountElements(float* arr, const size_t size, int* positive, int* negative)
{
    int positive_count = 0;
    int negative_count = 0;
    for (size_t i = 0; i < size; ++i)
        if (arr[i] > 0)
            positive_count++;
        else if (arr[i] < 0)
            negative_count++;
    if (positive)
        *positive = positive_count;
    if (negative)
        *negative = negative_count;
}
