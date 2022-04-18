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

	// Asks user to enter customer name
	// Displays title, customer name, and date
	// choice = getMenuChoice();
	//
	// set up while loop to check for choice of 'q'
	//		if not 'q', processMenuChoice
	//		call getMenuChoice() again
	cout << "Enter customer's name: ";
	getline(cin, custName);
	ShoppingCart cart(custName);

	cout << endl << "Customer Name: " << cart.getCustomerName() << "    Today's Date: " << cart.getCurrentDate() << endl << endl;

	choice = getMenuChoice();
	while (choice != 'q') {
		processMenuChoice(choice, cart);
		choice = getMenuChoice();
	}

}

char getMenuChoice() {
	string menuOptions = "adcpstoq";
	char choice = ' ';
	
	// COMPLETE THIS FUNCTION
	//	Display the menu
	//	Consider using string function "find" to determine
	//		if the choice is one of the letters in menuOptions string above

	//  Once a "valid" choice is made, return the choice to "main()"

	while (menuOptions.find(choice) == string::npos) {
		choice = ' ';
		cout << "-- Online Shopping Menu --" << endl;
		cout << "\ta - Add item to cart" << endl;
		cout << "\td - Remove item from cart" << endl;
		cout << "\tc - Change item quantity" << endl;
		cout << "\tp - Change item price" << endl;
		cout << "\to - Ouput shopping cart" << endl;
		cout << "\tq - Quit" << endl << endl;

		cout << "\tChoose option: ";
		cin >> choice;
	}

	
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
		cin.ignore();
		// get the item name, price, quantity from user
		// call addItemToCart with an Item object as an argument
		cout << endl  << "-- Add Item to Cart --" << endl;
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the item price : ";
		cin >> price;

		cout << "\tEnter the item quanity: ";
		cin >> quantity;

		theCart.addItemToCart(Item(name, price, quantity));

		break;

	case 'd':
		// get the item name from user
		// call removeItemFromCart with name as the argument
		cin.ignore();
		cout << "-- Remove Item from Cart --" << endl;
		cout << "Enter name of item to remove: ";
		getline(cin, name);


		theCart.removeItemFromCart(name);

		break;

	case 'c':
		// get the item name and new quantity from user
		// call changeItemQuantity with name and new quantity as arguments
		cin.ignore();
		cout << "-- Change Item Quantity --" << endl;
		cout << "Enter the item name: ";
		getline(cin, name);
		
		cout << "Enter the new quantity: ";
		cin >> quantity;

		theCart.changeItemQuantity(name, quantity);

		break;

	case 'p':
		// get the item name and new price from user
		// call changeItemPrice with name and new price as arguments
		cin.ignore();
		cout << "-- Change Item Price --" << endl;
		cout << "Enter the item name: ";
		getline(cin, name);

		cout << "Enter the new price: ";
		cin >> price;

		theCart.changeItemPrice(name, price);

		break;

	case 'o':
		// display cart info -- see sample runs

		theCart.outputCartInfo();

		break;
	}
}