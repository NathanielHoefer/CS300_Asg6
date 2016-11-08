/*****************************************************************************/
/* Program 6 - Binary Search Tree											 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #5



Class Name: Node
	Contains the data for a binary search tree, which in this case is a struct
	with the phone number, name, email, and complete address

Data:
	- ContactInfo mInfo: Contains all of the contact information within
		a structure
	- Node* mLeftTree: Pointer to left tree
	- Node* mRightTree: Pointer to the right tree
	- Node* mParent: Contains the pointer to the parent.

Constructors:
	+ Node() - Creates a node with default data
	+ Node(ContactInfo info) - Creates a node with the contact info supplied

Accessor and Mutator Functions:
	+ getInfo()
	+ getLeftTree()
	+ getRightTree()
	+ setInfo(ContactInfo info)
	+ setLeftTree(Node* ptr)
	+ setRightTree(Node* ptr)


 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>


using namespace std;



/*****************************************************************************/
// Class Protocol Functions and Variables
/*****************************************************************************/


struct ContactInfo
{
	int mPhone;
	string mName;
	string mAddress;
	string mEmail;
};


/*****************************************************************************/
// Class Protocol Functions and Variables
/*****************************************************************************/


class Node
{

private:

// MEMBER VARIABLES ************************************************************

	// Contains all of the contact information within a structure
	ContactInfo mInfo;

	// Pointer to parent
	Node* mParent;

	// Pointer to left tree
	Node* mLeftTree;

	// Pointer to the right tree
	Node* mRightTree;




public:

// CONSTRUCTORS ***************************************************************

	// Creates a node with default data
	Node();

	// Creates a node with the contact info supplied
	Node(ContactInfo info, Node* parent);


// Accessors and Mutators

	ContactInfo getInfo() { return mInfo; };

	Node* getParent() { return mParent; };

	Node* getLeftTree() { return mLeftTree; };

	Node* getRightTree() { return mRightTree; };

	void setInfo(ContactInfo info) { mInfo = info; };

	void setParent(Node* ptr) { mParent = ptr; };

	void setLeftTree(Node* ptr) { mLeftTree = ptr; };

	void setRightTree(Node* ptr) { mRightTree = ptr; };

};


#endif /* NODE_HPP_ */
