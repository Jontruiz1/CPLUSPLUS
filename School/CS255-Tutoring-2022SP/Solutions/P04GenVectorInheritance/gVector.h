// SOLUTION: gVector.h
#ifndef _GVECTOR_
#define _GVECTOR_

#include <vector>
#include "CS255Exceptions.h"
using namespace std;

template <typename T>
class gVector : public vector<T> {
public:
	// Constructor vector has high-low+1 elements in range [low,high]
	gVector(int low, int high);

	// Overloaded operator [] verifies that lower <= i <= upper.
	// if not, it throws the indexRangeError exception
	T& operator[] (int i);

	// resize vector and set range to [lowIndex, highIndex]
	void resize(int lowIndex, int highIndex);

private:
	int lower;
	int upper;
};

///////////////////// MEMBER FUNCTION IMPLEMENTATIONS ////////////////////////

// Constructor
//	Initialize base class vector to have high-low+1 elements. 
//	Initialize lower and upper.
template <class T>
gVector<T>::gVector(int low, int high) :
	vector<T>(high - low + 1), lower(low), upper(high) {
	cout << "\nlow=" << low << " upper=" << upper << endl;
}


// Overloaded operator [] verifies that lower <= i <= upper.
// if not, it throws the indexRangeError exception
template <class T>
T& gVector<T>::operator[] (int i) {
	// verify that i is in range (lower <= i <= upper)
	if (i < lower || i > upper)
		throw indexRangeError("gVector: index range error", i, (upper - lower + 1));

	// call the base class index operator using this syntax
	return vector<T>::operator[] (i - lower);
}


template <class T>
void gVector<T>::resize(int lowIndex, int highIndex) {
	// use base class function resize()
	vector<T>::resize(highIndex - lowIndex + 1);

	// set new upper index
	lower = lowIndex;
	upper = highIndex;
}

#endif //_GVECTOR_

