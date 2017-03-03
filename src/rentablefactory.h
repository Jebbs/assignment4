#ifndef RENTABLEFACTORY_H
#define RENTABLEFACTORY_H

#include <string>
#include "rentable.h"

/*
 * Creates Rentables (currently: DVDs) based on string that is passed in.
 */
class RentableFactory
{
public:
	RentableFactory();
	~RentableFactory();

	/*
     * Creates a Rentable based on str. 
     * D creates a DVD.
     * If incorrect string is passed in, prints 
     * error message to std::cerr.
     */
	bool createRentable(std::string str);

private:
	
};

#endif //RENTABLEFACTORY_H