#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <iostream> 
using namespace std;

class SmartPtr {
    Box* ptr; // Actual pointer 
public:
    // See the following for explanation of explicity keyword
    //  http://www.cs.technion.ac.il/users/yechiel/c++-faq/explicit-ctors.html

    explicit SmartPtr(Box* p = NULL) { ptr = p; }

    // Destructor 
    ~SmartPtr() { delete (ptr); }

    // Overloading dereferencing operator 
    Box& operator*() { return *ptr; }

    // Overload arrow operator to allow access to via pointer
    Box* operator->() { return ptr; }
};
#endif

