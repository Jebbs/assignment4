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
        std::cerr << "ERROR: Attempted to return a rentable";
        std::cerr<< " not carried in the store." << std::endl;
        return false;
    }

    //This function will add stock back to the movie that was actually borrowed
    //in the case that the requested movie to return is equivalent to what the
    // customer actually borrowed. (only for classics)
    actualCustomer->returnRentable(1, *actualRentable);

    return true;
}