//---------------------------------------------------------------------------------
// ComicBook.h
// Author: Mehakpreet Kambo
// Class Declarations
//---------------------------------------------------------------------------------
// ComicBook Class:	A class to represent a comic book, collectible item. It is 
//					derived from CollectibleItem class. Additional functionality:
//   -- allows for creating the object
//	 -- allows for setting the information in the object from an istream object 
//	 -- allows for comparisons between two ComicBook objects
//   --	stores a string title, string publisher, string grade, and integer year
//	 -- allows for displaying the information stored in the object
//	 -- allows for displaying the information of object for a transaction
//
// Assumptions:
//   -- CollectibleItem parent class is included and has virtual or pure virtual 
//		methods
//---------------------------------------------------------------------------------

#pragma once
#include "CollectibleItem.h"

class ComicBook : public CollectibleItem {

public:
	
	//------------------------------  constructor  -----------------------------------------
	//	Default constructor 
	//	Preconditions:	None
	//	Postconditions:	ComicBook object is created
	ComicBook();

	//------------------------------  destructor  ------------------------------------------
	//	Destructor 
	//	Preconditions:	The calling ComicBook object has been instantiated
	//	Postconditions:	ComicBook object is deleted
	~ComicBook();

	//---------------------------------  create  -------------------------------------------
	//	Creat, virtual function to create the object
	//	Preconditions:	a hash table with indexes to create ComicBook object has been set up
	//					in a ComparableFactory class and the object has been 
	//					instantiated. 
	//	Postconditions:	ComicBook object is created and returned.
	virtual Comparable* create();

	//---------------------------  setInformation  -------------------------------------
	//	SetInformation, virtual function to set the object information.
	//	Preconditions:	an istream is being passed in as a parameter
	//	Postconditions:	members in the ComicBook object are changed and their information
	//					is set
	void setInformation(istream& inStream);

	//-----------------------  setTransactionInformation  -------------------------------
	//	setTransactionInformation, virtual function to set the transaction information 
	//	Preconditions:	an istream is being passed in as a parameter.
	//	Postconditions:	members in the ComicBook object are changed and their information
	//					is set for a transaction
	virtual void setTransactionInformation(istream& inStream);

	//--------------------------------  <  ----------------------------------------------
	//	Operator overloaded < 
	//	Preconditions:	this and comparable both point to ComicBook objects
	//	Postconditions:	Returns true if this attributes are less than that of comparable, 
	//					false otherwise
	virtual bool operator<(const Comparable& comparable) const;

	//--------------------------------  ==  ----------------------------------------------
	//	Operator overloaded ==
	//	Preconditions:	this and comparable both point to ComicBook objects
	//	Postconditions:	Returns true if this attributes are equal to that of comparable, 
	//					false otherwise 
	virtual bool operator==(const Comparable& comparable) const;

	//--------------------------------  !=  ----------------------------------------------
	//	Operator overloaded !=
	//	Preconditions:	this and comparable both point to ComicBook objects
	//	Postconditions:	Returns true if this attributes are not equal to that of comparable, 
	//					false otherwise
	virtual bool operator!=(const Comparable& comparable) const;

	//--------------------------------  >  ----------------------------------------------
	//	Operator overloaded >
	//	Preconditions:	this and comparable both point to ComicBook objects
	//	Postconditions:	Returns true if this attributes are greater than that of comparable, 
	//					false otherwise
	virtual bool operator>(const Comparable& comparable) const;

	//------------------------  displayInformation  ----------------------------------------
	//	A pure virtual function to display the ComicBook information
	//	Preconditions:	parent class object has the pure virtual or virtual method
	//	Postconditions:	All the information from the calling object is displayed
	virtual void displayInformation() const;

	//------------------------  displayForTransaction  ----------------------------------------
	//	A pure virtual function to display transaction(s)
	//	Preconditions:	parent class object has the pure virtual or virtual method
	//	Postconditions:	Prints the values of ComicBook object for transaction
	virtual void displayForTransaction() const;

	//------------------------  getTitle  ----------------------------------------
	//	Getter function for the title
	//	Preconditions:	ComicBook has been created. a string is stored in title
	//	Postconditions:	a string is returned to calling object
	string getTitle();

	//------------------------  getPublisher  ----------------------------------------
	//	Getter function for the publisher
	//	Preconditions:	ComicBook has been created. a string is stored in publisher
	//	Postconditions:	a string is returned to calling object
	string getPublisher();

	//------------------------  getYear  ----------------------------------------
	//	A method that returns an integer that is stored in variable year
	//	Preconditions:	ComicBook has been created. an int is stored in year
	//	Postconditions:	an int is returned to calling object
	int getYear();

	//------------------------  getGrade  ----------------------------------------
	//	Getter function for the grade
	//	Preconditions:	ComicBook has been created. a string is stored in grade
	//	Postconditions:	a string is returned to calling object
	string getGrade();

private:
	string title;
	string publisher;
	int year;
	string grade;
};

