#include "store.h"
#include "command.h"
#include "commandfactory.h"

#include "rentablefactory.h"

#include "customer.h"

Store::Store(int id)
{
    storeID = id;

    //set up rentable craziness

    //set up customer hash table
}



//The file is assumed to be correctly formatted
//That is, there aren't any lines that have an incorrect
//number of items
void Store::loadCustomers(std::ifstream& file)
{
    while(!file.eof())
    {
        int customerID;
        std::string lastName, firstName;

        file >> customerID >> lastName >> firstName;

        Customer* newCustomer = new Customer(customerID, lastName, firstName);

        customers.insert(newCustomer);
    }
}

void Store::loadRentables(RentableType type, std::ifstream& file)
{
    while(!file.eof())
    {
        std::string line;

        std::getline(file, line);

        //may emit an error and return nullptr
        Rentable* newRentable = RentableFactory.createRentable(type, line);

        if(newRentable != nullptr)
        {
            //do something with the rentable
        }
    }
}

void Store::loadCommands(std::ifstream& file)
{
     while(!file.eof())
    {
        std::string line;

        std::getline(file, line);

        //may emit an error and return nullptr
        Command* newCommand = CommandFactory.createCommand(line);

        if(newCommand != nullptr)
        {
            //give the command an instance of the store that created it
            newCommand.storeInst = this;

            commandQueue.push(newCommand);
        }
    }
}

void Store::processCommands()
{
    while(!commandQueue.empty())
    {
        Command* nextCommand = commandQueue.pop();
        nextCommand->processCommand();
    }
}


int Store::getID() const
{
    return storeID;
}


void printInventory()
{
    classicMovies.printTree();
    dramaMovies.printTree();
    comedyMovies.printTree();
}

void displayHistory(int customerID)
{
    Customer* actualCustomer;

    storeInst->customers.retrieve(cust, actualCustomer);

    if(actualCustomer == nullptr)
    {
        //emit error
        return;
    }


    actualCustomer->displayHistory();
}

void borrowRentable(int customerID, RentableType type, int subtype, std::string data)
{
    Customer* actualCustomer;

    storeInst->customers.retrieve(cust, actualCustomer);

    if(actualCustomer == nullptr)
    {
        //emit error
        return;
    }

    Rentable* actualRentable;

    //build the rentable


    store->rentables[thing][thing].retrieve(*rent, actualRentable);

    if(actualRentable == nullptr)
    {
        //error
        return;
    }


    //update in store

    actualCustomer->borrowRentable(/* something */);
}

void returnRentable(int customerID, RentableType type, int subtype, std::string data)
{
    Customer* actualCustomer;

    storeInst->customers.retrieve(cust, actualCustomer);

    if(actualCustomer == nullptr)
    {
        //emit error
        return;
    }

    Rentable* actualRentable;

    //build the rentable

    store->rentables[thing][thing].retrieve(*rent, actualRentable);

    if(actualRentable == nullptr)
    {
        //error
        return;
    }


    //update in store

    actualCustomer->returnRentable(/* something */);
}