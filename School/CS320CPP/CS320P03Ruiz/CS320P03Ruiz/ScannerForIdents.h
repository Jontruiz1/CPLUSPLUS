#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class ScannerForIdents
{
public:
	explicit ScannerForIdents(fstream &fin) : numOfLines(0), numOfChars(0),
		numOfIdents(0), ch(' '), lexeme("") {
		fstreamObj = &fin;
		currentLineLen = 0;
		currentLinePos = 0;
	}
	int getIdent();
	unsigned int getNumberOfLines() { return numOfLines; }
	unsigned int getNumberOfChars() { return numOfChars; }
	unsigned int getNumberOfIdents() { return numOfIdents; }
	unsigned int getLastCharRead() { return ch; }
	string       getLastLexeme() { return lexeme; }
private:
	unsigned int numOfLines;
	unsigned int numOfChars;
	unsigned int numOfIdents;
	fstream *fstreamObj;
	char ch;
	string lexeme;
	string line;
	unsigned int currentLineLen;
	unsigned int currentLinePos;
	char getCh();
};



