#include "rentable.h"


Rentable::Rentable(RentableType type, int stock, std::string Title, int releaseYear, int rentalPeriodInDays)
{
	this->type = type;
	this->stock = stock;
	this->title = Title;
	this->releaseYear = releaseYear;
	this->rentalPeriodInDays = rentalPeriodInDays;
}

bool Rentable::inStock() const
{
	return stock>0;
}

bool Rentable::removeFromStock(int amount)
{
	if(stock-amount >= 0)
	{
		stock-=amount;
		return true;
	}

	return false;
}

void Rentable::addToStock(int amount)
{
	stock+=amount;
}

RentableType Rentable::getType() const
{
	return type;
}

int Rentable::getSubtype() const
{
	return subtype;
}

std::string Rentable::getTitle() const
{
	return title;
}

int Rentable::getReleaseYear() const
{
	return releaseYear;
}

int Rentable::getRentalPeriodInDays() const
{
	return rentalPeriodInDays;
}

void Rentable::setRentalPeriodInDays(int rentalPeriod)
{
	rentalPeriodInDays = rentalPeriod;
}

int Rentable::getStockCount() const
{
	return stock;
}

bool Rentable::operator==(const Rentable& rentable) const
{
    return this->equalTo(rentable);
}

bool Rentable::operator!=(const Rentable& rentable) const
{
    return !(this->equalTo(rentable));
}

bool Rentable::operator<(const Rentable& rentable) const
{
    return this->lessThan(rentable);
}

bool Rentable::operator>(const Rentable& rentable) const
{
    return this->greaterThan(rentable);
}

std::ostream& operator<<(std::ostream& outStream, Rentable& rentable)
{
    rentable.print(outStream);
    return outStream;
}
