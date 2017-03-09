#include "customer.h"

Customer::Customer(int id, std::string lastName, std::string firstName)
{
	this->id = id;
	this->lastName = lastName;
	this->firstName = firstName;
}

int Customer::getCustomerID() const
{
	return customerID;
}

void Customer::setCustomerID(int newID)
{
	customerID = newID;
}

std::string Customer::getCustomerFirstName() const
{
	return firstName;
}

void Customer::setCustomerFirstName(std::string newFirstName)
{
	firstName = newFirstName;
}

std::string Customer::getCustomerLastName() const
{
	return lastName;
}

void Customer::setCustomerLastName(std::string newLastName)
{
	lastName = newLastName;
}

void Customer::displayHistory(std::ostream & outStream) const
{
	for (int i = 0; i < customerHistory.size(); i++)
	{
		cout << customerHistory[i];
	}
}

bool Customer::operator==(const Customer& rhs) const  // do we need these? 
{
	return customerId == rhs.getCustomerID();
}

bool Customer::operator!=(const Customer& rhs) const  // do we need these? 
{
	return customerId != rhs.getCustomerID();
}

bool Customer::borrowRentable(int borrowCount, Rentable& rentable)
{
	//RentalDetails transaction = new RentalDetails();
	// or 
	RentalDetails transaction;

	transaction.count += borrowCount;
	transaction.rental = rentable;
	transaction.returned = false;
	transaction.action = "Borrow";

	customerHistory.push_back(transaction);
	customerHistory;

	// to set return date - NOT fully implemented, since out of the scope for this assignment.
	int type = rentable.getType();
	switch (type)
	{
	case 0: 
		//rental is a DVD
		currentlyRenting[i].setRentalPeriodInDayse = DVD_RENTAL_PERIOD;
		break;
	case 1:
		// this (and any other case) is for future implementation of other rentable types.
		break;
	}
}

bool Customer::returnRentable(int returnCount, Rentable& rentable)
{
	for (int i = 0; i < currentlyRenting.size; i++)
	{
		if (currentlyRenting[i] == rentable && currentlyRenting[i].count >= returnCount)
		{
			RentalDetails transaction = currentlyRenting[i];
			transaction.count -= returnCount;
			transaction.returned = true;
			transaction.action = "Return";

			addToCustomerHistory(transaction);

			//update to reflect return 
			currentlyRenting[i].count -= returnCount;
			currentlyRenting[i].returned = true;
			currentlyRenting[i].action = "Return";
			
			customerHistory.push_back(transaction);
			customerHistory;
			break;
		}
		else
		{
			cerr << "INVALID RETURN REQUEST" << enld;
		}
	}
}

void Customer::displayHistory() const
{
	cout << "Transaction History for: " << getCustomerLastName(); << ", " << setCustomerFirstName();
	cout << "  Customer ID: "<< customerID << endl;
	
	//RentalDetails transaction = new RentalDetails();
	// or 
	RentalDetails transaction;
	for (int i = customerHistory.size() - 1; i >= 0; i--)
	{
		transaction = customerHistory[i];
		cout << transaction.action << "     ";
		cout << transaction.rental.getType() << "     ";
		// cout << transaction.rental.subtypestuff
		cout << transaction.rental.getTitle() << "     ";
		//if (transaction.rental.getType() == classic)
		// {
		//     do the date thats necessary here 
		//     do the actors necessary here
		// else 
		// {
		cout << transaction.rental.getReleaseYear();
		// }
		cout << endl;
	}
}