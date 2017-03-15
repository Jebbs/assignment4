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

RentableType codeToRentableType(char code);

Store::Store(int id)
{
    storeID = id;
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

//build DVD rentables
static Comedy* buildComedy(std::string data);
static Drama* buildDrama(std::string data);
static Classic* buildClassic(std::string data);

Rentable* Store::buildRentable(char type, char subtype, std::string data)
{
    switch(codeToRentableType(type))
    {
        case RentableType::DVD:
        {
            switch(codeToDVDType(subtype))
            {
                case DVDType::ComedyDVD:
                {
                    return buildComedy(data);
                }
                case DVDType::DramaDVD:
                {
                    return buildDrama(data);
                }
                case DVDType::ClassicDVD:
                {
                    return buildClassic(data);
                }
                default:
                {
                    std::cerr << "ERROR: DVD code " << "\"";
                    std::cerr << subtype << "\"";
                    std::cerr << " is not a valid DVD code." << std::endl;

                    return nullptr;
                }
            }
        }
        default:
        {
            std::cerr << "ERROR: Rentable code " << "\"";
            std::cerr << type << "\"";
            std::cerr << " is not a valid rentable code." << std::endl;
            return nullptr;
        }
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

    std::string actorFirstName, actorLastName;

    // assign the data
    stream >> month >> year >> actorFirstName >> actorLastName;

    // create new
    return new Classic(0, "", "", year, actorFirstName, actorLastName, month);
}

RentableType codeToRentableType(char code)
{
    switch(code)
    {
        case 'D':
        {
            return RentableType::DVD;
        }
        default:
        {
            return RentableType::None;
        }
    }
}
