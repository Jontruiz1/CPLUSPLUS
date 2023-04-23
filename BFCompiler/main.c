#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* CS435P03 - Jonathan Ruiz
*/

char lexeme[256] = { '\0' };
FILE* src;

enum tokenType currentToken;
unsigned numErrs = 0;

const enum tokenType { GREATER_THAN, LESS_THAN, PLUS, MINUS, RBRACKET, LBRACKET, PERIOD, COMMA, SCAN_EOF};
const char* mnemonic[] = { "GREATER_THAN", "LESS_THAN", "PLUS", "MINUS", "RBRACKET", "LBRACKET", "PERIOD", "COMMA", "SCAN_EOF"};

int parse();
void expr();
void term();
void stmt();
void factor();


void lexical_error(char ch)
{
	fprintf(stderr, "Lexical Error. Unexpected character: %c.\n", ch);
}

enum tokenType scan()
{
	unsigned int lexLen = 0;
	static int currentCh = ' ', tempCh = ' ';
	const char* reserved[3] = { "read", "write", "test" };
	size_t resSize = sizeof(reserved) / sizeof(reserved[0]); // size of reserved array 
	size_t mneSize = sizeof(mnemonic) / sizeof(mnemonic[0]); // size of mnemonic array (these 2 done in case more keywords were added)
	extern FILE* src; // pointer to FILE handle that binds to source file.

	lexeme[0] = '\0';

	if (feof(src)) {
		return SCAN_EOF;
	}
	while ((currentCh = fgetc(src)) != EOF) {
		if (isspace(currentCh)) {
			continue;
		}
		else if (isalpha(currentCh) || currentCh == '_') {
			lexeme[0] = currentCh;
			lexLen = 1;

			for (tempCh = fgetc(src); isalnum(tempCh) || tempCh == '_'; ++lexLen) {
				//build identifier lexeme
				lexeme[lexLen] = tempCh;
				tempCh = fgetc(src);
			}
			lexeme[lexLen] = '\0';
			ungetc(tempCh, src); //put back character that is not a alpha/digit or ‘_’


			// see if lexeme is a reserved word, if not, return ID
			// this matters if there are more reserved words
			// will break if the tokens and mnemonics are not parallel
			for (size_t i = 0; i < resSize; ++i) {
				// compare the current lexeme to every reserved word
				if (strcmp(reserved[i], lexeme) == 0) {
					// make the lexeme uppercase to work with the mnemonics
					for (size_t j = 0; j < lexLen; ++j) {
						lexeme[j] = toupper(lexeme[j]);
					}
					//if the lexeme is in the mnemonics, return the token
					for (size_t k = 0; k < mneSize - 1; ++k) {
						if (strcmp(mnemonic[k], lexeme) == 0) return ((enum token_type)(k));
					}
					break; // no point in going through the rest of the reserved words (if there are more)
				}
			}

			return ID;
		}
		else if (isdigit(currentCh)) {
			// build lexeme for number
			// finish fixing lexeme string, ungetc the last character read that is not a digit and then return NUMBER
			lexeme[0] = currentCh;
			lexLen = 1;
			for (tempCh = fgetc(src); isdigit(tempCh); ++lexLen) {
				lexeme[lexLen] = tempCh;
				tempCh = fgetc(src);
			}
			lexeme[lexLen] = '\0';
			ungetc(tempCh, src);
			//put back char that is not number
			return NUMBER;
		}
		// use selection statements to look for tokens for operators and delimiters and assignment (:=)
		else {
			// organized by PEMDAS because I thought it was neat
			switch (currentCh) {
			case '(': return LPAREN;
			case ')': return RPAREN;
			case '*': return TIMES;
			case '/': return DIV;
			case '+': return PLUS;
			case '-': return MINUS;
			case ';': return SEMICOLON;
			case ',': return COMMA;
			case ':': if ((currentCh = fgetc(src)) == '=') return ASSIGN;
			case '$': if ((currentCh = fgetc(src)) == '$') return SCAN_EOF; // unsure if needed but it's here
			default: lexical_error(currentCh);
			}
		}
	}
	return SCAN_EOF;
}

int main(int argc, char* argv[]) {
	// open file
	extern FILE* src;
	if (argc > 1) {
		if (fopen_s(&src, argv[1], "r")) {
			fprintf(stderr, "Error opening source file: %s ", argv[1]);
			exit(1);
		}
	}

	// parse, prints the completion if no errors
	parse();
	printf("Parsing complete. No errors.\n");
	fclose(src);

	return 0;
}// end driver

int parse() {

	currentToken = scan();
	// I know you said we didn't need to check for EOF but I wanted to try so I put it here
	if (currentToken == SCAN_EOF) {
		printf("Error in parsing: Expected statement.\n");
		exit(1);
	}

	while (currentToken != SCAN_EOF) {
		stmt();
	}
	return numErrs;

}

void parse_error(char* errMsg, char* lexeme) {
	extern unsigned numErrs;	// for future error recovery
	numErrs++;
	fprintf(stderr, "%s: %s\n", errMsg, lexeme);
}

void match(enum tokenType expected) {
	if (currentToken == expected) {
		currentToken = scan();
	}
	else {
		parse_error("Expected symbol", mnemonic[expected]);
		fclose(src);
		exit(1);
	}
}

void stmt() {
	switch (currentToken) {
	case ID: // handling the ID := expr
		currentToken = scan();
		match(ASSIGN);
		expr();
		break;
	case WRITE: //handling the write(expr_1, expr_2, ... expr_i
		currentToken = scan();
		match(LPAREN);
		expr();
		while (currentToken == COMMA) {
			currentToken = scan();
			expr();
		}
		match(RPAREN);
		break;
	case READ: 	// handling the read(id_1, id_2 ... id_i)
		currentToken = scan();
		match(LPAREN);
		match(ID);
		while (currentToken == COMMA) {
			currentToken = scan();
			match(ID);
		}
		match(RPAREN);
		break;
	default:
		printf("Error in statement: Expected ID, READ, or WRITE.\n");
		exit(1);
	}

	// handles matching the semicolon at the end of every line
	match(SEMICOLON);
}

void expr() {
	term();
	while (currentToken == PLUS || currentToken == MINUS) {
		currentToken = scan();
		term();
	}
}

void term() {
	factor();
	while (currentToken == TIMES || currentToken == DIV) {
		currentToken = scan();
		factor();
	}
}

void factor() {
	if (currentToken == ID || currentToken == NUMBER) currentToken = scan();
	else if (currentToken == LPAREN) {
		currentToken = scan();
		expr();
		match(RPAREN);
	}
	else {
		printf("Error in expression: Expected ID, NUMBER, or '('.\n");
		exit(1);
	}
}
