#ifndef MOVIE_H
#define MOVIE_H

#include "rentable.h"

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
    DVD(MovieType type,int stock, std::string title, std::string director,
    int releaseYear, int rentalPeriodInDays);


private:

    std::string director;

    std::string title;

}

#endif //MOVIE_H
