#include <iostream>
#include <exception>
#include <random>

#include "Task2.h"
#include "Task3.h"


namespace task1
{

    template<typename T>
    T div(const T& dividend, const T& divisor)
    {
        if (not divisor)
            throw std::exception("division by zero");
        return dividend / divisor;
    }

} // end of namespace task1

void Task1()
{
    std::cout << "----- Task 1 -----";
    try
    {
        std::cout << task1::div(15, 3) << std::endl;
        std::cout << task1::div(17.5, 2.3) << std::endl;
        std::cout << task1::div(3, 0) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Task2()
{
    std::cout << "----- Task 2 -----" << std::endl;

    double input{1};
    task2::Bar bar;
    while (input)
    {
        using namespace task2;
        try
        {
            std::cout << "Input real number: ";
            std::cin >> input;
            bar.set(input);
        }
        catch (Ex& ex)
        {
            std::cout << "Exception! Value is " << ex << std::endl;
        }
    }
    std::cout << "Zero, finally" << std::endl;
}

void Task3()
{
    std::cout << "----- Task 3 -----" << std::endl;
    std::random_device rd;
    std::mt19937 e(rd());
    std::uniform_int_distribution<int> dist(0, 9);
    int goal_x = dist(e);
    int goal_y = dist(e);

    std::cout << "There is a chest hidden somewhere near, in that 10x10 field. Note that [0, 0] is a left up corner. Robot must find this chest. Help the robo!" << std::endl;
    std::cout << "Press 'u' for up, 'd' for down, 'l' for left, 'r' for right." << std::endl;
    char dir = 'f';
    
    using namespace task3;
    int init_x{};
    int init_y{};
    while (true)
    {
        init_x = dist(e);
        init_y = dist(e);
        if (not (init_x == goal_x and init_y == goal_y))
            break;
    }
    Robot robot(init_x, init_y);
    std::cout << robot << std::endl;

    while (true)
    {
        try
        {
            std::cin >> dir;
            robot.move(GetFromInput(dir));
            std::cout << robot << std::endl;
            if (robot.check(goal_x, goal_y))
            {
                std::cout << "You actually FOUND the chest. Congrats!!!!! Now you have mighty laser cannon, to destroy this world..." << std::endl;
                break;
            }
        }
        catch (OffTheField& obj)
        {
            std::cout << obj << std::endl;
        }
        catch (IllegalCommand& obj)
        {
            std::cout << obj << std::endl;
        }
    }
}

int main()
{
    Task1();
    Task2();
    Task3();
}
