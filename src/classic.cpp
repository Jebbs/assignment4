#include "classic.h"

Classic::Classic(RentableType type, int stock, std::string title, int releaseYear,
	int rentalPeriodInDays, std::string actor, int month)
{
	this->subType = type;
	this->stock = stock;
	this->title = title;
	this->year = releaseYear;
	this->setRentalPeriodInDays(rentalPeriodInDays);
	this->majorActor = actor;
	this->month = month;
}

void Classic::print(std::ostream& outStream) const
{
	// formatting
	if (this->getStockCount() > 9)
	{
		outStream << this->getStockCount() << "     ";
	}
	else if (this->getStockCount() > 99)
	{
		outStream << this->getStockCount() << "   ";
	}
	else
	{
		outStream << this->getStockCount() << "    ";
	}
	outStream << this->getDirector() << ", " << this->getTitle() << ", " << this->getMajorActor() << ", ";
	outStream << this->getMonth() << ". " << this->getReleaseYear << endl;
}