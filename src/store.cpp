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
    rentables.printInventory();
}

void displayHistory(Customer& searchCustomer)
{
    Customer* actualCustomer;

    storeInst->customers.retrieve(cust, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << cust.getCustomerID;
        std::cerr<< " not found." << endl;
        return;
    }

    actualCustomer->displayHistory();
}

void borrowRentable(Customer& searchCustomer, Rentable& searchRenatble)
{
    Customer* actualCustomer;

    storeInst->customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << cust.getCustomerID;
        std::cerr<< " not found." << endl;
        return;
    }

    Rentable* actualRentable;

    if(!store->rentables.retrieve(searchRentable, actualRentable))
    {
        std::cerr << "ERROR: Rentable with title " << rent.getTitle();
        std::cerr<< " not carried in the store." << endl;
        return;
    }

    //update in store

    actualCustomer->borrowRentable(/* something */);
}

void returnRentable(Customer& searchCustomer, Rentable& searchRenatble)
{
    Customer* actualCustomer;

    storeInst->customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << cust.getCustomerID;
        std::cerr<< " not found." << endl;
        return;
    }

    Rentable* actualRentable;

    if(!store->rentables.retrieve(searchRentable, actualRentable))
    {
        std::cerr << "ERROR: Rentable with title " << rent.getTitle();
        std::cerr<< " not carried in the store." << endl;
        return;
    }

    //update in store

    actualCustomer->returnRentable(/* something */);
}

//build DVD rentables
static Comedy* buildComedy(std::string data);
static Drama* buildDrama(std::string data);
static Classic* buildClassic(std::string data);

Rentable* Store::buildRentable(RentableType type, int subtype, std::string data)
{
    switch(type)
    {
        case DVD:
        {
            switch(intToDVDType(subtype))
            {
                case Comedy:
                {
                    return buildComedy(data);
                }
                case Drama:
                {
                    return buildDrama(data);
                }
                case Comedy:
                {
                    return buildComedy(data);
                }
                default:
                    return nullptr;
            }
        }
        default:
            return nullptr;
    }
}

Comedy* buildComedy(std::string data)
{

    return null;
}

Drama* buildDrama(std::string data)
{

    return null;
}

Classic* buildClassic(std::string data)
{

    return null;
}