//P05: circular_buffer.h
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
	using value_type = T; //type T will be the data type in the Container

	CircularBuffer() : _head(0), _tail(0), _size(0), _current(0), _capacity(cap) {}

	T& head() { return c.at(_head); }

	T& tail() { return c.at(_tail); }

	T const& head() const { return c.at(_head); }

	T const& tail() const { return c.at(_tail); }

	void push_back(T val) noexcept {
		//if (_current >= _capacity)
		//	_current = 0;

		c.at(_current) = val;
		_current++;

		_tail = _current - 1;

		if (_size >= _capacity) {
			_size = _capacity;
			_head++;
			if (_head >= _capacity)
				_head = 0;
		}
		else {
			_size++;
		}

		if (_current >= _capacity)
			_current = 0;
	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}

		_head++;
		if (_head >= _capacity)
			_head = 0;

		_size--;
	}

	int size() const noexcept { return _size; }

	int capacity() noexcept { return _capacity; }

	int current() noexcept { return _current; }

	bool empty() const noexcept { return (size() <= 0); }

	bool full() const noexcept { return (int)size() >= _capacity; }

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		os << "Buffer Info: head: " << buf._head << ", tail: " << buf._tail << ", current: "
			<< buf._current << ", capacity: " << buf._capacity << ", size: " << buf.size();

		os << "\n  Container: ";
		for (auto ptr = buf.begin(); ptr != buf.end(); ++ptr) {
			os << *ptr << " ";
		}
		os << ("\n");

		return (os);
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
