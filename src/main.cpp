#include <iostream>
#include <ifstream>


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
    store1.loadRentables(infile1);
    store1.loadCustomers(infile2);
    store1.loadCommands(infile3);
    store1.processCommands();

    return 0;
}