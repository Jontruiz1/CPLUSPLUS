// TO BE COMPLETED:
//		postfix()

// SOLUTION: InfixToPost.h
#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctype.h>

#include "ExpressionSymbol.h"	// expressionSymbol class
#include "CS255Exceptions.h"	// for expressionError exception

using namespace std;

// labels designating the parentheses characters
const char lParen = '(';
const char rParen = ')';

class InfixToPostfix
{
public:
	// default constructor. infix expression is NULL string
	InfixToPostfix();

	// initialize the infix expression
	InfixToPostfix(const string& infixExp);

	// change the infix expression
	void setInfixExp(const string& infixExp);

	// return a string that contains the equivalent postfix expression.
	//   The function throws ExpressionError if an error occurs during conversion
	string postfix();

private:
	// the infix expression to convert
	string infixExpression;

	// built to contain the postfix equivalent of infixExpression
	string postfixExpression;

	// stack of expressionSymbol objects
	myStack<ExpressionSymbol> operatorStack;

	// The expressionSymbol object op holds the current symbol.
	//   Pop the stack and output as long as the symbol
	//   on the top of the stack has a precedence >= that of
	//   the current operator
	void outputHigherOrEqual(const ExpressionSymbol& op);

	// is ch one of '+','-','*','/', '^'
	bool isOperator(char ch) const;
};

void InfixToPostfix::outputHigherOrEqual(const ExpressionSymbol& op) {
	ExpressionSymbol op2;

	while (!operatorStack.isEmpty() && (op2 = operatorStack.top()) >= op) {
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool InfixToPostfix::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

InfixToPostfix::InfixToPostfix() {}

InfixToPostfix::InfixToPostfix(const string& infixExp) : infixExpression{ infixExp } {}

void InfixToPostfix::setInfixExp(const string& infixExp) {
	// assign a new infix expression
	infixExpression = infixExp;
	// make postfixExpression the NULL string
	postfixExpression = "";
}

string InfixToPostfix::postfix() {
						/**** TO BE COMPLETED *****/

	for (int i = 0; i < infixExpression.size(); ++i) {
		char ch = infixExpression[i];
		ExpressionSymbol op(ch);

		if (isdigit(ch)) {
			postfixExpression += ch;
			postfixExpression += ' ';
		}
		else if (ch == ')') {
			outputHigherOrEqual(op);
			operatorStack.pop();
		}
		else if (isOperator(ch) || ch == lParen) {
			outputHigherOrEqual(op);
			operatorStack.push(ch);
		}
	}

	while (!operatorStack.isEmpty()) {
		postfixExpression += operatorStack.top().getOp();
		postfixExpression += ' ';
		operatorStack.pop();
	}

	return postfixExpression;

} //end postfix()
#endif	// INFIX_TO_POSTFIX
