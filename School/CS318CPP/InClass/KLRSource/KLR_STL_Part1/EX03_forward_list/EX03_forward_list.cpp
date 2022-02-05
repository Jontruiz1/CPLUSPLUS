// forward_list demo
#include<iostream> 
#include<forward_list> 
using namespace std;

int main()
{
	// Declaring forward list 
	forward_list<string> flist1;

	// Declaring another forward list 
	forward_list<string> flist2;

	// Assigning values using assign() 
	flist1.assign({string("Joe"), string("Jane"), string("Trevor"), string("Sam"), string("Sally") });

	// Assigning repeating values using assign() 
	// 5 elements with value 10 
	flist2.assign({ string("Fred"), string("Wilma") });

	// Displaying forward lists 
	cout << "The elements of first forward list are : ";
	for (string& a : flist1)
		cout << a << " ";
	cout << endl;

	cout << "The elements of second forward list are : ";
	for (string& b : flist2)
		cout << b << " ";
	cout << endl;

	cout << "First element of flist1: " << flist1.front() << endl;

	flist1.reverse();
	cout << "flist1 reversed: ";
	for (auto elem : flist1) {
		cout << elem << ' ';
	}
	cout << endl;

	return 0;
}
