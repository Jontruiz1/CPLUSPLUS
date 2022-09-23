/*  REQUIREMENTS NOTES:

	Functions that need to be written have a comment above the function or constructor

	Do not add any additional instance variables

	You may include the implementation/definition in this header file
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
		_size = 0;
		_head = 0;
		_tail = 0;
		// everything to 0
		_capacity = cap;

	};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN

	T& head() { }
	T& tail() { }
	T const& head() const {};
	T const& tail() const {};

	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables
	void push_back(T val) noexcept {

		c.at(_current) = val;
		_current++;
		// tail stays trailing behind current
		// if the buffer is full, then increase head
		// if current is greater than/equal to capacity, thats when we loop back to 0
		// increasing current and size until size is equal to capacity
		// then current goes back to 0
		// size stays the same when equal to capacity
		

	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
		// COMPLETE THE REMAINDER OF THIS FUNCTION
		
	}

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept { }

	int capacity() noexcept { }

	bool empty() const noexcept {} //returns true if buffer is empty

	bool full() const noexcept { }  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {

		os << "Buffer Info: head: " << buf._head;


		
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