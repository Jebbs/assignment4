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

void Rentable::addToStock(int amount);

RentableType Rentable::getType() const;

int Rentable::getSubtype() const;

std::string Rentable::getTitle() const;

int Rentable::getReleaseYear() const;

int Rentable::getRentalPeriodInDays() const;

void Rentable::setRentalPeriodInDays(int rentalPeriod);

int Rentable::getStockCount() const;

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
