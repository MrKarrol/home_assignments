#include <iostream>
#include <chrono>
#include <thread>

#include "Field.h"

#include "Master.h"


int main()
{
    Master master;

    master.InitializeField();

    while (master.IsGameNotDone())
    {
        master.MakeMove();
    }

    master.PrintWinner();
}
