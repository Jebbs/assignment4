/*******************************************************************************
 * Rentable
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * The Rentable class models any rentable type (for example, DVD, console, etc.) 
 * that can be rented from the store.
 ******************************************************************************/
#ifndef RENTABLE_H
#define RENTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "command.h"
#include "rentabletype.h"

/*
 * The Rentable class models some kind of item that can be
 * rented from a video store.
 */
class Rentable
{
public:
    Rentable(RentableType type, int stock, const std::string& Title, 
             int releaseYear, int rentalPeriodInDays);
    virtual ~Rentable();

    bool inStock() const;

    /*
     * Remove a number of items from the stock for this rentable as if it
     * was being rented out.
     *
     * This function will return false if there are not enough items
     * to cover the amount trying to be rented.
     */
    bool removeFromStock(int amount);

    /*
     * Add a number of items back to the stock for this rentable as if it
     * was being returned.
     */
    void addToStock(int amount);

    RentableType getType() const;

    int getSubtype() const;

    std::string getTitle() const;

    int getReleaseYear() const;

    int getRentalPeriodInDays() const;

    void setRentalPeriodInDays(int rentalPeriod);

    int getStockCount() const;

    bool operator==(const Rentable& rentable) const;
    bool operator!=(const Rentable& rentable) const;
    bool operator<(const Rentable& rentable) const;
    bool operator>(const Rentable& rentable) const;

    //prints the rentable data to outsream
    friend std::ostream& operator<<(std::ostream& outStream, Rentable& rentable);

protected:
    // This constructor is private so that it cannot be accessed through 
    // normal means.
    Rentable();

    //the main rentable type (DVD, Console, etc.)
    RentableType type;
    //some generic subtype, dependent on main type
    int subtype;
    
    int stock;

    int releaseYear;

    std::string title;

    int rentalPeriodInDays;

    std::vector<Command> history;

    virtual void print(std::ostream& outStream) const = 0;
    virtual bool equalTo(const Rentable& rentable) const = 0;
    virtual bool lessThan(const Rentable& rentable) const = 0;
    virtual bool greaterThan(const Rentable& rentable) const = 0;
};

#endif //RENTABLE_H
