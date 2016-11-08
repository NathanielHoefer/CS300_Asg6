/*****************************************************************************/
/* Program 5 - Decimal to Binary Converter									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #5


Description of the Problem:
	<Desc>

Functions:
    + main() - Begins the application loop
    	> Create empty tree
    	> Begin loop and print menu options
    	> 1. Add Contact Information
    	> 2. Delete a Telephone Number
    	> 3. Locate a Telephone Number
    	> 4. Traverse List: In-order
    	> 5. Traverse List: Pre-order
    	> 6. Traverse List: Post-order
    	> 7. Quit
    	> When quit option is selected, Save the tree to an indented format.
 */

#include "bstree.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{


	bool isFinished = false;
	int selection = 0;

	BSTree tree;

	// Test Info
	ContactInfo c1 = {99, "one", "116 St", "1@hotmail.com"};
	ContactInfo c2 = {88, "two", "Car St", "2@hotmail.com"};
	ContactInfo c3 = {448, "three", "fish St", "3@hotmail.com"};
	ContactInfo c4 = {64, "three", "fish St", "3@hotmail.com"};
	ContactInfo c5 = {89, "three", "fish St", "3@hotmail.com"};
	ContactInfo c6 = {623, "three", "fish St", "3@hotmail.com"};
	ContactInfo c7 = {103, "three", "fish St", "3@hotmail.com"};

	tree.insert(c1);
	tree.insert(c2);
	tree.insert(c3);
	tree.insert(c4);
	tree.insert(c5);
	tree.insert(c6);
	tree.insert(c7);
//
//	cout << "\nCount: " << tree.getCount() << endl;
//
//
//
//	cout << "\n" << tree.remove(448) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(64) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(89) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(88) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(99) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(448) << endl; // Works correctly
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(623) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//
//
//	cout << "\nCount: " << tree.getCount() << endl;
//
//	tree.destroy( tree.getRoot() );




	while (!isFinished)
	{

		cout << "Binary Search Tree Application - Program 6" << endl;
		cout << "Please make a selection" << endl << endl;

		cout << "1. Add Contact Information" << endl;
		cout << "2. Delete a Telephone Number" << endl;
		cout << "3. Locate a Telephone Number" << endl;
		cout << "4. Traverse List: In-order" << endl;
		cout << "5. Traverse List: Pre-order" << endl;
		cout << "6. Traverse List: Post-order" << endl;
		cout << "7. Quit" << endl;


		cin >> selection;

		if ( selection > 0 && selection <= 7)
		{
			switch (selection) {
				// Add contact
				case 1:
				{
					ContactInfo info;

					cout << "Enter Phone Number: " << endl;
					cin >> info.mPhone;
					cout << "Enter Name: " << endl;
					cin >> info.mName;
					cout << "Enter Address: " << endl;
					cin >> info.mAddress;
					cout << "Ender Email: " << endl;
					cin >> info.mEmail;

					tree.insert(info);

					break;
				}

				// Delete contact
				case 2:
				{
					int phone;

					cout << "Enter phone number to delete: ";
					cin >> phone;
					tree.remove(phone);
					break;
				}

				// Locate contact
				case 3:
				{
					int phone;

					cout << "Enter phone number: ";
					cin >> phone;
					tree.retrieve(phone);
					break;
				}

				// Traverse in-order
				case 4:
				{
					cout << "\nIn-order Traversal:\n" << endl;
					tree.traverseIn( tree.getRoot() );
					cout << endl;
					break;
				}

				// Traverse pre-order
				case 5:
				{
					cout << "\nPre-order Traversal:\n" << endl;
					tree.traversePre( tree.getRoot() );
					cout << endl << endl;
					break;
				}

				// Traverse post-order
				case 6:
				{
					cout << "\nPost-order Traversal:\n" << endl;
					tree.traversePost( tree.getRoot() );
					cout << endl;
					break;
				}

				// Quit and save
				case 7:
				{
					cout << "Exiting Program." << endl;
					isFinished = true;
					break;
				}
			}
		}
		else
		{
			cout << "Invalid response" << endl;
		}

	}

	string fileName = "tree.dat";

	// Opens Text file and saves each part until inventory is complete.
	ofstream saveFile(fileName.c_str());
	if (saveFile.is_open())
	{
		tree.saveTree(tree.getRoot(), 0, saveFile);
	}
	saveFile.close();


	if (!tree.isEmpty(tree.getRoot()))
	{
		tree.destroy( tree.getRoot() );
	}

	cout << "\nFile Saved" << endl;

	return 0;


}






