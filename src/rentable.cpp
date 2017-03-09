#include "rentable.h"


bool Rentable::operator==(Rentable& rentable)
{
    return (*this)->equals(rentable);
}

bool Rentable::operator!=(Rentable& rentable)
{
    return !((*this)->equals(rentable));
}

bool Rentable::operator<(Rentable& rentable)
{
    return (*this)->lessThan(rentable);
}

bool Rentable::operator>(Rentable& rentable)
{
    return (*this)->greaterThan(rentable);
}

std::ostream& Rentable::operator<<(std::ostream& outStream, Rentable& rentable)
{
    rentable->print(outStream);
}