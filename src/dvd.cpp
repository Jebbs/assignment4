#include "dvd.h"

DVD::DVD(DVDType type, int stock, std::string title, std::string director, int releaseYear, int rentalPeriodInDays)
{
	
}

std::string DVD::getDirector() const
{
	return this->director;
}