/*****************************************************************************
    Author: Rena Hixon
    Student ID: WSU userid                                                                                                                                          
    Program: #2
*/

#include "example.hpp"

// A .cpp file with the name of the class should contain all of the
// member function definitions.

// Constructor
Example::Example (int l, int w)
{
     len = l;
     width = w;
}

// Mutator Functions
void Example::Set_len (int ln)
{
     len = ln;
}

void Example::Set_width (int wid)
{
     width = wid;
}

// Calculate the area and perimeter
void Example::Calc (void)
{
     area = float (len) * width;
     perimeter = len * 2 + width * 2;
}

// Accessor Functions
float Example::Get_area (void)
{
     return area;
}

float Example::Get_perimeter(void)
{
      return perimeter;
}

