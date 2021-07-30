//---------------------------------------------------------------------------------
// ComicBook.cpp
// Author: Mehakpreet Kambo
// Class implementation
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

#include "ComicBook.h"

//------------------------------  constructor  -----------------------------------------
//	Default constructor 
//	Preconditions:	None
//	Postconditions:	ComicBook object is created
ComicBook::ComicBook() { }

//------------------------------  destructor  ------------------------------------------
//	Destructor 
//	Preconditions:	The calling ComicBook object has been instantiated
//	Postconditions:	ComicBook object is deleted
ComicBook::~ComicBook() { }

//---------------------------------  create  -------------------------------------------
//	Creat, virtual function to create the object
//	Preconditions:	a hash table with indexes to create ComicBook object has been set up
//					in a ComparableFactory class and the object has been 
//					instantiated. 
//	Postconditions:	ComicBook object is created and returned.
Comparable* ComicBook::create() 
{
	return new ComicBook;
}

//---------------------------  setInformation  -------------------------------------
//	SetInformation, virtual function to set the object information.
//	Preconditions:	an istream is being passed in as a parameter
//	Postconditions:	members in the ComicBook object are changed and their information
//					is set
void ComicBook::setInformation(istream& inStream) 
{
	inStream.ignore();					
	inStream >> quantity;				
	inStream.ignore();					
	inStream >> year;					
	inStream.ignore();					
	getline(inStream, grade, ',');		
	inStream.ignore();					
	getline(inStream, title, ',');		
	inStream.ignore();					
	getline(inStream, publisher, '\n');	
}

//-----------------------  setTransactionInformation  -------------------------------
//	setTransactionInformation, virtual function to set the transaction information 
//	Preconditions:	an istream is being passed in as a parameter.
//	Postconditions:	members in the ComicBook object are changed and their information
//					is set for a transaction
void ComicBook::setTransactionInformation(istream& inStream) 
{
	inStream.ignore();					
	inStream >> year;					
	inStream.ignore();					
	getline(inStream, grade, ',');		
	inStream.ignore();					
	getline(inStream, title, ',');		
	inStream.ignore();					
	getline(inStream, publisher, '\n');	
}

//--------------------------------  <  ----------------------------------------------
//	Operator overloaded < 
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	Returns true if this attributes are less than that of comparable, 
//					false otherwise
bool ComicBook::operator<(const Comparable& comparable) const 
{
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	if (publisher < comparableComicBook.publisher) 
	{
		return true;
	}
	else if (publisher == comparableComicBook.publisher) 
	{

		if (title < comparableComicBook.title) 
		{
			return true;
		}
		else if (title == comparableComicBook.title) 
		{
			if (year < comparableComicBook.year) 
			{
				return true;
			}
			else if (year == comparableComicBook.year) 
			{
				if (grade < comparableComicBook.grade) 
				{
					return true;
				}
			}
		}
	}
	return false;
}

//--------------------------------  ==  ----------------------------------------------
//	Operator overloaded ==
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	Returns true if this attributes are equal to that of comparable, 
//					false otherwise 
bool ComicBook::operator==(const Comparable& comparable) const 
{
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	return (publisher == comparableComicBook.publisher && title == comparableComicBook.title 
		&& year == comparableComicBook.year && grade == comparableComicBook.grade);
}

//--------------------------------  !=  ----------------------------------------------
//	Operator overloaded !=
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	Returns true if this attributes are not equal to that of comparable, 
//					false otherwise
bool ComicBook::operator!=(const Comparable& comparable) const 
{
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	return !(*this == comparableComicBook);
}

//--------------------------------  >  ----------------------------------------------
//	Operator overloaded >
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	Returns true if this attributes are greater than that of comparable, 
//					false otherwise
bool ComicBook::operator>(const Comparable& comparable) const 
{
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	if (publisher > comparableComicBook.publisher) 
	{
		return true;
	}
	else if (publisher == comparableComicBook.publisher) 
	{
		if (title > comparableComicBook.title) 
		{
			return true;
		}
		else if (title == comparableComicBook.title) 
		{
			if (year > comparableComicBook.year) 
			{
				return true;
			}
			else if (year == comparableComicBook.year) 
			{
				if (grade > comparableComicBook.grade) 
				{
					return true;
				}
			}
		}
	}
	return false;
}

//------------------------  displayInformation  ----------------------------------------
//	A pure virtual function to display the ComicBook information
//	Preconditions:	parent class object has the pure virtual or virtual method
//	Postconditions:	All the information from the calling object is displayed
void ComicBook::displayInformation() const 
{
	cout << title << " " << publisher << " " << year << " " << grade << " QUANTITY: " << quantity;
}

//------------------------  displayForTransaction  ----------------------------------------
//	A pure virtual function to display transaction(s)
//	Preconditions:	parent class object has the pure virtual or virtual method
//	Postconditions:	Prints the values of ComicBook object for transaction
void ComicBook::displayForTransaction() const 
{
	cout << " " << title << " " << publisher << " " << year << " " << grade;
}

//------------------------  getTitle  ----------------------------------------
//	Getter function for the title
//	Preconditions:	ComicBook has been created. a string is stored in title
//	Postconditions:	a string is returned to calling object
std::string ComicBook::getTitle() 
{
	return title;
}

//------------------------  getPublisher  ----------------------------------------
//	Getter function for the publisher
//	Preconditions:	ComicBook has been created. a string is stored in publisher
//	Postconditions:	a string is returned to calling object
string ComicBook::getPublisher() 
{
	return publisher;
}

//------------------------  getYear  ----------------------------------------
//	A method that returns an integer that is stored in variable year
//	Preconditions:	ComicBook has been created. an int is stored in year
//	Postconditions:	an int is returned to calling object
int ComicBook::getYear() 
{
	return year;
}

//------------------------  getGrade  ----------------------------------------
//	Getter function for the grade
//	Preconditions:	ComicBook has been created. a string is stored in grade
//	Postconditions:	a string is returned to calling object
string ComicBook::getGrade() 
{
	return grade;
}
