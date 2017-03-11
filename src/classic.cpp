#include "classic.h"
#include "rentalperiods.h"

Classic::Classic(int stock, std::string Title, std::string director,
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
	
	outStream << this->director << ", " << this->getTitle() << ", ";
	outStream << this->getMajorActor() << ", ";
	outStream << this->getMonth() << ". " << this->getReleaseYear() << std::endl;
}

bool Classic::equalTo(const Rentable& rentable) const //title, release year
{
		const Classic* asClassic = dynamic_cast<const Classic*>(&rentable);

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
	if (this->getTitle() < rentable.getTitle())
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