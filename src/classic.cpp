#include "classic.h"
#include "rentalperiods.h"

#include <iostream>

Classic::Classic(int stock, std::string Title, std::string director,
	        int releaseYear, std::string actor, int month)
{
	this->type = RentableType::DVD;
	this->subtype = ClassicDVD;
	this->stock = stock;
	this->title = Title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->rentalPeriodInDays = DVD_RENTAL_PERIOD;
	
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

bool Classic::equalTo(const Rentable& rentable) const //sorted by actor then releasedate
{
		const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

		if(asClassic == nullptr)
			return false;

		if (this->month == asClassic->month && 
			this->releaseYear == asClassic->releaseYear &&
			this->majorActor == asClassic->majorActor)
		{
			return true;
		}


		return false;
}

bool Classic::lessThan(const Rentable& rentable) const
{
	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	//asClassic should never be null

	if (this->month < asClassic->month && this->releaseYear < asClassic->releaseYear)
	{
		return true;
	}
	else if ((this->month == asClassic->month && this->releaseYear == asClassic->releaseYear) &&
		     (this->majorActor < asClassic->majorActor))
	{
		return true;
	}
	return false;
}

bool Classic::greaterThan(const Rentable& rentable) const
{
	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	if (this->month > asClassic->month && this->releaseYear > asClassic->releaseYear)
	{
		return true;
	}
	else if ((this->month == asClassic->month && this->releaseYear == asClassic->releaseYear) &&
		     (this->majorActor > asClassic->majorActor))
	{
		return true;
	}
	return false;
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