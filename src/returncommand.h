/*******************************************************************************
 * ReturnCommand
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * ReturnCommand is a subclass of Command.
 * ReturnCommand increases stock of a Rentable by 1 (if there's enough of stock).
 * ReturnCommand is added to Customer's history.
 *
 * Note: if the customer has not rented the rentable, an error
 * message is sent to std::cerr
 ******************************************************************************/
#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "command.h"
#include "rentable.h"
#include "customer.h"

/*
 * ReturnCommand is a subclass of Command.
 * ReturnCommand adds 1 to Rentable's stock if:
 * a) customer ID is valid
 * b) such a Rentable exists
 * c) customer has borrowed the Rentable.
 * If any of forementioned aren't met,
 * error is printed to std::cerr.
 *
 * Successful ReturnCommand is added to Customer's history.
 */

class ReturnCommand : public Command
{
public:
	ReturnCommand(int customerID, char type, char subtype, std::string data);
	~ReturnCommand();

	/*
     * Returns true if Command is valid and can be processed.
     * Else prints error message to std::cerr.
     */
	bool processCommand();

private:
	ReturnCommand();
	Rentable* searchRentable;
	Customer searchCustomer;
};

#endif //RETURNCOMMAND_H