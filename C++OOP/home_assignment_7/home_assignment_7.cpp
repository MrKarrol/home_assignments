#include <memory>

#include "Date.h"


void Task1()
{
    std::cout << "-------- Task 1 --------" << std::endl;
    auto today = std::make_unique<Date>(1, 2, 3);
    std::cout << "separated: " << today->GetDay() << ":" << today->GetMonth() << ":" << today->GetYear() << ", all together: " << today << std::endl;

    std::cout << "moving today into date" << std::endl;
    decltype(today) date = std::move(today);
    std::cout << "today ptr is nullptr? " << std::boolalpha << (today == nullptr) << ", date is nullptr? " << (date == nullptr) << std::endl;
}

using DatePtr = std::shared_ptr<Date>;
auto CompareDates(const DatePtr lhv, const DatePtr rhv)
{
    if (lhv->GetYear() > rhv->GetYear())
        return lhv;
    else if (lhv->GetYear() < rhv->GetYear())
        return rhv;
    else if (lhv->GetMonth() > rhv->GetMonth())
        return lhv;
    else if (lhv->GetMonth() < rhv->GetMonth())
        return rhv;
    else if (lhv->GetDay() > rhv->GetDay())
        return lhv;
    else if (lhv->GetDay() < rhv->GetDay())
        return rhv;
    else
        return lhv;
}

auto GetDate(int day, int month, int year)
{
    return std::make_shared<Date>(day, month, year);
}

void assert(bool sentence)
{
    if (not sentence)
        throw std::exception("assert failed");
}

void Task2()
{
    std::cout << std::endl << "-------- Task 2 --------" << std::endl;
    {
        auto date1 = GetDate(1, 2, 3);
        auto date2 = GetDate(1, 2, 4);
        assert(CompareDates(date1, date2) == date2);
        assert(CompareDates(date2, date1) == date2);
    }
    {
        auto date1 = GetDate(1, 3, 3);
        auto date2 = GetDate(1, 2, 3);
        assert(CompareDates(date1, date2) == date1);
        assert(CompareDates(date2, date1) == date1);
    }
    {
        auto date1 = GetDate(2, 2, 3);
        auto date2 = GetDate(1, 2, 3);
        assert(CompareDates(date1, date2) == date1);
        assert(CompareDates(date2, date1) == date1);
    }
    std::cout << "all assertions passed" << std::endl;
}

int main()
{
    Task1();
    Task2();
}
