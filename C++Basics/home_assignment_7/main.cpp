#include <iostream>
#include <random>

#include "mylib.h"

#define TASK_5_SIZE 10

#define TASK_2_COMPARE(x, y) ((x >= 0) and (x < y))

#define TASK_3_SIZE 5
#define SwapINT(a, b) std::swap(a, b)

void FastSort(int* arr, int left_index, int right_index)
{
    int l = left_index;
    int r = right_index;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> GetElement(left_index, right_index);

    int se = GetElement(gen);

    while (l <= r)
    {
        while (arr[l] < se)
            ++l;
        while (arr[r] > se)
            --r;
        if (l <= r)
            SwapINT(arr[l], arr[r]);
    }
    if (left_index < r)
        FastSort(arr, left_index, r);
    if (right_index > l)
        FastSort(arr, l, right_index);
}

#pragma pack(push, 1)
struct Employee
{
    int id;
    std::string phone_number;
    std::string first_name;
    std::string second_name;
    int age;
};
#pragma pack(pop)

void Task5()
{
    std::cout << "Task 5" << std::endl;
    using namespace task_5;
    
    auto arr = new float[TASK_5_SIZE];

    InitializeArray(arr, TASK_5_SIZE);

    std::cout << "\t";
    PrintArray(arr, TASK_5_SIZE);

    int positive = 0;
    int negative = 0;

    CountElements(arr, TASK_5_SIZE, &positive, &negative);
    
    std::cout << "\tIn array there are " << positive << " positive numbers and " << negative << " negative numbers." << std::endl;

    delete[] arr;
}

void Task2()
{
    std::cout << "Task 2" << std::endl;

    float a = 0;
    std::cout << "\tInput first number: ";
    std::cin >> a;

    float b = 0;
    std::cout << "\tInput second number: ";
    std::cin >> b;

    std::cout << "\tIs " << a << " in [0; " << b << ") range? Answer is " << std::boolalpha << TASK_2_COMPARE(a, b) << std::endl;
}

void Task3()
{
    std::cout << "Task 3" << std::endl;
    auto arr = new int[TASK_3_SIZE];

    std::cout << "\tInput " << TASK_3_SIZE << " numbers: ";
    for (int i = 0; i < TASK_3_SIZE; ++i)
        std::cin >> arr[i];

    FastSort(arr, 0, TASK_3_SIZE - 1);

    std::cout << "\tResult of quick sort is ";
    for (size_t i = 0; i < TASK_3_SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    delete[] arr;
}

void Task4()
{
    auto employee = new Employee;

    employee->id = 1;
    employee->phone_number = "+79995553344";
    employee->first_name = "robert";
    employee->second_name = "jhonson";
    employee->age = 45;

    std::cout << "\tEmployee: id " << employee->id <<
        ", phone number " << employee->phone_number << 
        ", " << employee->first_name << " " << employee->second_name << 
        ", age " << employee->age << std::endl;

    std::cout << "\tstruct size is " << sizeof(employee) << std::endl;



    delete employee;
}


int main()
{
    Task5();
    Task2();
    Task3();
    Task4();
}