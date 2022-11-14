// Circular_Buffer.h -- starter code
/*  REQUIREMENTS NOTES:

	Functions that need to be written have a comment above the function or constructor

	Do not add any additional instance variables

	You may include the implementation/definition of functions in this header file
		-- no need to create a separate .cpp file

*/

#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	//COMPLETE CONSTRUCTOR BELOW
	CircularBuffer() {

	};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN

	T& head() {  }
	T& tail() { };
	T const& head() const { };
	T const& tail() const {  };

	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables
	void push_back(T val) noexcept {

		// put your value, val, at the position _current in the container
		// move _current forward (if it's not already at the capacity)
		// if it's at the capacity, move it back to the beginning of the container
		// tail is always just 1 behind the current
		// head only can incarease if the size == container

	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}

		// 'take out' the oldest element in the buffer.
		// head corresponds to the oldest element so just move the head forward in the buffer
		// decrease size

		// COMPLETE THE REMAINDER OF THIS FUNCTION
	}

	// COMPLETE THE FUNCTIONS BELOW
	// these functions should just return a single value
	int size() const noexcept {

	}

	int capacity() noexcept {

	}

	bool empty() const noexcept {


	} //returns true if buffer is empty

	bool full() const noexcept {


	}  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {

	}

private:
	Container c; // will be std::array<T, cap>
	int _head; //oldest item in buffer
	int _tail; //newest item in buffer
	int _size; //# of elem in buffer
	int _current; //next write position in buffer
	int _capacity;
};
#endif
