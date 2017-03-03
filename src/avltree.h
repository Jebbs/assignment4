#ifndef AVLTREE_H
#define AVLTREE_H

#include "dvd.h"

/*
 * AVL Tree is a balanced binary tree storing DVD's
 * Extendability: can be templatized
 */
class AVLTree
{
public:

	/*
	 * Creates empty AVL tree with root node set to NULL
	 */
	AVLTree();
	
	~AVLTree();

	/*
	 * Inserts a DVD into tree, returns true if succeeded
	 */
	bool insert(DVD &dvd);

	/*
	 * Retrieves a DVD from tree, points to it
	 */
	bool retrieve(const DVD &dvd, DVD* &retDVD);

	/*
	 * Removes a DVD from the tree
	 */
	bool removeDVD(DVD &dvd);					
	
	/*
	 * Returns true if no items are in the tree
	 */
	bool isEmpty();								
	
	/*
	 * Prints out the tree in order
	 */
	void printTree();							
		
private:
	struct Node
	{
		DVD *dvd;
		Node *right;
		Node *left;
	};

	Node *root;
	
	//Returns height of the tree
	int getHeight();			

	//Balances the tree {
	//compare node heights
	//if subtrees of any node differ in height more than 1 level
	//find the lowest unbalanced node
	//rotate node
	//}
	void balanceTree();			

	//Helper function to balance tree
	void rotateLeft(Node *n);	

	//Helper function to balance tree
	void rotateRight(Node *n);	

	//Empties out the tree, deletes all data
	void makeEmpty();
};


#endif //AVLTREE_H