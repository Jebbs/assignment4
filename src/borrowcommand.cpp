#include "borrowcommand.h"

#include "hashtable.h"
#include "rentablestorage.h"

BorrowCommand::BorrowCommand():searchCustomer(0,"",""){}

BorrowCommand::BorrowCommand(int customerID, char type, char subtype,
                             std::string data): searchCustomer(customerID, 
                             "", "")
{
    searchRentable = buildRentable(type, subtype, data);
}

BorrowCommand::~BorrowCommand()
{
    delete searchRentable;
}

bool BorrowCommand::processCommand()
{

    RentableStorage& rentables = getRentableStorage();
    HashTable& customers = getHashTable();

    Customer* actualCustomer;

    customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID ";
        std::cerr << searchCustomer.getCustomerID();
        std::cerr << " not found." << std::endl;
        return false;
    }

    Rentable* actualRentable;

    if(!rentables.retrieve(searchRentable, actualRentable))
    {
        if (searchRentable == NULL)
        {
            std::cerr << "ERROR: Null Pointer exception" << std::endl;
            return false;
        }
        std::cerr << "ERROR: Rentable with title ";
        std::cerr << searchRentable->getTitle();
        std::cerr<< " not carried in the store." << std::endl;
        return false;
    }

    //update in store

    actualCustomer->borrowRentable(1, *actualRentable);

    return true;
}