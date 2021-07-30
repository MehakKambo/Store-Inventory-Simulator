//-----------------------------------------------------------------------------------
// CollectibleItem.h
// Author: Mehakpreet Kambo
// Class Declarations
//-----------------------------------------------------------------------------------
// CollectibleItem Class:	A class to represent a collectible item. It is derived 
//							from a Comparable class object. Additional functionality:
//	 -- allows for creating derived class objects
//	 -- allows for comparison between two derived class objects
//   --	allows for storing the quantity of collectible items
//   -- allows for getting the current quantity of object 
//	 -- allows for increasing the current quantity of object
//	 -- allows for decreasing the current quantity of object
//	 -- allows for displaying the information of the object
//	 -- allows for displaying the transaction information of the object
//
// Assumptions:
//   -- Comparable parent class is included and has pure virtual or virtual methods.
//   -- Derived class object are of different types of collectible items
//---------------------------------------------------------------------------------

#pragma once
#include "Comparable.h"

#include <string>
using namespace std;

class CollectibleItem :	public Comparable {

public:

	//-----------------------------  constructor  -----------------------------------------
	//	Default constructor 
	//	Preconditions:	None
	//	Postconditions:	CollectibleItem object is created
	CollectibleItem();

	//-----------------------------  destructor  -----------------------------------------
	//	Destructor 
	//	Preconditions:	CollectibleItem has previously been instantiated
	//	Postconditions:	CollectibleItem is deleted
	virtual ~CollectibleItem();

	//----------------------------  create  --------------------------------------
	//	Create, pure virtual function that allows to create derived class objects
	//	Preconditions:	ComparableFactory class object is instantiated and a hash
	//					table with indexes to create derived class objects is present
	//	Postconditions:	CollectibleItem and derived objects are created
	virtual Comparable* create() = 0;

	//-------------------------  setInformation  -------------------------------------
	//	A pure virtual function to set the derived object information.
	//	Preconditions:	an istream is being passed in as a parameter
	//	Postconditions:	members in a derived class object are changed and their information
	//					is set
	virtual void setInformation(istream& inStream) = 0;

	//-----------------------  setTransactionInformation  -------------------------------
	//	A pure virtual function to set the transaction information
	//	Preconditions:	an istream is being passed in as a parameter
	//	Postconditions:	members in a derived class object are changed and their transaction 
	//					information is set
	virtual void setTransactionInformation(istream& inStream) = 0;

	//--------------------------------  <  ----------------------------------------------
	//	Operator overloaded <
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	Returns true if this is less than comparable, false otherwise
	virtual bool operator<(const Comparable& comparable) const = 0;

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

	//--------------------------------  >  ----------------------------------------------
	//	Operator overloaded >
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	Returns true if this is greater than comparable, false otherwise
	virtual bool operator>(const Comparable& comparable) const = 0;

	//------------------------  displayInformation  ----------------------------------------
	//	A pure virtual function to display the information
	//	Preconditions:	Derived class object implements their own version of displayInformation
	//	Postconditions:	All the information from the calling object is displayed
	virtual void displayInformation() const = 0;

	//------------------------  displayForTransaction  ----------------------------------------
	//	A pure virtual function to display transaction(s)
	//	Preconditions:	Derived comparable object is instantiated. transaction information has
	//					been set before calling this method
	//	Postconditions:	Prints the values of derived comparable object
	virtual void displayForTransaction() const = 0;

	//---------------------------  getQuantity  -------------------------------------------
	//	A pure virtual function that returns the quantity of items in a derived class
	//	Preconditions:	Quantity has been defined
	//	Postconditions:	Int value of quantity is returned
	virtual int getQuantity();

	//--------------------------  increaseQuantity  -----------------------------------------
	//	A pure virtual function that increases quantity of items
	//	Preconditions:	Quantity has been defined
	//	Postconditions:	Returns true if quantity is increased by 1, false otherwise 
	bool increaseQuantity();

	//--------------------------  decreaseQuantity  ------------------------------------------
	//	A pure virtual function that decreases quantity of items
	//	Preconditions:	Quantity has been defined. 
	//	Postconditions:	Returns true if quantity is decreased by 1, false otherwise
	bool decreaseQuantity();

protected:

	int quantity;
};

