//gVector.
#pragma once
#include <vector>


using namespace std;


template <typename T>
class gVector : public vector<T> //finish inheritance
{
public:
		//gVector 2-arg constructor
		gVector(int low, int high);

		/* operator [] verifies that lower <= i <= upper.
			if not, it throws the indexRangeError exception
			returns the component of type T at position i.
		*/
		T& operator[](int i);

		// resize vector and reset range for gVector instance [lowIndex, highIndex]
		void resize(int lowIndex, int highIndex);


private:
		int lower;
		int upper;
};
#include "gVector.cpp"