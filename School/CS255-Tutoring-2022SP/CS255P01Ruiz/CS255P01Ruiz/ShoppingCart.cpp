#include <iostream>
#include "ShoppingCart.h"
#include "DateUtility.h"

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

int ShoppingCart::getItemCount() const  {
	return cart.size();
}

int ShoppingCart::findItemInCart(string name) {

	int i = 0;
	for (auto a : cart) {
		if (a.getItemName() == name) {
			return i;
		}
		++i;
	}
	return cart.size();
}

void ShoppingCart::addItemToCart(Item item) {
	if (findItemInCart(item.getItemName()) == cart.size()) {
		cart.push_back(item);
		cout << ">>> Item " << item.getItemName()  << " added to cart <<<" << endl;
	}
	else {
		cout << "Item " << item.getItemName() <<  " already in cart" << endl;
	}
}

void ShoppingCart::changeItemQuantity(string name, int quantity) {
	if (findItemInCart(name) == cart.size()) {
		cout << "Item " << name << " not in cart" << endl;
	}
	else {
		cart[findItemInCart(name)].setItemQuantity(quantity);
		cout << ">>> Item " << name << " quantity changed to " << quantity << " <<<" << endl;
	}
}

void ShoppingCart::changeItemPrice(string name, double price) {
	if (findItemInCart(name) == cart.size()) {
		cout << "Item " << name << " not in cart" << endl;
	}
	else {
		cart[findItemInCart(name)].setItemPrice(price);
		cout << ">>> Item " << name << " price changed to " << price << " <<<" << endl;
	}
}

void ShoppingCart::removeItemFromCart(string name) {

	if (findItemInCart(name) == cart.size()) {
		cout << "Item " << name << " not in cart" << endl;
	}
	else {
		cart.erase(cart.begin() + findItemInCart(name));
		cout << ">> Item " << name << " removed from cart <<<" << endl;
	}

}

void ShoppingCart::outputCartInfo() {
	cout << "-- Output Shopping Cart --" << endl;
	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	cout << "Number of Items: " << cart.size() << endl;
	cout << "--------------------" << endl;

	for (auto a : cart) {
		a.outputItemInfo();
	}
}