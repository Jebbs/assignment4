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
 *
 * Comdey movies are primarily sorted by Title, then by Release Year
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
	Comedy(int stock, const std::string& title, const std::string& director,
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
	* Returns < based on Title, then by Release Year
	*/
	bool lessThan(const Rentable& rentable) const;

	/*
	* Returns > based on Title, then by Release Year
	*/
	bool greaterThan(const Rentable& rentable) const;

private:
};

#endif //COMEDY_H