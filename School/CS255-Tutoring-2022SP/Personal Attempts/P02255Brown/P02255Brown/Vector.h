#include <iostream>

using namespace std;

class CustomVector {
private:
	int capacity;
	int back;
	int* vect;

public:

	CustomVector() {
		back = 0;
		capacity = 0;
		vect = nullptr;
	}

	// output vector
	void print() {
		for (int i = 0; i < back; ++i) {
			cout << "Index: " << i + 1  << " Values: " << vect[i] << " " << endl;
		}
		cout << endl;
	}

	// function to create vector
	void createVector(int size) {
		vect = new int[size];
		capacity = size;
		back = 0;
	}

	//destroy vector
	void destroyVector() {
		delete[] vect;
	}
	

	// function to add an item to the end of the vector
	bool addVector(int item) {
		if (back > (capacity - 1)) {
			int size = back;
			int* newArray = new int[size * 2];
			int* oldArray = vect;
			for (int i = 0; i < size; i++) {
				newArray[i] = oldArray[i];
			}
			delete[] vect;
			capacity = size * 2;
			vect = newArray;
		}

		vect[back] = item;
		back++;
		return true;

	}

	// function to remove an item from the end of the vector
	bool removeVector() {
		if (back < 0) {
			cerr << "Error: No value is stored at the specified index";
			return false;
		}
		vect[back] = INT_MAX;
		--back;
		return true;

	}

	// function to add an item to a random spot in the vector
	bool addVectorRand(int item) {
		int randIndex = rand() % back;


		++back;

	}


	// function to remove an item from a random spot in the vector

	

	// function to return the item at a specified index
	int getItem(int index) {
		if (index < 0 || index > back+1) {
			cerr << "Error: No value is stored at the specified index";
			return false;
		}
		return vect[index - 1];
	}

	// function to return the size(capacity) of the vector
	int getCapacity() {
		return capacity;
	}

	// function to return the number of items in the vector
	int getSize() {
		return back;
	}


	
};