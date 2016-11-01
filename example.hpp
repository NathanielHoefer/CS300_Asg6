/*****************************************************************************
    Author: Rena Hixon
    Student ID: WSU userid                                                                                                                                          
    Program: #2

   Description of the problem:
   	This program implements the Rectangle class.  It contains the length,
       widith, area, and perimeter of a rectangle.  The length and width can be
       set.  The area and perimeter are calculated. 

   Psuedo Code
    Class Name: Rectangle
    Data:       len - holds the length of a side
                width - holds the width of a side
                area - contains the area
                perimeter - contains the perimeter
    Mutator Functions:
                Set_len - Sets the length
                Set_width - Sets the width
    Accessor Functions:
                Get_area - Returns area
                Get_perimeter - Returns perimeter
    Functions:
                Calc - Calculates the area and perimeter using the class
                    members len and width.  Note: This function must be called from 
                    outside the class.
                Input Parms: None
                Output Parms: None
                
                area = len * width
                perimeter = 2 * len + 2 * width
*/

// Each main class should be defined in a header with its name
// Class names should be capitalized.  Structures should not be
// capitalized.

class Example
{
      // Use descriptive names in the program.  Points WILL BE deducted
      // if descriptive names are not used.  Documenting the names is NOT
      // sufficient. Descriptive abbreviations are acceptable.
      int len, width;
      float area, perimeter;
      
 public:
        // Constructor
        Example (int l, int w);
        
        // Mutator Functions
        void Set_len (int ln);
        void Set_width (int wid);
        
        // Calculates area and perimeter
        void Calc (void);
        
        // Accessor Functions
        float Get_area (void);
        float Get_perimeter (void);
};
