//---------------------------------------------------------------------------------
// Coin.cpp
// Author: Mehakpreet Kambo
// Class Implementation
//---------------------------------------------------------------------------------
// Coin Class:	A class To represent a coin, collectible item. It is derived from 
//				parnet class, CollectibleItem class. Additional functionality:
//   -- allows for creating the Coin object
//	 -- allows for setting the information in the object from an istream object 
//	 -- allows for comparisons between two coin objects
//   --	stores a string type, integer year, and integer grade
//	 -- allows for displaying the information stored in the object
//	 -- allows for displaying the information of object for a transaction 
//
// Assumptions:
//   -- CollectibleItem parent class is included and has virtual or pure virtual 
//		methods
//---------------------------------------------------------------------------------

#include "Coin.h"

//------------------------------  constructor  -----------------------------------------
//	Default constructor 
//	Preconditions:	None
//	Postconditions:	Coin object is created
Coin::Coin() { }

//------------------------------  destructor  ------------------------------------------
//	Destructor 
//	Preconditions:	The calling Coin object has been instantiated
//	Postconditions:	Coin object is deleted
Coin::~Coin() { }

//---------------------------------  create  -------------------------------------------
//	Creat, virtual function to create the object
//	Preconditions:	a hash table with indexes to create Coin object has been set up
//					in a ComparableFactory class and the object has been 
//					instantiated. 
//	Postconditions:	Coin object is created and returned.
Comparable* Coin::create() 
{
	return new Coin;
}

//---------------------------  setInformation  -------------------------------------
//	SetInformation, virtual function to set the object information.
//	Preconditions:	an istream is being passed in as a parameter
//	Postconditions:	members in the coin object are changed and their information
void Coin::setInformation(istream& inStream) 
{
	inStream.ignore();				
	inStream >> quantity;			
	inStream.ignore();				
	inStream >> year;				
	inStream.ignore();				
	inStream >> grade;				
	inStream.ignore();				
	getline(inStream, type, '\n');	
}

//-----------------------  setTransactionInformation  -------------------------------
//	setTransactionInformation, virtual function to set the transaction information 
//	Preconditions:	an istream is being passed in as a parameter.
//	Postconditions:	members in the Coin object are changed and their information
//					is set for a transaction
void Coin::setTransactionInformation(istream& inStream) 
{
	inStream.ignore();				
	inStream >> year;				
	inStream.ignore();				
	inStream >> grade;				
	inStream.ignore();				
	getline(inStream, type, '\n');	
}

//--------------------------------  <  ----------------------------------------------
//	Operator overloaded < 
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	Returns true if this attributes are less than that of comparable, 
//					false otherwise
bool Coin::operator<(const Comparable& comparable) const 
{
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);

	if (type < comparableCoin.type) 
	{
		return true;
	}
	else if (type == comparableCoin.type) 
	{
		if (year < comparableCoin.year) 
		{
			return true;
		}
		else if (year == comparableCoin.year) 
		{
			if (grade < comparableCoin.grade) 
			{
				return true;
			}
		}
	}
	return false;
}

//--------------------------------  ==  ----------------------------------------------
//	Operator overloaded ==
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	Returns true if this attributes are equal to that of comparable, 
//					false otherwise 
bool Coin::operator==(const Comparable& comparable) const 
{
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);
	
	return (type == comparableCoin.type && year == comparableCoin.year 
		&& grade == comparableCoin.grade);
}

//--------------------------------  !=  ----------------------------------------------
//	Operator overloaded !=
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	Returns true if this attributes are not equal to that of comparable, 
//					false otherwise
bool Coin::operator!=(const Comparable& comparable) const 
{
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);

	return !(*this == comparableCoin);
}

//--------------------------------  >  ----------------------------------------------
//	Operator overloaded >
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	Returns true if this attributes are greater than that of comparable, 
//					false otherwise
bool Coin::operator>(const Comparable& comparable) const 
{
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);

	if (type > comparableCoin.type) 
	{
		return true;
	}
	else if (type == comparableCoin.type) 
	{
		if (year > comparableCoin.year) 
		{
			return true;
		}
		else if (year == comparableCoin.year) 
		{
			if (grade > comparableCoin.grade) 
			{
				return true;
			}
		}
	}
	return false;
}

//------------------------  displayInformation  ----------------------------------------
//	A pure virtual function to display the Coin information
//	Preconditions:	parent class object has the pure virtual or virtual method
//	Postconditions:	All the information from the calling object is displayed
void Coin::displayInformation() const 
{
	cout << type << " " << year << " " << grade << " QUANTITY: " << quantity;
}

//------------------------  displayForTransaction  ----------------------------------------
//	A pure virtual function to display transaction(s)
//	Preconditions:	parent class object has the pure virtual or virtual method
//	Postconditions:	Prints the values of Coin object for transaction
void Coin::displayForTransaction() const 
{
	cout << " " << type << " " << year << " " << grade;
}

//------------------------  getType  ----------------------------------------
//	Getter function for the type
//	Preconditions:	Coin has been created. a string is stored in type
//	Postconditions:	a string is returned to calling object
string Coin::getType() 
{
	return type;
}

//------------------------  getYear  ----------------------------------------
//	Getter function for year
//	Preconditions:	Coin has been created. an int is stored in year
//	Postconditions:	an int is returned to the calling object
int getYear();
int Coin::getYear() 
{
	return year;
}

//------------------------  getGrade  ----------------------------------------
//	Getter function for grade
//	Preconditions:	Coin has been created. an int is stored in grade
//	Postconditions:	an int is returned to the calling object
int Coin::getGrade() 
{
	return grade;
}