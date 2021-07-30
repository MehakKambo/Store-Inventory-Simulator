//---------------------------------------------------------------------------------
// DisplayInventory.cpp
// Author: Mehakpreet Kambo
// Class Implementation
//---------------------------------------------------------------------------------
// DisplayInventory Class: A class to to display the entire store inventory. 
//						   Child class derived from Transaction class.
//						   Additional functionality of the class:
//   -- allows for constructing a DisplayInventory object 
//	 -- allows for displaying the object
//   -- allows for displaying all the collectible items present in the inventory of 
//		the store
//
// Assumptions:
//   -- Transaction class is the parent class
//	 -- Transaction class has all the necessary virtual methods
//   -- a factory class for transactions has been instantiated
//---------------------------------------------------------------------------------

#include "Store.h"
#include "DisplayInventory.h"

//----------------------------  constructor  -----------------------------------------
//	Default constructor  
//	Preconditions:	None
//	Postconditions:	transactionType is set to "DisplayInventory" action
DisplayInventory::DisplayInventory() 
{
	transactionType = "DisplayInventory";
}

//----------------------------  destructor  ------------------------------------------
//	Destructor
//	Preconditions:	The calling DisplayInventory object is instantiated 
//	Postconditions:	DisplayInventory object is deleted
DisplayInventory::~DisplayInventory() { }

//------------------------------  create  --------------------------------------------
//	Create, virtual function to create DisplayInventory object
//	Preconditions:	A hash table with an index to instantiate a new DisplayInventory
//					 object is present in TransactionFactory class. 
//	Postconditions:	Returns a new DisplayInventory object that is passed to factory class.
Transaction* DisplayInventory::create() 
{
	return new DisplayInventory;
}

//-----------------------------   display  ----------------------------------------------
//	Display, virtual function to display the DisplayInventory object in other methods.
//	Preconditions:	Comparable points to correct object and transactionType is correct
//	Postconditions:	the transaction type is displayed and displayForTransaction method is
//					 called that prints all the object information.
void DisplayInventory::display() { }

//----------------------------   perform  ---------------------------------------------
//	Perform, virtual function to help perform the DisplayInventory action
//	Preconditions:	DisplayInventory and Store object has been instantiated.   
//					store != nullptr. char input is a valid collectible item.
//	Postconditions:	The full inventory of the store is displayed containing collectible 
//					items.
bool DisplayInventory::perform(Store* store) 
{
	store->displayAllInventory();
	return true;
}
