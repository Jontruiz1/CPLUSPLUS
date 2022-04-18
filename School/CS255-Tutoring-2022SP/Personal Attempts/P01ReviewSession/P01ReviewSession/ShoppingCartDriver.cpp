// TO BE COMPLETED: ShoppingCartDriver.cpp
#include <iostream>
#include "ShoppingCart.h"
using namespace std;

char getMenuChoice();
void processMenuChoice(char, ShoppingCart&);

int main() {
	string custName;
	char choice;

	// COMPLETE THIS FUNCTION

	// we need to make a ShoppingCart

	// Asks user to enter customer 
	// cin custName
	ShoppingCart fred(custName);

	// Displays title, customer name, and date


	choice = getMenuChoice();

	processMenuChoice(choice, fred);

	// set up while loop to check for choice of 'q'
	//		if not 'q', processMenuChoice
	//		call getMenuChoice() again
}

char getMenuChoice() {
	string menuOptions = "adcpstoq";
	char choice = ' ';


	// some kind of if statement
	// check if we find choice in menuOptions
	// if that check == string::npos
	// we did not find the choice in string
	// keep looping

	// otherwise, we print out menu
	menuOptions.find(choice);

		// COMPLETE THIS FUNCTION
		//	Display the menu
		//	Consider using string function "find" to determine
		//		if the choice is one of the letters in menuOptions string above

		//  Once a "valid" choice is made, return the choice to "main()"


	return choice;
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
	string name = "";
	double price = 0.0;
	int quantity = 0;

	// COMPLETE THE "switch" below
	//	refer to sample runs for I/O formatting

	switch (choice) {
	case 'a':
		// get the item name, price, quantity from user
		// call addItemToCart with an Item object as an argument

		// getline/cin the item name
		// cin the price
		// cin the quantity

		// 



		theCart.addItemToCart(//Item(name, price, quantity//)

		break;

	case 'd':
		// get the item name from user
		// call removeItemFromCart with name as the argument


		// getline/cin the item name
		// theCart.removeItemFromCart(name);

		break;

	case 'c':
		// get the item name and new quantity from user
		// call changeItemQuantity with name and new quantity as arguments
		// getline name
		// cin quantity



		break;

	case 'p':
		// get the item name and new price from user
		// call changeItemPrice with name and new price as arguments
		break;

	case 'o':
		// display cart info -- see sample runs

		// calling outputCartInfo on thecart

		break;
	}
}