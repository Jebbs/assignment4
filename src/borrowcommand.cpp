#include "borrowcommand.h"



BorrowCommand::BorrowCommand(int customerID, RentableType type, int subtype, std::string data)
{
    cust = Customer(customerID, "", "");

    //rebuild a string with the correct data in it

    std::string dataLine;

    Rentable* rent = RentableFactory.createRentable(type, dataLine);
}

void BorrowCommand::processCommand()
{
    store->borrowRentable(customerID, type, subtype, data);
}