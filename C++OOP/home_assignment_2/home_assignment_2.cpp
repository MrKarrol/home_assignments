#include <iostream>
#include <vector>

#include "Student.h"

namespace students_work
{
    void StudentsPayload()
    {
        std::vector<Student> students;
        students.emplace_back("Elly", 21, false, 57, 1);
        students.emplace_back("John", 22, true, 82, 2);
        students.emplace_back("Kate", 22, false, 48, 2);

        bool is_running = true;
        while (is_running)
        {
            std::cout << ">>>>>>>>>>>>" << std::endl;
            std::cout << "There are " << students.size() << " students. Press 'p' to print student."
                << " Press 'd' to delete student."
                << " Press 'c' to create student."
                << " Press anyting else to quit students work." << std::endl;
            char action;
            std::cin >> action;
            switch (action)
            {
            case 'p':
            {
                std::cout << ">>>>>>>>>>>>" << std::endl;
                std::cout << "Input student index (started by 1): ";
                int index = 0;
                std::cin >> index;
                if (index > 0 and index <= students.size())
                {
                    auto& student = students.at(index - 1);
                    std::cout << "Student name: " << student.Name()
                        << ", age " << student.Age()
                        << ", student is " << (student.IsMale() ? "male" : "female")
                        << ", weight is " << student.Weight()
                        << ", education year is " << student.Year()
                        << std::endl;
                }
                else
                {
                    std::cout << "Index incorrect, exit printing mode" << std::endl;
                }
                break;
            }
            case 'd':
            {
                std::cout << ">>>>>>>>>>>>" << std::endl;
                std::cout << "Input student index (started by 1): ";
                int index = 0;
                std::cin >> index;
                if (index > 0 and index <= students.size())
                    students.erase(students.begin() + index - 1);
                else
                    std::cout << "Index incorrect, exit printing mode" << std::endl;
                break;
            }
            case 'c':
            {
                std::cout << ">>>>>>>>>>>>" << std::endl;
                std::cout << "Input name, age (years), weight (kg) and education year number, separated by space: ";
                std::string name;
                int age;
                float weight;
                int education_year;
                std::cin >> name >> age >> weight >> education_year;

                std::cout << "If student is male, press 'y', 'n' otherwise: ";
                char action = 'y';
                std::cin >> action;

                students.emplace_back(name, age, action == 'y', weight, education_year);

                std::cout << "Student creation is completed." << std::endl;
                break;
            }
            default:
                std::cout << "Exiting students work" << std::endl;
                is_running = false;
                break;
            }
        }
    }
} // end of namespace students_work

namespace fruits_work
{
    void FruitsPayload()
    {

    }
} // end of namespace fruits_work


int main()
{
    bool is_running = true;
    while (is_running)
    {
        std::system("cls");
        std::cout << "Press '1' for students work, '2' for fruits work, anything else to stop program: ";
        char action = '3';
        std::cin >> action;

        switch (action)
        {
        case '1':
            students_work::StudentsPayload();
            break;
        case '2':
            fruits_work::FruitsPayload();
            break;
        default:
            std::cout << "Exiting program" << std::endl;
            is_running = false;
            break;
        }
    }
}