// SOLUTION: ShoppingCart.h
#ifndef __SHOPPING_CART__
#define __SHOPPING_CART__

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class ShoppingCart {
public:
    // no default constructor

    ShoppingCart(string name);

    string getCustomerName() const;
    string getCurrentDate() const;
    int getItemCount() const;
    int findItemInCart(string name);
    void addItemToCart(Item item);
    void changeItemQuantity(string name, int quantity);
    void changeItemPrice(string name, double price);
    void removeItemFromCart(string name);
    void outputCartInfo();

private:
    string customerName;
    string currentDate;
    vector<Item> cart;
};

#endif