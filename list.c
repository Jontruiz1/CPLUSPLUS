#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum tokenType {
    READ, WRITE, ID, NUMBER, LPAREN, RPAREN, SEMICOLON, COMMA, ASSIGN, PLUS, MINUS, TIMES, DIV, SCAN_EOF
};

char *mnemonic[] = { 
    "READ", "WRITE", "ID", "NUMBER", "LPAREN", "RPAREN", "SEMICOLON", "COMMA",
"ASSIGN", "PLUS", "MINUS", "TIMES", "DIV", "SCAN_EOF"
};

void lexical_error(char ch){
    fprintf(stderr, "Lexical Error. Unexpected character: %c.\n", ch);
}

char lexeme[256] = { '\0' };
unsigned int lexLen = 0;
FILE *src;

enum tokenType scan(){
    static int currentCh = ' ';
    static int tempCh = ' ';
    char* reserved[2] = { "read", "write" };
    lexLen = 0; // clear lexeme buffer for each scan
    lexeme[0] = '\0';
    extern FILE *src; //pointer to FILE handle that binds to source file.
    if (feof(src)) {
        return SCAN_EOF;
    }
    while ((currentCh = fgetc(src)) != EOF) {
        if (isspace(currentCh)) {
            continue;
        }
        else if (isalpha(currentCh)) { //needs to be modified
            lexeme[0] = currentCh;
            lexLen = 1;
            for (tempCh = fgetc(src); isalnum(tempCh) || tempCh == '_';) {
                //build identifier lexeme
            }
            lexeme[lexLen] = '\0';
            ungetc(tempCh, src); //put back character that is not a alpha/digit or ‘_’
            // see if lexeme is a reserved word, if not, return ID.
        }
        else if (isdigit(currentCh)) {
            // build lexeme for number
            // finish fixing lexeme string, ungetc the last character read that is not a digit and then return NUMBER
        }
        else if (currentCh == '+') {
            return PLUS;
        }
        // use selection statements to look for tokens for operators and delimiters and assignment (:=)
        else {
            lexical_error(currentCh);
        }
    }
    return SCAN_EOF;
}

int main(int argc, char *argv[]){
    extern FILE *src;
    enum tokenType currentToken;
    if(argc > 1){
        if(fopen_s(&src, argv[1], "r")){
            fprintf(stderr, "Error opening source file: %s ", argv[1]);
            exit(1);
        }
    }
    while((currentToken = scan()) != SCAN_EOF){
        //finish body for displaying the string version of the internal token name and
        //also print lexeme if the token is a ID or NUMBER. Do not print lexeme for the other tokens.
    }
    fclose(src);
    return 0;
}