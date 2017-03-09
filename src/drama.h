// --------------------------- classic.h -----------------
// 
// Creation Date: 2/25/2017
// Date of Last Modification: 
// ------------------------------------------------------
// Drama movie: interface
// Drama DVD inherits from public DVD
// ------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "dvd.h"
#include <string>
#include "dvd.h"

/*
* Subclass of DVD class.
*
* Drama movies are stored in AVL tree, sorted by Director and Title.
*/
class Drama : public DVD
{
public:
	/*
	* Creates an instance of drama movie.
	*/
	Drama(); // no extra parameters, since same as dvd

	~Drama();

protected:
	/*
	* prints the drama inventory
	* output example: 10, Nora Ephron, You've Got Mail, 1998
	*/
	void print(std::ostream& outStream) const;

	/*
	* Returns title==, director==
	*/
	bool equalTo(Rentable& rentable) const;

	/*
	* Returns < based on title and director
	*/
	bool lessThan(Rentable& rentable) const;

	/*
	* Returns > based on title and director
	*/
	bool greaterThan(Rentable& rentable) const;

private:
	Drama();
};

#endif //DRAMA_H