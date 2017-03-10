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
	Comedy(DVDType type, int stock, std::string title, std::string director,
		int releaseYear, int rentalPeriodInDays);

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
	//Comedy(); //was duplicated
	int year;
	std::string title;
};

#endif //COMEDY_H