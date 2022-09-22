// SOLUTION: Item.cpp
#include <iostream>
#include "Item.h"
using namespace std;

Item::Item(string name, double price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    return;
}

void Item::setItemName(string name) {
    itemName = name;
    return;
}

void Item::setItemPrice(double price) {
    itemPrice = price;
    return;
}

void Item::setItemQuantity(int quantity) {
    itemQuantity = quantity;
    return;
}

string Item::getItemName() const {
    return itemName;
}

double Item::getItemPrice() const {
    return itemPrice;
}

int Item::getItemQuantity() const {
    return itemQuantity;
}

void Item::outputItemInfo() {
    cout << "\t" << itemName << " " << itemQuantity << " @ $" << itemPrice
        << " = $" << itemPrice * itemQuantity << endl;
}
