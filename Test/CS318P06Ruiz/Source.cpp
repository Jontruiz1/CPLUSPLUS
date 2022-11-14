#include <iostream>
#include <assert.h>
#include "Polynomial.h"

using namespace std;

int main() {

	cout << "*** P07 Polynomial Driver Sample Run ***\n\n";
	Monomial<int> m1(1,5);
	Polynomial<int> p1(m1);
	Polynomial<int> p2;


	cin >> p2;
	cout << p2;
}