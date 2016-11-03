/*****************************************************************************/
/* Program 6 - Binary Search Tree											 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #6

*/

#include "node.hpp"
#include "bstree.hpp"
#include <string>

using namespace std;



/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


BSTree::BSTree()
{
	mRoot = NULL;
	mCount = 0;
}


// METHODS ********************************************************************


//	Inserts a node with the contact information int the correct location within
//		the BST
//		Preconditions: None
//		Postconditions: Node with contact info is correctly located in tree
void BSTree::insert(ContactInfo info)
{

	if ( isEmpty(mRoot) )
	{
		mRoot = new Node(info);
	}
	else
	{
		addNode(info, mRoot);
	}


}


//	Deletes all of the nodes within the tree
//		Precodition: None
//		Postcodition: Tree is empty
Node* BSTree::addNode(ContactInfo info, Node* root)
{
	if ( isEmpty(root) )
	{
		return new Node(info);
	}
	else if ( info.mPhone < root->getInfo().mPhone )
	{
		root->setLeftTree(addNode(info, root->getLeftTree()));
	}
	else
	{
		root->setRightTree(addNode(info, root->getRightTree()));
	}

	return root;
}


/*****************************************************************************/


//	Deletes the selected node based on the phone if it exists
//		Precondition: None
//		Postcondition: If phone found, node is removed from tree and child node
//			is inserted into the location there are children
//		Return: True if phone found and deleted
	bool deleteNode(int phone);


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
bool BSTree::isEmpty(Node* root)
{
	if ( root == NULL )
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*****************************************************************************/


//	Deletes all of the nodes within the tree
//		Precodition: None
//		Postcodition: Tree is empty
	void destroy();


