// KLR_Functors:Bind02  Source: GeeksforGeeks

// Property 1: The position of the placeholder determines the value position 
//		in the function call statement 

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

	// Second parameter to fn1() is assigned to 'a' in fun().
	// 2 is assigned to 'b' in fun
	// First parameter to fn1() is assigned to 'c' in fun().
	auto fn1 = bind(func, _2, 2, _1);
	cout << "The value of function is : ";
	fn1(1, 13);

	// First parameter to fn2() is assigned to 'a' in fun().
	// 2 is assigned to 'b' in fun
	// Second parameter to fn2() is assigned to 'c' in fun().
	auto fn2 = bind(func, _1, 2, _2);
	cout << "The value of function after changing placeholder position is : ";
	fn2(1, 13);

	return 0;
}
