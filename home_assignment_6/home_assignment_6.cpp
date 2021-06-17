#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <string>

namespace task_1
{
    int* CreateArray(int size)
    {
        return new (std::nothrow) int[size];
    }

    void FillArray(int* arr, int size)
    {
        for (int i = 0; i < size; ++i)
            arr[i] = std::ceil(std::pow(2, i));
    }

    void PrintArray(int* arr, int size)
    {
        std::cout << "\tResult array is - ";
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

    void DeleteArray(int* arr)
    {
        delete[] arr;
    }
}

namespace task_2
{
    int** CreateMatrix(int size)
    {
        int** matrix = new int* [size];
        for (int i = 0; i < size; ++i)
            matrix[i] = new int[size];
        return matrix;
    }

    void DeleteMatrix(int** matrix, int size)
    {
        for (int i = 0; i < size; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }

    void InitMatrix(int** matrix, int size)
    {
        for (int row = 0; row < size; ++row)
            for (int col = 0; col < size; ++col)
                matrix[row][col] = std::rand();
    }

    void PrintMatrix(int** matrix, int size)
    {
        for (int row = 0; row < size; ++row)
        {
            std::cout << "\t";
            for (int col = 0; col < size; ++col)
                std::cout << std::setw(7) << std::setfill(' ') << matrix[row][col] << " ";
            std::cout << std::endl;
        }
    }
} // end of namespace task_2

namespace task_3
{
    void CreateFile(const std::string& file_name)
    {
        std::ofstream out(file_name);

        if (not out.is_open())
        {
            std::cerr << "Can't create/write file " << file_name << std::endl;
            return;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> get_size(50, 100);
        const auto size = get_size(gen);

        std::uniform_int_distribution<int> get_num(0, 9);

        for (int i = 0; i < size; ++i)
            out << get_num(gen);
        out.close();
    }

    void ReadFile(const std::string& file_name)
    {
        std::ifstream in(file_name);

        if (not in.is_open())
        {
            std::cerr << "Can't read file " << file_name << std::endl;
            return;
        }
        std::string line;
        std::cout << "\tIn file " << file_name << " is: " << std::endl;
        while (std::getline(in, line))
        {
            std::cout << "\t" << line << std::endl;
        }
        std::cout << std::endl;
    }
} // end of namespace task_3

namespace task_4
{
    void ReadToFile(const std::string& file_name_in, std::ostream& out)
    {
        std::ifstream in(file_name_in);

        if (not in.is_open())
        {
            std::cerr << "Can't read file " << file_name_in << std::endl;
            return;
        }
        std::string line;
        while (std::getline(in, line))
        {
            out << line;
        }
        in.close();
    }

    void ConcatenateFiles(const std::string& file_name_in_1, const std::string& file_name_in_2, const std::string& file_name_out)
    {
        std::ofstream out(file_name_out);

        if (not out.is_open())
        {
            std::cerr << "Can't create/write file " << file_name_out << std::endl;
            return;
        }
        ReadToFile(file_name_in_1, out);
        ReadToFile(file_name_in_2, out);

        out.close();
    }
} // end of namespace task_4

namespace task_5
{
    void FindWord(const std::string& word, const std::string& file_name)
    {
        std::ifstream in(file_name);

        if (not in.is_open())
        {
            std::cerr << "Can't read file " << file_name << std::endl;
            return;
        }
        std::string line;
        int line_count = 0;
        int found = 0;
        while (std::getline(in, line))
        {
            line_count++;
            size_t pos = 0;
            while (line.find(word, pos) != std::string::npos)
            {
                auto line_copy = line;
                line_copy.insert(line.find(word, pos), ">>");
                line_copy.insert(line.find(word, pos) + 2 + word.size(), "<<");
                std::cout << "\tFound word \"" << word << "\" at " << line_count << " line: \"" << line_copy << "\"" << std::endl;
                found++;
                pos = line.find(word, pos) + 1;
            }
        }
        in.close();

        if (found)
            std::cout << "\tWord \"" << word << "\" found " << found << " times." << std::endl;
        else
            std::cout << "\tNothing found" << std::endl;
    }
} // end of namespace task_5

void Task1()
{
    using namespace task_1;
    std::cout << "Task 1" << std::endl;
    std::cout << "\tInput array size: ";
    int n = 0;
    std::cin >> n;
    auto arr = CreateArray(n);
    if (arr)
    {
        FillArray(arr, n);
        PrintArray(arr, n);
        DeleteArray(arr);
    }
    else
    {
        std::cout << "\tSize " << n << " is not appropriate for array creation." << std::endl;
    }
}

void Task2()
{
    using namespace task_2;
    std::cout << "Task 2" << std::endl;
    constexpr int matrix_size = 4;
    auto matrix = CreateMatrix(matrix_size);
    InitMatrix(matrix, matrix_size);
    PrintMatrix(matrix, matrix_size);
    DeleteMatrix(matrix, matrix_size);
}

void Task3()
{
    using namespace task_3;
    std::cout << "Task 3" << std::endl;
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "\tInput filename: ";
        std::string file_name = "";
        std::cin >> file_name;
        CreateFile(file_name);
        ReadFile(file_name);
    }
}

void Task4()
{
    using namespace task_4;
    std::cout << "Task 4" << std::endl;

    std::cout << "\tInput first filename: ";
    std::string first_file;
    std::cin >> first_file;

    std::cout << "\tInput second filename: ";
    std::string second_file;
    std::cin >> second_file;

    std::cout << "\tInput output filename: ";
    std::string output_file;
    std::cin >> output_file;

    ConcatenateFiles(first_file, second_file, output_file);
    task_3::ReadFile(output_file);
}

void Task5()
{
    using namespace task_5;
    std::cout << "Task 5" << std::endl;

    std::cout << "\tInput word to search: ";
    std::string word;
    std::cin >> word;

    std::cout << "\tInput filename to search in: ";
    std::string file_name;
    std::cin >> file_name;

    std::cout << std::endl;

    FindWord(word, file_name);
}


int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
}
