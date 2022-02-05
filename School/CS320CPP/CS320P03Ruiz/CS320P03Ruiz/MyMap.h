#pragma once
// MyMap: emphasizes the insertion and retrieval of keys
// with access to the values.

#include "BinarySearchTree.h"
#include "OrderedPair.h"

//STARTER CODE
//Jonathan RUiz

// implements a map containing key/value pairs.
// a map does not contain multiple copies of the same item.
// types V and Key must have a default constructor
template <typename Key, typename V>
class MyMap
{
public:

	typedef typename BinarySearchTree< OrderedPair<const Key, V> >::iterator map_iterator;
	typedef typename BinarySearchTree< OrderedPair<const Key, V> >::const_iterator const_map_iterator;
	// MyMap iterators are simply BinarySearchTree iterators. an iterator cannot
	// change the key in a tree node, since the key attribute
	// of a OrderedPair object in the tree is const

	typedef OrderedPair<const Key, V> value_type;
	// for programmer convenience

	MyMap();
	// default constructor. create an empty map

	MyMap(value_type *first, value_type *last);
	// build a map whose key/value pairs are determined by pointer
	// values [first, last)

	bool empty() const;
	// is the map empty?

	int size() const;
	// return the number of elements in the map

	map_iterator find(const Key& key);
	// search for item in the map with the given key
	// and return an iterator pointing at it, or end()
	// if it is not found

	const_map_iterator find(const Key& key) const;
	// constant version of find()

	V& operator[] (const Key& key);
	// if no value is associated with key, create a new
	// map entry with the default value V() and return a
	// reference to the default value; otherwise,
	// return a reference to the value already associated
	// with the key 

	OrderedPair<map_iterator, bool> insert(const value_type& kvpair);
	// if the map does not contain a key/value pair whose
	// key matches that of kvpair, insert a coy of kvpair
	// and return a OrderedPair object whose first element is an
	// map_iterator positioned at the new key/value pair and whose second
	// element is true. if the map already contains a key/value
	// pair whose key matches that of kvpair, return a OrderedPair
	// object whose first element is an map_iterator positioned at the
	// existing key/value pair and whose second element is false

	int erase(const Key& key);
	// erase the key/value pair with the specified key
	// from the map and return the number
	// of items erased (1 or 0)

	void erase(map_iterator pos);
	// erase the map key/value pair pointed by to pos

	void erase(map_iterator first, map_iterator last);
	// erase the key/value pairs in the range [first, last)

	map_iterator begin();
	// return an map_iterator pointing at the first member
	// in the map
	const_map_iterator begin() const;
	// constant version of begin()

	map_iterator end();
	// return an map_iterator pointing just past the last
	// member in the map
	const_map_iterator end() const;
	// constant version of end()

private:
	// MyMap implemented using a BinarySearchTree of key-value pairs
	BinarySearchTree<OrderedPair<const Key, V> > t;
};

template <typename Key, typename V>
MyMap<Key, V>::MyMap()
{}

template <typename Key, typename V>
MyMap<Key, V>::MyMap(value_type *first, value_type *last) :
	t(first, last)
{}

template <typename Key, typename V>
bool MyMap<Key, V>::empty() const
{
	return t.empty();
}

template <typename Key, typename V>
int MyMap<Key, V>::size() const
{
	//TO DO:
	return t.size();
}

template <typename Key, typename V>
typename MyMap<Key, V>::map_iterator MyMap<Key, V>::find(const Key& key)
{
	//TO DO:

	// pass an OrderedPair to BinarySearchTree find() that contains key as its
	// first member and V() as its second

	// search for item in the map with the given key
	// and return an iterator pointing at it, or end()
	// if it is not found


	return t.find(OrderedPair<Key, V>(key, V()));


	 
}

template <typename Key, typename V>
typename MyMap<Key, V>::const_map_iterator MyMap<Key, V>::find(const Key& key) const
{
	//TO DO: 

	// pass a OrderedPair to BinarySearchTree find() that contains key as its
	// first member and V() as its second
	//t.find(OrderedPair<Key, V>(key, V()));
	return t.find(OrderedPair<Key, V>(key, V()));
}

template <typename Key, typename V>
V& MyMap<Key, V>::operator[] (const Key& key)
{
	// build a OrderedPair object consisting of key
	// and the default value V()
	value_type tmp(key, V());
	// will point to a pair in the map
	map_iterator iter = t.insert(tmp).first;
	//TO DO: 

	return (*iter).second;
// try to insert tmp into the map. the map_iterator
// component of the pair returned by t.insert()
// points at either the newly created key/value
// pair or a pair already in the map. return a
// reference to the value in the pair

}


template <typename Key, typename V>
typename OrderedPair<typename MyMap<Key, V>::map_iterator, bool> MyMap<Key, V>::insert(typename const MyMap<Key, V>::value_type& kvpair)
{
	// t.insert() returns a pair<map_iterator,bool> object, not a
	// OrderedPair<map_iterator,bool> object

	//confused as to why it needs to be made into a pair if we already have an ordered pair and the ordered pair has the same member variables but it says make it a pair not an ordered pair so I made it a pair

	//TO DO:

	OrderedPair<map_iterator, bool> p = t.insert(kvpair);


	// build and return a OrderedPair<map_iterator,bool> object
	return OrderedPair<map_iterator, bool>(p.first, p.second);
}

template <typename Key, typename V>
int MyMap<Key, V>::erase(const Key& key)
{
	// pass a OrderedPair to BinarySearchTree erase() that contains key as its
	// first member and V() as its second

	// erase the key/value pair with the specified key
	// from the map and return the number
	// of items erased (1 or 0)

	//TO DO:
	
	return t.erase(OrderedPair<Key, V>(key, V()));

}

template <typename Key, typename V>
void MyMap<Key, V>::erase(map_iterator pos)
{
	//TO DO: 
	t.erase(pos);

}

template <typename Key, typename V>
void MyMap<Key, V>::erase(map_iterator first, map_iterator last)
{
	//TO DO: 
	t.erase(first, last);
}

template <typename Key, typename V>
typename MyMap<Key, V>::map_iterator MyMap<Key, V>::begin()
{
	//TO DO: 
	return map_iterator(t.begin());
	
}

template <typename Key, typename V>
typename MyMap<Key, V>::map_iterator MyMap<Key, V>::end()
{
	//TO DO: 
	return map_iterator(t.end());
}

template <typename Key, typename V>
typename MyMap<Key, V>::const_map_iterator MyMap<Key, V>::begin() const
{
	//TO DO: 
	return const_map_iterator(t.begin());
}

template <typename Key, typename V>
typename MyMap<Key, V>::const_map_iterator MyMap<Key, V>::end() const
{
	//TO DO:
	return const_map_iterator(t.end());
	
}


