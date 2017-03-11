#include "drama.h"
#include "rentalperiods.h"

Drama::Drama(int stock, std::string title, std::string director,
	         int releaseYear): DVD(DramaDVD, stock, title,
			 director, releaseYear,DVD_RENTAL_PERIOD)
{
	//this->subType = type;
	//this->stock = stock;
	//this->title = title;
	//this->director = director;
	//this->year = releaseYear;
	//this->setRentalPeriodInDays(getRentalPeriodInDays);
}


Drama::~Drama()
{
}

void Drama::print(std::ostream& outStream) const
{
	std::string tab5 = "     ";
	std::string tab4 = "    ";
	std::string tab3 = "   ";

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

	outStream << this->director << ", " << this->getTitle() << ", ";
	outStream << this->getReleaseYear();
}

bool Drama::equalTo(const Rentable & rentable) const
{
	try
	{
	    const Drama& asDrama = dynamic_cast<const Drama&>(rentable);

	    if ((asDrama.getTitle() == rentable.getTitle()) &&
		(asDrama.getReleaseYear() == rentable.getReleaseYear()))
	    {
		return true;
	    }
	}
	catch(...) // catch all other cases
	{
		return false;
	}
}

bool Drama::greaterThan(const Rentable & rentable) const
{
	try
	{
	    const Drama& asDrama = dynamic_cast<const Drama&>(rentable);

	    if (asDrama.getTitle() > rentable.getTitle())
	    {
		return true;
	    }
	}
	catch(...) // catch all other cases
	{
		return false;
	}
}

bool Drama::lessThan(const Rentable & rentable) const
{
	try
	{
		const Drama& asDrama = dynamic_cast<const Drama&>(rentable);

		//TODO!!!!!!
		//only comparing title?
		//What if title is same but release year is different?

		if (asDrama.getTitle() < rentable.getTitle())
		{
			return true;
		}
	}
	catch(...) // catch all other cases
	{
		return false;
	}
}
