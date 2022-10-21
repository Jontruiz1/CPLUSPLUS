//InventoryDriver.cpp
#include "InventoryManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

int inventoryChoice()
{
    //Ask the user for Inventory choice and return validated input
}

//DO THIS
//buy Widgets (check invalid input and reprompt if necessary)
void buyWidgets(InventoryManager* im)
{








}

//DO THIS
//sell Widgets and return the profit (check invalid input and reprompt if necessary)
double sellWidgets(InventoryManager* im)
{








}

bool mainMenu(InventoryManager* im)
{
    //Create and Get validated response from Main menu
    double profit = 0;

    if (menuChoice == 1)
    {
        buyWidgets(im);
        return 1;
    }
    else if (menuChoice == 2)
    {
        sellWidgets(im);
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout << setprecision(2) << fixed;

    int inv_choice = inventoryChoice();
    InventoryManager* im = new InventoryManager(inv_choice);

    bool ask = 1;
    while (ask)
    {
        ask = mainMenu(im);
    }

    double runningTotal = im->getTotalProfit();
    cout << "Your total profit for all transactions is $" << runningTotal << endl;

    delete im;
}
