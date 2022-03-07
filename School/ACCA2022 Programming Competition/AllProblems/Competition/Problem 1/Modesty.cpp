#include <iostream>

using namespace std;

/*

A natural number n is said to be modest if its digits can be partitioned into two natural numbers a and b such that: a

A natural number is said to be extremely modest if it is modest for all partitions a and b.

For example, 79 is modest. Let a= 7 and b= 9. 79 ÷ 9 has remainder 7.
218 is also modest. Let a= 2 and b= 18. 218 ÷ 18 has remainder 2.
1333 is extremely modest. 1333 ÷ 333 has remainder 1, and 1333 ÷ 33 has remainder 13.

Write a program that will accept a natural number at the console. For this number, it will produce a message corresponding to whether the number is modest or not: 'Not modest', 'Modest', or 'Extremely modest'.

You may assume that the input value is a natural number.

*/


void is_modst(int n) {

}

int main() {
	int n;
	cin >> n;

	cout << n % 10;

}