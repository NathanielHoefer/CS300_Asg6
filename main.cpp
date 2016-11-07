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




	BSTree tree;

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

	tree.retrieve(448);
	tree.retrieve(64);
	tree.retrieve(99);
	tree.retrieve(449);

	tree.destroy( tree.getRoot() );

	cout << "***In order***" << endl;
	tree.traverseIn( tree.getRoot() );



//	cout << "\n***Post order***" << endl;
//	tree.traversePost( tree.getRoot() );
//
//	cout << "\n***Pre order***"<< endl;
//	tree.traversePre( tree.getRoot() );

//	cout << "\n" << tree.remove(448) << endl; // Works correctly
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(99) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(16) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(64) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(623) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(89) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "\n" << tree.remove(88) << endl;
//	tree.traverseIn( tree.getRoot() );
//
//	cout << "" << endl;

	return 0;
}






