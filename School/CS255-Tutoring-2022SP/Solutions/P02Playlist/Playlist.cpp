// SOLUTION:  Playlist.cpp
#include <iostream>
#include "Playlist.h"
using namespace std;

//Default and only constructor
Playlist::Playlist() {
	init();
}

//Destructor
Playlist::~Playlist() {
	cout << "\n>>> Playlist destructor called <<<" << endl;
	eraseList(head);
}

//Copy Constructor -- not needed
Playlist::Playlist(const Playlist& rhs) {
	eraseList(head);
	init();
	*this = rhs;
}

int Playlist::getNodeCount() {
	return nodeCount;
}

//Add a SongNode to the front of the list
void Playlist::insertFront(SongNode* songNode) {
	if (head == nullptr) {
		head = songNode;
	}
	else {
		songNode->setNext(head);
		head = songNode;
	}

	nodeCount++;
}

//Remove an SongNode from the list;
//	if the value doesn't exist in the list return false;
//   otherwise search for the SongNode, adjust pointers, and return true.
bool Playlist::remove(string id) {
	if (!contains(id)) {
		return false;
	}

	SongNode* curr = head;
	SongNode* prev = head;

	// Don't really need to do the nullptr check --
	//		since we know it is in the list
	while (curr->getUniqueID() != id) {
		prev = curr;
		curr = curr->getNext();
	}
	// Remove from front of list
	if (curr == head) {
		head = curr->getNext();
		delete curr;
	}
	// Remove from middle or end
	else {
		prev->setNext(curr->getNext());
		delete curr;
	}

	nodeCount--;
	return true;
}

void Playlist::changeSongPosition(int fromPos, int toPos) {
	SongNode* fromPosNode = head;
	SongNode* prevNode;
	SongNode* insertPosNode;
	int listPos = 1;

	// STEP 1: find node that is at fromPos
	while ((fromPosNode != nullptr) && (listPos < fromPos)) {
		fromPosNode = fromPosNode->getNext();
		listPos++;
	}

	// STEP 2: Remove node at fromPos from list.

	// If fromPos was 1, fromPosNode must be head,
	//	so change the head of the list
	if (fromPosNode == head) {
		head = fromPosNode->getNext();
	}
	// find the node before fromPosNode in the list
	//   and adjust its next pointer
	else {
		prevNode = head; // node before the fromPosNode
		while (prevNode->getNext() != fromPosNode) {
			prevNode = prevNode->getNext();
		}

		// set prevNode's next to point to fromPosNode's next
		prevNode->setNext(fromPosNode->getNext());
	}

	// At this point songNode at fromPos is no longer in the list

	// STEP 3: Insert song at toPos
	if (toPos == 1) {  // Insert fromPosNode at head
		fromPosNode->setNext(head);
		head = fromPosNode;
	}
	else {  // Insert middle or end
		//prevNode = head; // trails insertPosNode
		insertPosNode = head;  //node before the node at toPos
		listPos = 1;

		// stop 1 before toPos which will be insertPosNode
		while ((insertPosNode != nullptr) && (listPos < (toPos - 1))) {
			//prevNode = insertPosNode;
			insertPosNode = insertPosNode->getNext();
			listPos++;
		}

		insertAfter(insertPosNode, fromPosNode);
	}
}

// insertAfter ... inserts newNode after prevNode
void Playlist::insertAfter(SongNode* prevNode, SongNode* newNode) {
	newNode->setNext(prevNode->getNext());
	prevNode->setNext(newNode);
}

// calculate total time in seconds in playlist
int Playlist::getTotalTime() {
	int totalTime = 0;

	SongNode* curr = head;

	while (curr != nullptr) {
		totalTime += curr->getSongLength();
		curr = curr->getNext();
	}

	return totalTime;
}

// Print out all nodes in the list
void Playlist::printPlaylist() {
	printTableHeadings();

	if (head == nullptr) {
		cout << "\n\t>>> Playlist is empty! <<<" << endl;
	}
	else {
		SongNode* curr = head;
		//Song* song;
		int position = 0;

		while (curr != nullptr) {
			position++;
			//song = curr->getSong();
			printTableRow(curr, position);
			curr = curr->getNext();
		}
	}
}

// Print out all nodes in the list
void Playlist::printByArtist(string artist) {
	printTableHeadings();

	if (head == nullptr) {
		cout << "\n\t>>> Playlist is empty! <<<" << endl;
	}
	else {
		SongNode* curr = head;
		//Song* song;
		int position = 0;

		while (curr != nullptr) {
			position++;
			//song = curr->getSong();

			if (curr->getArtistName() == artist) {
				printTableRow(curr, position);
			}
			curr = curr->getNext();
		}
	}
}

// Search to see if list contains a duplicate uniqueID
bool Playlist::contains(const string& id) {
	SongNode* curr = head;

	while (curr != nullptr) {
		if (id == curr->getUniqueID())
			return true;
		else
			curr = curr->getNext();
	}

	return false;
}


// Clear the list -- remove all nodes
void Playlist::clearList() {
	eraseList(head);
	init();
	cout << "\n\t>>> Playlist has been cleared! <<<" << endl;
	return;
}

// Set up linked list starting values
void Playlist::init() {
	head = nullptr;
	nodeCount = 0;
}

// Delete allocated objects
void Playlist::eraseList(SongNode* head) {
	SongNode* curr = this->head;
	SongNode* succ;

	while (curr != nullptr) {
		succ = curr->getNext();
		delete curr;
		curr = succ;
	}
}

// Print headings for playlist table
void Playlist::printTableHeadings() {
	cout << "\n\t------------------------- PLAYLIST ------------------------------" << endl;
	cout << "\t" << setw(5) << left << "Pos  ";
	cout << setw(12) << left << "Unique Id";
	cout << setw(20) << left << "Song";
	cout << setw(20) << left << "Artist";
	cout << setw(4) << left << "Time" << endl;
}

void Playlist::printTableRow(SongNode* song, int position) {
	cout << "\t" << setw(5) << left << position;
	cout << setw(12) << left << song->getUniqueID();
	cout << setw(20) << left << song->getSongName();
	cout << setw(20) << left << song->getArtistName();
	cout << setw(4) << right << song->getSongLength() << endl;
}
