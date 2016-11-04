/*****************************************************************************/
/* Program 6 - Binary Search Tree											 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #6



Struct Name: ContactInfo
	Contains phone number, name, email and complete address

Data:
	+ int mPhone
	+ string mName
	+ string mAddress
	+ string mEmail



Class Name: BSTree
	A binary search tree that operates with nodes containing ContactInfo struct
	which hold a phone number, name, address, and email.

Data:
	- Node* mRoot: The very first entry of the binary search tree
	- int mCount: The number of elements within the tree

Constructors:
	+ BSTree(): Initializes an empty binary search tree.

Accessor and Mutator Functions:
	+ getCount

Functions:
	+ insert(ContactInfo info): Inserts a node with the contact information into
		the correct location within the BST
		Preconditions: None
		Postconditions: Node with contact info is correctly located in tree
		> If the tree is empty, update root to new node
		> If the phone number is less than the root, recursively check the left
			node.
		> Otherwise, recursively check the right node.

	+ deleteNode(int phone): Deletes the selected node based on the phone if it
		exists
		Precondition: None
		Postcondition: If phone found, node is removed from tree and child node
			is inserted into the location there are childred
		Return: True if phone found and deleted
		> <Steps>

	+ retrieve(int phone): Locates the contact information containing the phone
		number entered and returns the info.
		Precondition: None
		Postcondition: None
		Return: Contact info with the phone number
		> <Steps>

	+ traversePre(): Prints the contact info in preorder
		Precondition: None
		Postcondition: Contact info is printed to console in preorder
		> <Steps>

	+ traverseIn(): Prints the contact info in inorder
		Precondition: None
		Postcondition: Contact info is printed to console in inorder
		> <Steps>

	+ traversePost(): Prints the contact info in postorder
		Precondition: None
		Postcondition: Contact info is printed to console in postorder
		> <Steps>

	+ isEmpty(): Determines if tree is empty
		Precodition: None
		Postcondition: None
		Return: True if tree empty, false if contains a node
		> <Steps>

	+ destroy(): Deletes all of the nodes within the tree
		Precodition: None
		Postcodition: Tree is empty
		> <Steps>


 */

#ifndef BSTREE_HPP_
#define BSTREE_HPP_

#include "node.hpp"
#include <string>

using namespace std;



/*****************************************************************************/
// Class Protocol Functions and Variables
/*****************************************************************************/


class BSTree
{

private:

// MEMBER VARIABLES ************************************************************

	// The very first entry of the binary search tree
	Node* mRoot;

	// The number of elements within the tree
	int mCount;


public:

// CONSTRUCTORS ***************************************************************

	BSTree();


// Accessors and Mutators

	Node* getRoot() { return mRoot; };

	int getCount() { return mCount; };

	void setRoot(Node* root) { mRoot = root; };

	void setCount(int count) { mCount = count; };


// METHODS ********************************************************************

//	Inserts a node with the contact information int the correct location within
//		the BST
//		Preconditions: None
//		Postconditions: Node with contact info is correctly located in tree
	void insert(ContactInfo info);


/*****************************************************************************/


//	Deletes the selected node based on the phone if it exists
//		Precondition: None
//		Postcondition: If phone found, node is removed from tree and child node
//			is inserted into the location there are children
//		Return: True if phone found and deleted
	bool remove(int phone);


/*****************************************************************************/


//	Locates the contact information containing the phone number entered and
//		returns the info.
//		Precondition: None
//		Postcondition: None
//		Return: Contact info with the phone number
	ContactInfo retrieve(int phone);


/*****************************************************************************/


//	Prints the contact info in preorder
//		Precondition: None
//		Postcondition: Contact info is printed to console in preorder
	void traversePre();


/*****************************************************************************/


//	Prints the contact info in inorder
//		Precondition: None
//		Postcondition: Contact info is printed to console in inorder
	void traverseIn();


/*****************************************************************************/


//	Prints the contact info in postorder
//		Precondition: None
//		Postcondition: Contact info is printed to console in postorder
	void traversePost();


/*****************************************************************************/


//	Determines if tree is empty
//		Precodition: None
//		Postcondition: None
//		Return: True if tree empty, false if contains a node
	bool isEmpty(Node* root);


/*****************************************************************************/


//	Deletes all of the nodes within the tree
//		Precodition: None
//		Postcodition: Tree is empty
	void destroy();


/*****************************************************************************/


//	Returns the max value
//		Precodition: None
//		Postcodition: None
//		Return: Contact information with the greatest number
	Node* maxInfo(Node* root)
	{
		if ( root->getRightTree() == NULL )
			return root;
		else
			return maxInfo( root->getRightTree() );
	}


/*****************************************************************************/


//	Returns the min value
//		Precodition: None
//		Postcodition: None
//		Return: Contact information with the smallest number
	Node* minInfo(Node* root)
	{
		if ( root->getLeftTree() == NULL )
			return root;
		else
			return minInfo( root->getLeftTree() );
	}


/*****************************************************************************/


private:


//	Adds the info beginning with a root node
//		Precodition: None
//		Postcodition: Node is added
	Node* addNode(ContactInfo info, Node* root, Node* parent);


/*****************************************************************************/


//	Finds the root with the matching phone number and deletes it
//		Precodition: None
//		Postcodition: Found node is deleted
//		Return: True if node is deleted
	bool deleteNode(int phone, Node* root);

};


#endif /* BSTREE_HPP_ */
