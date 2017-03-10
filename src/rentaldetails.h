#ifndef RENTALDETAILS_H
#define RENTALDETAILS_H
#include "rentable.h"
#include <iostream>
#include <string>

/*
 * RentalDetails describes the detail of something being rented.
 * That is, it will store, the rental data, what was rented, and how
 * many were rented.
 */
struct RentalDetails
{
public:

    Rentable& rental;
    int rentDate;
	int count;
	bool returned;
	std::string action;

private:

};

#endif //RENTALDETAILS_H
