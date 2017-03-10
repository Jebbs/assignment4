#include "rentablefactory.h"

#include "dvd.h"
#include "classic.h"
#include "family.h"
#include "drama.h"

#include <vector>
#include "split.h"


Rentable* loadDVD(std::string line);

Rentable* RentableFactory::createRentable(RentableType type, std::string line)
{
    switch(type)
    {
        case DVD:
        {
            return loadDVD(line);
        }
    }
}



Rentable* loadDVD(std::string line)
{
    if(line.empty())
    {
        //print error

        return nullptr;
    }

    char DVDCode = line[0];

    switch(DVDCode)
    {
        case 'C':
        {
            std::vector<std::string> info = split(line, ", ");

            return new Classic();
        }
        case 'D':
        {
            std::vector<std::string> info = split(line, ", ");

            return new Drama();
        }
        case 'F':
        {
            std::vector<std::string> info = split(line, ", ");

            return new Family();
        }
        default:
        {
            //unknown error code if here

            //print error

            return nullptr;
        }
    }
}