#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "MyMap.h"
#include "ScannerForIdents.h"
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

bool isReserved(const string);
void printOut(MyMap<const string, set<unsigned>>&  cross_ref, const string write_file, int maxLen);

int main() {
	
	
	int maxLen = INT_MIN;
	unsigned currLine;
	
	MyMap<const string, set<unsigned>> cross_ref;
	fstream inFile;

	const string inPath = "Input\\";
	string lastLex;
	string read_file;
	string write_file;
	
	
	cout << "Please enter file name to read (full name including extension): ";
	cin >> read_file;

	cout << "Please enter file name for output of cross-reference (ful name including extension): ";
	cin >> write_file;

	inFile.open(inPath + read_file);
	if (!inFile) {
		cerr << "Unable to open input file " << read_file;
		exit(1);
	}
	
	ScannerForIdents reader(inFile);
	while (reader.getIdent()) {
		currLine = reader.getNumberOfLines();
		lastLex = reader.getLastLexeme();
		maxLen = static_cast<int>(lastLex.length()) > maxLen ? static_cast<int>(lastLex.length()) : maxLen;  // this line is just for the formatting of the output at the end

		if (!isReserved(lastLex)) {
			cross_ref[lastLex].insert(currLine);
		}
	}
	
	inFile.close();
	printOut(cross_ref, write_file, maxLen);
	
}

//checks if passed in lexeme is a reserved word
bool isReserved(const string lexeme){
	
	static set<string> reserved = { "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "class", "compl", "const", "const_cast", "continue", "default", "delete", "do", "double",
					"dynmaic_cast", "else", "enum", "explicit", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "not", "not_eq", "operator", "or", "or_eq", "private",
					"protected", "public", "register", "reinterpret-cast", "return", "short", "signed", "sizeof", "static", "static_cast", "struct", "switch", "template", "this", "throw", "true", "try",
					"typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq" }; //list of reserved words I guess

	return binary_search(reserved.begin(), reserved.end(), lexeme);

}

//prints out the cross_ref map
void printOut(MyMap<const string, set<unsigned>>& cross_ref, const string write_file, int maxLen) {
	
	int width;

	string outPath = "Output\\";
	ofstream oFile;
	
	oFile.open(outPath + write_file);
	if (!oFile) {
		cerr << "Unable to open output file " << write_file;
		exit(2);
	}

	for (auto itr = cross_ref.begin(); itr != cross_ref.end(); itr++) {
		oFile << (*itr).first;
		width = maxLen + 4 - static_cast<int>((*itr).first.length());
		oFile << setw(width);

		for (auto itl = (*itr).second.begin(); itl != (*itr).second.end(); itl++) {
			oFile << *itl << "   ";
		}
		oFile << endl;
	}

	oFile.close();
	cout << endl << "Cross reference information written to output file " << write_file;
}


