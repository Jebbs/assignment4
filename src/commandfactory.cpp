#include "commandfactory.h"
#include "command.h"
#include "borrowcommand.h"
#include "returncommand.h"
#include "inventorycommand.h"
#include "historycommand.h"

#include <sstream>

Command* CommandFactory::createCommand(std::string line)
{

    if(line.empty())
    {
        //print error?

        return nullptr;
    }


    std::stringstream stream;
    stream.str(line);


    char commandCode;

    stream >> commandCode;

    switch(commandCode)
    {
        case 'I':
        {
            return new InventoryCommand();
        }
        case 'H':
        {
            //get remaining info

            int customerID;

            stream >> customerID;

            return new HistoryCommand(customerID);
        }
        case 'B':
        {
            int customerID;
            char type, subtype;
            std::string data;

            stream >> customerID >> type >> subtype >> data;

            return new BorrowCommand(customerID, type, subtype, data);
        }
        case 'R':
        {
            int customerID;
            char type, subtype;
            std::string data;

            stream >> customerID >> type >> subtype >> data;
            
            return new ReturnCommand(customerID, type, subtype, data);
        }
        default:
        {
            std::cerr << "Error: Command code \"" << commandCode << "\" not a ";
            std::cerr << "valid command code." << std::endl;

            return nullptr;
        }
    }

}