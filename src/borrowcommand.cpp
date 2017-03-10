#include "borrowcommand.h"

#include "store.h"

BorrowCommand::BorrowCommand(int customerID, char type, char subtype,
                             std::string data)
{
    cust = Customer(customerID, "", "");
    rent = Store::buildRentable(type, subtype, data);
}
BorrowCommand::~BorrowCommand()
{
    delete rent;
}

bool BorrowCommand::processCommand()
{
    storeInst->borrowRentable(cust, *rent);

    return true;
}