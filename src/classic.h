/*******************************************************************************
 * Classic
 *
 * Author: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-10
 *
 * Classic movie: interface
 * Classic DVD inherits from public DVD
 ******************************************************************************/

#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include "dvd.h"

/*
 * Subclass of DVD class.
 * In addition to DVD, Classical movie contains Major Actor's name and 
 * release month.
 *
 * Classic movies are stored in Binary Search Tree, sorted by Release date, 
 * then Major Actor
 */
class Classic : public DVD
{
public:

    /*
     * Creates an instance of Classic movie.
     */
	Classic(int stock, std::string Title, std::string director,
	        int releaseYear, std::string actor, int month);

    ~Classic();

	/*
	 * Returns title==, director==, and month/year==
	 */
	bool operator ==(const Classic &rhs) const;		

	/*
	 * Returns title!=, director!=, and month/year!=
	 */
	bool operator !=(const Classic &rhs) const;		

	/*
	 * Returns < based on Release date, then Major actor
	 */
	bool operator <(const Classic &rhs) const;

	/*
	 * Returns > based on Release date, then Major actor
	 */
	bool operator >(const Classic &rhs) const;

    /*
     * Returns Major Actor's name
     */
	std::string getMajorActor();

    /*
     * Returns month of the release
     */
	int getMonth();

private:
	int month;
	std::string majorActor;
};

#endif //CLASSIC_H