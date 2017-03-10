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
	std::string tab5 = "     ";
	std::string tab4 = "    ";
	std::string tab3 = "   ";

	//10, George Cukor, Holiday, Katherine Hepburn 9 1938
	if (this->getStockCount() > 9)
	{
		outStream << this->getStockCount() << tab5;
	}
	else if (this->getStockCount() > 99)
	{
		outStream << this->getStockCount() << tab3;
	}
	else
	{
		outStream << this->getStockCount() << tab4;
	}

	outStream << this->getDirector() << ", " << this->getTitle() << ", " << this->getMajorActor() << ", ";
	outStream << this->getMonth() << ". " << this->getReleaseYear << endl;
}