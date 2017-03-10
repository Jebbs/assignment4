#include "dvd.h"

DVD::DVD(DVDType type, int stock, std::string title, std::string director, int releaseYear, int rentalPeriodInDays): 
	Rentable(RentableType type, int stock, std::string Title, int releaseYear, int rentalPeriodInDays)
{
	this->type = DVD;
	this->subType = type;
	this->director = director;
}

std::string DVD::getDirector() const
{
	return this->director;
}