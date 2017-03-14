#include <iostream>
#include <fstream>
#include "store.h"

int main()
{
    std::ifstream infile1("data4movies.txt");
    std::ifstream infile2("data4customers.txt");
    std::ifstream infile3("data4commands.txt");

    if (!infile1.is_open() || !infile2.is_open() || !infile3.is_open())
    {
        std::cerr << "file could not be opened." << std::endl;
        return -1;
    }

    Store store1(1001);

    //Since formatting could be different for each type, we should specify when
    //loading a file that contains rentables
    store1.loadRentables(RentableType::DVD, infile1);

    store1.loadCustomers(infile2);
    store1.loadCommands(infile3);
    store1.processCommands();

    return 0;
}