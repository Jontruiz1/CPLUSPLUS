// SOLUTION: InfixToPostDriver.cpp
//
// This program inputs an infix expression until the user enters an empty string.
//
// It uses the class infix2Postfix to convert the infix expression to postfix.
//		It assumes no errors.
//
// Assuming the infix to postfix works and the postfix string is correctly formatted,
//		class postfixEval is used to evaluate the postfix expression and output the result.

#include <iostream>
#include <string>
#include "InfixToPostfix.h"
#include "PostfixEval.h"
#include "CS255Exceptions.h"

using namespace std;

int main() {
	// use iexp for infix to postfix conversion
	InfixToPostfix iexp;

	string infixExp; //infix expression input
	string postfixExp; //postfix expression output

	PostfixEval pexp; //use pexp to evaluate postfix expressions

	// input and evaluate infix expressions until the
	// user enters an empty string

	// get the first expression
	cout << "Enter an infix expression: ";
	getline(cin, infixExp);

	while (infixExp != "") {
		// an exception may occur. enclose the conversion
		// to postfix and the output of the expression
		// value in a try block
		try {
			// set entered infix expression in iexp
			iexp.setInfixExp(infixExp);
			// convert to postfix
			postfixExp = iexp.postfix();

			// output the postfix expression
			cout << "The postfix form is " << postfixExp << endl;

			// use PostfixEval object pexp
			// store postfileExp string
			pexp.setPostfixExp(postfixExp);

			// Evaluate the postfix expression
			cout << "Value of the expression = " << pexp.evaluate() << endl << endl;
		}
		// catch an exception and output the error
		catch (const ExpressionError& ee) {
			cout << ee.what() << endl << endl;
		}

		// input another expression
		cout << "Enter an infix expression: ";
		getline(cin, infixExp);
	} //end while

	return 0;
} //end main

