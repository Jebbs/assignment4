#include "comedy.h"


Comedy::Comedy(DVDType type, int stock, std::string title, std::string director,
	           int releaseYear, int rentalPeriodInDays): DVD(DVDType type, 
			   int stock, std::string title, std::string director,
               int releaseYear, int rentalPeriodInDays)
{
	this->subType = type;
	this->stock = stock;
	this->title = title;
	this->director = director;
	this->year = releaseYear;
	this->setRentalPeriodInDays(getRentalPeriodInDays);
}

Comedy::~Comedy()
{

}

//for the scope of this assignment, we know that it will always be correct input 
// by the time it reaches here.  
bool Comedy::equalTo(const Rentable& rentable) const //title, release year
{
		Comedy& asComedy = static_cast<Comedy&>(rentable);
		
		if ((asComedy.getTitle() == rentable.getTitle()) && 
		    (asComedy.getReleaseYear() == rentable.getReleaseYear()))
		{
			return true;
		}
		return false;
}

bool Comedy::lessThan(const Rentable& rentable) const
{
	Comedy& asComedy = static_cast<Comedy&>(rentable);
	
	if (asComedy.getTitle() < rentable.getTitle())
	{
		return true;
	}
	return false;
}

bool Comedy::greaterThan(const Rentable& rentable) const
{
	Comedy& asComedy = static_cast<Comedy&>(rentable);

	if (asComedy.getTitle() > rentable.getTitle())
	{
		return true;
	}
	return false;
}

void Comedy::print(std::ostream& outStream) const
{
	std::string tab5 = "     ";
	std::string tab4 = "    ";
	std::string tab3 = "   ";
	
	//10, Nora Ephron, You've Got Mail, 1998
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