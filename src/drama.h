/*******************************************************************************
 * Drama
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * Drama movie: interface
 * Drama DVD inherits from public DVD
 *
 * Drama movies are primarily sorted by Director, then by Title
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
	Drama(int stock, const std::string& title, const std::string& director,
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
	* Returns < based on Director, then by Title
	*/
	bool lessThan(const Rentable& rentable) const;

	/*
	* Returns > based on Director, then by Title
	*/
	bool greaterThan(const Rentable& rentable) const;
};

#endif //DRAMA_H