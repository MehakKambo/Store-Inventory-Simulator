//-----------------------------------------------------------------------------------
// CollectibleItem.h
// Author: Mehakpreet Kambo
// Class Implementation
//-----------------------------------------------------------------------------------
// CollectibleItem Class:	A class to represent a collectible item. It is derived 
//							from a Comparable class object. Additional functionality:
//	 -- allows for creating derived class objects
//	 -- allows for comparison between two derived class objects
//   --	allows for storing the quantity of collectible items
//   -- allows for getting the current quantity of object 
//	 -- allows for increasing the current quantity of object
//	 -- allows for decreasing the current quantity of object
//	 -- allows for displaying the information of the object
//	 -- allows for displaying the transaction information of the object
//
// Assumptions:
//   -- Comparable parent class is included and has pure virtual or virtual methods.
//   -- Derived class object are of different types of collectible items
//---------------------------------------------------------------------------------

#include "CollectibleItem.h"

//-----------------------------  constructor  -----------------------------------------
//	Default constructor 
//	Preconditions:	None
//	Postconditions:	CollectibleItem object is created
CollectibleItem::CollectibleItem() { }

//-----------------------------  destructor  -----------------------------------------
//	Destructor 
//	Preconditions:	CollectibleItem has previously been instantiated
//	Postconditions:	CollectibleItem is deleted
CollectibleItem::~CollectibleItem() { }

//---------------------------  getQuantity  -------------------------------------------
//	A pure virtual function that returns the quantity of items in a derived class
//	Preconditions:	Quantity has been defined
//	Postconditions:	Int value of quantity is returned
int CollectibleItem::getQuantity() 
{
	return quantity;
}

//--------------------------  increaseQuantity  -----------------------------------------
//	A pure virtual function that increases quantity of items
//	Preconditions:	Quantity has been defined
//	Postconditions:	Returns true if quantity is increased by 1, false otherwise 
bool CollectibleItem::increaseQuantity() 
{
	quantity++;
	return true;
}

//--------------------------  decreaseQuantity  ------------------------------------------
//	A pure virtual function that decreases quantity of items
//	Preconditions:	Quantity has been defined. 
//	Postconditions:	Returns true if quantity is decreased by 1, false otherwise
bool CollectibleItem::decreaseQuantity() 
{
	if (quantity > 0) 
	{
		quantity--;
		return true;
	}
	return false;
}