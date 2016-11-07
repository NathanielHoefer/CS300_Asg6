/*****************************************************************************/
/* Program 5 - Decimal to Binary Converter									 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #5


Description of the Problem:
	<Desc>

Functions:
    + main() - <Desc>
    	> <Steps>

 */

#include "bstree.hpp"
#include <string>
#include <iostream>

using namespace std;


int main()
{


	bool isFinished = false;
	int selection = 0;

	BSTree tree;

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
					break;
				}


				// Locate contact
				case 3:
				{
					break;
				}

				// Traverse in-order
				case 4:
				{
					break;
				}

				// Traverse pre-order
				case 5:
				{
					break;
				}

				// Traverse post-order
				case 6:
				{
					break;
				}

				// Quit and save
				case 7:
				{
					break;
				}
			}
		}
		else
		{
			cout << "Invalid response" << endl;
		}

	}



	ContactInfo c1 = {99, "one", "116 St", "1@hotmail.com"};
	ContactInfo c2 = {88, "two", "Car St", "2@hotmail.com"};
	ContactInfo c3 = {448, "three", "fish St", "3@hotmail.com"};
	ContactInfo c4 = {64, "three", "fish St", "3@hotmail.com"};
	ContactInfo c5 = {89, "three", "fish St", "3@hotmail.com"};
	ContactInfo c6 = {623, "three", "fish St", "3@hotmail.com"};

	tree.insert(c1);
	tree.insert(c2);
	tree.insert(c3);
	tree.insert(c4);
	tree.insert(c5);
	tree.insert(c6);

	cout << "***In order***" << endl;
	tree.traverseIn( tree.getRoot() );

//	cout << "\n***Post order***" << endl;
//	tree.traversePost( tree.getRoot() );
//
//	cout << "\n***Pre order***"<< endl;
//	tree.traversePre( tree.getRoot() );

	cout << "\n" << tree.remove(448) << endl; // Works correctly
	tree.traverseIn( tree.getRoot() );

	cout << "\n" << tree.remove(99) << endl;
	tree.traverseIn( tree.getRoot() );

	cout << "\n" << tree.remove(16) << endl;
	tree.traverseIn( tree.getRoot() );

	cout << "\n" << tree.remove(64) << endl;
	tree.traverseIn( tree.getRoot() );

	cout << "\n" << tree.remove(623) << endl;
	tree.traverseIn( tree.getRoot() );

	cout << "\n" << tree.remove(89) << endl;
	tree.traverseIn( tree.getRoot() );

	cout << "\n" << tree.remove(88) << endl;
	tree.traverseIn( tree.getRoot() );

	cout << "" << endl;

	return 0;
}






