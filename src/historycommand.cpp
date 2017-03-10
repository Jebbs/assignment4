#include "historycommand.h"

#include "hashtable.h"

HistoryCommand::HistoryCommand():searchCustomer(0,"","")
{

}

HistoryCommand::HistoryCommand(int customerID): searchCustomer(customerID, "", "")
{
    
}


bool HistoryCommand::processCommand()
{

    HashTable& customers = getHashTable();

    Customer* actualCustomer;

    customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << searchCustomer.getCustomerID();
        std::cerr<< " not found." << std::endl;
        return false;
    }

    actualCustomer->displayHistory();

    return true;
}