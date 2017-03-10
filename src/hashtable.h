#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"
#include <string>

/*
 * HashTable class implements Hash Table, based on
 * double hashing. Customers are placed in unique
 * buckets based on their ID's. In case of collision,
 * second hash function is applied.
 *
 * Assumption: start with 1000 customers, thus minimum table
 * size is defined as 2003.
 *
 * Extendability: can be templatized to store other items.
 */
#define MIN_TABLE_SIZE 2003

class HashTable
{
public:
	/*
     * Creates an empty hash table.
    */
	HashTable();
	~HashTable();

	/*
     * Inserts a customer into table, returns true if succeeded.
     * {
	 *   if (customers[hash1]==NULL)
     *       {customer[hash1]==cust;}
     *   else
     *       {probe the table with hash2 function}
     * }
    */
	bool insert(Customer* cust);

    /*
     * Retrieves a customer from table, points to it.
     */
    bool retrieve(const Customer& cust, Customer*& retC);

    /*
     * Removes a customer from the table
     */
	bool removeCustomer(Customer& cust);

    /*
	 * Resizes the table.
     * Requires additional helper functions: findPrime(), reinsertCustomer().
     */
    void resize(int newSize);

private:
	struct Node
	{
		Customer *customer;
		bool isFilled;
	};

    //Array of pointers to customers.
	Node* customers[MIN_TABLE_SIZE];

	//Returns h for a customer: customerId % MIN_TABLE_SIZE
	int hash1(const Customer *cust);

	//Function for double hashing.
	int hash2(const Customer *cust);

	//Empties out the hash table
	void makeEmpty();
};

#endif //HASHTABLE_H
