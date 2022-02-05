// NullPointer
#include <iostream>
using namespace std;

void print(int x)
{
	cout << "print(int): " << x << '\n';
}

void print(int* x)
{
	if (!x)
		cout << "print(int*): null\n";
	else
		cout << "print(int*): " << *x << '\n';
}

int main()
{
	int x(5);
	int* ptr{ &x };
	int* ptr2{ 0 };
	int* ptr3; // undefined

	print(x);
	print(*ptr);
	print(ptr);
	print(ptr2);
	ptr = nullptr;
	print(ptr);
	//print(ptr3); // error undefined
	print(nullptr);

	return 0;
}