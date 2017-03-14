#include "comedy.h"
#include "rentalperiods.h"

Comedy::Comedy(int stock, const std::string& title, const std::string& director,
	           int releaseYear):DVD(DVDType::ComedyDVD, stock, title, director,
			   releaseYear, DVD_RENTAL_PERIOD)
{
}

Comedy::~Comedy()
{
}

bool Comedy::equalTo(const Rentable& rentable) const
{
	const Comedy* asComedy = dynamic_cast<const Comedy*>(&rentable);

	if(asComedy == nullptr)
	{
		return false;
	}

	if ((this->title == asComedy->title) &&
		    (this->releaseYear == asComedy->releaseYear))
	{
		return true;
	}
	return false;
}

bool Comedy::lessThan(const Rentable& rentable) const
{
	const Comedy* asComedy = dynamic_cast<const Comedy*>(&rentable);

	if (this->title < asComedy->title)
	{
		return true;
	}
	else if ((this->title == asComedy->title) &&
	         (this->releaseYear < asComedy->releaseYear))
	{
		return true;
	}
	return false;
}

bool Comedy::greaterThan(const Rentable& rentable) const
{
	const Comedy* asComedy = dynamic_cast<const Comedy*>(&rentable);

	if (this->title > asComedy->title)
	{
		return true;
	}
	else if ((this->title == asComedy->title) &&
			 (this->releaseYear > asComedy->releaseYear))
	{
		return true;
	}
	return false;
}

void Comedy::print(std::ostream& outStream) const
{
	// if statement for formatting purposes only
	if (this->getStockCount() < 10)
	{
		outStream << this->stock << "    ";
	}
	else if (this->stock < 100)
	{
		outStream << this->stock << "   ";
	}
	else
	{
		outStream << this->stock << "  ";
	}

	outStream << this->director << ", " << this->title << ", " << this->releaseYear;
}