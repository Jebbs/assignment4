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
        // Unclear whether an error message should be print
        // will revisit at a later time.
        return nullptr;
    }

    std::stringstream stream;
    stream.str(line);

    char commandCode;

    stream >> commandCode;

    switch(commandCode)
    {
        case 'I': // inventory
        {
            return new InventoryCommand();
        }
        case 'H': // history
        {
            //get remaining info

            int customerID;

            stream >> customerID;

            return new HistoryCommand(customerID);
        }
        case 'B':  // Borrow
        {
            int customerID;
            char type, subtype;
            std::string data;

            stream >> customerID >> type >> subtype >> data;

            return new BorrowCommand(customerID, type, subtype, data);
        }
        case 'R': // Return
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