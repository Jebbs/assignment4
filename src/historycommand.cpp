#include "historycommand.h"

#include "store.h"

HistoryCommand::HistoryCommand(int customerID)
{
    cust = Customer(customerID, "", "");
}


bool HistoryCommand::processCommand()
{
    storeInst->displayHistory(cust);

    return true;
}