// KLR_Functors:Bind03  Source: GeeksforGeeks

// Property 2: The number of placeholders determines the number of arguments 
//		required to pass in the function.
// 
//		We can use any no. of placeholders in the function call statement 
//		(obviously less than the maximum number of arguments). 
//		The rest of the values are replaced by the user-defined default values. 

#include <functional> // for bind()
#include <iostream>
using namespace std;

// for placeholders
using namespace std::placeholders;

// Driver function to demonstrate bind()
void func(int a, int b, int c){
	cout << (a - b - c) << endl;
}

int main() {
	// for placeholders
	using namespace std::placeholders;

	// 1 placeholder
	auto fn1 = bind(func, _1, 2, 4);
	// calling of function with 1 argument
	cout << "The value of function with 1 placeholder is : ";
	fn1(10);

	// 2 placeholders
	auto fn2 = bind(func, _1, 2, _2);
	// calling of function with 2 arguments
	cout << "The value of function with 2 placeholders is : ";
	fn2(13, 1);

	// 3 placeholders
	auto fn3 = bind(func, _1, _3, _2);
	// calling of function with 3 arguments
	cout << "The value of function with 3 placeholders is : ";
	fn3(13, 1, 4);

	return 0;
}
