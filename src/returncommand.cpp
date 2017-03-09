#include "returncommand.h"

ReturnCommand::ReturnCommand(int customerID, RentableType type, int subtype, std::string data)
{
    cust = Customer(customerID, "", "");

    //rebuild a string with the correct data in it

    std::string dataLine;

    Rentable* rent = RentableFactory.createRentable(type, dataLine);
}



void ReturnCommand::processCommand()
{
    store->returnRentable(customerID, type, subtype, data);
}