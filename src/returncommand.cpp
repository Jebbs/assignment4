#include "returncommand.h"

#include "store.h"

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

bool ReturnCommand::processCommand()
{
    storeInst->returnRentable(cust, *rent);

    return true;
}