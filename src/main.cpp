#include <iostream>
#include <ifstream>
#include "store.h"


int main()
{
    ifstream infile1(“data4movies.txt”);
    ifstream infile1(“data4customers.txt”);
    ifstream infile1(“data4commands.txt”);

    if (!infile1 || !infile2 || !infile3)
    {
        cerr << “file could not be opened.” << endl;
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