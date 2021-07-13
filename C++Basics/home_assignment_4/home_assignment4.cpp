#include <iostream>

bool IsPrime(uint64_t num)
{
    for (int i = 2; i <= std::sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}


int main()
{
    // task 1
    {
        std::cout << "Task 1" << std::endl;
        std::cout << "\tInput two numbers: ";
        double number1, number2 = 0.f;

        std::cin >> number1 >> number2;

        if (number1 + number2 >= 10 and number1 + number2 <= 20)
            std::cout << "\ttrue" << std::endl;
        else
            std::cout << "\tfalse" << std::endl;
    }

    // task 2
    {
        std::cout << "Task 2" << std::endl;
        constexpr int const1 = 10;
        constexpr int const2 = 9;

        if (((const1 == 10) and (const2 == 10)) or (const1 + const2 == 10))
            std::cout << "\ttrue" << std::endl;
        else
            std::cout << "\tfalse" << std::endl;
    }

    // task 3
    {
        std::cout << "Task 3" << std::endl << "\t";
        for (int i = 0; i < 50; ++i)
            if (i % 2 != 0)
                std::cout << i << " ";
        std::cout << std::endl;
    }

    // task 4
    {
        std::cout << "Task 4" << std::endl;
        std::cout << "\tInput number: ";
        uint64_t n = 0;
        std::cin >> n;
        if (IsPrime(n))
            std::cout << "\tNumber is prime!" << std::endl;
        else
            std::cout << "\tNumber is NOT prime.." << std::endl;
    }

    // task 5
    {
        std::cout << "Task 5" << std::endl;
        const std::string leap_year_string = "\tIt's a leap year!";
        const std::string not_leap_year_string = "\tNot a leap year, sorry";
        std::cout << "\tInput year: ";
        int year = 0;
        std::cin >> year;
        if (year % 4 == 0)
        {
            if (year % 400 == 0)
            {
                std::cout << leap_year_string << std::endl;
            }
            else if (year % 100 == 0)
            {
                std::cout << not_leap_year_string << std::endl;
            }
            else
                std::cout << leap_year_string << std::endl;
        }
        else
            std::cout << not_leap_year_string << std::endl;
    }
}
