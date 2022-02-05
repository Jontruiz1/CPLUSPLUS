#include <iostream>
#include "BinarySearchTree.h"
#include "MyMap.h"

using namespace std;

//mymap tester
void myMapTester() {
	MyMap< const string, int> cross_ref;

	cout << "MyMap size: " << cross_ref.size() << endl;
	cross_ref.insert(OrderedPair<const string, int>("include", 1));
	cross_ref.insert(OrderedPair< const string, int>("namespace", 2));
	cross_ref.insert(OrderedPair< const string, int>("iostream", 3));
	cross_ref.insert(OrderedPair<const string, int>("std", 4));
	cross_ref.insert(OrderedPair<const string, int>("somethihng", 5));
	cout << "MyMap size: " << cross_ref.size() << endl;

	for (auto itr = cross_ref.begin(); itr != cross_ref.end(); itr++) {
		cout << (*itr).first << endl;
	}

	cout << endl;

	auto mitr = cross_ref.find("include");
	cout << (*mitr).first;
	cross_ref.erase(mitr);
	cout << endl << "include erased" << endl << endl;

	for (auto itr = cross_ref.begin(); itr != cross_ref.end(); itr++) {
		cout << (*itr).first << endl;
	}

	cout << endl;

	cross_ref.erase("namespace");
	for (auto itr = cross_ref.begin(); itr != cross_ref.end(); itr++) {
		cout << (*itr).first << endl;
	}

	cross_ref.erase(cross_ref.begin(), cross_ref.end());
	cout << cross_ref.size() << endl;
	cout << cross_ref.empty() << endl;

	cross_ref.insert(OrderedPair<const string, int>("string", 1));
	cross_ref.insert(OrderedPair<const string, int>("testing", 2));
	cross_ref.insert(OrderedPair<const string, int>("tester", 3));

	cout << cross_ref["tester"];
}