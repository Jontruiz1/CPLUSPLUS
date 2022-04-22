// TO BE COMPLETED:
//		isEmpty()
//		makeEmpty()
//		pop()
//		push()

// SOLUTION: MyStack.h -- Linked List Implementation
//
// CONSTRUCTOR: with no parameters.
//
// ******************PUBLIC OPERATIONS*********************
// void push( x )    --> Insert x
// void pop( )       --> Remove most recently inserted item
// T top( )          --> Return most recently inserted item
// T topAndPop( )    --> Return and remove most recently inserted item
// bool isEmpty( )   --> Return true if empty; else false
// void makeEmpty( ) --> Remove all items
// ******************ERRORS********************************
// UnderflowException thrown as needed.

#ifndef MY_STACK
#define MY_STACK

//#include <stdlib.h>
#include "CS255Exceptions.h"

template <typename T>
class myStack {
public:
	myStack();
	myStack(const myStack& rhs);
	~myStack();

	bool isEmpty() const;
	const T& top() const;

	void makeEmpty();
	void pop();
	void push(const T& x);
	T topAndPop();

	const myStack& operator=(const myStack& rhs);

private:
	struct StackNode {
		T    element;
		StackNode* next;

		StackNode(const T& theElement, StackNode* n = NULL)
			: element(theElement), next(n) { }
	};

	StackNode* topOfStack;
};

// Construct the stack.
template <typename T>
// Default/no-arg constructor
myStack<T>::myStack() {
	topOfStack = nullptr;
}

// Copy constructor.
template <typename T>
myStack<T>::myStack(const myStack<T>& rhs) {
	topOfStack = nullptr;
	*this = rhs;
}

// Destructor.
template <typename T>
myStack<T>::~myStack() {
	makeEmpty();
}

// Test if the Stack is logically empty.
//    Return true if empty, false, otherwise.
template <typename T>
bool myStack<T>::isEmpty() const {
					/**** TO BE COMPLETED *****/
	return (topOfStack == nullptr);
}

// Make the stack logically empty.
template <typename T>
void myStack<T>::makeEmpty() {
					/***** TO BE COMPLETED *****/
	StackNode* prev = topOfStack;
	StackNode* curr = topOfStack;
	while (curr != nullptr) {
		prev = curr;
		curr = curr->next;
		delete prev;
	}
	delete curr;
	topOfStack = nullptr;
}

// Return the most recently inserted item in the stack.
//    Throw an underflowError if empty.
template <typename T>
const T& myStack<T>::top() const {
	if (isEmpty())
		throw UnderflowError();
	return topOfStack->element;
}

// Remove the most recently inserted item from the stack.
//    Throw underflowError if the stack is empty.
template <typename T>
void myStack<T>::pop() {
					/***** TO BE COMPLETED *****/
}

// Return and remove the most recently inserted item
// from the stack.
template <typename T>
T myStack<T>::topAndPop() {
	T topItem = top();
	pop();
	return topItem;
}

// Insert x into the stack.
template <typename T>
void myStack<T>::push(const T& x) {
					/***** TO BE COMPLETED *****/
	if (topOfStack == nullptr) {
		topOfStack = new StackNode(x, nullptr);
	}
	else {
		StackNode* curr = topOfStack;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->element = new StackNode(x, nullptr);
	}
}

// Deep copy.
template <typename T>
const myStack<T>& myStack<T>::operator=(const myStack<T>& rhs) {
	if (this != &rhs) {
		makeEmpty();

		if (rhs.isEmpty())
			return *this;

		StackNode* rptr = rhs.topOfStack;
		StackNode* ptr = new StackNode(rptr->element);
		topOfStack = ptr;

		for (rptr = rptr->next; rptr != NULL; rptr = rptr->next)
			ptr = ptr->next = new StackNode(rptr->element);
	}
	return *this;
}

#endif // MY_STACK
