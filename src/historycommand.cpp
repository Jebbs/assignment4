#include "historycommand.h"

HistoryCommand::HistoryCommand(int customerID)
{
    cust = Customer(customerID);
}


void HistoryCommand::processCommand()
{
    store->displayHistory(customerID);
}