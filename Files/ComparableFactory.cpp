//---------------------------------------------------------------------------------
// ComparableFactory.cpp
// Author: Mehakpreet Kambo	
// Class Implementation
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

#include "ComparableFactory.h"

//----------------------------  constructor  -----------------------------------------
//	Default constructor 
//	Preconditions:	table points to the related objects of derived 
//	Postconditions:	comparableTable is initialized. the chars being hashed are set to
//					instantiate a new object of a derived Comparable class
ComparableFactory::ComparableFactory() 
{
	for (int i = 0; i < TABLE_SIZE; i++) 
	{
		comparableTable[i] = nullptr;
	}

	comparableTable[hashChar('M')] = new Coin;
	comparableTable[hashChar('C')] = new ComicBook;
	comparableTable[hashChar('S')] = new SportsCard;
}

//----------------------------  destructor  -----------------------------------------
//	Destructor 
//	Preconditions:	The table is initialized
//	Postconditions:	Any dynamically allocated memory is deleted and table values are 
//					set to nullptr
ComparableFactory::~ComparableFactory() 
{
	for (int i = 0; i < TABLE_SIZE; i++) 
	{
		if (comparableTable[i] != nullptr) 
		{
			delete comparableTable[i];
			comparableTable[i] = nullptr;
		}
	}
}

//------------------------------  create  -------------------------------------------
//	Preconditions:	The input char is valid. 		
//	Postconditions:	Returns a Comparable* to the calling object
Comparable* ComparableFactory::create(istream& inStream, char key) 
{
	int index = hashChar(key);

	if (comparableTable[index] == nullptr) 
	{
		string garbage;
		getline(inStream,garbage,'\n');
		return nullptr;
	}

	return comparableTable[index]->create();
}

//------------------------------  hashChar  -------------------------------------------
//	Helper function to hash a char
//	Preconditions:	A char is passed as a parameter
//	Postconditions:	Hashed value is returned
int hashChar(char key);
int ComparableFactory::hashChar(char key) 
{
	return (key - 'A') % TABLE_SIZE;
}
