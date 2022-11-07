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

		_head = 0;
		_size = 0;
		_tail = 0;
		_current = 0;
		_capacity = cap;

	};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN

	T& head() { return _head; }
	T& tail() { return _tail; };
	T const& head() const { return head(); };
	T const& tail() const { return tail(); };

	//COMPLETE THE push_back function -- circular buffer will overwrite
	//		oldest data if buffer is full.  This function must update
	//		appropriate instance variables
	void push_back(T val) noexcept {
		c[_current] = val;
		_current = (_current + 1) % cap;
		_tail = _current == 0 ? cap - 1 : _current - 1;
		
		if (_head == _current) {
			_head++;
		}
		if (_head >= cap) _head = 0;

		_size = _size >= cap ? cap : _size + 1;
	} 

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
		
		cout << "Popping: ";
		cout << c[_head];
		_head++;
		_size--;

		// COMPLETE THE REMAINDER OF THIS FUNCTION
	}

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept { 

		return _size;
	}

	int capacity() noexcept { 

		return _capacity;

	}

	bool empty() const noexcept { 

		return _size == 0;

	} //returns true if buffer is empty

	bool full() const noexcept { 

		return _size != 0;

	}  //returns true if buffer is full

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {

		os << "Buffer Info: head: " << buf.head() << ", tail: " << buf.tail() << ", current: " << buf._current << ", capacity: " << buf.capacity() << ", size: " << buf.size() << endl;
		os << "\tContainer: ";
		for (auto i : buf) { os << i << " "; }
		os << endl;
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
