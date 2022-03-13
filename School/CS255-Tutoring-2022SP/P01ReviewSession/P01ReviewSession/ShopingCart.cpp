#include "ShoppingCart.h"
#include "DateUtility.h"

// no default constructor

    // constructor to initialize shopping cart object
    //	initialize currentDate with a call to getDateString()
    //		from DateUtility.h
ShoppingCart::ShoppingCart(string name) {
    currentDate = getDateString();
}

string getCustomerName() const; //returns customerName value
string getCurrentDate() const;	//returns currentDate value

// returns count of items in cart
// 	for example 2 chips; 3 pepsi -- would return 5
int getItemCount() const {
    cart.size();
}

// returns the index position of the item in the cart
//
//		use a for loop to iterate through the cart looking for an
//			item with the value of the name parameter
//
//		if the item is found,
//			the index position returned will be less than cart.size()
//		otherwise
//			the index will be equal to cart.size()
int findItemInCart(string name) {
    for (int i = 0; i < cart.size(); ++i){
        // if the item's name
        // at position i
        // in cart

        // equal to the name we passed
        // we return i

    }

    // when we get out of loop
    // we did not find the item

    // we can return cart.size();
}

// Will add the item to the cart but will need to check
// if item is already in cart (use findItemInCart)
//
// if item in already in cart
//		print appropriate message see sample runs
// else
//		add item
//		print appropriate message see sample runs
void addItemToCart(Item item) {
    // need to use findItemInCart

    // when do we know that we have found the item in the cart?
    // if findItemInCart returns something less than cart size
    // print out that it was already in cart

    // else
    //      add the item into the cart
    //      cart.push_back(item);
    //      print out the message



}

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
void changeItemQuantity(string name, int quantity) {

    int position = findItemInCart(name);

    // if the item is not in cart
    //  print the message

    // else
    //   Item curr = cart.at(position)
    //   curr.setItemQuantity


}
void changeItemPrice(string name, double price) {

}


// Use "findItemInCart" to locate the position of the item
//
// If item is not in cart
//		print appropriate message
// else
//		remove the item using vector "erase" function using index returned
//			need to use cart.begin() + index with this function
//		print appropriate message
void removeItemFromCart(string name) {
    int index = findItemInCart(name);

    // if item == cart size
    //      print message

    // else
    //      cart.erase(cart.begin() + index)
    // print message
}


// refer to sample runs for formatting of this output
void outputCartInfo() {

    // use some kind of loop
    // we're going until we reach the end of cart
    // variable before loop  called the running total
    //for (int i = 0; i < cart.size etc...)

    // Item item = cart.at(i)
    // item.outputItemInfo()
    // add the current item's price multiplied by the quantity
    // to the running total

    // outside of the loop
    // we can then just print out the running total


}