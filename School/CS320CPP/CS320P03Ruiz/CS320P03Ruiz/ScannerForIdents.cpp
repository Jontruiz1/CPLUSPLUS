#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "ScannerForIdents.h"
#include <list>
#include <algorithm>
using namespace std;
char ScannerForIdents::getCh() {
	if (currentLinePos == line.length()) {
		if (fstreamObj->eof()) return 0;
		line.clear();
		currentLinePos = 0; //reset the position in the current line and get next line
		while (!fstreamObj->eof() && (ch = fstreamObj->get()) != '\n') {
			line.push_back(ch);
			numOfChars++;
		}
		numOfLines++;
		if (ch == '\n') {
			numOfChars++;   //count the eoln char; could be at eof without eoln on last line
			line.push_back(ch);
		}
	}
	if (line.length() > 0)
		return ch = line[currentLinePos++];
	else
		return ' '; //consider empty line as a blank

}

int ScannerForIdents::getIdent() {
	
	lexeme = "";  //reset lexeme
	while (ch != '\0') {  //getCh() return 0 on eof is read. Note return when ident is found.
		while (isspace(ch)) ch = getCh();//skip white space

		if (isalpha(ch) || ch == '_') {
			//You write the code here.
			//You build an ident lexeme and send back int code 1 to indicate an ident is found.
			//The client code will get code that an ident is found and then call
			//getLexeme() to get the actual name of the identifier, i.e., the lexeme. 

			while (isalpha(ch) || ch == '_' || isdigit(ch)) {
				lexeme += ch;
				ch = getCh();
			}

			return 1;// ident found
		}
		else if (ch == '\'') {
			ch = getCh(); //read past char
			if (ch == '\\') {
				ch = getCh(); //read past escaped char  
			}
			ch = getCh(); // read past closing single quote
		}
		else if (ch == '"') { // process string literal
			// You write the code for reading past string literals
			ch = getCh();
			while (ch != '"') {
				ch = getCh();
			}
			ch = getCh();
		}
		else if (ch == '/') {  //potential start of a single line or multi line comment  
			ch = getCh();
			if (ch == '/') {  // one line comment
				ch = getCh();
				while (!fstreamObj->eof() && ch != '\n')	ch = getCh();
				if (fstreamObj->eof()) return 0; //return early when eof is reached. 
			}
			else if (ch == '*') { // multi-line comment 
				bool processMultiLineComment = true;
				ch = getCh();  //read past the '*'
				while (processMultiLineComment) { //process comment
					while (ch != '*' && processMultiLineComment) ch = getCh();
					ch = getCh(); // read past '*'
					if (ch != '/') {
						ch = getCh();
						if (ch == '\0') return 0;
					}
					else {
						ch = getCh(); //read past closing comment slash '/'
						processMultiLineComment = false; // stop the comment processing loop
					}

				}
			}
		}
		else {
			ch = getCh(); // read past current char
			if (ch == '\0') return 0;  //check for eof. 
		}

	}

	return 0;  //finally reached an eof
}

