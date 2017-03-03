

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
    Rentable(RentableType type, int stock, std::string Title, int releaseYear, int rentalPeriodInDays);

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

    /*
     * Add a command that interacts with this rentable into a history
     * for later analysis.
     */
    void addToHistory(Command& command);//change this name because it's dumb

    RentableType getType() const;

    std::string getTitle() const;

    int getReleaseYear() const;
    int getRentalPeriodInDays() const;
    void setRentalPeriodInDays(int rentalPeriod);

    int getStockCount() const;

    //out puts data and stuff
    friend std::ostream& operator<<(std::ostream& outStream, Rentable& rentable);

private:

    //so people can't call it!
    Rentable();

    RentableType type;
    int stock;

    int releaseYear;

    std::string title;

    int rentalPeriodInDays;

    std::vector<Command> history;

};

#endif //RENTABLE_H
