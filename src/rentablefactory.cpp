#include "rentablefactory.h"
#include "dvd.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include <vector>
#include "split.h"
#include "rentalperiods.h"

Rentable* loadDVD(std::string line);

Rentable* RentableFactory::createRentable(RentableType type, std::string line)
{
    switch(type)
    {
        case RentableType::DVD:
        {
            return loadDVD(line);
        }
        default:
        {
            return nullptr;
        }
    }
}

Rentable* loadDVD(std::string line)
{
    if(line.empty())
    {
        return nullptr;
    }

    char DVDCode = line[0];

    switch(DVDCode)
    {
        case 'C':
        {
            std::vector<std::string> info = split(line, ", ");

            try
            {
                int stock = std::stoi(info[1]);

                std::string director = info[2];
                std::string title = info[3];

                std::vector<std::string> extra = split(info[4], " ");

                std::string majorActorFirstName = extra[0];
                std::string majorActorLastName = extra[1];

                int releaseYear = std::stoi(extra[2]);
                int releaseMonth = std::stoi(extra[3]);

                std::string majorActor = extra[0];


                Classic *newClassic = new Classic(stock, title, director,
                                      releaseYear, majorActorFirstName,
                                      majorActorLastName, releaseMonth);

                return newClassic;
            }
            catch (...)
            {
                return nullptr;
            }
        }
        case 'D':
        {
            std::vector<std::string> info = split(line, ", ");
            try
            {
                int stock = std::stoi(info[1]);
                int releaseYear = std::stoi(info[4]);

                std::string director = info[2];
                std::string title = info[3];

                Drama *newDrama = new Drama(stock, title, director, releaseYear);

                return newDrama;
            }
            catch(...)
            {
                return nullptr;
            }
        }
        case 'F':
        {
            std::vector<std::string> info = split(line, ", ");

            try
            {
                int stock = std::stoi(info[1]);
                int releaseYear = std::stoi(info[4]);

                std::string director = info[2];
                std::string title = info[3];

                Comedy *newComedy = new Comedy(stock, title, director, releaseYear);

                return newComedy;
            }
            catch(...)
            {
                return nullptr;
            }
        }
        default:
        {
            std::cerr << "ERROR: DVD code " << "\"" << DVDCode << "\"";
            std::cerr << " is not a valid DVD code." << std::endl;

            return nullptr;
        }
    }
}