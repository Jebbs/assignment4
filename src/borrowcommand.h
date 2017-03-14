/*******************************************************************************
 * BorrowCommand
 * 
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * BorrowCommand is a subclass of Command.
 * BorrowCommand reduces stock of a Rentable by 1 (if there's enough of stock).
 * BorrowCommand is added to Customer's history.
 *
 * Note: if there are not enough Rentables in stock, error
 * message is sent to std::cerr
 ******************************************************************************/

#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "command.h"
#include "rentable.h"
#include "customer.h"
#include <string>

class BorrowCommand : public Command
{
public:

    /*
     * Creates a new instance of BorrowCommand.
     * Empty BorrowCommand cannot be created.
     */
	BorrowCommand(int customerID, char type, char subtype, std::string data);
	~BorrowCommand();

    /*
     * Processes the BorrowCommand: reduces stock of a Rentable by 1,
	 * adds to Customer's history.
	 *
	 * If cannot be processed, is printed to std::cerr.
     */
	bool processCommand();

private:
	BorrowCommand();
	Rentable* searchRentable;
	Customer searchCustomer;
};

#endif //BORROWCOMMAND_H