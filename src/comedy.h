/*******************************************************************************
 * Comedy
 *
 * Author:
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified:
 * 2017-03-10
 *
 * Comedy movie: interface
 * Comedy DVD inherits from public DVD
 ******************************************************************************/

#ifndef COMEDY_H
#define COMEDY_H

#include "dvd.h"
#include <string>
#include "dvd.h"

/*
* Subclass of DVD class.
*
* Comedy movies are stored in Binary Search Tree, sorted by Title and
* Release Year.
*/
class Comedy : public DVD
{
public:
	/*
	* Creates an instance of Comedy movie.
	*/
	Comedy(int stock, std::string title, std::string director,
		   int releaseYear);

	~Comedy();

protected:
	/*
	* prints the comedy inventory
	*/
	void print(std::ostream& outStream) const;

	/*
	* Returns title==, releaseYear==
	*/
	bool equalTo(const Rentable& rentable) const;

	/*
	* Returns < based on title and release year
	*/
	bool lessThan(const Rentable& rentable) const;

	/*
	* Returns > based on title and release year
	*/
	bool greaterThan(const Rentable& rentable) const;

private:
	int year;
	std::string title;
};

#endif //COMEDY_H