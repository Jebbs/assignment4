/*******************************************************************************
 * Rentable
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * RentableFactory creates a rentable based on the string passed in.
 ******************************************************************************/
#ifndef RENTABLEFACTORY_H
#define RENTABLEFACTORY_H

#include <string>
#include "rentable.h"
#include "rentabletype.h"

/*
 * Creates Rentables (currently: DVDs) based on string that is passed in.
 */
class RentableFactory
{
public:
	/*
     * Creates a Rentable based on str given its main type.
     *
     * If incorrect string is passed in, prints
     * error message to std::cerr.
     */
	static Rentable* createRentable(RentableType type, std::string line);
};

#endif //RENTABLEFACTORY_H