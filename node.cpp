/*****************************************************************************/
/* Program 6 - Binary Search Tree											 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #6

*/

#include "node.hpp"
#include <string>

using namespace std;



/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


	// Creates a node with default data
	Node::Node()
	{
		ContactInfo info;
		info.mPhone = 0;
		info.mName = "default name";
		info.mAddress = "default address";
		info.mEmail = "default email";

		mInfo = info;
		mParent = NULL;
		mLeftTree = NULL;
		mRightTree = NULL;
	}


/*****************************************************************************/


	// Creates a node with the contact info supplied
	Node::Node(ContactInfo info, Node* parent)
	{
		mInfo = info;
		mParent = parent;
		mLeftTree = NULL;
		mRightTree = NULL;
	}



