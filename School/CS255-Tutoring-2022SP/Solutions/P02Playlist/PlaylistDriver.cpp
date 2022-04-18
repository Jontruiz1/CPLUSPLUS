// SOLUTION: PlaylistDriver.cpp
#include <iostream>
#include <limits>
#include "Playlist.h"

using namespace std;

char getMenuChoice();
void processMenuChoice(char, Playlist&);
int getInteger();
bool isInteger(const string& s);

int main() {
	Playlist playlist;
	char choice = ' ';

	choice = getMenuChoice();

	while (choice != 'q') {
		processMenuChoice(choice, playlist);
		choice = getMenuChoice();
	}

	cout << "\n>>> Exiting Playlist <<<" << endl;

	return 0;
}

char getMenuChoice() {
	// Output menu option, prompt users for valid selection
	string menuOptions = "adpstocq";
	char choice = ' ';

	do {
		cout << "\n ************** PLAYLIST MENU **************************" << endl;

		cout << "\ta - Add song" << endl;
		cout << "\td - Remove song" << endl;
		cout << "\tp - Change position of song" << endl;
		cout << "\ts - Output songs by specific artist" << endl;
		cout << "\tt - Output total time of playlist (in seconds)" << endl;
		cout << "\to - Output full playlist" << endl;
		cout << "\tc - Clear playlist" << endl;
		cout << "\tq - Quit" << endl << endl;

		cout << "\tChoose option: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " *******************************************************" << endl;

	} while (menuOptions.find(choice) == string::npos);

	return choice;
}

void processMenuChoice(char choice, Playlist& playlist) {
	// Song* song = nullptr;
	SongNode* songNode = nullptr;
	string uniqueID;
	string songName;
	string artistName;
	int songLength = 0;

	int nodeCount = 0;
	int currPosition = 0;
	int newPosition = 0;

	// Call corresponding menu action
	switch (choice) {
	case 'a':
		// Add song to playlist
		// Prompt user for song information
		cout << "\n\tAdd Song - Enter song's unique ID: ";
		cin >> uniqueID;

		if (playlist.contains(uniqueID)) {
			cout << "\n\t<<< Duplicate unique ID - not added! >>>" << endl;
			break;
		}

		cin.ignore();
		cout << "\t\t   Enter song's name: ";
		getline(cin, songName);
		cout << "\t\t   Enter artist's name: ";
		getline(cin, artistName);
		cout << "\t\t   Enter song's length (in seconds): ";
		songLength = getInteger();
		//cin >> songLength;

		// Create a new node for playlist
		songNode = new SongNode(uniqueID, songName, artistName, songLength, nullptr);

		playlist.insertFront(songNode);
		playlist.printPlaylist();
		break;

	case 'd':
		// Remove song from playlist
		cout << "\n\tDelete Song - Enter song's unique ID: ";
		cin >> uniqueID;

		if (playlist.remove(uniqueID))
			cout << "\n\t<<< Successfully deleted song with unique ID " << uniqueID << " >>>" << endl;
		else
			cout << "\n\t<<< Song with unique ID " << uniqueID << " is not in playlist! >>>" << endl;

		playlist.printPlaylist();
		break;

	case 'p':
		// Change song position in playlist
		cout << "\n\tChange Song's Playlist Position - " << endl;

		nodeCount = playlist.getNodeCount();

		if (nodeCount <= 1) {
			cout << "\n\t<<< Playlist is empty or has only one song! >>>" << endl;
			break;
		}

		cout << "\t\tCurrent position (1 through " << nodeCount << "): ";
		currPosition = getInteger();

		if (currPosition < 1 || currPosition > nodeCount) {
			cout << "\n\t\t<<< Invalid current position!  >>>" << endl;
			break;
		}

		cout << "\t\tNew position (1 through " << nodeCount << "): ";
		newPosition = getInteger();

		if (newPosition < 1 || newPosition > nodeCount || newPosition == currPosition) {
			cout << "\n\t\t<<< Invalid new position! >>>" << endl;
			break;
		}

		playlist.changeSongPosition(currPosition, newPosition);

		cout << "\n\t<<< Song moved from position " << currPosition
			<< " to position " << newPosition << " >>>" << endl;

		playlist.printPlaylist();
		break;

	case 's':
		// Output playlist for specific artist
		// Consume newline and prompt user for output criteria
		//cin.ignore();
		cout << "\n\tSearch Playlist - Enter artist's name: ";
		getline(cin, artistName);
		playlist.printByArtist(artistName);
		break;

	case 't':
		// Output playlist total time
		cout << "\n\tPlaylist Total Time - " << playlist.getTotalTime() << endl;
		break;

	case 'o':
		playlist.printPlaylist();
		break;

	case 'c':
		playlist.clearList();
		break;
	}
}

int getInteger() {
	string str = "";
	getline(cin, str);

	while (!(isInteger(str))) {
		cout << "\t\t\t>>> Invalid integer - please enter an integer: ";
		getline(cin, str);
	}

	// convert str to an int
	return stoi(str);
}

bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p; //stores the first location of non-integer character

	// The C library function long int strtol(const char *str, char **endptr, int base) 
	//		converts the initial part of the string in str to a long int value according 
	//		to the given base, which must be between 2 and 36 inclusive, or be the special value 0.
	strtol(s.c_str(), &p, 10);

	return (*p == 0); // will be true if s contains an integer
}

