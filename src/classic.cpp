#include "classic.h"
#include "rentalperiods.h"

#include <iostream>

Classic::Classic(int stock, const std::string& title, const std::string& director,
	        int releaseYear, const std::string& actorFirstName,
			const std::string& actorLastName, int month):
			DVD(DVDType::ClassicDVD, stock, title, director, releaseYear,
				 DVD_RENTAL_PERIOD)
{
    this->majorActorFirstName = actorFirstName;
	this->majorActorLastName = actorLastName;
    this->month = month;
}

Classic::~Classic()
{
}

std::string Classic::getMajorActor() const
{
	return majorActorFirstName + " " + majorActorLastName;
}

int Classic::getMonth() const
{
	return month;
}

bool Classic::isEquivalent(const Rentable& rentable) const
{

	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	if(asClassic == nullptr)
			return false;

	if (this->month == asClassic->month &&
		this->releaseYear == asClassic->releaseYear &&
		this->title == asClassic->title)
	{
		return true;
	}

	return false;
}

bool Classic::equalTo(const Rentable& rentable) const
{
		const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

		if(asClassic == nullptr)
			return false;

		if (this->month == asClassic->month &&
			this->releaseYear == asClassic->releaseYear &&
			this->majorActorFirstName == asClassic->majorActorFirstName &&
			this->majorActorLastName == asClassic->majorActorLastName)
		{
			return true;
		}

		return false;
}

bool Classic::lessThan(const Rentable& rentable) const
{
	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	//asClassic should never be null

	if (this->month < asClassic->month)
	{
		return true;
	}
	else if(this->month == asClassic->month &&
	          this->releaseYear < asClassic->releaseYear)
	{
		return true;
	}
	else if (this->month == asClassic->month &&
			 this->releaseYear == asClassic->releaseYear &&
			 this->majorActorLastName < asClassic->majorActorLastName)
	{
		return true;
	}
	else if (this->month == asClassic->month &&
			 this->releaseYear == asClassic->releaseYear &&
			 this->majorActorLastName == asClassic->majorActorLastName &&
			 this->majorActorFirstName < asClassic->majorActorFirstName)
	{
		return true;
	}

	return false;
}

bool Classic::greaterThan(const Rentable& rentable) const
{
	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	if (this->month > asClassic->month &&
	    this->releaseYear > asClassic->releaseYear)
	{
		return true;
	}
	else if (this->month == asClassic->month &&
			 this->releaseYear == asClassic->releaseYear &&
			 this->majorActorLastName > asClassic->majorActorLastName)
	{
		return true;
	}
	else if (this->month == asClassic->month &&
			 this->releaseYear == asClassic->releaseYear &&
			 this->majorActorLastName == asClassic->majorActorLastName &&
			 this->majorActorFirstName > asClassic->majorActorFirstName)
	{
		return true;
	}

	return false;
}

void Classic::print(std::ostream& outStream) const
{
	// if statement for formatting purposes only
	if (this->getStockCount() < 10)
	{
		outStream << this->getStockCount() << "    ";
	}
	else if (this->getStockCount() < 100)
	{
		outStream << this->getStockCount() << "   ";
	}
	else
	{
		outStream << this->getStockCount() << "  ";
	}

	outStream << this->month << " " << this->releaseYear << ", ";
	outStream << this->getMajorActor() << " stars in: " << this->title;
	//outStream << this->director << ", " 
}