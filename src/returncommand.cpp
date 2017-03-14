#include "returncommand.h"
#include "store.h"

ReturnCommand::ReturnCommand():searchCustomer(0,"","")
{
}

ReturnCommand::ReturnCommand(int customerID, char type, char subtype,
                             std::string data): searchCustomer(customerID, "", "")
{
    searchRentable = buildRentable(type, subtype, data);
}

ReturnCommand::~ReturnCommand()
{
    delete searchRentable;
}

bool ReturnCommand::processCommand()
{
    RentableStorage& rentables = getRentableStorage();
    HashTable& customers = getHashTable();

    Customer* actualCustomer;

    customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << searchCustomer.getCustomerID();
        std::cerr<< " not found." << std::endl;
        return false;
    }

    Rentable* actualRentable;

    if(!rentables.retrieve(searchRentable, actualRentable))
    {
        std::cerr << "ERROR: Rentable with title " << searchRentable->getTitle();
        std::cerr<< " not carried in the store." << std::endl;
        return false;
    }

    //update in store
    actualRentable->addToStock(1);
    actualCustomer->returnRentable(1, *actualRentable);

    return true;
}