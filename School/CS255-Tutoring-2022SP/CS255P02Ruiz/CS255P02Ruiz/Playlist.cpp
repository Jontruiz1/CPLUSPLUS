// Playlist.cpp -- MOST FUNCTIONS TO BE COMPLETED -- READ COMMENTS
// DO NOT INCLUDE ANYTHING OTHER THAN THESE LIBRARIES/CLASSES
#include <iostream>
#include "Playlist.h"
using namespace std;

// ************************** TO BE COMPLETED ******************************************
//Default and only constructor -- call private function init
Playlist::Playlist() {
	init();
}

// ************************** TO BE COMPLETED ******************************************
//Destructor -- call private function eraseList with head
Playlist::~Playlist() {
	eraseList(head);
}

// ************************** TO BE COMPLETED ******************************************
int Playlist::getNodeCount() {
	return nodeCount;
}

// ************************** TO BE COMPLETED ******************************************
//Add a SongNode to the front of the list
void Playlist::insertFront(SongNode* songNode) {

	songNode->setNext(head);
	head = songNode;

}

// ************************** TO BE COMPLETED ******************************************
//Remove an SongNode from the list; if the value doesn't exist in the list return false;
//   otherwise search for the SongNode, adjust pointers, and return true.
bool Playlist::remove(string id) {

	if (!contains(id)) {
		return false;
	}
	
	SongNode* curr = head;
	SongNode* prev = nullptr;

	while (curr->getUniqueID() != id) {
		prev = curr;
		curr = curr->getNext();
	}

	if (prev == nullptr) {
		head = head->getNext();
	}
	else {
		prev->setNext(curr->getNext());
		curr = nullptr;
	}

	--nodeCount;
	return true;

}

// ************************** TO BE COMPLETED ******************************************
//This function is the most complicated
//   songPosition and newPosition values have been validated in main
//		before this function is called
void Playlist::changeSongPosition(int songPosition, int newPosition) {

	// STEP 1: Find songNode that is at songPosition
	int pos = 1;
	SongNode* curr = head;
	SongNode* prev = nullptr;
	SongNode* songNode = nullptr;
	while (pos != songPosition) {
		prev = curr;
		curr = curr->getNext();
	}
	songNode = curr;

	// STEP 2: Remove songNode at songPosition from list. Keep reference to that songNode.
	remove(songNode->getUniqueID());

	// If songPosition was 1, song being moved was the head of the list
	//		so change what head points to
	// otherwise
	//		find the node before songNode in the list and adjust that node's
	//		next pointer

	// At this point songNode is no longer in the list

	if (newPosition == 1) {
		SongNode* temp = head;
		head = songNode;
		head->setNext(temp);
	}
	else {
		pos = 1;
		curr = head;
		prev = nullptr;
		while (pos != songPosition) {
			prev = curr;
			curr = curr->getNext();
			++pos;
		}
		insertAfter(prev, songNode);
	}
	// STEP 3: Insert song at newPosition
	//	If the newPosition was 1 ... the songNode will become the head of the list
	//		adjust pointers appropriately
	//	otherwise
	//		find the node that is before the newPosition
	//		it will be somewhere after original head position or at
	//		the end of the list
	//		call insertAfter
}

// ************************** TO BE COMPLETED ******************************************
// insertAfter ... inserts newNode after prevNode
void Playlist::insertAfter(SongNode* prevNode, SongNode* newNode) {
	SongNode* temp = prevNode->getNext();
	prevNode->setNext(newNode);
	newNode->setNext(temp);
	++nodeCount;
}

// ************************** TO BE COMPLETED ******************************************
// calculate total time in seconds in playlist
int Playlist::getTotalTime() {
	SongNode* curr = head;
	int runningTotal = 0;

	while (curr != nullptr) {
		runningTotal += curr->getSongLength();
		curr = curr->getNext();
	}

	return runningTotal;
}

// ************************** TO BE COMPLETED ******************************************
// Print out all nodes in the list
void Playlist::printPlaylist() {
	printTableHeadings();
	SongNode* curr = head;
	int pos = 1;
	while (curr != nullptr) {
		printTableRow(curr, pos);
		curr = curr->getNext();
		++pos;
	}
}

// ************************** TO BE COMPLETED ******************************************
// Print out all nodes in the list with the artist's name
void Playlist::printByArtist(string artist) {
	printTableHeadings();
	SongNode* curr = head;
	int pos = 1;
	while (curr != nullptr) {
		if (curr->getArtistName() == artist) {
			printTableRow(curr, pos);
		}
		++pos;
	}
}

// ************************** TO BE COMPLETED ******************************************
// Search to see if list contains the uniqueID
bool Playlist::contains(const string& id) {
	SongNode* curr = head;

	while (curr != nullptr) {
		if (curr->getUniqueID() == id) {
			return true;
		}
		curr = curr->getNext();
	}
	return false;
}

// ************************** TO BE COMPLETED ******************************************
// Clear the list -- remove all nodes and initialize the playlist again
void Playlist::clearList() {
}

// ************************** TO BE COMPLETED ******************************************
// Set up linked list starting values
void Playlist::init() {

	head = nullptr;
	nodeCount = 0;

}

// ************************** TO BE COMPLETED ******************************************
// Delete all allocated objects
void Playlist::eraseList(SongNode* head) {
}

// COMPLETED -- DO NOT CHANGE
// Print headings for playlist table
void Playlist::printTableHeadings() {
	cout << "\n\t------------------------- PLAYLIST ------------------------------" << endl;
	cout << "\t" << setw(5) << left << "Pos  ";
	cout << setw(12) << left << "Unique Id";
	cout << setw(20) << left << "Song";
	cout << setw(20) << left << "Artist";
	cout << setw(4) << left << "Time" << endl;
}

// COMPLETED -- DO NOT CHANGE
void Playlist::printTableRow(SongNode* song, int position) {
	cout << "\t" << setw(5) << left << position;
	cout << setw(12) << left << song->getUniqueID();
	cout << setw(20) << left << song->getSongName();
	cout << setw(20) << left << song->getArtistName();
	cout << setw(4) << right << song->getSongLength() << endl;
}
