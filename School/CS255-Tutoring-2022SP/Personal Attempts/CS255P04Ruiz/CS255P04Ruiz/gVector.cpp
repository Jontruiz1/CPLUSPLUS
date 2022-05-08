//gVector.cpp
#ifndef __G_VECTOR_CPP__
#define __G_VECTOR_CPP__
#include "gVector.h"
#include "CS255Exceptions.h"

// For all gVector<T> member function definitions, utilize base class vector
template <typename T>
//You must implement utilize vector<T>’s constructor(s)
gVector<T>::gVector(int low, int high):vector<T>((high - low) + 1), lower(low), upper(high) {
}

//Override vector<T>’s []
//You must implement
template <typename T>
T& gVector<T>::operator[] (int i) {
	if (i < lower || i > upper) {
		throw indexRangeError("gVector: index range error", i, (upper - lower));
	}

	return vector<T>::operator[] (i - lower);

}

//Overload vector<T>’s resize
//You must implement
template <class T>
void gVector<T>::resize(int lowIndex, int highIndex) {
	lower = lowIndex;
	upper = highIndex;
	vector<T>::resize(upper - lower + 1);z
	
}
#endif
