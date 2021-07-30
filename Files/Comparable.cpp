//---------------------------------------------------------------------------
// Comparable.cpp
// Author: Mehakpreet Kambo	
// Class Implementation
//---------------------------------------------------------------------------
// Comparable class:	Takes in a char from istream and stores in a
//						comparable object. Additional functinality:	
//   --	allows for different comparisons of binary objects
//   --	allows for printing of binary object member variable
//   --	allows user input of char into comparable object 
//
// Assumptions:
//   --	uses compiler version of default constructor
//   -- Only char is inputted by the user
//----------------------------------------------------------------------------

#include "Comparable.h"

//-----------------------------  constructor  -----------------------------------------
//	Default constructor 
//	Preconditions:	None
//	Postconditions:	Comparable object is created
Comparable::Comparable() { }

//-----------------------------  destructor  -----------------------------------------
//	Destructor 
//	Preconditions:	Comparable has previously been instantiated
//	Postconditions:	Comparable is destroyed
Comparable::~Comparable() { }

//-----------------------------  ==  -----------------------------------------
//	Operator overloaded ==
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	Returns true if the private member "data" is of the same
//					value for both comparable objects, false otherwise
bool Comparable::operator==(const Comparable& comparable) const 
{
	return (data == comparable.data);
}

//-----------------------------  !=  -----------------------------------------
//	Operator overloaded !=
//	Preconditions:  this and comparable both point to comparable objects
//	Postconditions: Returns false if the private member "data" is of the same
//					value for both comparable objects, true otherwise
bool Comparable::operator!=(const Comparable& comparable) const 
{
	return (data != comparable.data);
}

//--------------------------------  <  ----------------------------------------------
//	Operator overloaded <
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	Returns trueif this is less than comparable, false otherwise
bool Comparable::operator<(const Comparable& comparable) const 
{
	return (data < comparable.data);
}

//-------------------------------  >  -----------------------------------------------
//	Operator overloaded >
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	Returns true if the private member "data" of this is
//					is greater than that of Comparable, false otherwise 
bool Comparable::operator>(const Comparable& comparable) const 
{
	return (data > comparable.data);
}

//-----------------------------  <<  -----------------------------------------
//	Overloaded output operator 
//	Preconditions:	Comparable object has been instantiated.
//	Postconditions:	Private member "data" is sent to ostream
ostream& operator<<(ostream& output, const Comparable& comparable) 
{
	output << comparable.data;
	return output;
}

//-----------------------------  >>  -----------------------------------------
//	Overloaded input operator 
//	Preconditions:	comparable.data is ready for a char
//	Postconditions:	The value of the char passed into the istream is stored in
//					private member variable "data"
istream& operator>>(istream& input, Comparable& comparable) 
{
	input >> comparable.data;
	return input;
}
