# Store-Inventory-Simulator
A local collectibles store wishes to automate their inventory tracking system. Three types of items are to be tracked:
-Coins
-Comic books
-Sports cards

Customer transactions (buy/sell) are also to be tracked. Five types of actions are desired in the system:
Sell: removes an item from the store inventory
Buy: adds an item to the store inventory
Display: outputs the entire inventory of the store, including the number of each item in inventory
Customer: outputs all of the transactions for a customer (in chronological order), including the item
History: outputs the history for every customer, with the customers in alphabetical order.

This program initializes the contents of the inventory from a file, the customer list from another file, and process an arbitrary sequence of commands from a third file.

#Details of the program
All coins have type, year, and grade (an integer). All comic books have a title, publisher, year, and grade (a string). All sports cards have a player, a manufacturer, a year, and a grade (a string). The items in the inventory are sorted as follows:
-Coins are sorted first by type, then by year, then by grade
-Comics are sorted first by publisher, then by title, then by year, then by grade
-Sports cards are sorted by player, then by year, then by manufacturer, then by grade

#Assumptions
Each item is uniquely identified by the complete set of sorting criteria. To facilitate processing of the files, Coins are marked ‘M’, comics are marked ‘C’, and sports cards are marked ‘S’. Assume correct formatting in the files, but the data could be invalid.
