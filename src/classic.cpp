#include "classic.h"
#include "rentalperiods.h"

Classic(int stock, std::string Title, std::string director,
	        int releaseYear, std::string actor, int month):DVD(ClassicDVD, stock,
			title, director, releaseYear, DVD_RENTAL_PERIOD)
{
	//this->subType = type;
	//this->stock = stock;
	//this->title = title;
	//this->year = releaseYear;
	//this->setRentalPeriodInDays(rentalPeriodInDays);
	this->majorActor = actor;
	this->month = month;
}

void Classic::print(std::ostream& outStream) const
{
	// if statement for formatting purposes only
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
	
	outStream << this->getDirector() << ", " << this->getTitle() << ", ";
	outstream << this->getMajorActor() << ", ";
	outStream << this->getMonth() << ". " << this->getReleaseYear << endl;
}