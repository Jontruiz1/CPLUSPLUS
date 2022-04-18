// SOLUTION: Item.h
#ifndef __ITEM__
#define __ITEM__

#include <string>
using namespace std;

class Item {

public:
    Item(string name, double price, int quantity);

    void setItemName(string name);
    void setItemPrice(double price);
    void setItemQuantity(int quantity);

    string getItemName() const;
    double getItemPrice() const;
    int getItemQuantity() const;

    void outputItemInfo();

private:
    string itemName;
    double itemPrice;
    int itemQuantity;
};

#endif