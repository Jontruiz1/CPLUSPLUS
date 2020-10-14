#include <iostream>
#include "rectangle.h"

using std::cout;
using std::endl;

int main() {
	const int v = 5;
	const int* ptr = &v; 
	//declares pointer pointing to constant int
	//You can modify ptr itself but not v

	//*ptr = 5; //you can't do this
	ptr++; //you can do this

	int c = 10;
	int *const point = &c;
	//declares constant pointer pointing to an int.
	//Can't modify ptr, but can modify c

	*point = 5; //you can do this, sets c = 5
	//point++; //you can't do this


	//define Rectangle pointer
	Rectangle* rectPtr = nullptr;

	rectPtr = new Rectangle; 
	// this dynamically allocates a rectangle object
	//which means this pointer puts the object on the heap

	//store values
	rectPtr->setWidth(10.0);
	rectPtr->setLength(15.0);

	//you must delete object from memory at the end of program
	delete rectPtr;
	//then set the pointer to null
	rectPtr = nullptr;

	Rectangle kitchen; 
	//this gets built on the stack
	//calls the default constructor
	//once main ends, this will be deleted
}
