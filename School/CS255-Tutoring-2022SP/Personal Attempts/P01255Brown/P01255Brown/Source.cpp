
/*
Yahaira Gonzalez
CS255
Project 1: Structs
Program that allows the user to store integer variables at specific locations
*/
#include "Vector_Array.h"
#include <iostream>

using namespace std;

Vector* createVector(int size) {
    Vector* v = new Vector;
    int* i = new int[size];
    v->index = 0;
    v->items = i;
    v->capacity = size;
    return v;
}

void resizeVector(Vector* v) { //don't need to put it in the .h because the user doesn't necessarily need to access it thmselves
    int size = v->index;
    int* newArray = new int[size * 2];
    int* oldArray = v->items;
    for (int i = 0; i < size; i++) {
        newArray[i] = oldArray[i];
    }
    delete[] v->items;
    v->capacity = size * 2;
    v->items = newArray;
}


void deleteVector(Vector* v) {
    delete[] v->items;
    delete v;
}

void printVector(Vector* v) {
    int size = v->index;
    int* values = v->items;
    for (int i = 0; i < size; i++) {
        cout << "Index: " << i + 1 << " Values: " << values[i] << endl;
    }
}

int getSize(Vector* v) {
    return v->index;
}

int getCapacity(Vector* v) {
    return v->capacity;
}

int getItem(Vector* v, int loc) {
    //Is the location valid?
    int size = v->index;
    if (loc < 1 || loc > size + 1) {
        return 0; //any impossible result. could also be false because false returns a value of 0
    }
    return v->items[loc - 1]; //whatever item the user wants is in the subscript (-1) of the value they gave i.e. 4 == subscript 3
}

bool addVector(Vector* v, int item, int loc) {
    //Is the location valid?
    int size = v->index;
    if (loc < 1 || loc > size + 1) {
        return false;
    }

    //Is there room?
    int maxSize = v->capacity;
    if (size == maxSize) {
        resizeVector(v);
    }

    //Make a hole
    int* values = v->items;
    for (int i = size; i >= loc; i--) {
        values[i] = values[i - 1];
    }
    values[loc - 1] = item;
    v->index++;
    return true;
}

bool removeVector(Vector* v, int loc) {
    //Is location valid?
    int size = v->index;
    if (loc < 1 || loc > size + 1) {
        return false;
    }

    //Fill in the blank
    int* values = v->items;
    for (int i = loc; i < size; i++) {
        values[i - 1] = values[i];
    }

    v->index--;
    return true;
}

bool setVector(Vector* v, int item, int loc) {
    //Is location valid?
    int size = v->index;
    if (loc < 1 || loc > size + 1) {
        return false;
    }

    //Set the value
    v->items[loc - 1] = item;
}

bool addVector(Vector* v, int item) {
    int size = v->index + 1;
    return addVector(v, item, size);
}

bool removeVector(Vector* v) {
    int size = v->index;
    return removeVector(v, size);
}


int main() {
    //Test creation of Vector
    Vector* v = createVector(2);
    cout << "Vector Capacity: " << getCapacity(v) << endl;


    //Add values in several ways
    addVector(v, 13);
    addVector(v, 11);
    addVector(v, 12, 2);
    cout << "Print Vector. Should be 13/12/11" << endl;
    printVector(v);
    cout << "Size: " << getSize(v) << " Capacity: " << getCapacity(v) << endl;

    //Add a few more values
    addVector(v, 10);
    addVector(v, 14, 1);
    addVector(v, 13, 6);
    cout << "Print Vector. Should be 14/13/12/11/10/13" << endl;
    printVector(v);
    cout << "Size: " << getSize(v) << " Capacity: " << getCapacity(v) << endl;
    addVector(v, 15, 8);

    //Remove from vector
    removeVector(v);
    removeVector(v, 2);
    if (!removeVector(v, 6)) {
        cout << "Nothing removed" << endl;
    }
    cout << "Printing Vector. Should be 14/12/11/10" << endl;
    printVector(v);

    cout << "The item at index 3 is: " << getItem(v, 3) << endl; // should be 11
    cout << "Setting item 3..." << endl;
    setVector(v, 8, 3);
    printVector(v);

    deleteVector(v);
}
