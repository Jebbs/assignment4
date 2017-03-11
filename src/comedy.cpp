#include "comedy.h"
#include "rentalperiods.h"

Comedy::Comedy(int stock, std::string title, std::string director,
	           int releaseYear): DVD(ComedyDVD, stock, title, director,
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
		return false;

	if ((this->title == asComedy->title) &&
		    (this->year == asComedy->year))
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
		     (this->year < asComedy->year 
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
		     (this->year > asComedy->year 
	{
		return true;
	}
	return false;
}

void Comedy::print(std::ostream& outStream) const
{
	// if statement for formatting purposes only
	if (this->getStockCount() > 9)
	{
		outStream << this->stock << "     ";
	}
	else if (this->stock > 99)
	{
		outStream << this->stock << "   ";
	}
	else
	{
		outStream << this->stock << "    ";
	}

	outStream << this->director << ", " << this->title << ", " << this->year << std::endl;
}