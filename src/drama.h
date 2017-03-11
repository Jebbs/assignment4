/*******************************************************************************
 * Drama
 *
 * Author: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-10
 *
 * Drama movie: interface
 * Drama DVD inherits from public DVD
 ******************************************************************************/
#ifndef DRAMA_H
#define DRAMA_H

#include "dvd.h"
#include <string>


/*
* Subclass of DVD class.
*
* Drama movies are stored in a Binary Search Tree, sorted by Director and Title.
*/
class Drama : public DVD
{
public:
	/*
	* Creates an instance of drama movie.
	*/
	Drama(int stock, std::string title, std::string director,
		  int releaseYear);

	~Drama();

protected:
	/*
	* Prints the drama inventory
	* output example: 10, Nora Ephron, You've Got Mail, 1998
	*/
	void print(std::ostream& outStream) const;

	/*
	* Returns title==, director==
	*/
	bool equalTo(const Rentable& rentable) const;

	/*
	* Returns < based on title and director
	*/
	bool lessThan(const Rentable& rentable) const;

	/*
	* Returns > based on title and director
	*/
	bool greaterThan(const Rentable& rentable) const;
};

#endif //DRAMA_H