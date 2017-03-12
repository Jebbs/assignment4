#include "store.h"
#include "command.h"
#include "commandfactory.h"

#include "rentablefactory.h"

#include "customer.h"

#include "dvd.h"
#include "dvdtypes.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "split.h"

#include <sstream>


Store::Store(int id)
{
    storeID = id;

    //set up rentable craziness

    //set up customer hash table
}

//The file is assumed to be correctly formatted
//That is, there aren't any lines that have an incorrect
//number of items
void Store::loadCustomers(std::ifstream& file)
{
    while(!file.eof())
    {
        int customerID;
        std::string lastName, firstName;

        file >> customerID >> lastName >> firstName;

        Customer* newCustomer = new Customer(customerID, lastName, firstName);

        customers.insert(newCustomer);
    }
}

void Store::loadRentables(RentableType type, std::ifstream& file)
{
    while(!file.eof())
    {
        std::string line;
        std::getline(file, line);

        //may emit an error and return nullptr
        Rentable* newRentable = RentableFactory::createRentable(type, line);

        if(newRentable != nullptr)
        {
            //do something with the rentable
            rentables.insert(newRentable);
        }
    }
}

void Store::loadCommands(std::ifstream& file)
{
     while(!file.eof())
    {
        std::string line;

        std::getline(file, line);

        //may emit an error and return nullptr
        Command* newCommand = CommandFactory::createCommand(line);

        if(newCommand != nullptr)
        {
            //give the command an instance of the store that created it
            newCommand->storeInst = this;

            commandQueue.push(newCommand);
        }
    }
}

void Store::processCommands()
{
    while(!commandQueue.empty())
    {
        Command* nextCommand = commandQueue.front();
        commandQueue.pop();
        nextCommand->processCommand();

        delete nextCommand;
    }
}


int Store::getID() const
{
    return storeID;
}


void Store::printInventory()
{
    rentables.printInventory();
}

void Store::displayHistory(Customer& searchCustomer)
{
    Customer* actualCustomer;

    customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << searchCustomer.getCustomerID();
        std::cerr<< " not found." << std::endl;
        return;
    }

    actualCustomer->displayHistory();
}

void Store::borrowRentable(Customer& searchCustomer, Rentable& searchRentable)
{
    Customer* actualCustomer;

    customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << searchCustomer.getCustomerID();
        std::cerr<< " not found." << std::endl;
        return;
    }

    Rentable* actualRentable;

    if(!rentables.retrieve(&searchRentable, actualRentable))
    {
        std::cerr << "ERROR: Rentable with title " << searchRentable.getTitle();
        std::cerr<< " not carried in the store." << std::endl;
        return;
    }

    //update in store

    actualCustomer->borrowRentable(1, *actualRentable);
}

void Store::returnRentable(Customer& searchCustomer, Rentable& searchRentable)
{
    Customer* actualCustomer;

    customers.retrieve(searchCustomer, actualCustomer);

    if(actualCustomer == nullptr)
    {
        std::cerr << "ERROR: Customer with ID " << searchCustomer.getCustomerID();
        std::cerr<< " not found." << std::endl;
        return;
    }

    Rentable* actualRentable;

    if(!rentables.retrieve(&searchRentable, actualRentable))
    {
        std::cerr << "ERROR: Rentable with title " << searchRentable.getTitle();
        std::cerr<< " not carried in the store." << std::endl;
        return;
    }

    //update in store

    actualCustomer->returnRentable(1, *actualRentable);
}

//build DVD rentables
static Comedy* buildComedy(std::string data);
static Drama* buildDrama(std::string data);
static Classic* buildClassic(std::string data);

Rentable* Store::buildRentable(char type, char subtype, std::string data)
{

    //code to RentableType

    RentableType test = DVD;

    switch(test)
    {
        case DVD:
        {
            switch(codeToDVDType(subtype))
            {
                case ComedyDVD:
                {
                    return buildComedy(data);
                }
                case DramaDVD:
                {
                    return buildDrama(data);
                }
                case ClassicDVD:
                {
                    return buildClassic(data);
                }
                default:
                    return nullptr;
            }
        }
        default:
            return nullptr;
    }
}

Comedy* buildComedy(std::string data)
{
    // split the string, ex. You've Got Mail, 1998
    std::vector<std::string> retString = split(data, ", ");

    // assign the data
    std::string title = retString[0];
    int year = std::stoi(retString[1]);

    // create new 
    return new Comedy(0, title, "", year);
}

Drama* buildDrama(std::string data)
{
    // split the string, ex. Steven Spielberg, Schindler's List,
    std::vector<std::string> retString = split(data, ",");
    
    // assign the data
    std::string director = retString[0];
    std::string title = retString[1];
    title = title.substr(1, std::string::npos);

    // create new 
    return new Drama(0, title, director, 0);
}

Classic* buildClassic(std::string data)
{
    // split the string, ex. 9 1938 Katherine Hepburn 
    std::stringstream stream;

    stream.str(data);

    int month, year;

    std::string actor;
    
    // assign the data 
    stream >> month >> year;
    std::getline(stream, actor);

    actor = actor.substr(1,std::string::npos);
    
    // create new
    return new Classic(0, "", "", year, actor, month);
}