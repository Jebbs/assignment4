#include "rentable.h"


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