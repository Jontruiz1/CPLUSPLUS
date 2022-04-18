// SOLUTION: Playlist.h
#ifndef __PLAYLIST__
#define __PLAYLIST__
#include <iostream>
#include "SongNode.h"
using namespace std;

class Playlist {
public:
	//Default and only constructor
	Playlist();

	//Destructor
	~Playlist();

	//Copy Constructor -- not needed
	Playlist(const Playlist& rhs);

	int getNodeCount();

	//Add a SongNode to the front of the list
	void insertFront(SongNode* songNode);

	//Remove an SongNode from the list; if the value doesn't exist in the list return false;
	//   otherwise search for the SongNode, adjust pointers, and return true.
	bool remove(string id);

	void changeSongPosition(int songPosition, int newPosition);

	// insertAfter ... inserts newNode after prevNode
	void insertAfter(SongNode* prevNode, SongNode* newNode);

	// calculate total time in seconds in playlist
	int getTotalTime();

	// Print out all nodes in the list
	void printPlaylist();

	// Print out all nodes in the list
	void printByArtist(string artist);

	// Search to see if list contains a duplicate uniqueID
	bool contains(const string& id);

	// Clear the list -- remove all nodes
	void clearList();

private:
	// Set up linked list starting values
	void init();

	// Delete allocated objects
	void eraseList(SongNode* head);

	// Print headings for playlist table
	void printTableHeadings();

	void printTableRow(SongNode* song, int position);

	SongNode* head = nullptr;
	int nodeCount = 0;
};
#endif

