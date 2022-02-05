#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <iostream> 
using namespace std;

// Generic smart pointer class
template <class T>
class SmartPtr {
    T* ptr; // Actual pointer 
public:

    explicit SmartPtr(T* p = NULL) { ptr = p; }

    // Destructor 
    ~SmartPtr() { delete (ptr); }

    // Overloading dereferencing operator 
    T& operator*() { return *ptr; }

    // Overload arrow operator to allow access to via pointer
    T* operator->() { return ptr; }
};
#endif

