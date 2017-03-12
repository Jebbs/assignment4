#include "dvd.h"

DVD::DVD(DVDType type, int stock, const std::string& title, const std::string& director,
         int releaseYear, int rentalPeriodInDays): Rentable(RentableType::DVD,
		 stock, title, releaseYear, rentalPeriodInDays)
{
	this->subtype = type;
	this->director = director;
}

