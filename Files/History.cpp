//---------------------------------------------------------------------------------
// History.cpp
// Author: Mehakpreet Kambo
// Class Implementation
//---------------------------------------------------------------------------------
// History Class: A class to display transactions of all the customers in an 
//				  alphabetical order. Child class derived from Transaction class.
//			  Additional functionality of the class:
//   -- allows for constructing a History object 
//	 -- allows for displaying the object
//   --	allows for displaying the transaction history of all the customers
//
// Assumptions:
//   -- Transaction class is the parent class
//	 -- Transaction class has all the necessary virtual methods
//   -- a factory class for transactions has been instantiated

#include "Store.h"
#include "History.h"

//----------------------------  constructor  -----------------------------------------
//	Default constructor  
//	Preconditions:	None
//	Postconditions:	transactionType is set to "History" action
History::History() 
{
	transactionType = "History";
}

//----------------------------  destructor  ------------------------------------------
//	Destructor
//	Preconditions:	The calling History object is instantiated 
//	Postconditions:	History object is deleted
History::~History() { }

//------------------------------  create  --------------------------------------------
//	Create, virtual function to create History object
//	Preconditions:	A hash table with an index to instantiate a new History object is 
//					is present in TransactionFactory class. 
//	Postconditions:	Returns a new History object that is passed to factory class.
Transaction* History::create() 
{
	return new History;
}

//----------------------------   perform  ---------------------------------------------
//	Perform, virtual function to help perform the History action
//	Preconditions:	History and Store object has been instantiated. store != nullptr. char  
//					input is a valid collectible item.
//	Postconditions:	History of transactions of all the store customers is displayed in an 
//					alphabetical order.
bool History::perform(Store* store) 
{
	store->displayAllHistory();
	return true;
}

//-----------------------------   display  ----------------------------------------------
//	Display, virtual function to display the History object in other methods.
//	Preconditions:	Comparable points to correct object and transactionType is correct
//	Postconditions:	the transaction type is displayed and displayForTransaction method is
//					 called that prints all the object information.
void History::display() { }