// SOLUTION: ShoppingCart.cpp
#include <iostream>
#include <iomanip>
#include "DateUtility.h"
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart(string name) {
	customerName = name;
	currentDate = getDateString();
}

string ShoppingCart::getCustomerName() const {
	return customerName;
}

string ShoppingCart::getCurrentDate() const {
	return currentDate;
}

int ShoppingCart::getItemCount() const{
	unsigned i;
	int numItems = 0;

	for (i = 0; i < cart.size(); ++i) {
		numItems += cart.at(i).getItemQuantity();
	}

	return numItems;
}

int ShoppingCart::findItemInCart(string name) {
	int index;

	for (index = 0; index < cart.size(); ++index) {
		if (cart.at(index).getItemName() == name)
			break;
	}

	return index;
}

void ShoppingCart::addItemToCart(Item item) {
	string name = item.getItemName();
	int index = findItemInCart(name);

	if (index < cart.size()) {
		cout << "\n\t>>> Item " << name << " already in cart <<<" << endl;
	}
	else {
		cart.push_back(item);
		cout << "\n\t>>> Item " << name << " added to cart <<<" << endl;
	}
}

void ShoppingCart::changeItemQuantity(string name, int quantity) {
	int index = findItemInCart(name);

	if (index == cart.size()) {
		cout << "\n\t>>> Item " << name << " not in cart <<<" << endl;
	}
	else {
		cart.at(index).setItemQuantity(quantity);
		cout << "\n\t>>> Item " << name << " quantity changed to " << quantity << " <<<" << endl;
	}
}

void ShoppingCart::changeItemPrice(string name, double price) {
	int itemPos = findItemInCart(name);

	if (itemPos == cart.size()) {
		cout << "\n\t>>> Item " << name << " not in cart <<<" << endl;
	}
	else {
		cart.at(itemPos).setItemPrice(price);
		cout << fixed << setprecision(2);
		cout << "\n\t>>> Item " << name << " price changed to $" << price << " <<<" << endl;
	}
}

void ShoppingCart::removeItemFromCart(string name) {
	int index = findItemInCart(name);

	if (index == cart.size()) {
		cout << "\n\t>>> Item " << name << " not in cart <<<" << endl;
	}
	else {
		cart.erase(cart.begin() + index);
		cout << "\n\t>>> Item " << name << " removed from cart <<<" << endl;
	}
}

void ShoppingCart::outputCartInfo() {
	int i;
	double totalCost = 0.0;

	cout << fixed << setprecision(2);
	cout << "\t" << customerName << "'s Shopping Cart - " << currentDate << endl;
	cout << "\n\tNumber of Items: " << getItemCount() << endl;
	cout << "\t---------------------" << endl;
	if (cart.size() > 0) {
		for (i = 0; i < cart.size(); ++i) {
			cart.at(i).outputItemInfo();
			totalCost += cart.at(i).getItemPrice() * cart.at(i).getItemQuantity();
		}
		cout << endl << "\tTotal: $" << totalCost << endl;
	}
	else {
		cout << "\n\t>>> Shopping Cart is empty <<<" << endl;
	}
}