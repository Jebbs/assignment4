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
    DVD(DVDType type,int stock, std::string title, std::string director,
    int releaseYear, int rentalPeriodInDays);


private:

    std::string director;

    std::string title;
};

#endif //MOVIE_H
