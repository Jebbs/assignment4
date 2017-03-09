#include "borrowcommand.h"



BorrowCommand::BorrowCommand(int customerID, RentableType type, int subtype, std::string data)
{
    cust = Customer(customerID, "", "");
    rent = Store.buildRentable(type, subtype, data);
}
BorrowCommand::~BorrowCommand()
{
    delete rent;
}

void BorrowCommand::processCommand()
{
    store->borrowRentable(cust, *rent);
}