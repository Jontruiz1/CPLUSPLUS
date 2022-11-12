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

template<typename T, int cap, typename Container = std::array<T, cap> > //    LEAVE THIS ALONE - ROSSI
class CircularBuffer {
private:
	Container c; // will be std::array<T, cap>
	int _head; //oldest item in buffer
	int _tail; //newest item in buffer
	int _size; //# of elem in buffer
	int _current; //next write position in buffer
	int _capacity;

public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	//COMPLETE CONSTRUCTOR BELOW
	CircularBuffer() {
		_size = 0;
		_head = 0;
		_tail = 0;
		_current = 0;
		_capacity = cap;
	};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN
	//return .at head
	T& head() { return _head; };
	T& tail() { return _tail; };
	T const& head() const { return _head; };
	T const& tail() const { return _tail; };


	bool empty() const noexcept {
		if (size() <= 0) { return true; }

		else { return false; }
	};

	bool full() const noexcept {
		if (size() == _capacity) { return true; }	//returns true if buffer is empty
		//call size <= 0; 
		else { return false; }
	};

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept { return _size; }
	//return size

	int capacity() noexcept { return _capacity; }
	// return cap


	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables

	// push_back updates current
	// tail = current -1; want curent to point at nect right posision 
	void push_back(T val) noexcept {

		if (empty()) {

			_head = val;

			_tail = _head;

			_current++;
			_size++;
		}

		else if (size() == 1 || size() == 2 || size() == 3 || size == 4) {

			_current = val;

			_size++;
			_tail++;
			_current++;

		}
		else if (full()) {
			_current = 0;

			_head = val;

			_head++;
			_tail++;

		}

	};

	// COMPLETE THE REMAINDER OF THIS FUNCTION
		// two if statements 
		// if the head is grater than capacity, then head needs to become 0 , decrement size ; getting rid
		// of one 
	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}

		if (head() > _capacity) {

			head() = 0;
			_size = _size - 1;

			_current;
		}
	};


	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {

		os << "Buffer Info: head: " << buf._head << ", tail: " << buf._tail << ", current: " <<
			_current << ", capacity: " << _capacity << ", size: " << _size << endl;

		/*os << "  Container: ";
				for (const auto& value : buf) {
					cout << value << ' ';
				};*/

		return os;
	};
};
#endif
