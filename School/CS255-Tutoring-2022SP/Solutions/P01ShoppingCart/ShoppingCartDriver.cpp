// SOLUTION: ShoppingCartDriver.cpp
#include <iostream>
#include "ShoppingCart.h"
using namespace std;

char getMenuChoice();
void processMenuChoice(char, ShoppingCart&);

int main() {
	string custName;
	char choice;

	cout << "**** Shopping Cart ****" << endl;

	cout << "\nEnter customer's name: ";
	getline(cin, custName);

	ShoppingCart myCart(custName);

	cout << "\nCustomer Name: " << myCart.getCustomerName();
	cout << "   Today's Date: " << myCart.getCurrentDate() << endl << endl;

	choice = getMenuChoice();

	while (choice != 'q') {
		processMenuChoice(choice, myCart);
		choice = getMenuChoice();
	}

	return 0;
}

char getMenuChoice() {
	string menuOptions = "adcpstoq";
	char choice = ' ';

	do {
		//cout << "\n" << menuOptions.find(choice) << endl; 

		cout << "\n-- Online Shopping Menu --" << endl;
		cout << "\ta - Add item to cart" << endl;
		cout << "\td - Remove item from cart" << endl;
		cout << "\tc - Change item quantity" << endl;
		cout << "\tp - Change item price" << endl;
		cout << "\to - Output shopping cart" << endl;
		cout << "\tq - Quit" << endl << endl;

		cout << "\tChoose option: ";
		cin >> choice;

		//cout << "\n" << menuOptions.find(choice) << endl;
	} while (menuOptions.find(choice) == string::npos);

	return choice;
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
	string name = "";
	double price = 0.0;
	int quantity = 0;

	switch (choice) {
	case 'a':
		cin.ignore();

		cout << "\n-- Add Item to Cart --" << endl;
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the item price: ";
		cin >> price;

		cout << "\tEnter the item quantity: ";
		cin >> quantity;

		theCart.addItemToCart(Item(name, price, quantity));

		break;

	case 'd':
		cin.ignore();

		cout << "\n-- Remove Item from Cart --" << endl;
		cout << "\tEnter name of item to remove: ";
		getline(cin, name);

		theCart.removeItemFromCart(name);

		break;

	case 'c':
		cin.ignore();

		cout << "\n-- Change Item Quantity --" << endl;
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the new quantity: ";
		cin >> quantity;

		theCart.changeItemQuantity(name, quantity);

		break;

	case 'p':
		cin.ignore();

		cout << "\n-- Change Item Price --" << endl;
		cout << "\tEnter the item name: ";
		getline(cin, name);

		cout << "\tEnter the new price: ";
		cin >> price;

		theCart.changeItemPrice(name, price);

		break;

	case 'o':
		cout << "\n-- Output Shopping Cart --" << endl;
		theCart.outputCartInfo();

		break;
	}
}