/*******************************************************************************
 * DVD
 *
 * Author:
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified:
 * 2017-03-10
 *
 * The DVD class models a rentable type DVD.
 * DVD is the only rentable in the scope of this assignment.
 * 
 * To store the data in the system, the items should be sorted as follows:
 * 
 * comedy (‘F’) -> by Title, then Year it released 
 * dramas (‘D’) -> by Director, then Title 
 * classic (‘C’) -> by Release date, then Major Actor
 * 
 * Assumption: Each item is uniquely identified by its complete set 
 * of sorting attributes.  
 ******************************************************************************/
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "rentable.h"
#include "dvdtypes.h"

/*
 * The DVD class models some kind of DVD movie, which
 * is something that can be rented.
 */
class DVD: public Rentable
{
public:

	/*
     * Create a new DVD with the given information.
     */
    DVD(DVDType type,int stock, const std::string& title, const std::string& director,
        int releaseYear, int rentalPeriodInDays);

protected:
    DVD();

    std::string director;
};

#endif //MOVIE_H
