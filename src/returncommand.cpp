#include "returncommand.h"

ReturnCommand::ReturnCommand(int customerID, char type, char subtype,
                             std::string data)
{
    cust = Customer(customerID, "", "");
    rent = Store::buildRentable(type, subtype, data);
}

ReturnCommand::~ReturnCommand()
{
    delete rent;
}

void ReturnCommand::processCommand()
{
    store->returnRentable(cust, *rent);
}