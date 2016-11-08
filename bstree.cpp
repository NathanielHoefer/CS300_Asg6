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
#include <iostream>
#include <fstream>

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
		mRoot = new Node(info, NULL);
		mCount++;
	}
	else
	{
		addNode(info, mRoot, mRoot);
	}

}


//	Deletes all of the nodes within the tree
//		Precodition: None
//		Postcodition: Tree is empty
Node* BSTree::addNode(ContactInfo info, Node* root, Node* parent)
{
	if ( isEmpty(root) )
	{
		mCount++;
		return new Node(info, parent);
	}
	else if ( info.mPhone < root->getInfo().mPhone )
	{
		root->setLeftTree(addNode(info, root->getLeftTree(), root));
	}
	else
	{
		root->setRightTree(addNode(info, root->getRightTree(), root));
	}
	return root;
}


/*****************************************************************************/


//	Deletes the selected node based on the phone if it exists
//		Precondition: None
//		Postcondition: If phone found, node is removed from tree and child node
//			is inserted into the location there are children
//		Return: True if phone found and deleted
	bool BSTree::remove(int phone)
	{
		return deleteNode(phone, mRoot);
	}


/*****************************************************************************/


//	Finds the root with the matching phone number and deletes it
//		Precodition: None
//		Postcodition: Found node is deleted
//		Return: True if node is deleted
bool BSTree::deleteNode(int phone, Node* root)
{
	if ( isEmpty(root) )
	{
		return false;
	}
	else if ( phone < root->getInfo().mPhone )
	{
		return deleteNode( phone, root->getLeftTree() );
	}
	else if ( phone > root->getInfo().mPhone )
	{
		return deleteNode( phone, root->getRightTree() );
	}
	else
	{
		Node* parent = root->getParent();
		Node* ptr;

		// Root only has right child
		if ( root->getLeftTree() == NULL )
		{

			// Checks to see if root is top most root
			if ( root == mRoot )
			{

				// Root is only node left to be deleted
				if (root->getRightTree() == NULL)
				{
					cout << root->getInfo().mName << " deleted\n" << endl;
					delete root;
					mRoot = NULL;
				}
				else
				{
					// grabs node with largest value
					ptr = minInfo(mRoot->getRightTree());

					// Sets the parent's pointer to NULL
					if (ptr->getParent()->getLeftTree() == ptr )
						ptr->getParent()->setLeftTree(NULL);
					// Only one node left from root
					else if (ptr == maxInfo(ptr->getParent()))
						mRoot->setRightTree(NULL);
					else
						ptr->getParent()->setRightTree(ptr->getRightTree());

					// Updates the root info to max info
					mRoot->setInfo(ptr->getInfo());

					cout << root->getInfo().mName << " deleted\n" << endl;
					// Deletes max node since that info replaced the root
					delete ptr;
				}

			}
			// If the root is the left child of the parent, update the parent's
			// left node to the left child of the root.
			else if ( parent->getLeftTree() == root )
			{
				cout << root->getInfo().mName << " deleted\n" << endl;

				parent->setLeftTree(root->getRightTree());

				if ( root->getRightTree() != NULL )
					root->getRightTree()->setParent(parent);

				delete root;
			}
			// If the root is the right child of the parent, update the parent's
			// right node to the left child of the root.
			else
			{
				cout << root->getInfo().mName << " deleted\n" << endl;

				parent->setRightTree(root->getRightTree());

				if ( root->getRightTree() != NULL )
					root->getRightTree()->setParent(parent);

				delete root;
			}

		}
		// Root only has left child
		else if ( root->getRightTree() == NULL )
		{

			// Checks to see if root is top most root
			if ( root == mRoot )
			{
				cout << root->getInfo().mName << " deleted\n" << endl;

				// grabs node with largest value
				ptr = maxInfo(mRoot->getLeftTree());

				// Sets replaces the parent right node with NULL
				ptr->getParent()->setRightTree(NULL);

				// Updates the root info to max info
				mRoot->setInfo(ptr->getInfo());

				ptr->getParent()->setRightTree(NULL);

				// Deletes max node since that info replaced the root
				delete ptr;
			}
			else if ( parent->getLeftTree() == root )
			{
				cout << root->getInfo().mName << " deleted\n" << endl;

				parent->setLeftTree(root->getLeftTree());

				if ( root->getLeftTree() != NULL )
					root->getLeftTree()->setParent(parent);

				delete root;
			}

			else
			{
				cout << root->getInfo().mName << " deleted\n" << endl;

				parent->setRightTree(root->getLeftTree());

				if ( root->getLeftTree() != NULL )
					root->getLeftTree()->setParent(parent);

				delete root;
			}

		}
		// Root has two children
		// Switches max and root info and then recursively deletes the number in
		// the new location
		else
		{
			ContactInfo cTemp = root->getInfo();

			// Locates the node with the largest data value in the left subtree
			ptr = maxInfo(root->getLeftTree());

			// Transfers the data from the largest node to the current root,
			// overriding the current info
			root->setInfo(ptr->getInfo());

			ptr->setInfo(cTemp);

			deleteNode(phone, root->getLeftTree());
		}

		mCount--;
		return true;
	}
}


/*****************************************************************************/


//	Locates the contact information containing the phone number entered and
//		returns the info.
//		Precondition: None
//		Postcondition: Prints the contact info if found
void BSTree::retrieve(int phone)
{
	Node* root = findNode(phone, mRoot);
	if ( root == NULL )
	{
		cout << "Number not found" << endl << endl;
	}
	else
	{
		cout << "\nTelephone Number:" << endl;
		cout << root->getInfo().mPhone << endl;
		cout << "Name:" << endl;
		cout << root->getInfo().mName << endl;
		cout << "Address:" << endl;
		cout << root->getInfo().mAddress << endl;
		cout << "Email:" << endl;
		cout << root->getInfo().mEmail << endl << endl;
	}
}


/*****************************************************************************/


//	Locates the contact information containing the phone number entered and
//		returns the info.
//		Precondition: None
//		Postcondition: None
//		Return: Node with the contact information
Node* BSTree::findNode(int phone, Node* root)
{
	if ( root != NULL )
	{
		if ( phone < root->getInfo().mPhone )
			return findNode( phone, root->getLeftTree());
		else if ( phone > root->getInfo().mPhone )
			return findNode( phone, root->getRightTree());
	}
	return root;
}



/*****************************************************************************/


//	Prints the contact info in preorder
//		Precondition: None
//		Postcondition: Contact info is printed to console in preorder
	bool BSTree::traversePre( Node* root )
	{
		if ( !isEmpty(root) )
		{
			cout << "- Telephone Number:" << endl;
			cout << root->getInfo().mPhone << endl;
			cout << "- Name:" << endl;
			cout << root->getInfo().mName << endl;
			cout << "- Address:" << endl;
			cout << root->getInfo().mAddress << endl;
			cout << "- Email:" << endl;
			cout << root->getInfo().mEmail << endl << endl;

			if ( root->getLeftTree() != NULL )
				traversePre( root->getLeftTree() );

			if ( root->getRightTree() != NULL )
				traversePre( root->getRightTree() );

			return true;
		}
		else
			cout << "Tree is Empty." << endl << endl;
			return false;
	}


/*****************************************************************************/


//	Prints the contact info in inorder
//		Precondition: None
//		Postcondition: Contact info is printed to console in inorder
	bool BSTree::traverseIn( Node* root )
	{
		if ( !isEmpty(root) )
		{
			if ( root->getLeftTree() != NULL )
				traverseIn( root->getLeftTree() );

			cout << "- Telephone Number:" << endl;
			cout << root->getInfo().mPhone << endl;
			cout << "- Name:" << endl;
			cout << root->getInfo().mName << endl;
			cout << "- Address:" << endl;
			cout << root->getInfo().mAddress << endl;
			cout << "- Email:" << endl;
			cout << root->getInfo().mEmail << endl << endl;

			if ( root->getRightTree() != NULL )
				traverseIn( root->getRightTree() );

			return true;
		}
		else
			cout << "Tree is Empty." << endl << endl;
			return false;

	}


/*****************************************************************************/


//	Prints the contact info in postorder
//		Precondition: None
//		Postcondition: Contact info is printed to console in postorder
	bool BSTree::traversePost( Node* root )
	{
		if ( !isEmpty(root) )
		{
			if ( root->getLeftTree() != NULL )
				traversePost( root->getLeftTree() );

			if ( root->getRightTree() != NULL )
				traversePost( root->getRightTree() );

			cout << "- Telephone Number:" << endl;
			cout << root->getInfo().mPhone << endl;
			cout << "- Name:" << endl;
			cout << root->getInfo().mName << endl;
			cout << "- Address:" << endl;
			cout << root->getInfo().mAddress << endl;
			cout << "- Email:" << endl;
			cout << root->getInfo().mEmail << endl << endl;

			return true;
		}
		else
			cout << "Tree is Empty." << endl << endl;
			return false;
	}


/*****************************************************************************/


//	Saves tree to file
//		Precodition: None
//		Postcodition: Tree is saved to a file using indented notation
bool BSTree::saveTree( Node* root, int depth, ofstream& saveFile )
{
	string output = "";

	// Adds tabs based on the depth
	for ( int i = 0; i < depth; i++ )
		output += "\t";

	if ( root != NULL)
	{
		saveFile << output << root->getInfo().mPhone << endl;
		saveFile << output << root->getInfo().mName << endl;
		saveFile << output << root->getInfo().mAddress << endl;
		saveFile << output << root->getInfo().mEmail << endl;

		if ( root->getLeftTree() != NULL )
			saveTree( root->getLeftTree(), depth + 1, saveFile );

		if ( root->getRightTree() != NULL )
			saveTree( root->getRightTree(), depth + 1, saveFile );
	}


	return true;

}


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
bool BSTree::destroy( Node* root )
{
		if ( root->getLeftTree() != NULL )
			destroy(root->getLeftTree());
		if ( root->getRightTree() != NULL )
			destroy(root->getRightTree());
		mCount--;
		delete root;
		return true;
}



