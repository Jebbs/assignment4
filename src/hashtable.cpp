#include "hashTable.h"

	HashTable();
	~HashTable();

	bool HashTable::insert(Customer* cust)
	{
		int i = 0;
		bool collision = false;

		do
		{
			int index = (hash1(cust) + i * hash2(cust)) % MIN_TABLE_SIZE;
			
			if (customers[index] == NULL)
			{
				customers[index] = new Node{cust, true};
				return true;
			}
			else if (!customers[index].filled)
			{
				customers[index]->cust = cust;
				customers[index].filled = true;
				return true;
			}
			else 
			{
				collision = true;
				i++;
			}

		} while (collision);
		
		return false;
	}

    /*
     * Retrieves a customer from table, points to it.
     */
	bool retrieve(const Customer& cust, Customer*& retC)
	{
		int i = 0;
		bool found = false;

		do
		{
			int index = (hash1(cust) + i * hash2(cust)) % MIN_TABLE_SIZE;

			if (customers[index] == NULL)
			{
				return false;
			}
			else if (!customers[index].filled || customers[index] != cust)
			{
				i++;

				// if we were to delete, but not remove. Not in the scope of this assignment.
				continue;
			}
			else
			{
				retC = customers[index]->cust; 
				return true;
			}

		} while (!found);

		return false;
	}

    /*
     * Removes a customer from the table
     */
	bool removeCustomer(Customer& cust)
	{
		// we would do a lazy delete; however, not required for assignment. 
	}

    /*
	 * Resizes the table.
     * Requires additional helper functions: findPrime(), reinsertCustomer().
     */
	void resize(int newSize)
	{
		// not implemented in this assignment, but may be necessary in case of increased customers
	}

	//Returns h for a customer: customerId % MIN_TABLE_SIZE
	int hash1(const Customer *cust)
	{
		return cust->getCustomerID() % MIN_TABLE_SIZE;
	}

	//Function for double hashing.
	int hash2(const Customer *cust)
	{
		return (7 - (cust->getCustomerID() % 7));
	}

	//Empties out the hash table
	void makeEmpty();
};

#endif //HASHTABLE_H
