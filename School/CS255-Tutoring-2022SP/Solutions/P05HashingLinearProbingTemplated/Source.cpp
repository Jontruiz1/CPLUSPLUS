//P05_HashingTemplate
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


//Person Class
class Person {
public:
	Person() {}

	Person(int id, string name, string relationship) {
		this->id = id;
		this->name = name;
		this->relationship = relationship;
	}

	int getHashKey() { return id; }

	void setHashKey(int key) { id = key; };

	int getId() { return id; }

	string getName() { return name; }

	friend ostream& operator<<(ostream& os, const Person& node) {
		cout << "ID: " << setw(2) << node.id << "  Name: " << left << setw(6) << node.name
			<< " Relationship: " << node.relationship;
		return os;
	}

private:
	int id; // person id
	string name;
	string relationship;
}; //end Person class

//Book Class
class Book {
public:
	Book() {}

	Book(int isbn, string title, string author, int publicationYear, double price) {
		this->id = id;
		this->name = name;
		this->relationship = relationship;
		int isbn; // person id
		string title;
		string author;
		int publicationYear;
		double price;
	}

	int getHashKey() { return isbn; }

	void setHashKey(int key) { isbn = key; };

	int getIsbn() { return isbn; }

	string getTitle() { return title; }

	friend ostream& operator<<(ostream& os, const Book& book) {
		cout << "ID: " << setw(2) << book.id
			<< "  Name: " << left << setw(6) << book.title
			<< "  Author: " << book.author
			<< "  Published: " << book.publicationYear
			<< "  Price: " << book.price;
		return os;
	}

private:
	int id; // person id
	string title;
	string author;
	int publicationYear;
	double price;
}; //end Book class




// HashTable
template <class T>
class HashTable {
public:
	HashTable(int capacity) {
		this->capacity = capacity;
		size = 0;
		hashTable = new T[capacity];

		//set everything to empty
		for (int i = 0; i < capacity; i++)
			hashTable[i].setHashKey(EMPTY_SS);
	}

	// This implements hash function to find index for a key
	int hash(int key) { return key % capacity; }

	//Return size of hash table
	int getSize() { return size; }

	//Is hash table empty
	bool isEmpty() { return size == 0; }

	//Is hash table full
	bool isFull() { return size == capacity; }

	bool emptySinceStart(int bucket) { return hashTable[bucket].getHashKey() == EMPTY_SS; }

	bool emptyAfterRemoval(int bucket) { return hashTable[bucket].getHashKey() == EMPTY_AR; }

	bool hashInsert(T node) {
		// Apply hash function to find index for given key
		int bucket = hash(node.getHashKey());
		int bucketsProbed = 0;

		//find next free space
		while ((hashTable[bucket].getHashKey() != node.getHashKey()) && (bucketsProbed < capacity)) {
			// Insert item in next empty bucket
			if (emptySinceStart(bucket) || emptyAfterRemoval(bucket)) {
				hashTable[bucket] = node;
				size++;
				return true;
			}

			// Increment bucket index
			bucket = (bucket + 1) % capacity;
			// Increment number of buckets probed
			++bucketsProbed;
		}

		return false;
	}

	//Function to delete a node
	bool hashRemove(int key) {
		// Apply hash function to find index for given key
		int bucket = hash(key);
		int bucketsProbed = 0;

		while (!emptySinceStart(bucket) && bucketsProbed < capacity) {
			//finding the node with given key
			if (hashTable[bucket].getHashKey() == key) {
				//Mark this space as empty after removal
				hashTable[bucket].setHashKey(EMPTY_AR);
				// Reduce size
				size--;
				return true;
			}

			bucket = (bucket + 1) % capacity;
			bucketsProbed++;
		}

		return false;
	}

	T* hashSearch(int key) {
		// Apply hash function to find index for given key
		int bucket = hash(key);
		int bucketsProbed = 0;

		//finding the node with given key
		while (!emptySinceStart(bucket) && (bucketsProbed < capacity)) {
			//if node found return value
			if (!emptySinceStart(bucket) && hashTable[bucket].getHashKey() == key) {
				return &hashTable[bucket];
			}
			bucket = (bucket + 1) % capacity;
		}

		//If not found return 
		return nullptr;
	}

	void displayHashTable() {
		cout << "\nHash Table Contents: " << endl;
		for (int i = 0; i < capacity; i++) {
			if (emptySinceStart(i))
				cout << "\tBucket: " << i << " \tEmpty" << endl;
			else if (emptyAfterRemoval(i))
				cout << "\tBucket: " << i << " \tEmpty after removal" << endl;
			else
				cout << "\tBucket: " << i << " \t" << hashTable[i] << endl;
		}
	}

private:
	T* hashTable = nullptr;
	int capacity;
	int size;
	const int EMPTY_SS = -1;
	const int EMPTY_AR = -2;
}; //end HashTable class


void findPerson(HashTable<Person>& ht, int key) {
	cout << "\nSearching for key " << key << ":   ";

	Person* p = ht.hashSearch(key);

	if (p)
		cout << *p << endl;
	else
		cout << "Key not found" << endl;
}

int main() {
	HashTable<Person> ht(11);
	Person* p;

	ht.displayHashTable();

	ht.hashInsert(Person(54, "Sally", "aunt"));
	ht.hashInsert(Person(26, "Fred", "brother"));
	ht.hashInsert(Person(93, "Mike", "uncle"));
	ht.hashInsert(Person(17, "Pat", "father"));
	ht.hashInsert(Person(77, "Sue", "sister"));
	ht.hashInsert(Person(44, "Mary", "mother"));

	ht.displayHashTable();

	ht.hashInsert(Person(31, "John", "brother"));
	ht.hashInsert(Person(55, "Beth", "sister"));
	ht.hashInsert(Person(72, "Sam", "grandfather"));

	ht.displayHashTable();

	ht.hashRemove(77);
	cout << "\nRemoved key 77" << endl;
	ht.displayHashTable();

	findPerson(ht, 44);

	ht.hashInsert(Person(65, "Will", "brother"));
	cout << "\nInserted key 65" << endl;
	ht.displayHashTable();

	findPerson(ht, 33);

	return 0;
}