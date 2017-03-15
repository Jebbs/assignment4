/*******************************************************************************
 * Classic
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * Classic movie: interface
 * Classic DVD inherits from public DVD
 * 
 * Classic movies are primarily sorted by Release date, then by Major actor
 ******************************************************************************/
#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include "dvd.h"

/*
 * Subclass of DVD class.
 * In addition to DVD, Classical movie contains Major Actor's name and
 * release date.
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
	Classic(int stock, const std::string& title, const std::string& director,
	        int releaseYear, const std::string& actorFirstName,
			const std::string& actorLastName, int month);

    ~Classic();

    /*
     * Returns Major Actor's name
     */
	std::string getMajorActor() const;

    /*
     * Returns month of the release
     */
	int getMonth() const;

	virtual bool isEquivalent(const Rentable& rentable) const;

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
	* Returns < based on Release date, then by Major actor
	*/
	bool lessThan(const Rentable& rentable) const;

	/*
	* Returns > based on Release date, then by Major actor
	*/
	bool greaterThan(const Rentable& rentable) const;

private:
	int month;
	std::string majorActorFirstName;
	std::string majorActorLastName;
};

#endif //CLASSIC_H