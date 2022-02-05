#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string> 
#include "MyHashFunctions.h"
using namespace std;

unsigned nextPrime(int n);  //Support function
extern unsigned int probes; //For analysis of hashtable
							// Quadratic Probing Hash table class
							//
							// CONSTRUCTION: an approximate initial size or default of 101
							//
							// ******************PUBLIC OPERATIONS*********************
							// bool insert( x )       --> Insert x
							// bool remove( x )       --> Remove x
							// bool contains( x )     --> Return true if x is present
							// void makeEmpty( )      --> Remove all items
							// int hashCode( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTableQuad
{
public:
	explicit HashTableQuad(int size = 101) : array(nextPrime(size))
	{
		makeEmpty();
	}

	bool contains(const HashedObj& x) const
	{
		return isActive(findPos(x));
	}

	void makeEmpty()
	{
		currentSize = 0;
		for (auto& entry : array)
			entry.info = EMPTY;
	}

	bool insert(const HashedObj& x)
	{
		// Insert x as active
		int currentPos = findPos(x);
		if (isActive(currentPos))
			return false;

		array[currentPos].element = x;
		array[currentPos].info = ACTIVE;
		++currentSize;
		// Rehash; see Section 5.5 DO NOT USE for this project
		//if (++currentSize >  array.size() / 2) 
		//	rehash(); 

		return true;
	}

	bool insert(HashedObj&& x)
	{
		// Insert x as active
		int currentPos = findPos(x);
		if (isActive(currentPos))
			return false;

		array[currentPos] = std::move(x);
		array[currentPos].info = ACTIVE;
		++currentSize;
		// Rehash; Do not use for this project.
		/*if (++currentSize > array.size() / 2)
		rehash();*/

		return true;
	}

	bool remove(const HashedObj& x)
	{
		int currentPos = findPos(x);
		if (!isActive(currentPos))
			return false;

		array[currentPos].info = DELETED;
		return true;
	}

	enum EntryType { ACTIVE, EMPTY, DELETED };
	size_t getNumBuckets() { return array.size(); }
private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
			: element{ e }, info{ i } { }

		HashEntry(HashedObj&& e, EntryType i = EMPTY)
			: element{ std::move(e) }, info{ i } { }
	};

	vector<HashEntry> array;
	size_t currentSize;

	bool isActive(int currentPos) const
	{
		return array[currentPos].info == ACTIVE;
	}

	int findPos(const HashedObj& x) const
	{
		int offset = 1;
		unsigned currentPos = myhash(x);
		unsigned iteration = 0;

		probes = 1;
		while (array[currentPos].info != EMPTY &&
			array[currentPos].element != x)
		{
			if (++iteration > array.size()) {
				cerr << "Cannot find an empty bucket in Hash Table using Quadratic probe." << endl;
				exit(1);
			}
			probes++;
			currentPos += offset;  // Compute ith probe
			offset += 2;
			/*if (currentPos >=  array.size())
			currentPos -= array.size();*/
			currentPos = currentPos % array.size();
		}

		return currentPos;
	}

	void rehash()
	{
		vector<HashEntry> oldArray = array;

		// Create new double-sized, empty table
		array.resize(nextPrime(2 * oldArray.size()));
		for (auto& entry : array)
			entry.info = EMPTY;

		// Copy table over
		currentSize = 0;
		for (auto& entry : oldArray)
			if (entry.info == ACTIVE)
				insert(std::move(entry.element));
	}

	size_t myhash(const HashedObj& x) const
	{
		static hash<HashedObj> hf;  //Default hash functions for HashedObj = built-ins (e.g.int) is in xstddef
		//static   MY_HASH_FUNCTIONS::hash<HashedObj> hf;
		return hf(x) % array.size();
	}
};

#endif 


