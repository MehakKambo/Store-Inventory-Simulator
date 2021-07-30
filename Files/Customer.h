//---------------------------------------------------------------------------------
// Customer.h
// Author: Mehakpreet Kambo
// Class Declarations
//---------------------------------------------------------------------------------
// Customer Class:	A class to represents a customer in the store. It stores the 
//					customer's information and all of their transaction history
//   --	stores the customer's name 
//   --	stores the customer's ID number
//   -- stores the customer's transaction history
//	 -- allows for displaying customer's transaction history
//	 -- allows for comparing less than of customers
//
// Assumptions: 
//	 -- Transaction class is included
//---------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

class Customer {

public:
	
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor 
	//	Preconditions:	None 
	//	Postconditions:	Customer object is created, idNumber = 0
	Customer();

	//----------------------------  destructor  -----------------------------------------
	//	Destructor 
	//	Preconditions:	Customer object is already instantiated
	//	Postconditions:	Customer object is deleted
	virtual ~Customer();

	//----------------------------  getIdNumber  -----------------------------------------
	//	Getter function for the Customer's idNumber 
	//	Preconditions:	customer object has been instantiated, an integer is stored in idNumber
	//	Postconditions:	an integer value of IdNumber is returned to the calling object 
	int getIdNumber() const;

	//------------------------------  getName  ---------------------------------------------
	//	Getter function for the Customer's name 
	//	Preconditions:	customer object has been instantiated, a string is stored in name
	//	Postconditions:	a string value of name is returned to the calling object
	string getName() const;

	//------------------------  displayAllTransactions  -------------------------------------
	//	Displays all transactions for a customer
	//	Preconditions:	customer object has been created, transactionHistory vector has been created
	//	Postconditions:	transactionHistory vector is iterated, each transaction has 
	//					its display method called which prints the transaction 
	void displayAllTransactions();

	//----------------------------  setCustomerInfo  ------------------------------------------
	//	Sets the Customer's information 
	//	Preconditions:	customer object has been created. customer has private variables idNumber 
	//					and name
	//	Postconditions:	idNumber is updated with an integer and name is updated with a string
	void setCustomerInfo(istream& inStream);

	//--------------------------------  setName  ---------------------------------------------
	//	Setter function to set  name of the customer
	//	Preconditions:	customer object has been created. customer has private name variable. the 
	//					parameter passed in is a valid string
	//	Postconditions:	name is updated with newName
	void setName(string newName);

	//------------------------------  addTransaction  -----------------------------------------
	//	A method that adds a Transaction object to the vector of transactionHistory 
	//	Preconditions:	customer object has been created. the parameter being passed in is a 
	//					valid Transaction object
	//	Postconditions:	transaction is pushed onto the transactionHistory vector
	void addTransaction(Transaction transaction);

	//------------------------------------  <  ------------------------------------------------
	//	Operator overloaded < 
	//	Preconditions:	this and customer both point to Customer objects
	//	Postconditions:	Returns true this.name is less than customer.name, false otherwise
	bool operator<(const Customer& customer)const;

private:

	int idNumber;
	string name;
	vector <Transaction> transactionHistory;
};

