//---------------------------------------------------------------------------------
// CustomerTransactions.h
// Author: Mehakpreet Kambo
// Class Declarations
//---------------------------------------------------------------------------------
// CustomerTransactions Class:	A class that displays customer transactions, derived
//								from the Transaction class and represented by a 'C'
//								in the commands file. Additional functionality:
//   -- allows for creating a CustomerTransaction object
//   --	allows for displaying a customer's transaction history
//	 -- allows for performing an action
//	 -- allows for displaying the object 
//
// Assumptions: 
//   -- a factory class for creating transactions has been instantiated
//   -- Transaction class is the parent class and has virtual 
//---------------------------------------------------------------------------------

#pragma once
#include "Transaction.h"

class CustomerTransactions : public Transaction {

public:
	
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor  
	//	Preconditions:	None
	//	Postconditions:	transactionType is set to "CustomerTransactions" action
	CustomerTransactions();

	//----------------------------  destructor  ------------------------------------------
	//	Destructor
	//	Preconditions:	The calling CustomerTransactions object is instantiated 
	//	Postconditions:	CustomerTransactions object is deleted
	virtual ~CustomerTransactions();

	//------------------------------  create  --------------------------------------------
	//	Create, virtual function to create CustomerTransactions object
	//	Preconditions:	A hash table with an index to instantiate a new CustomerTransactions object is 
	//					is present in TransactionFactory class. 
	//	Postconditions:	Returns a new CustomerTransactions object that is passed to factory class.
	virtual Transaction* create();

	//----------------------------   perform  ---------------------------------------------
	//	Perform, virtual function to help perform the CustomerTransactions action
	//	Preconditions:	CustomerTransactions and Store object has been instantiated. store != nullptr. char  
	//					input is a valid collectible item.
	//	Postconditions:	Comparable object's quantity increasea if it is already present 
	//					in the BSTree of collectible items otherwise, it is added. 
	virtual bool perform(Store* store, int customerID);

	//-----------------------------   display  ----------------------------------------------
	//	Display, virtual function to display the CustomerTransactions object in other methods.
	//	Preconditions:	Comparable points to correct object and transactionType is correct
	//	Postconditions:	the transaction type is displayed and displayForTransaction method is
	//					 called that prints all the object information. 
	virtual void display();

};

