#include "historycommand.h"

#include "hashtable.h"

HistoryCommand::HistoryCommand(int customerID): cust(customerID, "", "")
{
    
}


bool HistoryCommand::processCommand()
{

    HashTable& customers = getHashTable();

    Customer* actualCustomer;

    customers.retrieve(cust, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << cust.getCustomerID();
        std::cerr<< " not found." << std::endl;
        return;
    }

    actualCustomer->displayHistory();

    return true;
}