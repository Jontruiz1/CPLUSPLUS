// COMPLETED: ShoppingCart.h
//  Do not modify
//  Read all comments for information on implementation ShoppingCart.cpp
#ifndef __SHOPPING_CART__
#define __SHOPPING_CART__

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class ShoppingCart {
public:
    // no default constructor

    // constructor to initialize shopping cart object
    //	initialize currentDate with a call to getDateString()
    //		from DateUtility.h
    ShoppingCart(string name);

    string getCustomerName() const; //returns customerName value
    string getCurrentDate() const;	//returns currentDate value

    // returns count of items in cart
    // 	for example 2 chips; 3 pepsi -- would return 5
    int getItemCount() const;

    // returns the index position of the item in the cart
	//
    //		use a for loop to iterate through the cart looking for an
    //			item with the value of the name parameter
    //
    //		if the item is found,
    //			the index position returned will be less than cart.size()
    //		otherwise
    //			the index will be equal to cart.size()
    int findItemInCart(string name);

 	// Will add the item to the cart but will need to check
 	// if item is already in cart (use findItemInCart)
 	//
 	// if item in already in cart
 	//		print appropriate message see sample runs
 	// else
 	//		add item
 	//		print appropriate message see sample runs
 	void addItemToCart(Item item);

 	// The next two functions will allow change of quantity or change of price
 	//	of an existing item
 	//
 	// Use "findItemInCart" to get the index position
 	//
 	// If item is not in cart
 	//		print appropriate message
 	// else
 	//		update the item's quantity or price
 	//		print appropriate message
    void changeItemQuantity(string name, int quantity);
    void changeItemPrice(string name, double price);


    // Use "findItemInCart" to locate the position of the item
    //
	// If item is not in cart
	//		print appropriate message
	// else
 	//		remove the item using vector "erase" function using index returned
 	//			need to use cart.begin() + index with this function
 	//		print appropriate message
    void removeItemFromCart(string name);


    // refer to sample runs for formatting of this output
    void outputCartInfo();

private:
    string customerName;
    string currentDate;
    vector<Item> cart;
};

#endif