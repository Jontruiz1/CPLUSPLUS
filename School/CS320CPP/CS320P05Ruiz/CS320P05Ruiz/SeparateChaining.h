#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include "Utilities.h"
#include "MyHashFunctions.h" 
using namespace std;



extern unsigned int probes; //For analysis of hashtable

							// SeparateChaining Hash table class
							//
							// CONSTRUCTION: an approximate initial size or default of 101
							//
							// ******************PUBLIC OPERATIONS*********************
							// bool insert( x )       --> Insert x
							// bool remove( x )       --> Remove x
							// bool contains( x )     --> Return true if x is present
							// void makeEmpty( )      --> Remove all items

template <typename HashedObj>
class HashTableChaining
{
public:
	explicit HashTableChaining(int size = 101) : currentSize{ 0 }
	{
		theLists.resize(nextPrime(size));
		makeEmpty();
	}

	bool contains(const HashedObj& x) const
	{
		
		auto& whichList = theLists[myhash(x)];
		auto itr = whichList.begin();

		probes = 1;
		while (itr != whichList.end() && *itr != x) {
			probes++;
			itr++;
		}

		return itr != whichList.end();
		
	}

	void makeEmpty()
	{
		for (auto& thisList : theLists)
			thisList.clear();
	}

	bool insert(const HashedObj& x)
	{
		
		auto& whichList = theLists[myhash(x)];
		auto itr = whichList.begin();

		probes = 1;
		while (itr != whichList.end() && *itr != x) {
			probes++;
			itr++;
		}
		if (itr != whichList.end()) {
			return false;
		}
		whichList.push_back(x);

		/*
		 Rehash; see Section 5.5 DO NOT USE for this project
		if (++currentSize > theLists.size())
		rehash();
		*/

		return true;
		
		
	}

	bool insert(HashedObj&& x)
	{
		
		auto& whichList = theLists[myhash(x)];
		auto itr = whichList.begin();
		
		probes = 0;
		while (itr != whichList.end() && *itr != x) {
			probes++;
			itr++;
		}
		if (itr != whichList.end()) {
			return false;
		}
		
		whichList.push_back(std::move(x));
		// Rehash; see Section 5.5 DO NOT USE for this project
		/*if (++currentSize > theLists.size()) {
		rehash();

		}*/

		return true;
		
		
	}

	bool remove(const HashedObj& x)
	{
		
		auto& whichList = theLists[myhash(x)];
		auto itr = find(begin(whichList), end(whichList), x);
		

		if (itr == end(whichList))
			return false;

		whichList.erase(itr);
		--currentSize;
		return true;
	}
	size_t getNumBuckets() { return theLists.size(); }


private:
	vector<list<HashedObj>> theLists;   // The array of buckets holding Lists
	size_t  currentSize;

	void rehash()
	{
		vector<list<HashedObj>> oldLists = theLists;

		// Create new double-sized, empty table
		theLists.resize(nextPrime(2 * theLists.size()));
		for (auto& thisList : theLists)
			thisList.clear();

		// Copy table over
		currentSize = 0;
		for (auto& thisList : oldLists)
			for (auto& x : thisList)
				insert(std::move(x));
	}

	size_t myhash(const HashedObj& x) const
	{
		static hash<HashedObj> hf;  //Default hash functions for HashedObj = built-ins (e.g.int) is in xstddef
		//static   MY_HASH_FUNCTIONS::hash<HashedObj> hf;
		return hf(x) % theLists.size();
	}
};

#endif


