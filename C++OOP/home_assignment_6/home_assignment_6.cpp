#include <iostream>
#include <string>

namespace std
{
    std::ostream& endll(std::ostream& out)
    {
        out << std::endl << std::endl;
        out.flush();
        return out;
    }
}

int main()
{
    while (true)
    {
        std::cout << "Input number: ";
        int number = 0;
        std::string number_string;
        std::cin >> number_string;
        try
        {
            number = std::stoi(number_string);
            if (std::to_string(number) == number_string)
            {
                std::cout << "Great, you inputed " << number << "!!!" << std::endll;
                break;
            }
            else
                std::cerr << "Wrong! Do it again." << std::endll;
            
        }
        catch (...)
        {
            std::cerr << "Wrong! Do it again." << std::endll;
        }

    }
}
