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
	Drama(/*parameters to create drama movie*/);

	~Drama();

	/*
	* Returns title==, director==
	*/
	bool operator ==(const Drama &rhs) const;

	/*
	* Returns title!=, director!=
	*/
	bool operator !=(const Drama &rhs) const;

	/*
	* Returns < based on title and director
	*/
	bool operator <(const Drama &rhs) const;

	/*
	* Returns > based on title and director
	*/
	bool operator >(const Drama &rhs) const;

	/*
	* Returns title
	*/
	std::string getTitle();

	/*
	* Returns director
	*/
	int getDirector();


private:
	Drama();
	std::string director;
	std::string title;
};

#endif //COMEDY_H