#include "comedy.h"
#include "rentalperiods.h"

Comedy::Comedy(int stock, std::string title, std::string director,
	           int releaseYear): DVD(ComedyDVD, stock, title, director,
			   releaseYear, DVD_RENTAL_PERIOD)
{
	//this->subType = type;
	//this->stock = stock;
	//this->title = title;
	//this->director = director;
	//this->year = releaseYear;
	//this->setRentalPeriodInDays(getRentalPeriodInDays);
}

Comedy::~Comedy()
{

}

//for the scope of this assignment, we know that it will always be correct input
// by the time it reaches here.
bool Comedy::equalTo(const Rentable& rentable) const //title, release year
{
		const Comedy* asComedy = dynamic_cast<const Comedy*>(&rentable);

		if(asComedy == nullptr)
			return false;

		if ((this->getTitle() == asComedy->getTitle()) &&
		    (this->getReleaseYear() == asComedy->getReleaseYear()))
		{
			return true;
		}
		return false;
}

bool Comedy::lessThan(const Rentable& rentable) const
{
	if (this->getTitle() < rentable.getTitle())
	{
		return true;
	}
	return false;
}

bool Comedy::greaterThan(const Rentable& rentable) const
{
	//don't even need to cast, because all rentables have this field

	//compare other fields here if title is equal?

	return this->getTitle() > rentable.getTitle();

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

	outStream << this->director << ", " << this->getTitle() << ", " << this->getReleaseYear();
}