//---------------------------------------------------------------------------------
// Buy.h
// Author: Mehakpreet Kambo
// Class Declarations
//---------------------------------------------------------------------------------
// Buy Class: A class to perform the buy action for a collectible item. Child class
//			  derived from Transaction class, represented by a 'B' in commands file.
//			  Additional functionality of the class:
//   -- allows for constructing a Buy object 
//	 -- allows for displaying the object
//   --	increases the quantity when the action is performed.
//
// Assumptions:
//   -- Transaction class is the parent class
//	 -- Transaction class has all the necessary virtual methods
//   -- a factory class for transactions has been instantiated
//---------------------------------------------------------------------------------

#pragma once
#include "Transaction.h"


class Buy :	public Transaction {

public:
	
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor  
	//	Preconditions:	None
	//	Postconditions:	transactionType is set to "Buy" action
	Buy();

	//----------------------------  destructor  ------------------------------------------
	//	Destructor
	//	Preconditions:	The calling Buy object is instantiated 
	//	Postconditions:	Buy object is deleted
	virtual ~Buy();

	//------------------------------  create  --------------------------------------------
	//	Create, virtual function to create Buy object
	//	Preconditions:	A hash table with an index to instantiate a new Buy object is 
	//					is present in TransactionFactory class. 
	//	Postconditions:	Returns a new Buy object that is passed to factory class.
	virtual Transaction* create();	

	//----------------------------   perform  ---------------------------------------------
	//	Perform, virtual function to help perform the Buy action
	//	Preconditions:	Buy and Store object has been instantiated. store != nullptr. char  
	//					input is a valid collectible item.
	//	Postconditions:	Comparable object's quantity increasea if it is already present 
	//					in the BSTree of collectible items otherwise, it is added. 
	virtual bool perform(Store* store, Comparable* comparable, char type);	

	//-----------------------------   display  ----------------------------------------------
	//	Display, virtual function to display the Buy object in other methods.
	//	Preconditions:	Comparable points to correct object and transactionType is correct
	//	Postconditions:	the transaction type is displayed and displayForTransaction method is
	//					 called that prints all the object information. 
	virtual void display();

};