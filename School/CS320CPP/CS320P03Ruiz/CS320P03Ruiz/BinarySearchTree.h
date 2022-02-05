#pragma once
#include <iostream>
#include "exceptions_CS320.h"
#include "OrderedPair.h" 
using namespace std;

//STARTER CODE
// Jonathan Ruiz
template <typename Comparable>
class BinarySearchTree
{
private:
	//A Binary Search Tree (BST) is a recursive ADT: (1) it is empty or (2) a root node with left and right sub-BSTs. 
	//Thus, the BST is a recursive data structure.
	//To represent a BST instance each node structure for BSTs includes left and right pointers to
	//left and right sub-BST and also a pointer back to its parent node. This parent node pointer simplifies traversing BSTs.
	//Note: The root's parent is nullptr
	//To encapsulate a node we use struct is used for BST nodes and use the public data members for faster "get()" selection;
	//However, the BST_Node struc is private to only BST member functions (aka methods).
	//BST stores values using <= relationship defined for the instance of Comparable type. 
	struct BST_Node
	{
		Comparable element;
		BST_Node* left;
		BST_Node* right;
		BST_Node* parent;
		BST_Node(const Comparable& theElement, BST_Node* lt = nullptr, BST_Node* rt = nullptr, BST_Node* p = nullptr)
			: element(theElement), left(lt), right(rt), parent(p) { }
	};

public:
	class iterator;  //declaration of non-const iterator subclass... definition later. 

	 //First, the const_iterator subclass definition: 
	 //   this is used to traverse a tree with const data.
	 //   The const_iterator can be constructed from iterator class. 

public:
	class const_iterator
	{

	public:

		// default constructor
		const_iterator()
		{}

		// Conversion constructor: a const iterator converted to a const_iterator
		const_iterator(const iterator& pos) : nodePtr(pos.nodePtr)
		{}

		// Compare for equality of const_iterator objects. This only looks at whether the two iterator point at the same BST_Node instances.
		bool operator== (const const_iterator& rhs) const
		{
			return nodePtr == rhs.nodePtr;
		}

		bool operator!= (const const_iterator& rhs) const
		{
			return nodePtr != rhs.nodePtr;
		}

		// Access the BST_Node value of the element field. This simply returns a const reference to
		// the element value pointed to by nodePtr. 
		// Exception(s): ReferenceError with nodePtr is a nullptr. 
		//                  Error message: BinarySearchTree const_iterator operator* (): nullptr reference
		const Comparable& operator* () const
		{
			if (nodePtr == nullptr)
				throw
				referenceError("BinarySearchTree const_iterator operator* (): nullptr reference");
			return nodePtr->element;
		}

		// Preincrement: Advances the const_iterator to next element in sorted order according to < for Comparable type 
		const_iterator& operator++ ()
		{
			BST_Node* p;

			if (nodePtr == nullptr)
			{
				// ++ from end(). Go back to the root of the entire tree
				nodePtr = tree->root;

				// error: ++ requested for an empty tree
				if (nodePtr == nullptr)
					throw underflowError("BinarySearchTree const_iterator operator++ (): tree empty");

				// move to the smallest value in the tree,
				// which is the first node inorder
				while (nodePtr->left != nullptr)
					nodePtr = nodePtr->left;
			}
			else {
				if (nodePtr->right != nullptr)
				{
					// successor is the furthest left node of
					// right subtree
					nodePtr = nodePtr->right;

					while (nodePtr->left != nullptr)
						nodePtr = nodePtr->left;
				}
				else
				{
					// Reached here, so the left subtree was already traversed, and
					// there is no right subtree, so must move up the tree,
					// to look for a parent for which nodePtr is a left child, and then 
					// stopping if the parent becomes nullptr. A successor is a non-nullptr parent.
					// If parent is nullptr, the original node
					// was the last node inorder, and its successor
					// is the end of the list
					p = nodePtr->parent;

					while (p != nullptr && nodePtr == p->right)
					{
						nodePtr = p;
						p = p->parent;
					}

					// If we were previously at the right-most node in
					// the tree, nodePtr = nullptr, and the iterator specifies
					// the end of the list
					nodePtr = p;
				}
			}
			return *this;
		}

		// Post-increment: Advances the const_iterator to next element in sorted order according to <= for Comparable type,
		//                 however returns a const_iterator to the BST node that it originally referenced.
		const_iterator operator++ (int)
		{
			// save current const_iterator
			const_iterator tmp = *this;  //save for later

			// Move  forward to the next tree node
			++* this;

			// then return the previous value
			return tmp;
		}

		// This is the predecrement method. First move backward to largest value < current value
		// NOT DONE
		const_iterator& operator--()
		{
			//TO DO:
			BST_Node* p;

			if (tree->size() < 0) {
				throw underflowError("BinarySearchTree const_iterator operator--(): tree empty");
			}


			if (nodePtr == nullptr)
			{
				// -- from end(). Go back to the root of the entire tree
				nodePtr = tree->root;

				// move to the smallest value in the tree,
				// which is the first node inorder
				while (nodePtr->left != nullptr)
					nodePtr = nodePtr->left;
			}
			else {
				if (nodePtr->left != nullptr)
				{
					// successor is the furthest right node of
					// left subtree
					nodePtr = nodePtr->left;

					while (nodePtr->right != nullptr)
						nodePtr = nodePtr->right;
				}
				else
				{
					// Reached here, so the right subtree was already traversed, and
					// there is no left subtree, so must move up the tree,
					// to look for a parent for which nodePtr is a right child, and then 
					// stopping if the parent becomes nullptr. A predecessor is a non-nullptr parent.
					// If parent is nullptr, the original node
					// was the last node <, and its predecessor
					// is the end of the list
					p = nodePtr->parent;

					while (p != nullptr && nodePtr == p->left)
					{
						nodePtr = p;
						p = p->parent;
					}

					// If we were previously at the right-most node in
					// the tree, nodePtr = nullptr, and the iterator specifies
					// the end of the list
					nodePtr = p;
				}
			}

			return *this;
		}

		// The postdecrement method version
		const_iterator operator-- (int)
		{
			// save current const_iterator
			const_iterator tmp = *this;  //save for later

			// Move  forward to the next tree node
			--* this;

			// then return the previous value
			return tmp;
		}

	private:
		const BST_Node* nodePtr;
		const BinarySearchTree<Comparable>* tree;

		// The data member, nodePtr, is the current location in the tree. 
		// We can traverse the tree using left, right, and parent.
		// The data member, tree, is the address of the BinarySearchTree object associated
		// with this iterator; it must be used only to access the
		// root pointer, which is needed for ++ and --
		// when the iterator value is end()


		// The following is utilized to construct a const_iterator object to be used as a return value from
		// a BST_Node pointer
		const_iterator(const BST_Node* p, const BinarySearchTree<Comparable>* t) : nodePtr(p), tree(t)
		{}
		friend class BinarySearchTree<Comparable>;  //Allow BinarySearchTree access to these private data members. 
	};   //end of const_iterator class

	class iterator
	{


	public:

		// constructor
		iterator()
		{}

		// Comparison operators for iterators
		// Probably done?
		bool operator== (const iterator& rhs) const
		{
			//TO DO: 
			return nodePtr == rhs.nodePtr;
		}

		//prob done
		bool operator!= (const iterator& rhs) const
		{
			//TO DO:
			return !(nodePtr == rhs.nodePtr);
		}

		// The dereference operator. Returns a reference to
		// the value pointed to by nodePtr
		//done
		Comparable& operator* () const
		{
			//TO DO:
			if (nodePtr == nullptr)
				throw
				referenceError("BinarySearchTree iterator operator* (): nullptr reference");
			return nodePtr->element;
		}

		// This is the preincrement iterator operator. Move forward to next larger value
		//done
		iterator& operator++ ()
		{
			//TO DO:
			BST_Node* p;

			if (nodePtr == nullptr)
			{
				// ++ from end(). Go back to the root of the entire tree
				nodePtr = tree->root;

				// error: ++ requested for an empty tree
				if (nodePtr == nullptr)
					throw underflowError("BinarySearchTree iterator operator++ (): tree empty");

				// move to the smallest value in the tree,
				// which is the first node inorder
				while (nodePtr->left != nullptr)
					nodePtr = nodePtr->left;
			}
			else {
				if (nodePtr->right != nullptr)
				{
					// successor is the furthest left node of
					// right subtree
					nodePtr = nodePtr->right;

					while (nodePtr->left != nullptr)
						nodePtr = nodePtr->left;
				}
				else
				{
					// Reached here, so the left subtree was already traversed, and
					// there is no right subtree, so must move up the tree,
					// to look for a parent for which nodePtr is a left child, and then 
					// stopping if the parent becomes nullptr. A successor is a non-nullptr parent.
					// If parent is nullptr, the original node
					// was the last node inorder, and its successor
					// is the end of the list
					p = nodePtr->parent;

					while (p != nullptr && nodePtr == p->right)
					{
						nodePtr = p;
						p = p->parent;
					}

					// If we were previously at the right-most node in
					// the tree, nodePtr = nullptr, and the iterator specifies
					// the end of the list
					nodePtr = p;
				}
			}
			return *this;
		}

		// postincrement
		//done
		iterator operator++ (int) {
			//TO DO:
			iterator tmp = *this; //save for later

			// Move  forward to the next tree node
			++*this;

			// then return the previous value
			return tmp;

		}

		// predecrement. move backward to largest value < current value
		iterator& operator-- () {
			//TO DO: 
			BST_Node* p;

			if (tree->size() < 0) {
				throw underflowError("BinarySearchTree iterator operator--(): tree empty");
			}


			if (nodePtr == nullptr)
			{
				// -- from end(). Go back to the root of the entire tree
				nodePtr = tree->root;

				// move to the smallest value in the tree,
				// which is the first node inorder
				while (nodePtr->left != nullptr)
					nodePtr = nodePtr->left;
			}
			else {
				if (nodePtr->left != nullptr)
				{
					// successor is the furthest right node of
					// left subtree
					nodePtr = nodePtr->left;

					while (nodePtr->right != nullptr)
						nodePtr = nodePtr->right;
				}
				else
				{
					// Reached here, so the right subtree was already traversed, and
					// there is no left subtree, so must move up the tree,
					// to look for a parent for which nodePtr is a right child, and then 
					// stopping if the parent becomes nullptr. A predecessor is a non-nullptr parent.
					// If parent is nullptr, the original node
					// was the last node <, and its predecessor
					// is the end of the list
					p = nodePtr->parent;

					while (p != nullptr && nodePtr == p->left)
					{
						nodePtr = p;
						p = p->parent;
					}

					// If we were previously at the right-most node in
					// the tree, nodePtr = nullptr, and the iterator specifies
					// the end of the list
					nodePtr = p;
				}
			}

			return *this;
		}

		// postdecrement
		iterator operator-- (int)
		{
			//TO DO:
			iterator tmp = *this;
			--*this;
			return tmp;

		}

	private:

		// nodePtr is the current location in the tree. we can move
		// freely about the tree using left, right, and parent.
		BST_Node* nodePtr;
		// tree is the address of the BinarySearchTree object associated
		// with this iterator. it is used only to access the
		// root pointer, which is needed for ++ and --
		// when the iterator value is end()
		BinarySearchTree<Comparable>* tree;

		// used to construct an iterator return value from
		// an BST_Node pointer
		iterator(BST_Node* p, BinarySearchTree<Comparable>* t) : nodePtr(p), tree(t)
		{}
		friend class BinarySearchTree<Comparable>;
		friend class const_iterator;

	};   //end of iterator class

	// the interface for BinarySearchTree class 
public:
	BinarySearchTree();
	BinarySearchTree(Comparable* first, Comparable* last);
	BinarySearchTree(const BinarySearchTree<Comparable>& rhs);
	BinarySearchTree(BinarySearchTree<Comparable>&& rhs);
	~BinarySearchTree();

	const BinarySearchTree& operator=(const BinarySearchTree& rhs);
	const BinarySearchTree& operator=(BinarySearchTree&& rhs);
	bool empty() const;
	unsigned size() const;
	void printInOrder(ostream& out = cout) const;
	void makeEmpty();
	typename iterator find(const Comparable& x);
	typename const_iterator find(const Comparable& x) const;
	OrderedPair<typename BinarySearchTree<Comparable>::iterator, bool>  insert(const Comparable& x);
	unsigned erase(const Comparable& x);  //erases node x from tree ; if x is in tree returns 1; if not in tree returns 0
	void erase(typename BinarySearchTree<Comparable>::iterator);  //Fixed const_iterator to iterator
	void erase(iterator first, iterator last);
	// erase all items in the range [first, last).
	// Precondition: the tree must not be empty. 
	//               if the tree is empty, the function throws the underflowError exception.
	// Postcondition: the size of the tree decreases by the number of elements in the range [first, last)
	const Comparable& findMin() const;   //tree must be non-empty
	const Comparable& findMax() const;   //tree must be non-empty

	// return an iterator pointing to the first item of inorder traversal
	iterator begin()
	{
		BST_Node* curr = root;

		// if the tree is not empty, the first node
		// inorder is the farthest node left from root
		if (curr != nullptr)
			while (curr->left != nullptr)
				curr = curr->left;

		// build return value using private constructor
		return iterator(curr, this);
	}

	// constant version
	// maybe done?
	const_iterator begin() const
	{
		//TO DO:
		BST_Node* curr = root;

		// if the tree is not empty, the first node
		// inorder is the farthest node left from root
		if (curr != nullptr)
			while (curr->left != nullptr)
				curr = curr->left;

		// build return value using private constructor
		return const_iterator(iterator(curr, this));
	}

	// return an iterator pointing just past the last inorder element of tree
	iterator end()
	{
		// end indicated by an iterator with nullptr stnode pointer
		return iterator(nullptr, this);
	}

	// constant version
	// maybe done?
	const_iterator end() const
	{
		//TO DO:
		return const_iterator(iterator(nullptr, this));
	}

private:
	// helper functions
	void makeEmpty(BST_Node*& t);
	void printInOrder(BST_Node* t, ostream& out = cin) const;
	BST_Node* clone(BST_Node* t) const;
	BST_Node* findMin(BST_Node* t) const;
	BST_Node* findMax(BST_Node* t) const;

	//The tree
	BST_Node* root;
	unsigned numberOfNodes;

};




/******* DEFINITONS of MEMBER FUNCTIONS *********/

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() :root(nullptr), numberOfNodes(0) { }

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(Comparable* first, Comparable* last) : root(nullptr), numberOfNodes(0)
{
	Comparable* p = first;

	// insert each item in [first, last) into the tree
	while (p != last)
	{
		insert(*p);
		p++;
	}
}

/**
* Destructor for BinarySearchTree

*/
template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}

/*
* Copy Constructor for BinarySearchTree

*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree<Comparable>& rhs)
{
	root = clone(rhs.root);
	numberOfNodes = rhs.numberOfNodes;
}

// not done
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree<Comparable>&& rhs) {
	//TO DO:
	root = clone(rhs.root);
	numberOfNodes = rhs.numberOfNodes;
	delete rhs;
}

/*
* Assignment operator with deep copy (cloning of a tree).
*/
template<typename Comparable>
const BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& rhs)
{
	if (this != &rhs)
	{
		makeEmpty();    //erase *this target
		root = clone(rhs.root);
		numberOfNodes = rhs.numberOfNodes;
	}
	return *this;
}
template<typename Comparable>
const BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(BinarySearchTree&& rhs)
{
	std::swap(root, rhs.root);
	std::swap(numberOfNodes, rhs.numberOfNodes);
	return *this;
}
/* Accessor return the number of nodes in this tree
*/
template<typename Comparable>
unsigned BinarySearchTree<Comparable>::size() const { return numberOfNodes; }

/* Accessor method returns whether this BinarySearchTree
*/
template<typename Comparable>
bool BinarySearchTree<Comparable>::empty() const { return root == nullptr; }

/* Prints this tree's node values using inOrder traversal
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::printInOrder(ostream& out) const
{
	printInOrder(root, out);
}
/*
* Find an element in this tree.
* non-const version of find()
* Returns an iterator pointing to node if found and returns nullptr if not found
*
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::iterator  BinarySearchTree<Comparable>::find(const Comparable& x)
{

	BST_Node* t = root/*, *curr*/;   //Fixed: comment out unused variable. 

	// Starting at root, traverse the tree using t and 
	// terminate on on empty subtree or found value
	while (t != nullptr && !(x == t->element)) {
		if (x < t->element)
			t = t->left;
		else
			t = t->right;
	}

	// Exit loop when either go past a leaf or x is found in a BST_Node: t is nullptr if not found
	// if x is found, return a iterator with pointer t;
	// otherwise, return that the end() of tree was reached
	if (t != nullptr)
		return iterator(t, this);
	else
		return iterator(nullptr, this); //BinarySearchTree member function
										//.end() will return true if iterator has nullptr as first component
}
/*
*  const iterator version of find()
*/
//probably done?
template<typename Comparable>
typename BinarySearchTree<Comparable>::const_iterator  BinarySearchTree<Comparable>::find(const Comparable& x) const
{

	//TO DO: 
	BST_Node* t = root;

	// Starting at root, traverse the tree using t and 
	// terminate on on empty subtree or found value
	while (t != nullptr && !(x == t->element)) {
		if (x < t->element)
			t = t->left;
		else
			t = t->right;
	}

	// Exit loop when either go past a leaf or x is found in a BST_Node: t is nullptr if not found
	// if x is found, return a const_iterator with pointer t;
	// otherwise, return that the end() of tree was reached
	if (t != nullptr) {
		const_iterator tmp(iterator(t, this));
		return tmp;
	}
	else {
		const_iterator tmp(iterator(nullptr, this));
		return tmp; //BinarySearchTree member function
		//.end() will return true if iterator has nullptr as first component
	}
}

/*
* Insert x into this BinarySearchTree;
* Returns an OrderedPair: if second is true, the first element is an
*                         iterator object just inserted in tree
*                         if second is false, the first element is an
*                         iterator pointing to the node in the tree where x already exists

probably done
*/
template<typename Comparable>
typename OrderedPair<typename BinarySearchTree<Comparable>::iterator, bool> BinarySearchTree<Comparable>::insert(const Comparable& x) {

	BST_Node* t = root;
	BST_Node* p = nullptr;  //will hold the parent
	
	
	//if root is a nullptr, we make a new node with x as the element, increase size, and return
	if (root == nullptr) {
		root = new BST_Node(x);
		numberOfNodes++;
		return OrderedPair<BinarySearchTree<Comparable>::iterator, bool>(iterator(root, this), true);
	}

	//loops through the tree and until either node pointer is null or it's element is = to x
	while (t != nullptr && !(x == t->element)) {
		p = t; //sets the parent to what t points to currently
		t = x < t->element ? t->left : t->right; //if x < t->element t = t->left else t->right
	}


	//breaks out of loop, if t != nullptr, the element is already in the tree, return
	if (t != nullptr) {
		return OrderedPair<BinarySearchTree<Comparable>::iterator, bool>(iterator(t, this), false);
	}
	else {
		t = new BST_Node(x, nullptr, nullptr, p);


		if (x < p->element) {
			p->left = t;
		}
		else {
			p->right = t;
		}

		numberOfNodes++;
		return OrderedPair<BinarySearchTree<Comparable>::iterator, bool>(iterator(t, this), true);
	}
}

/*
* Erase (remove) node pointed at by iterator itr
* Precondition: tree is non-empty
*               and itr points to a BST_node in (this) tree
* Postcondition: BST_node is removed (erased) from (this) tree
*                and nodecount decreases by 1
* Exceptions Thrown: underflowError("BinarySearchTree::erase() : underflow") for empty tree
				   and referenceError("BinarySearchTree::erase(): invalid iterator") for bad itr
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::erase(typename BinarySearchTree<Comparable>::iterator itr)   //Fixed const_iterator to iterator
{
	// dNodePtr = pointer to node D that is deleted
	// pNodePtr = pointer to parent P of node D
	// rNodePtr = pointer to node R that replaces D
	BinarySearchTree<Comparable>::BST_Node* dNodePtr = itr.nodePtr, * pNodePtr, * rNodePtr;
	if (root == nullptr)
		throw  underflowError("BinarySearchTree::erase() : underflow"); //Fixed underFlowError to underflowError
	if (dNodePtr == nullptr)
		throw  referenceError("BinarySearchTree::erase(): invalid iterator");

	// assign pNodePtr the address of P
	pNodePtr = dNodePtr->parent;

	// If D has a nullptr pointer, the replacement node is the other child
	if (dNodePtr->left == nullptr || dNodePtr->right == nullptr)
	{
		if (dNodePtr->right == nullptr)
			rNodePtr = dNodePtr->left;
		else
			rNodePtr = dNodePtr->right;

		if (rNodePtr != nullptr)
			// the parent of R is now the parent of D
			rNodePtr->parent = pNodePtr;
	}
	// both pointers of dNodePtr are non-nullptr.
	else
	{
		// find and unlink replacement node for D.
		// starting at the right child of node D,
		// find the node whose value is the smallest of all
		// nodes whose values are greater than the value in D.
		// unlink the node from the tree.

		// pOfRNodePtr = pointer to parent of replacement node
		/*BST_Node<Comparable> */ BST_Node* pOfRNodePtr = dNodePtr;

		// first possible replacement is right child of D
		rNodePtr = dNodePtr->right;

		// descend down left subtree of the right child of D,
		// keeping a record of current node and its parent.
		// when we stop, we have found the replacement
		while (rNodePtr->left != nullptr)
		{
			pOfRNodePtr = rNodePtr;
			rNodePtr = rNodePtr->left;
		}

		if (pOfRNodePtr == dNodePtr)
		{
			// right child of deleted node is the replacement.
			// assign left subtree of D to left subtree of R
			rNodePtr->left = dNodePtr->left;
			// assign the parent of D as the parent of R
			rNodePtr->parent = pNodePtr;
			// assign the left child of D to have parent R
			dNodePtr->left->parent = rNodePtr;
		}
		else
		{
			// we moved at least one node down a left branch
			// of the right child of D. unlink R from tree by
			// assigning its right subtree as the left child of
			// the parent of R
			pOfRNodePtr->left = rNodePtr->right;

			// the parent of the right child of R is the
			// parent of R
			if (rNodePtr->right != nullptr)
				rNodePtr->right->parent = pOfRNodePtr;

			// put replacement node in place of dNodePtr
			// assign children of R to be those of D
			rNodePtr->left = dNodePtr->left;
			rNodePtr->right = dNodePtr->right;
			// assign the parent of R to be the parent of D
			rNodePtr->parent = pNodePtr;
			// assign the parent pointer in the children
			// of R to point at R
			rNodePtr->left->parent = rNodePtr;
			rNodePtr->right->parent = rNodePtr;
		}
	}

	// complete the link to the parent node.

	// deleting the root node. assign new root
	if (pNodePtr == nullptr)
		root = rNodePtr;
	// attach R to the correct branch of P
	else if (dNodePtr->element < pNodePtr->element)
		pNodePtr->left = rNodePtr;
	else
		pNodePtr->right = rNodePtr;

	// delete the node from memory and decrement tree size
	delete dNodePtr;
	numberOfNodes--;

}

/*
* Erase (remove) x from the tree.
* Returns 1 if x is removed ; returns 0 if x is not in tree
* No exceptions are thrown.
*/
//probably done
template<typename Comparable>
unsigned BinarySearchTree<Comparable>::erase(const Comparable& x) {

	// search tree for item
	// traverse the tree using t and starting at root
	// terminate on on empty subtree or found value
	
	//First I found the easiest and cleanest way to make this and then I made a much more complicated and redundant way to do this because I wasn't sure which one you wanted.
	//You said we should loop through the tree using that BST_Node but we already did that in find so the code kinda seemed a bit redundant. The code below works fine as far as I know
	
	auto itr = find(x); //auto because the find can return a const_iterator not just an iterator

	if (itr.nodePtr != nullptr) {
		erase(itr);
		return 1;
	}

	return 0;

	/*
	BST_Node* t = root;
	 
	//A lot of this code is honestly quite redundant
	while (t != nullptr && x != t->element) {
		if (x < t->element) {
			t = t->left;
		}
		else if (t->element < x){
			t = t->right;
		}
	}

	
	//if x isn't in the list or the list is empty we return
	if (t == nullptr) {
		return 0;
	}

	//if t has 2 children
	if (t->left != nullptr && t->right != nullptr) {
		erase(find(t->element));
		return 1;
	}
	//if t only has one child on the left
	else if (t->left != nullptr) {
		BST_Node* oldNode = t;
		t = t->left;
		if (oldNode == root) {
			root = t;
		}
		else {
			t->parent = oldNode->parent != nullptr ? oldNode->parent : nullptr; //relinking parent
			oldNode->parent->left = t; //relinking parent
		}
		delete oldNode; //delete the oldNode which is pointing to t
	}
	//if t only has one child on the right
	else if(t->right != nullptr){
		BST_Node* oldNode = t;
		t = t->right;
		if (oldNode == root) {
			root = t;
		}
		else {
			t->parent = oldNode->parent != nullptr ? oldNode->parent : nullptr; //relinking parent
			oldNode->parent->right = t; //relinking parent
		}
		
		delete oldNode; //delete the oldNode which is pointing to t
	}
	//if t has no children
	else {
		BST_Node* parent = t->parent;
		if (parent != nullptr) {
			if (t->element < parent->element) {
				parent->left = nullptr; //no more left child
			}
			else {
				parent->right = nullptr; //no more right child
			}
		}
		delete t; //delete t
	}
	numberOfNodes--; //get rid of a node
	if(size() == 0) root = nullptr; // if the size is 0 we set root to nullptr because we didn't do this above
	return 1;
	*/
	
	
}

/* erase(iterator first, iterator last)
 * Erases (removes) all items in the range [first, last) in inorder.
 * Precondition: the tree must be non-empty.
 * Postcondition: all elements in range [first, last)
 * the number of BST_Nodes in the tree decreases by
 * the number of elements in the range
 * Throws  underflow exceptionif tree is empty.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::erase(iterator first, iterator last)
{
	if (root == nullptr)
		throw
		underflowError("BinarySearchTree::erase(): tree is empty");

	iterator p = first;

	if (first == begin() && last == end())
	{
		//  
		// erase this entire BinarySearchTreetree from memory
		makeEmpty(root);

		// redundant for emphasis. tree is empty
		root = nullptr;
	}
	else
		// erase each item in a subrange of the tree
		while (p != last) {
			erase(p++);
			numberOfNodes--;
		}
}


/*
* Public member to find the largest item this tree.
* Return node containing the largest item.
* Precondition: tree must be non-empty otherwise ReferenceError exception is thrown
*/
template<typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax() const
{
	if (root == nullptr)
		throw  referenceError("BinarySearchTree::findMax(): Cannot find Max in empty tree");
	else return BinarySearchTree<Comparable>::findMax(root)->element;
}

/*
* Public member function to find the smallest item this tree.
* Return node containing the smallest item.
* Precondition: tree must be non-empty otherwise ReferenceError exception is thrown
*/
template<typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin() const
{
	if (root == nullptr)
		throw  referenceError("BinarySearchTree::findMax(): Cannot find Min in empty tree");
	else return BinarySearchTree<Comparable>::findMin(root)->element;
}
/*
* Private helper function to find the largest item in a subtree t.
* Return node containing the largest item.
* NOTE: if tree is empty, a nullptr is returned.
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::BST_Node* BinarySearchTree<Comparable>::findMax(BST_Node* t) const
{
	//TO DO:
	if (t != nullptr) {
		while (t->right != nullptr) {
			t = t->right;
		}
	}
	return t;
	
}
/*
* Private helper member function find the smallest item in a subtree t.
* Return node containing the smallest item.
* NOTE: if tree is empty, a nullptr is returned.
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::BST_Node* BinarySearchTree<Comparable>::findMin(BST_Node* t) const
{
	//TO DO: 
	if (t == nullptr) {
		return nullptr;
	}
	if (t->left == nullptr) {
		return t;
	}
	return findMin(t->left);

}

/*
* Private helper function to print a subtree rooted at pointer t. Prints to an ostream object
*/
//done
template<typename Comparable>
void BinarySearchTree<Comparable>::printInOrder(BST_Node* t, ostream& out) const
{
	//TO DO:

	if (t != nullptr) {
		printInOrder(t->left, out);
		out << t->element << " ";
		printInOrder(t->right, out);
	}

}
/*
* Member function to remove the BinarySearchTree from memory
* Postcondition: original tree is removed from memory, root is set to nullptr.
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
	if (root != nullptr)
	{
		makeEmpty(root);
	}
	root = nullptr;
}

/*
* Private helper function to make subtree empty.
* This function is used to delete a subtree in (this) tree
*/
//done?
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BST_Node*& t)
{
	//TO DO:
	if (t != nullptr) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		numberOfNodes--;
	}
	t = nullptr;

}

/*
* Private helper function to clone subtree.
* This generates a new tree with same structure and same node values as (this) tree
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::BST_Node* BinarySearchTree<Comparable>::clone(BST_Node* t) const
{
	//TO DO:
	//return clonedNode;
	if (t == nullptr) {
		return nullptr;
	}
	else {
		return new BST_Node(t->element, clone(t->left), clone(t->right));
	}
	

}
