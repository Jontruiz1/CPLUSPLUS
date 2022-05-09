// EX03_Hashing_LinearProbing_Objectv3
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Person Class
class Student {
public:
	Student(string eNumber, string lName, string fName, double gpa , string major) {
		this->eNumber = eNumber;
		this->lName = lName;
		this->fName = fName;
		this->gpa = gpa;
		this->major = major;
	}

	string getENumber() { return eNumber; }

	string getLName() { return lName; }

	string getFName() { return fName; }



	friend ostream& operator<<(ostream& os, const Student& node) {
		cout << "eNumber: " << setw(2) << node.id << "  Name: " << left << setw(6) << node.name
			<< " Relationship: " << node.relationship;
		return os;
	}

private:
	string eNumber; // person id
	string lName;
	string fName;
	double gpa;
	string major;
}; //end Person class



template<typename K, typename V>
class HashNode {
public:
	//Constructor of hashnode
	HashNode(K key, V* value) {
		this->value = value;
		this->key = key;
	}

	V* getValue() { return value; }
	void setValue(V* value) { this->value = value; }

	K getKey() { return key; }
	void setKey(K key) { this->key = key; }

private:
	V* value;
	K key;
}; //end HashNode classs

template<typename K, typename V>
class HashTable {
public:
	HashTable() {
		capacity = 11;
		size = 0;
		ht = new HashNode<K, V> * [capacity];
		for (int i = 0; i < capacity; i++)
			ht[i] = nullptr;

		// node for empty after removal marking
		emptyAR = new HashNode<K, V>(-1, nullptr);
	}

	// returns bucket index
	int hash(const K key) { return key % capacity; }

	K hashKey(string str) {
		K hk = 0;
		for (int i = 0; i < str.length(); i++)
			hk = (7 * hk + str[i]);
		return hk;
	}

	bool emptySinceStart(int bucket) { return ht[bucket] == nullptr; }

	bool emptyAfterRemoval(int bucket) { return ht[bucket]->getKey() == -1; }

	//Inserts a node into hash table
	void hashInsert(K key, V* value) {
		HashNode<K, V>* temp = new HashNode<K, V>(key, value);

		// Apply hash function to find index for given key
		int bucket = hash(key); //get bucket index
		int bucketsProbed = 0;

		//find next empty bucket
		while (!(emptySinceStart(bucket)) && (!emptyAfterRemoval(bucket))
			&& (ht[bucket]->getKey() != key)) {
			bucket = (bucket + 1) % capacity;
			bucketsProbed++;
		}

		// Insert item into empty bucket
		if (emptySinceStart(bucket) || emptyAfterRemoval(bucket)) {
			ht[bucket] = temp;
			size++;
		}
	}

	//Removes a node from hash table
	V* hashRemove(K key) {
		int bucket = hash(key); //get bucket index
		int bucketsProbed = 0;

		//finding the node with given key
		while (!emptySinceStart(bucket) && bucketsProbed < capacity) {
			//if node found
			if (ht[bucket]->getKey() == key) {
				HashNode<K, V>* temp = ht[bucket]; //get node from hash table
				ht[bucket] = emptyAR; //insert emptyAR (after removal) node
				size--;
				return temp->getValue();
			}
			bucket = (bucket + 1) % capacity;
			bucketsProbed++;
		}

		return nullptr; //not found return null
	}

	// search for a given key
	V* hashSearch(K key) {
		int bucket = hash(key);
		int bucketsProbed = 0;

		while (!emptySinceStart(bucket) && bucketsProbed < capacity) {
			if (ht[bucket]->getKey() == key) {
				return ht[bucket]->getValue();
			}
			bucket = (bucket + 1) % capacity;
			bucketsProbed++;
		}

		//If not found return nullptr
		return nullptr;
	}

	// return number of buckets used in hash table
	int getSize() { return size; }

	// return true of all buckets unoccuppied
	bool isEmpty() { return size == 0; }

	void displayHashTable() {
		cout << "\nHash Table Contents: " << endl;
		for (int bucket = 0; bucket < capacity; bucket++) {
			if (emptySinceStart(bucket))
				cout << "\tBucket: " << bucket << " \tEmpty" << endl;
			else if (emptyAfterRemoval(bucket))
				cout << "\tBucket: " << bucket << " \tEmpty after removal" << endl;
			else
				cout << "\tBucket: " << bucket << " \t" << *(ht[bucket]->getValue()) << endl;
		}
	}

private:
	HashNode<K, V>** ht; // hash element array
	int capacity;
	int size;
	HashNode<K, V>* emptyAR;
}; //end HashTable class

// Driver functions //

template <typename V>
void displayResult(V* obj) {
	if (obj)
		cout << *obj << endl;
	else
		cout << "Key not found!" << endl;
}

int main() {
	HashTable<int, Student>* h = new HashTable<int, Student>;

	h->hashInsert(54, new Student(54, "Sally", "aunt"));
	h->hashInsert(26, new Student(26, "Fred", "brother"));
	h->hashInsert(93, new Student(93, "Mike", "uncle"));
	h->hashInsert(17, new Student(17, "Pat", "father"));
	h->hashInsert(77, new Student(77, "Sue", "sister"));
	h->hashInsert(44, new Student(44, "Mary", "mother"));
	h->displayHashTable();

	h->hashInsert(31, new Student(31, "John", "brother"));
	h->hashInsert(55, new Student(55, "Beth", "sister"));
	h->hashInsert(72, new Student(72, "Sam", "grandfather"));
	h->displayHashTable();

	cout << "\nExecuting h->hashRemove(77): ";
	displayResult(h->hashRemove(77));

	cout << "\nExecuting h->hashRemove(77): ";
	displayResult(h->hashRemove(77));

	h->displayHashTable();

	cout << "\nExecuting h->hashSearch(44): ";
	displayResult(h->hashSearch(44));
	
	cout << "\nExecuting h->hashSearch(77): ";
	displayResult(h->hashSearch(77));

	cout << "\nExecuting h->hashInsert(65, Person(65, \"Will\", \"brother\"))" << endl;
	h->hashInsert(65, new Student(65, "Will", "brother"));
	h->displayHashTable();

	return 0;
}