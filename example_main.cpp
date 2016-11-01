/*****************************************************************************/
/* This is what is expected of ALL programs that you write.  Read carefully. */
/* Don't go past column 80 when editting.												  */
/*****************************************************************************
    Author: Rena Hixon
    Student ID: WSU userid                                                                                                                                          
    Program: #2

   Description of the problem:
   	This program implements the Rectangle class.  It contains the length,
       widith, area, and perimeter of a rectangle.  The length and width can be
       set.  The area and perimeter are calculated. 
*/

// This is where include fules will go.
#include "example.cpp"
#include <iostream>
using namespace std;

// Defines should come next in the file.
// ALL define values, like QUIT, should be capitalized.
#define QUIT -1

// Leave blanks between different parts of the program.
// Space does not increase the size of your program, so use it to make
// programs more readable.
int main (void)
{
     
   Example ex1(5, 7);
   
   // Leave a blank line after definitions of variables.
   // Line up comments with the code associated with it.
   
   
   // Print the area and the perimeter.
   ex1.Calc();
   cout << "\nArea is " << ex1.Get_area();
   cout << "\nPerimeter is " << ex1.Get_perimeter() << endl;
 
   // Line up the braces under the code with which they are associated.
   // DO NOT put a brace at the end of a line of code.
   // Indent consistently at 3 or 4 spaces.  
   // Inside { } always indent another 3 or 4 spaces
   // Variable for loop
   char end_loop = 'y';
   while (end_loop == 'y')
   {
       int len, wid;
         
       // Ask user for length and width
       cout << "Enter a length: ";
       cin >> len;
       ex1.Set_len(len);
       cout << "Enter a width: ";
       cin >> wid;
       ex1.Set_width(wid);
       
       // Calculate the area and perimeter
       ex1.Calc();
   
       // Display the area and perimeter
       cout << "Area is " << ex1.Get_area() 
            << "Perimeter is " << ex1.Get_perimeter();
       cout << "\nEnter another rectangle (y/n)? ";
       cin >> end_loop;
         
   }
     	
}
// DO NOT use break except in switch statements and error handling.
// DO NOT use continue statments at all.  Using break and continue statements
// are usually more confusing and code can always be written without them -
// switch statements being the exception.
