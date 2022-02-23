#include <iostream>

using namespace std;


class List {
private:
	int val;
	List* next;
public:
	List(int v) : val(v), next(nullptr) {};
	List() : val(0), next(nullptr) {};
	int getVal() {
		return val;
	}
	List* getNext() {
		return next;
	}
	void insert(List* node) {
		this->next = node;
	}
};


int main() {

	List* head = new List(5);
	head->insert(new List(10));
	List* curr = head;
	List* todel;

	while (curr != nullptr) {
		cout << curr->getVal();
		curr = curr->getNext();
	}
	curr = head;

	while (curr != nullptr) {
		todel = curr;
		curr = curr->getNext();
		delete todel;
	}

}