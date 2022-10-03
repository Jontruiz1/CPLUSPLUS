// KLR_Functors:Bind01  Source: GeeksforGeeks
// In the code below, bind() modifies the call of a function 
//		to take 1 argument and returned the desired output. 

// C++ code to demonstrate bind() and placeholders
#include <iostream>
#include <functional> // for bind()
using namespace std;

// for placeholders
using namespace std::placeholders;

// Driver function to demonstrate bind()
void func(int a, int b, int c) {
	cout << (a - b - c) << endl;
}

int main() {
	// for placeholders
	using namespace std::placeholders;

	// Use of bind() to bind the function
	// _1 is for first parameter and assigned to 'a' in above declaration.
	// 2 is assigned to b
	// 3 is assigned to c
	auto fn1 = bind(func, _1, 2, 3);

	// 2 is assigned to a.
	// _1 is for first parameter and assigned to 'b' in above declaration.
	// 3 is assigned to c.
	auto fn2 = bind(func, 2, _1, 3);

	// calling of modified functions
	fn1(10);
	fn2(10);

	return 0;
}
