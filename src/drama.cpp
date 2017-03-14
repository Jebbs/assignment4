#include "drama.h"
#include "rentalperiods.h"

Drama::Drama(int stock, const std::string& title, const std::string& director,
	         int releaseYear):DVD(DVDType::DramaDVD, stock, title, director, 
			 releaseYear, DVD_RENTAL_PERIOD)
{
}

Drama::~Drama()
{
}

bool Drama::equalTo(const Rentable & rentable) const
{
	const Drama* asDrama = dynamic_cast<const Drama*>(&rentable);

		if(asDrama == nullptr)
			return false;

		if ((this->director == asDrama->director) &&
		    (this->title == asDrama->title))
		{
			return true;
		}
		return false;
}

bool Drama::greaterThan(const Rentable & rentable) const
{
	const Drama* asDrama = dynamic_cast<const Drama*>(&rentable);

	if (this->director > asDrama->director)
	{
		return true;
	}
	else if ((this->director == asDrama->director) &&
	         (this->title > asDrama->title))
	{
		return true;
	}
	return false;
}

bool Drama::lessThan(const Rentable & rentable) const
{
	const Drama* asDrama = dynamic_cast<const Drama*>(&rentable);
	
	if (this->director < asDrama->director)
	{
		return true;
	}
	else if ((this->director == asDrama->director) &&
	         (this->title < asDrama->title))
	{
		return true;
	}
	return false;
}

void Drama::print(std::ostream& outStream) const
{
	// if statement for formatting purposes only
	if (this->stock < 10)
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

	outStream << this->director << ", " << this->title << ", ";
	outStream << this->releaseYear;
}
