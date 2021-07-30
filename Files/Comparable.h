//---------------------------------------------------------------------------
// Comparable.h
// Author: Mehakpreet Kambo	
// Class declarations
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

#pragma once
#include <iostream>

using namespace std;

class Comparable {
	
	//-----------------------------  <<  -----------------------------------------
	//	Overloaded output operator 
	//	Preconditions:	Comparable object has been instantiated.
	//	Postconditions:	Private member "data" is sent to ostream
	friend ostream& operator <<(ostream& output, const Comparable& comparable);

	//-----------------------------  >>  -----------------------------------------
	//	Overloaded input operator 
	//	Preconditions:	comparable.data is ready for a char
	//	Postconditions:	The value of the char passed into the istream is stored in
	//					private member variable "data"
	friend istream& operator >>(istream& input, Comparable& comparable);

public:

	//-----------------------------  constructor  -----------------------------------------
	//	Default constructor 
	//	Preconditions:	None
	//	Postconditions:	Comparable object is created
	Comparable();

	//-----------------------------  destructor  -----------------------------------------
	//	Destructor 
	//	Preconditions:	Comparable has previously been instantiated
	//	Postconditions:	Comparable is deleted
	virtual ~Comparable();

	//-----------------------------  ==  -----------------------------------------
	//	Operator overloaded ==
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	Returns true if the private member "data" is of the same
	//					value for both comparable objects, false otherwise
	virtual bool operator==(const Comparable& comparable) const = 0;

	//-----------------------------  !=  -----------------------------------------
	//	Operator overloaded !=
	//	Preconditions:  this and comparable both point to comparable objects
	//	Postconditions: Returns false if the private member "data" is of the same
	//					value for both comparable objects, true otherwise
	virtual bool operator!=(const Comparable& comparable) const = 0;

	//--------------------------------  <  ----------------------------------------------
	//	Operator overloaded <
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	Returns true if this is less than comparable, false otherwise
	virtual bool operator<(const Comparable& comparable) const = 0;

	//-------------------------------  >  -----------------------------------------------
	//	Operator overloaded >
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	Returns true if the private member "data" of this is
	//					is greater than that of Comparable, false otherwise 
	virtual bool operator>(const Comparable& comparable) const = 0;

	//----------------------------  create  --------------------------------------
	//	Create, pure virtual function that allows to create derived class objects
	//	Preconditions:	ComparableFactory class object is instantiated and a hash
	//					table with indexes to create derived class objects is present
	//	Postconditions:	Comparable and derived objects are created
	virtual Comparable* create() = 0;

	//-------------------------  setInformation  -------------------------------------
	//	A pure virtual function to set the derived object information.
	//	Preconditions:	an istream is being passed in as a parameter
	//	Postconditions:	members in a derived class object are changed and their information
	//					is set
	virtual void setInformation(istream& input) = 0;

	//-----------------------  setTransactionInformation  -------------------------------
	//	A pure virtual function to set the transaction information
	//	Preconditions:	an istream is being passed in as a parameter
	//	Postconditions:	members in a derived class object are changed and their transaction 
	//					information is set
	virtual void setTransactionInformation(istream& input) = 0;

	//------------------------  displayInformation  ----------------------------------------
	//	A pure virtual function to display the information
	//	Preconditions:	Derived class object implements their own version of displayInformation
	//	Postconditions:	All the information from the calling object is displayed
	virtual void displayInformation() const = 0;

	//---------------------------  getQuantity  -------------------------------------------
	//	A pure virtual function that returns the quantity of items in a derived class
	//	Preconditions:	Quantity has been defined
	//	Postconditions:	Int value of quantity is returned
	virtual int getQuantity() = 0;

	//--------------------------  increaseQuantity  -----------------------------------------
	//	A pure virtual function that increases quantity of items
	//	Preconditions:	Quantity has been defined
	//	Postconditions:	Returns true if quantity is increased by 1, false otherwise 
	virtual bool increaseQuantity() = 0;

	//--------------------------  decreaseQuantity  ------------------------------------------
	//	A pure virtual function that decreases quantity of items
	//	Preconditions:	Quantity has been defined. 
	//	Postconditions:	Returns true if quantity is decreased by 1, false otherwise
	virtual bool decreaseQuantity() = 0;

	//------------------------  displayForTransaction  ----------------------------------------
	//	A pure virtual function to display transaction(s)
	//	Preconditions:	Derived comparable object is instantiated. transaction information has
	//					been set before calling this method
	//	Postconditions:	Prints the values of derived comparable object
	virtual void displayForTransaction() const = 0;

private:

	char data;
};

