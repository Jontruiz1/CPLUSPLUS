//COMPLETE -- MAKE NO CHANGES

// SOLUTION: CS255Exceptions.h
#ifndef __CS255EXCEPTIONS__
#define __CS255EXCEPTIONS__

#include <sstream>
#include <string>
using namespace std;

class BaseException {
public:
	BaseException(const string& str = "") : msgString(str) {
		if (msgString == "")
			msgString = "Unspecified exception";
	}

	string what() const {
		return msgString;
	}

protected: // allows a derived class to access msgString.
	string msgString;
};

// failure to allocate memory (new() returns NULL)
class MemoryAllocationError : public BaseException {
public:
	MemoryAllocationError(const string& msg = "") : BaseException(msg) {}
};

// function argument out of proper range
class RangeError : public BaseException {
public:
	RangeError(const string& msg = "") : BaseException(msg) {}
};

// index out of range
class IndexRangeError : public BaseException {
public:
	IndexRangeError(const string& msg, int i, int size) : BaseException() {
		ostringstream indexErr;

		indexErr << msg << "  index " << i << "  size = " << size << ends;
		// indexRangeError can modify msgString, since it is in
		// the protected section of baseException
		msgString = indexErr.str();
	}
};

// attempt to erase from an empty container
class UnderflowError : public BaseException {
public:
	UnderflowError(const string& msg = "") : BaseException(msg) {}
};

// attempt to insert into a full container
class OverflowError : public BaseException
{
public:
	OverflowError(const string& msg = "") : BaseException(msg) {}
};

// error in expression evaluation
class ExpressionError : public BaseException {
public:
	ExpressionError(const string& msg = "") : BaseException(msg) {}
};

// bad object reference
class ReferenceError : public BaseException {
public:
	ReferenceError(const string& msg = "") : BaseException(msg) {}
};

// feature not implemented
class NotImplementedError : public BaseException {
public:
	NotImplementedError(const string& msg = "") : BaseException(msg) {}
};

// date errors
class DateError : public BaseException {
public:
	DateError(const string& first, int v, const string& last) : BaseException() {
		ostringstream dateErr;

		dateErr << first << ' ' << v << ' ' << last << ends;
		// dateError can modify msgString, since it is in
		// the protected section of baseException
		msgString = dateErr.str();
	}
};

// error in graph class
class GraphError : public BaseException {
public:
	GraphError(const string& msg = "") : BaseException(msg) {}
};

// file open error
class FileOpenError : public BaseException {
public:
	FileOpenError(const string& fname) : BaseException() {
		ostringstream fileErr;

		fileErr << "Cannot open \"" << fname << "\"" << ends;
		// fileOpenError can modify msgString, since it is in
		// the protected section of baseException
		msgString = fileErr.str();
	}
};

// error in graph class
class FileError : public BaseException {
public:
	FileError(const string& msg = "") : BaseException(msg) {}
};

#endif	// __CS255EXCEPTIONS__

