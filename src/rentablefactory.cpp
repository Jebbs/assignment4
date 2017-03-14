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
        case DVD:
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

            //check for exexption?
            int stock = std::stoi(info[1]);

            std::string director = info[2];
            std::string title = info[3];

            std::vector<std::string> extra = split(info[4], " ");

            int extraLength = extra.size();

            int releaseYear = std::stoi(extra[extraLength-1]);
            int releaseMonth = std::stoi(extra[extraLength-2]);

            std::string majorActor = extra[0];
            int position = 1;

            while (position < extraLength -2)
            {
                majorActor += " " + extra[position];
                position++;
            }

            Classic* newClassic = new Classic(stock, title, director,
	        releaseYear, majorActor, releaseMonth);

            return newClassic;

        }
        case 'D':
        {
            std::vector<std::string> info = split(line, ", ");

            //check for exexption?
            int stock = std::stoi(info[1]);
            int releaseYear = std::stoi(info[4]);

            std::string director = info[2];
            std::string title = info[3];

            Drama* newDrama = new Drama(stock, title, director,releaseYear);

            return newDrama;
        }
        case 'F':
        {
            std::vector<std::string> info = split(line, ", ");

            //check for exexption?
            int stock = std::stoi(info[1]);
            int releaseYear = std::stoi(info[4]);

            std::string director = info[2];
            std::string title = info[3];

            Comedy* newComedy = new Comedy(stock, title, director, releaseYear);

            return newComedy;
        }
        default:
        {
            std::cerr << "ERROR: Unknown DVD code " << "\"" << DVDCode << "\"";
            std::cerr << std::endl;

            return nullptr;
        }
    }
}