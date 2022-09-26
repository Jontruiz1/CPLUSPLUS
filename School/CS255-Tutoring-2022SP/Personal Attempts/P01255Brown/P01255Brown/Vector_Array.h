#pragma once
#if !defined VECTOR_ARRAY_H //include guard! important
#define VECTOR_ARRAY_H

struct Vector {
    int* items;
    int capacity;
    int index;
};

//Standards
Vector* createVector(int size);
/*
Function creates a list for number(integer) items
Pre: User must set the size of the list. List cannot equal zero
Post: Function will return the list wherever referenced with the size of the list that was set by user
*/
void deleteVector(Vector* v);
/*
Function removes("cleans up") the memory that is being used for the list
Pre: List must be created before being able to be deleted
Post: Function will delete the items in the list first, then it will delete the list itself
*/
void printVector(Vector* v);
/*
Function will print all the items in the list
Pre: List must already be created
Post: Function will print all the items in the list along with their place(index) in the list
*/

//Helper Functions
int getSize(Vector* v);
/*
Function retrieves the size of the list
Pre: List must already be created. Size must not be 0
Post: Function will return the size of the list
*/
int getCapacity(Vector* v);
/*
Function retrieves the capcity of the list
Pre:  List must already be created
Post: Function will return the capcity of the list
*/
int getItem(Vector* v, int loc);
/*
Function retrieves an item from the list of a specific location requested by the user
Pre: The location requested must be greater than 0 and less than or equal to the maximum size of the list
Post: Function will return the item in the location chosen by user. If the location does not meet preconditions, it will not return an item
*/

//Data Functions
bool addVector(Vector* v, int item, int loc);
/*
Function inserts a specific item into a specific location of the list
Pre: The location must be greater than 0 or less than or equal to the maximum size of the list
Post: Function will change the size of the list to accommodate the new item being added
*/
bool removeVector(Vector* v, int loc);
/*
Function removes the item of a specific location requested by the user
Pre: The location must be greater than 0 or less than or equal to the size of the list
Post: Function will remove the item of the specified location and change the size of the list to reflect the new set of items
*/
bool setVector(Vector* v, int item, int loc);
/*
Function will set an item in the list to another item
Pre: Location must be greater than 0 or less than or equal to the size of the list
Post: Function will replace the item in a specific location given by user to another item that was specified by user
*/

//Convience Functions
bool addVector(Vector* v, int item);
/*
Function adds item at the end of the list
Pre: List must be created
Post: Function will add the item specified by the user at the end of the list
*/
bool removeVector(Vector* v);
/*
Function removes item from the end of the list
Pre: List must be created
Post: Function will remove the last item of the list
*/

#endif