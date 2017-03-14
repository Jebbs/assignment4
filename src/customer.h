/*******************************************************************************
 * Customer
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * The customer class models a store customer. 
 *
 * Assumption: The input data will always be valid.
 ******************************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "rentable.h"
#include "rentaldetails.h"
#include "command.h"
#include "rentalperiods.h"
#include "rentabletype.h"
#include "dvdtypes.h"

/*
 * Customer class for modeling a store customer.
 *
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
     * Borrow (X) copies of some rentable and store the transaction into the
     * customer's history
     * 
     * Update what the customer currenlty has on hand
     */
    bool borrowRentable(int count, Rentable& rentable);

    /*
     * Return (X) copies of some rentable and store the transaction into the
     * customer's history
     * 
     * Update what the customer currenlty has on hand
     */
    bool returnRentable(int count, Rentable& rentable);

    /*
     * Display the customer's history for everything they've rented and
     * returned, starting with latest first. 
     *
     * This will output the information to std::cout by default.
     */
    void displayHistory() const;

	/*
	* Overloaded operator to check if it is the same customer
	*/
	bool operator==(const Customer& rhs) const;

    bool operator!=(const Customer& rhs) const;

private:

    /*
	* Construct a new Customer.
    *
    * This is a blank customer with no id or name.
    *
    * This constructor is private so that it cannot be accessed through 
    * normal means.
	*/
    Customer();

    int customerID;

    std::string firstName;
    std::string lastName;

    std::vector<RentalDetails> currentlyRenting; // on hand only

    std::vector<RentalDetails> customerHistory; // entire customer history
};

#endif //CUSTOMER_H
