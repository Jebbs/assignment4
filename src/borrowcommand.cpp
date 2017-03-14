#include "borrowcommand.h"

#include "hashtable.h"
#include "rentablestorage.h"

#include "classic.h"

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

    if (searchRentable == NULL)
    {
        return false;//borrow command was made with a rentable that was invalid
    }

    RentableStorage& rentables = getRentableStorage();
    HashTable& customers = getHashTable();

    Customer* actualCustomer = nullptr;

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
        std::cerr << "ERROR: Rentable with title ";
        std::cerr << searchRentable->getTitle();
        std::cerr<< " not carried in the store." << std::endl;
        return false;
    }


    //check stock because of potential problems

    std::vector<std::string> searchList;


    while(!actualRentable->removeFromStock(1))
    {

        const Classic* asClassic = dynamic_cast<const Classic*>(actualRentable);

        //not a classic, and only classics search for equivalents
        if(asClassic == nullptr)
        {
            std::cerr << "Error: Not enough stock to rent ";
            std::cerr << searchRentable->getTitle() << std::endl;
            return false;
        }

        //make a list of all major actors we've searched for in case there are
        //multiple copies of the same movie with different actors
        searchList.push_back(asClassic->getMajorActor());

        Rentable* newSearchRentable = actualRentable;

        if(!rentables.retrieveEquivalent(newSearchRentable, searchList, actualRentable))
        {
            std::cerr << "Error: Not enough stock to rent ";
            std::cerr << actualRentable->getTitle() << std::endl;
            return false;
        }
    }

    actualCustomer->borrowRentable(1, *actualRentable);

    return true;
}