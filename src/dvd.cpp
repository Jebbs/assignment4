#include "dvd.h"

DVD::DVD(DVDType type, int stock, std::string title, std::string director,
         int releaseYear, int rentalPeriodInDays): Rentable(RentableType::DVD,
		 stock, title, releaseYear, rentalPeriodInDays)
{
	this->subtype = type;
	this->director = director;
}
