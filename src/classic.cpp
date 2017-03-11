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

bool Classic::equalTo(const Rentable& rentable) const //sorted by actor then releasedate
{
		const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

		if(asClassic == nullptr)
			return false;

		if ((this->title == asClassic->title) &&
		    (this->releaseYear == asClassic->releaseYear))
		{
			return true;
		}
		return false;
}

bool Classic::lessThan(const Rentable& rentable) const
{
	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	if (this->month < asClassic.month && this->year < asClassic.year)
	{
		return true;
	}
	else if ((this->month == asClassic.month && this->year == asClassic.year) &&
		     (this->majorActor < asClassic->majorActor 
	{
		return true;
	}
	return false;
}

bool Classic::greaterThan(const Rentable& rentable) const
{
	const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

	if (this->month > asClassic.month && this->year > asClassic.year)
	{
		return true;
	}
	else if ((this->month == asClassic.month && this->year == asClassic.year) &&
		     (this->majorActor > asClassic->majorActor 
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