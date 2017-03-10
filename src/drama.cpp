#include "drama.h"

bool Drama::greaterThan(Rentable & rentable) const
{
	Drama& asDrama = static_cast<Drama&>(rentable);

	if (asDrama.getTitle() > rentable.getTitle())
	{
		return true;
	}
	return false;
}

Drama::Drama(): DVD(DVDType type, int stock, std::string title, std::string director,
	int releaseYear, int rentalPeriodInDays)
{
	this->subType = type;
	this->stock = stock;
	this->title = title;
	this->director = director;
	this->year = releaseYear;
	this->setRentalPeriodInDays(getRentalPeriodInDays);
}

Drama::~Drama()
{
}

void Drama::print(std::ostream& outStream) const
{
	std::string tab5 = "     ";
	std::string tab4 = "    ";
	std::string tab3 = "   ";
	
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

	outStream << this->getDirector() << ", " << this->getTitle() << ", " << this->getReleaseYear();
}

bool Drama::equalTo(Rentable & rentable) const
{
	
	Drama& asDrama = static_cast<Drama&>(rentable);

	if ((asDrama.getTitle() == rentable.getTitle()) && (asDrama.getReleaseYear() == rentable.getReleaseYear()))
	{
		return true;
	}
	return false;
}

bool Drama::lessThan(Rentable & rentable) const
{
	Drama& asDrama = static_cast<Drama&>(rentable);

	if (asDrama.getTitle() < rentable.getTitle())
	{
		return true;
	}
	return false;
}
