#include "commandfactory.h"

#include "command.h"
#include "borrowcommand.h"
#include "returncommand.h"
#include "inventorycommand.h"
#include "historycommand.h"



Command* CommandFactory::createCommand(std::string line)
{

    if(line.empty())
    {
        //print error

        return nullptr;
    }

    char commandCode = line[0];

    switch(commandCode)
    {
        case 'I':
        {
            return new InventoryCommand();
        }
        case 'H':
        {
            //get remaining info
            return new HistoryCommand();
        }
        case 'B':
        {
            //get remaining info
            return new BorrowCommand();
        }
        case 'R':
        {
            //get reamining info
            return new ReturnCommand();
        }
        default:
        {
            //unknown error code if here

            //print error

            return nullptr;
        }
    }

}