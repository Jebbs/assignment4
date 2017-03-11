#include "classic.h"
#include "rentalperiods.h"

Classic::Classic(int stock, std::string Title, std::string director,
	        int releaseYear, std::string actor, int month):DVD(ClassicDVD, stock,
			title, director, releaseYear, DVD_RENTAL_PERIOD)
{
	this->majorActor = actor;
	this->month = month;
}

Classic::~Classic()
{

}

std::string Classic::getMajorActor() const
{
	return majorActor;
}

int Classic::getMonth() const
{
	return month;
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
	
	outStream << this->director << ", " << this->title << ", ";
	outStream << this->majorActor << ", ";
	outStream << this->month << " " << this->releaseYear << std::endl;
}

bool Classic::equalTo(const Rentable& rentable) const //title, release year
{
		const Classic* asClassic = dynamic_cast<const Classic*>(&rentable); //update others also

		if(asClassic == nullptr)
			return false;

		if ((this->getTitle() == asClassic->getTitle()) &&
		    (this->getReleaseYear() == asClassic->getReleaseYear()))
		{
			return true;
		}
		return false;
}

bool Classic::lessThan(const Rentable& rentable) const
{
	// sorted by title, then release year.
	if (this->getTitle() < rentable.getTitle())
	{
		return true;
	}
	else if ((this->getTitle() == asClassic->getTitle()) &&
		     (this->getReleaseYear() < asClassic->getReleaseYear() 
	{
		return true;
	}
	return false;
}

bool Classic::greaterThan(const Rentable& rentable) const
{
	//don't even need to cast, because all rentables have this field

	//compare other fields here if title is equal?

	return this->getTitle() > rentable.getTitle();

}