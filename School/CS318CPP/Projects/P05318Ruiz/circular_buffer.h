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
		_current = 0;
		_capacity = cap;
		array<value_type, cap> c;
	};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN

	T& head() { return c[_head]; }
	T& tail() { return c[_tail]; }
	T const& head() const { return _head.to(T); }
	T const& tail() const { return _tail.to(T); }

	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables
	void push_back(T val) noexcept {
		
		c[_current] = val;
		_current++;
		_tail = _current != 0 ? _current - 1 : _capacity - 1; //if _current != 0 then _tail = _current - 1 else _tail = _capacity - 1

		if (!full()) {
			_size++;
		}
		else {
			_head++;
		}

		if (_current == _capacity) _current = 0;
	};

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}


		// COMPLETE THE REMAINDER OF THIS FUNCTION
		_head++;
		_size--;
		if (_head == _capacity) _head = 0;
	}

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept { return _size; }

	int capacity() noexcept { return _capacity; }

	bool empty() const noexcept { return _size <= 0; } //returns true if buffer is empty

	bool full() const noexcept { return _size >= _capacity; }  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		os << "Buffer Info: head: " << buf._head << ", tail: " << buf._tail << ", current: " << buf._current << ", capacity: " << buf.capacity() << ", size: " << buf.size() << endl;
		os << " Container: ";


		for (auto i = buf.begin(); i != buf.end(); i++) {
			os << *i << " ";
		}

		os << endl << endl;
		return os;
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
