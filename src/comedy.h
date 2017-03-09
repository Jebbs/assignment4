// --------------------------- classic.h -----------------
// 
// 
// Creation Date: 2/25/2017
// Date of Last Modification: 
// ------------------------------------------------------
// Comedy movie: interface
// Comedy DVD inherits from public DVD
// ------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "dvd.h"
#include <string>
#include "dvd.h"

/*
* Subclass of DVD class.
* 
* Comedy movies are stored in AVL tree, sorted by Title and Release Year.
*/
class Comedy : public DVD
{
public:
	/*
	* Creates an instance of Comedy movie.
	*/
	Comedy(/*parameters to create comedy movie*/);

	~Comedy();
	
	/*
	* Returns title==, releaseYear==
	*/
	bool operator ==(const Comedy &rhs) const;

	/*
	* Returns title!=, releaseYear!=
	*/
	bool operator !=(const Comedy &rhs) const;

	/*
	* Returns < based on title and release year
	*/
	bool operator <(const Comedy &rhs) const;

	/*
	* Returns > based on title and release year
	*/
	bool operator >(const Comedy &rhs) const;

	/*
	* Returns title 
	*/
	std::string getTitle();

	/*
	* Returns release year
	*/
	int getReleaseYear();


private:
	Comedy();
	int year;
	std::string title;
};

#endif //COMEDY_H