
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "rentable.h"
#include "rentaldetails.h"
#include "command.h"

/*
 * Customer class for modeling a store customer.
 *
 * Assume that the input data will always be in a valid format.
 */
class Customer
{
public:

    /*
     * Construct a new customer with the given id, last name, and first name.
     */
    Customer(int id, std::string lastName, std::string firstName);

    int getCustomerID() const;
    void setCustomerID(int newID);

    std::string getCustomerFirstName() const;
    void setCustomerFirstName(std::string newFirstName);

    std::string getCustomerLastName() const;
    void setCustomerLastName(std::string newLastName);

    /*
     * Borrow some rentable and store the borrowing into the
     * customer's history
     */
    bool borrowRentable(Rentable& rentable);

    /*
     * Return some rentable and store the returning into the
     * customer's history
     */
    bool returnRentable(Rentable& rentable);

    /*
     * Display the customer's history for everything they've rented and
     * returned.
     *
     * This will output the information to std::cout by default unless
     * overridden.
     */
    void displayHistory(std::ostream& outStream = std::cout) const;


private:

    //Construct a new Customer.
    //
    //This is a blank customer with no id or name.
    //
    //This constructor is private so that it cannot be accessed through normal means.
    Customer();

    //Add a borrow or return command into the customer's history after processing.
    void addToHistory(Command& newCommand);

    int customerID;

    std::string firstName;
    std::string lastName;

    std::vector<RentalDetails> currentlyRenting;

    std::vector<Command> history;
};

#endif //CUSTOMER_H
