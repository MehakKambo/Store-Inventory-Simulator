//---------------------------------------------------------------------------------
// ComparableFactory.h
// Author: Mehakpreet Kambo	
// Class Declarations
//---------------------------------------------------------------------------------
// ComparableFactory Class:	A factory class that initializes a table of objects.
//							It uses a hash function to determine which comparable 
//							object to create. Additional functionality:
//   --	allows for hashing a char and return an integer value
//   --	allows for creating an object derived from the parent CollectibleItem class
//   -- uses a table that stores new objects
//
// Assumptions:
//   -- Comparable class is included
//   -- All other necessary files are included
//   -- a valid key is passed into the create method
//---------------------------------------------------------------------------------

#pragma once
#include "Comparable.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"
#include <string>

using namespace std;

#define TABLE_SIZE 26

class ComparableFactory {

public:

	//----------------------------  constructor  -----------------------------------------
	//	Default constructor 
	//	Preconditions:	table points to the related objects of derived 
	//	Postconditions:	comparableTable is initialized. the chars being hashed are set to
	//					instantiate a new object of a derived Comparable class
	ComparableFactory();

	//----------------------------  destructor  -----------------------------------------
	//	Destructor 
	//	Preconditions:	The table is initialized
	//	Postconditions:	Any dynamically allocated memory is deleted and table values are 
	//					set to nullptr
	virtual ~ComparableFactory();

	//------------------------------  create  -------------------------------------------
	//	Preconditions:	The input char is valid. 		
	//	Postconditions:	Returns a Comparable* to the calling object
	Comparable* create(istream& inStream, char key);

private:
	
	//------------------------------  hashChar  -------------------------------------------
	//	Helper function to hash a char
	//	Preconditions:	A char is passed as a parameter
	//	Postconditions:	Hashed value is returned
	int hashChar(char key);

	Comparable* comparableTable[TABLE_SIZE];
};

